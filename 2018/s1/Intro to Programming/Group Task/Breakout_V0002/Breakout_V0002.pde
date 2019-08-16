//Creates a 6x10 array to store brick values
int[][] bricks = {
  {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, 
  {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}
};
//Global variables
int ballX = 0;
int ballY = 0;
int ballDX = -1; //States direction: -1 == Left, 1==Right, 0 == Stationary
int ballDY = -1; //States direction: -1 == Up, 1==Down, 0 == Stationary
boolean directionChange = false;
int ballSpeed = 1; //Try not to change this as it has increasing effects on detection
int ballRadius = 5;
float platformX = 0;
float platformSpeed = 1;
float platformWidth = 70;
int platformHeight = 10;
int nextFrameX = 0;
int nextFrameY = 0;

void setup() {
  size(500,500);
  background(0);
  //noCursor();
  rectMode(CENTER);
  ballX = width/2;
  ballY = 9*height/10;
  frameRate(120);
  nextFrameX = ballX;
  nextFrameY = ballY;
}

void draw() {
  background(0);
    
  //Ball Location Changes
  if (ballDX == -1) {
    ballX -= ballSpeed;
  } else if (ballDX == 1) {
    ballX += ballSpeed;
  } if (ballDY == -1) {
    ballY -= ballSpeed;
  } else if (ballDY == 1) {
    ballY += ballSpeed;
  } 
  
  directionChange = false;
  
  //Ball Direction Changes
  if (nextFrameX <= 0) {
    ballDX = 1;
    directionChange = true;
  } else if (ballX >= width) {
    ballDX = -1;
    directionChange = true;
  } if (nextFrameY <= 0) {
    ballDY = 1;
    directionChange = true;
  } else if (ballY >= height) {
    ballDY = -1;
    //ballDX = -1;  make this a fail condition
  } 
  
  //Check for hitting platform - currently if mouse off screen, ball passes through
  if (nextFrameY >= 9*height/10 - platformHeight/2 && nextFrameY <= 9*height/10 + platformHeight/2 
  && nextFrameX >= platformX - platformWidth && nextFrameX <= platformX + platformHeight) {
    ballDY = -1;
    directionChange = true;
  }
    
  //Locks platform within the view window
  if (abs(mouseX - platformX) > 0.1) {
    platformX = platformX + (mouseX - platformX) * platformSpeed;
  }
  platformX = constrain(platformX, platformWidth/2, width-platformWidth/2);
  
  //Draw platform
  rect(platformX, 9*height/10, platformWidth, platformHeight);
  
  //Draw Bricks
  fill(255);
  //X-axis bricks
  for (int i = 0; i < bricks[0].length; i++) {
    //Y-axis bricks
    for (int j = 0; j < bricks.length; j++) {
      
      //Check if the brick is in play
      if (nextFrameY <= (j+1)*height/20+height/10 && nextFrameY >= j*height/20+height/10 
      && ballX >= i*width/10+width/20 && ballX <= (i+1)*width/10+width/20 && bricks[j][i] == 1) {
        bricks[j][i] = 0;
        //Check which way it is approaching from
        if (ballDY == -1) {
          ballDY = 1;
          directionChange = true;
        } else if (ballDY == -1) {
          ballDY = -1;
          directionChange = true;
        }
      }
      else if (nextFrameX >= i*width/10+width/20 && nextFrameX <= (i+1)*width/10+width/20 
      && ballY <= (j+1)*height/20+height/10 && ballY >= j*height/20+height/10 && bricks[j][i] == 1) {
        bricks[j][i] = 0;
        //Check which way it is approaching from
        if (ballDX == -1) {
          ballDX = 1;
          directionChange = true;
        } else if (ballDX == -1) {
          ballDX = -1;
          directionChange = true;
        }
      }
      
      //Draw brick if it is in play
      if (bricks[j][i] == 1) {
        rect(i*width/10+width/20,j*height/20+height/10,width/10,height/20);
      }
      
    }
    
  }
  
  //Calculating the ball edge location on the next frame
  if (directionChange == false) {
    if (ballDX == -1) {
      nextFrameX = ballX - ballSpeed - ballRadius;
    } else if (ballDX == 1) {
      nextFrameX = ballX + ballSpeed + ballRadius;
    } if (ballDY == -1) {
      nextFrameY = ballY - ballSpeed - ballRadius;
    } else if (ballDY == 1) {
      nextFrameY = ballY + ballSpeed + ballRadius;
    }
  } else if (directionChange == true) {
    //Needs to detect the type of change - is currently redundent for the sake of working
    if (ballDX == -1) {
      nextFrameX = ballX - ballSpeed - ballRadius;
    } else if (ballDX == 1) {
      nextFrameX = ballX + ballSpeed + ballRadius;
    } if (ballDY == -1) {
      nextFrameY = ballY - ballSpeed - ballRadius;
    } else if (ballDY == 1) {
      nextFrameY = ballY + ballSpeed + ballRadius;
    }
  }
  
  //Draw Ball
  fill(255);
  ellipse(ballX,ballY,2*ballRadius,2*ballRadius);
  
}