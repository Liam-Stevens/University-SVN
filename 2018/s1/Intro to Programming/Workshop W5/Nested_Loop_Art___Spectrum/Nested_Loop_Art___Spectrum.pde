size(500,500);
background(0);

int squares=250;
int[][] art = new int[squares][squares];
int rad=1;
int thicc=width/squares;
rectMode(RIGHT);
noStroke();

for (int i=squares; i>0; i--) {
  
  for (int t=squares; t>0; t--) {
    
    fill(i/t,i-t,i+t);
    rect((t-1)*thicc,(i-1)*thicc,t*thicc,i*thicc);
    
  }
  
}