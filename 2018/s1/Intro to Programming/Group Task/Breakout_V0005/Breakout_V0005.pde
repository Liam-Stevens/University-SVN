//Creates a 6x10 array to store brick values
int[][] bricks = {
  {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, 
  {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}
};
//Global variables
float ballX = 0;
float ballY = 0;
int ballDX = -1; //States direction: -1 == Left, 1==Right, 0 == Stationary
int ballDY = -1; //States direction: -1 == Up, 1==Down, 0 == Stationary
boolean directionChange = false;
float ballSpeedY = 1;
float ballSpeedX = 1;
float speedIncrease = 0;
int ballRadius = 5;
int life = 3;
int lifeTimer = 0;
int lifeFade = 0;
float platformX = 0;
float platformSpeed = 1;
float platformWidth = 70;
int platformHeight = 10;
float ballEdgeX = 0;
float ballEdgeY = 0;
int sideLeft = 0;
int sideRight = 0;
int sideUp = 0;
int sideDown = 0;
float ballDxRand;
boolean hitPlatform = false;
boolean lifeLost = false;
int bricksExist = 0;

void setup() {
  size(500,500);
  background(0);
  //noCursor();
  rectMode(CENTER);
  resetGame();
  frameRate(120);
  ballEdgeX = ballX;
  ballEdgeY = ballY;
}

void draw() {
  background(0);
  
  checkGameState();
    
  //Ball Location Changes
  if (ballDX == -1) {
    ballX -= ballSpeedX;
  } else if (ballDX == 1) {
    ballX += ballSpeedX;
  } 
  if (ballDY == -1) {
    ballY -= ballSpeedY;
  } else if (ballDY == 1) {
    ballY += ballSpeedY;
  } 
  
  //Ball Direction Changes
  if (ballEdgeX <= 0) {
    ballDX = 1;
  } else if (ballX >= width) {
    ballDX = -1;
  } 
  if (ballEdgeY <= 0) {
    ballDY = 1;
  } else if (ballY >= height+ballSpeedY*120) {
    //Will reset the game 2 seconds after the ball has gone off screen
    resetGame();
    life -= 1;
  } 
  
  //Displays remaining lives for 7 seconds
  if (lifeTimer > 0) {
    fill(255,255,255,240-lifeFade);
    textSize(19);
    text("Life: " + life, 5, 20);
    fill(255);
    lifeTimer -= 1;
    //Fades the text out after 5 seconds, over 2 seconds
    if (lifeTimer != 0 && lifeTimer < 240) {
      lifeFade++;
    }
    //Resets timer state
    if (lifeTimer == 0) {
      lifeLost = false;
      lifeFade = 0;
    }
  }
    
  //Locks platform within the view window
  if (abs(mouseX - platformX) > 0.1) {
    platformX = platformX + (mouseX - platformX) * platformSpeed;
  }
  platformX = constrain(platformX, platformWidth/2, width-platformWidth/2);
  
  //Draw platform
  rect(platformX, 9*height/10, platformWidth, platformHeight);
  
  //Check for hitting platform
  if (ballEdgeY-ballSpeedY >= height/500+9*height/10 - platformHeight && ballEdgeY <= height/500+9*height/10 + platformHeight 
  && ballEdgeX >= platformX - platformWidth/2 && ballEdgeX <= platformX + platformWidth/2) {
    ballDY = -1;
    ballDX = DxRand();
    ballSpeedX = randomSpeed();
    ballSpeedY = randomSpeed();
    hitPlatform = false;
  }
  
  //Forces average ball speed to increase
  ballSpeedIncreaseRate();
  
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
        //Check which way it is approaching from
        if (sideDown == 1) {
          ballDY = 1;
          sideDown = 0;
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
  
  //Checks 1 frame head to see if ball will hit a brick
  for (int i = 0; i < bricks[0].length; i++) {
    for (int j = 0; j < bricks.length; j++) {
      //Check if hitting side of brick
      if (ballDX == -1) {
        //Each of these if statements is unique to the direction of the ball and cannot be shortened
        if (ballEdgeY <= (j+1)*height/20+height/10 && ballEdgeY >= j*height/20+height/10 
        && ballEdgeX-ballSpeedX >= i*width/10 && ballEdgeX-ballSpeedX <= (i+1)*width/10 && bricks[j][i] == 1) {
          sideRight = 1;
        }
      } else if (ballDX == 1) {
          if (ballEdgeY <= (j+1)*height/20+height/10 && ballEdgeY >= j*height/20+height/10 
          && ballEdgeX+ballSpeedX >= i*width/10 && ballEdgeX+ballSpeedX <= (i+1)*width/10 && bricks[j][i] == 1) {
            sideLeft = 1;
        }
      } 
      if (ballDY == -1) {
          if (ballEdgeY-ballSpeedY <= (j+1)*height/20+height/10 && ballEdgeY+ballSpeedY >= 1+j*height/20+height/10 
          && ballEdgeX >= i*width/10 && ballEdgeX <= (i+1)*width/10 && bricks[j][i] == 1) {
            sideDown = 1;
        }
      } else if (ballDY == 1) {
          if (ballEdgeY+ballSpeedY <= (j+1)*height/20+height/10 && ballEdgeY-ballSpeedY >= -1+j*height/20+height/10 
          && ballEdgeX >= i*width/10 && ballEdgeX <= (i+1)*width/10 && bricks[j][i] == 1) {
            sideUp = 1;
        }
      }
    }
  }
    
  //Draw Ball
  noStroke();
  fill(255);
  ellipse(ballX,ballY,2*ballRadius,2*ballRadius);
  stroke(0);
    
}

//Checks if the game has been won or lost
void checkGameState() {
  
  //Checks losing Conditions
  if (life == 0) {
    //Losing Event
    
  }
  
  //Checks Winning Conditions
  bricksExist = 0;
  
  for (int i = 0; i < bricks[0].length; i++) {
    for (int j = 0; j < bricks.length; j++) {
      if (bricks[j][i] != 0) {
        bricksExist = 1;
      }
    }
  }
  
  if(bricksExist == 0) {
    //winning Event
    
  }
}

//Resets the active game state
void resetGame() {
  //X-axis bricks
  for (int i = 0; i < bricks[0].length; i++) {
    //Y-axis bricks
    for (int j = 0; j < bricks.length; j++) {
      
      bricks[j][i] = 1;
            
    }
  }
  
  ballX = width/2;
  ballY = 9*height/10;
  ballDX = DxRand();
  ballDY = -1;
  ballSpeedX = random(0.5,2);
  ballSpeedY = random(0.5,2);
  speedIncrease = 0;
  lifeTimer = 840;
  lifeFade = 0;
}

//Increases ball average ball speed at rate of 1 pixel per 30 seconds
void ballSpeedIncreaseRate() {
  if (speedIncrease <= 3) {
    speedIncrease += 0.0001;
  }
}

//Generates a random speed for the ball
float randomSpeed() {
  float speed = random(0.5 + speedIncrease, 2 + speedIncrease);
  return speed;
}

//Randomises the direction of the ball in the x direction
int DxRand() {
  for (int i=0; i<1; i++) {
    ballDxRand = (float)random(-1, 1);
    if (ballDxRand <0) {
      ballDxRand = -1;
    } else if 
      (ballDxRand > 0) {
      ballDxRand = 1;
    }
   
    while (ballDxRand==0) {
      for (int j=0; j<10; j++) {
        ballDxRand= (float)random(-1, 1);
        if (ballDxRand <0) {
          ballDxRand=-1;
        } else if 
          (ballDxRand>0) {
          ballDxRand=1;
        }
      }
     
    }
  }
  return int(ballDxRand);
}