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
int ballEdgeX = 0;
int ballEdgeY = 0;
int sideLeft = 0;
int sideRight = 0;
int sideUp = 0;
int sideDown = 0;

void setup() {
  size(500,500);
  background(0);
  //noCursor();
  rectMode(CENTER);
  ballX = width/2;
  ballY = 9*height/10;
  frameRate(120);
  ballEdgeX = ballX;
  ballEdgeY = ballY;
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
  
  //Ball Direction Changes
  if (ballEdgeX <= 0) {
    ballDX = 1;
  } else if (ballX >= width) {
    ballDX = -1;
  } if (ballEdgeY <= 0) {
    ballDY = 1;
  } else if (ballY >= height) {
    ballDY = -1;
    //ballDX = -1;  make this a fail condition
  } 
  
  //Check for hitting platform - currently if mouse off screen, ball passes through
  if (ballEdgeY >= 9*height/10 - platformHeight/2 && ballEdgeY <= 9*height/10 + platformHeight/2 
  && ballEdgeX >= platformX - platformWidth && ballEdgeX <= platformX + platformHeight) {
    ballDY = -1;
  }
    
  //Locks platform within the view window
  if (abs(mouseX - platformX) > 0.1) {
    platformX = platformX + (mouseX - platformX) * platformSpeed;
  }
  platformX = constrain(platformX, platformWidth/2, width-platformWidth/2);
  
  //Draw platform
  rect(platformX, 9*height/10, platformWidth, platformHeight);
  
  //Calculating the ball edge location
  if (ballDX == -1) {
    ballEdgeX = ballX - ballRadius;
  } else if (ballDX == 1) {
    ballEdgeX = ballX + ballRadius;
  } if (ballDY == -1) {
    ballEdgeY = ballY - ballRadius;
  } else if (ballDY == 1) {
    ballEdgeY = ballY + ballRadius;
  }
  
  //Draw Bricks
  fill(255);
  //X-axis bricks
  for (int i = 0; i < bricks[0].length; i++) {
    //Y-axis bricks
    for (int j = 0; j < bricks.length; j++) {
      
      //Check if the brick is in play
      if (ballEdgeY <= (j+1)*height/20+height/10 && ballEdgeY >= j*height/20+height/10 
      && ballEdgeX >= i*width/10 && ballEdgeX <= (i+1)*width/10 && bricks[j][i] == 1) {
        bricks[j][i] = 0;
        //Check which way it is approaching from - change to work with side of brick code
        if (sideDown == 1) {
          ballDY = 1;
          sideDown = 0;
          println(sideDown);
        } else if (sideUp == 1) {
          ballDY = -1;
          sideUp = 0;
        } else if (sideLeft == 1) {
          ballDX = -1;
          sideLeft = 0;
        } else if (sideRight == 1) {
          ballDX = 1;
          sideRight = 0;
        }        
      }
      
      //Draw brick if it is in play
      if (bricks[j][i] == 1) {
        rect(i*width/10+width/20,j*height/20+height/10,width/10,height/20);
      }
      
    }
    
  }
  
  //something wrong - not detecting
  for (int i = 0; i < bricks[0].length; i++) {
    for (int j = 0; j < bricks.length; j++) {
      //Check if hitting side of brick
      if (ballDX == -1) {
        if (ballEdgeY <= (j+1)*height/20+height/10 && ballEdgeY >= j*height/20+height/10 
        && ballEdgeX-ballSpeed >= i*width/10 && ballEdgeX-ballSpeed <= (i+1)*width/10 && bricks[j][i] == 1) {
          sideLeft = 1;
        }
      } else if (ballDX == 1) {
          if (ballEdgeY <= (j+1)*height/20+height/10 && ballEdgeY >= j*height/20+height/10 
          && ballEdgeX+ballSpeed >= i*width/10 && ballEdgeX+ballSpeed <= (i+1)*width/10 && bricks[j][i] == 1) {
            sideRight = 1;
        }
      } 
      if (ballDY == -1) {
          if (ballEdgeY+ballSpeed <= (j+1)*height/20+height/10 && ballEdgeY+ballSpeed >= ballSpeed+j*height/20+height/10 
          && ballEdgeX >= i*width/10 && ballEdgeX <= (i+1)*width/10 && bricks[j][i] == 1) {
            sideUp = 1;
        }
      } else if (ballDY == 1) {
          if (ballEdgeY-ballSpeed <= (j+1)*height/20+height/10 && ballEdgeY-ballSpeed >= -ballSpeed+j*height/20+height/10 
          && ballEdgeX >= i*width/10 && ballEdgeX <= (i+1)*width/10 && bricks[j][i] == 1) {
            sideDown = 1;
        }
      }
    }
  }
  
  //Draw Ball
  fill(255);
  ellipse(ballX,ballY,2*ballRadius,2*ballRadius);
  
}