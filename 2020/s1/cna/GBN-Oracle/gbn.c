#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "emulator.h"
#include "altbit.h"

/********************************************************************
   IMPORTANT Note for Intructors: I forgot the write the changes made in
   the SVN comments, so I am trying to make up for it here.

   SVN CHANGELOG for Alt Bit Oracle Tests
   Rev 701: B_init's expectedseqnum to 0.
   Rev 702: Added starttimer to A_output and A_timerinterrupt. Added stoptimer to A_input.
   Rev 703: Added static int A_acknum, which is initialised to -1 in A_init to store num of the last ACKed packet.
            Made A count ACK as duplicate if A_acknum is larger than the ACK. Made B send an ACK with num: expectedseqnum - 1.
   Rev 704: I realised the ACK can only be 0 or 1. Changed B ACK sent to be (expectedseqnum + 1) % 2.
   Rev 705: Created checksum as integer sum of the payload.
   Rev 706: Initialised A_acknum to 1.
   Rev 707: Added seqnum and acknum to checksum.

   SVN CHANGELOG for GBN Oracle Tests
   REV 718: Updated all of the variables which change between 0 and 1 to account for the larger window size.
   REV 719:
   TODO: Change timers to work with the larger windows size.
**********************************************************************/

#define RTT  15.0       /* round trip time.  MUST BE SET TO 15.0 when submitting assignment */
#define WINDOWSIZE 6    /* alternating bit only allows one unacked packet */
#define NOTINUSE (-1)   /* used to fill header fields that are not being used */

/* generic procedure to compute the checksum of a packet.  Used by both sender and receiver
   the simulator will overwrite part of your packet with 'z's.  It will not overwrite your
   original checksum.  This procedure must generate a different checksum to the original if
   the packet is corrupted.
*/
int ComputeChecksum(struct pkt packet)
{
  int checksum = 0;
  int i = 0;

  /****** 4. FILL IN CODE to calculate the checksum of packet *****/
  checksum = packet.seqnum + packet.acknum;

  for (i = 0; i < 20; i++)
  {
      checksum += (int)packet.payload[i];
  }

  return checksum;
}

bool IsCorrupted(struct pkt packet)
{
  if (packet.checksum == ComputeChecksum(packet))
    return (false);
  else
    return (true);
}

/********* Sender (A) variables and functions ************/

static struct pkt buffer[WINDOWSIZE];  /* array for storing packets waiting for ACK */
static int windowfirst, windowlast;    /* array indexes of the first/last packet awaiting ACK */
static int windowcount;                /* the number of packets currently awaiting an ACK */
static int A_nextseqnum;               /* the next sequence number to be used by the sender */
static int A_acknum;
static int activePackets;

/* called from layer 5 (application layer), passed the message to be sent to other side */
void A_output(struct msg message)
{
  struct pkt sendpkt;
  int i;

  /* if not blocked waiting on ACK */
  if ( windowcount < WINDOWSIZE) {
    if (TRACE > 1)
      printf("----A: New message arrives, send window is not full, send new messge to layer3!\n");

    /* create packet */
    sendpkt.seqnum = A_nextseqnum;
    sendpkt.acknum = NOTINUSE;
    for ( i=0; i<20 ; i++ )
      sendpkt.payload[i] = message.data[i];
    sendpkt.checksum = ComputeChecksum(sendpkt);

    /* put packet in window buffer */
    /* windowlast will always be 0 for alternating bit; but not for GoBackN */
    windowlast = (windowlast + 1) % WINDOWSIZE;
    buffer[windowlast] = sendpkt;
    for (i=0; i<20; i++)
      buffer[windowlast].payload[i]=sendpkt.payload[i];  /* copy the array */
    windowcount++;

    /* send out packet */
    if (TRACE > 0)
      printf("Sending packet %d to layer 3\n", sendpkt.seqnum);
    tolayer3 (A, sendpkt);
    /* REV 719: will not start timer with more packets */
    if (activePackets == 0)
    {
        starttimer(A, RTT);
    }
    activePackets++;


    /* REV 718: changed to account for window SIZE */
    A_nextseqnum = (A_nextseqnum + 1) % WINDOWSIZE;
  }
  /* if blocked,  window is full */
  else {
    if (TRACE > 0)
      printf("----A: New message arrives, send window is full\n");
    window_full++;
  }
}


