/**  smsh1.c  small-shell version 1
 **		first really useful version after prompting shell
 **		this one parses the command line into strings
 **		uses fork, exec, wait, and ignores signals
 **/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	"smsh2.h"

#define	DFL_PROMPT	"> "

int main()
{
	char	*cmdline, *prompt, **arglist;
	int	result;
	void	setup();

	prompt = DFL_PROMPT ;
	setup();

	while ( (cmdline = next_cmd(prompt, stdin)) != NULL ){

		//Finds number of arguments
		int i, argSize = 0;
		for(i = 0; i < 255; i++)
		{
			if(cmdline[i] == ' ')
			{
				argSize++;
			}
		}


		if ( (arglist = splitline(cmdline)) != NULL  ){

			//sets the pipe to NULL
			int pipes = 0;
			for(i = 0; i < argSize+1; i++)
	        {
				//printf("[%d] %c \n",i,*arglist[i]);
	            if(*arglist[i] == '|')
	            {
	                pipes++;
					arglist[i] = NULL;
	            }
	        }


			result = execute(arglist,pipes+1);
			freelist(arglist);
		}
		free(cmdline);
	}
	return 0;
}

void setup()
/*
 * purpose: initialize shell
 * returns: nothing. calls fatal() if trouble
 */
{
	signal(SIGINT,  SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void fatal(char *s1, char *s2, int n)
{
	fprintf(stderr,"Error: %s,%s\n", s1, s2);
	exit(n);
}
