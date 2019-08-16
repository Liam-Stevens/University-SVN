//Creates a 6x10 array to store brick values
int[][] bricks = {
  {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, 
  {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}
};
int ballX = 0;
int ballY = 0;
int ballDX = 0; //States direction: 0 == Left, 1==Right
int ballDY = 0; //States direction: 0 == Up, 1==Down

void setup() {
  size(500,500);
  rectMode(CENTER);
  ballX = width/2;
  ballY = 9*height/10;
  frameRate = 60;
}

void draw() {
  background(0);
  
  //Draw Bricks
  fill(255);
  //X-axis bricks
  for (int i = 0; i < bricks[0].length; i++) {
    //Y-axis bricks
    for (int j = 0; j < bricks.length; j++) {
      
      rect(i*width/10+width/20,j*height/20+height/10,width/10,height/20);
      
    }
    
  }
  
  //Ball
  fill(255);
  ellipse(ballX,ballY,10,10);
  if (ballDX == 0) {
    ballX-=2;
  } else if (ballDX == 1) {
    ballX+=2;
  } if (ballDY == 0) {
    ballY-=2;
  } else if (ballDY == 1) {
    ballY+=2;
  } if (ballX <= 0) {
    ballDX = 1;
  } else if (ballX >= width) {
    ballDX = 0;
  } if (ballY <= 0) {
    ballDY = 1;
  } else if (ballY >= height) {
    ballDY = 0;
    ballDX = int(random(0,2)-0.1);
  }
  
}