/* called from layer 3, when a packet arrives for layer 4
   In this practical this will always be an ACK as B never sends data.
*/
void A_input(struct pkt packet)
{

  /* if received ACK is not corrupted */
  if (!IsCorrupted(packet)) {
    if (TRACE > 0)
      printf("----A: uncorrupted ACK %d is received\n",packet.acknum);
    total_ACKs_received++;

    /* check if new ACK or duplicate */
    if (packet.acknum != A_acknum) {    /**** 2. FILL IN CODE replace TRUE with test whether this is a new ACK ***/
      /* packet is a new ACK */
      if (TRACE > 0)
        printf("----A: ACK %d is not a duplicate\n",packet.acknum);
      new_ACKs++;

      A_acknum = packet.acknum;

      /* delete the acked packets from window buffer */
      windowcount--;

      stoptimer(A);

      /* REV 719: start timer again if there is an active packet */
      activePackets--;
      if (activePackets != 0)
      {
          starttimer(A, RTT);
      }
    }
    else
      if (TRACE > 0)
        printf ("----A: duplicate ACK received, do nothing!\n");
  }
  else
    if (TRACE > 0)
      printf ("----A: corrupted ACK is received, do nothing!\n");
}

/* called when A's timer goes off */
void A_timerinterrupt(void)
{

  if (TRACE > 0)
    printf("----A: time out,resend packets!\n");

  if (TRACE > 0)
    printf ("---A: resending packet %d\n", (buffer[windowfirst]).seqnum);
  tolayer3(A,buffer[windowfirst]);
  /**** 1. FILL IN CODE What state should the timer be in at this point? *****/
  starttimer(A, RTT);


  packets_resent++;
}



/* the following routine will be called once (only) before any other */
/* entity A routines are called. You can use it to do any initialization */
void A_init(void)
{
  /* initialise A's window, buffer and sequence number */
  A_nextseqnum = 0;  /* A starts with seq num 0, do not change this */
  windowfirst = 0;
  windowlast = -1;   /* windowlast is where the last packet sent is stored.
		     new packets are placed in winlast + 1
		     so initially this is set to -1		   */
  windowcount = 0;
  A_acknum = WINDOWSIZE-1;
  activePackets = 0;
}



/********* Receiver (B)  variables and procedures ************/

static int expectedseqnum; /* the sequence number expected next by the receiver */
static int B_nextseqnum;   /* the sequence number for the next packets sent by B */
static bool firstPacket;


/* called from layer 3, when a packet arrives for layer 4 at B*/
void B_input(struct pkt packet)
{
  struct pkt sendpkt;
  int i;

  /* if not corrupted and received packet is in order */
  if  ( (!IsCorrupted(packet))  && (packet.seqnum == expectedseqnum) ) {
    if (TRACE > 0)
      printf("----B: packet %d is correctly received, send ACK!\n",packet.seqnum);
    packets_received++;

    /* deliver to receiving application */
    tolayer5(B, packet.payload);

    /* send an ACK for the received packet */
    sendpkt.acknum = expectedseqnum;

    /* update state variables */
    /* REV 718: update for windows size */
    expectedseqnum = (expectedseqnum + 1) % WINDOWSIZE;
    firstPacket = false;
  }
  else {
    /* packet is corrupted or out of order */
    if (TRACE > 0)
      printf("----B: packet corrupted or not expected sequence number, resend ACK!\n");
    /***** 3. FILL IN CODE  What ACK number should be sent if the packet
	   was corrupted or out of order? *******/
    if (firstPacket == false)
    {
        sendpkt.acknum = (expectedseqnum + 1) % WINDOWSIZE;
    }
  }

  /* create packet */
  sendpkt.seqnum = B_nextseqnum;
  /* REV 718: update for window size*/
  B_nextseqnum = (B_nextseqnum + 1) % WINDOWSIZE;

  /* we don't have any data to send.  fill payload with 0's */
  for ( i=0; i<20 ; i++ )
    sendpkt.payload[i] = '0';

  /* computer checksum */
  sendpkt.checksum = ComputeChecksum(sendpkt);

  /* send out packet */
  tolayer3 (B, sendpkt);
}

/* the following routine will be called once (only) before any other */
/* entity B routines are called. You can use it to do any initialization */
void B_init(void)
{
  expectedseqnum = 0;
  B_nextseqnum = 1;
  firstPacket = true;
}

/******************************************************************************
 * The following functions need be completed only for bi-directional messages *
 * They do not need to be completed for this practical                        *
 *****************************************************************************/

/* Note that with simplex transfer from a-to-B, there is no B_output() */
void B_output(struct msg message)
{
}

/* called when B's timer goes off */
void B_timerinterrupt(void)
{
}
