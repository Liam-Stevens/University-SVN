//Creates a 6x10 array to store brick values
int[][] bricks = {
  {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, 
  {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}, {1,1,1,1,1,1,1,1,1,1}
};
//Global variables
//Main Game Variables
color backgroundColour = color(24,35,149);
color baseBrick = color(255);
float ballX = 0;
float ballY = 0;
int ballDX = -1; //States direction: -1 == Left, 1==Right, 0 == Stationary
int ballDY = -1; //States direction: -1 == Up, 1==Down, 0 == Stationary
boolean directionChange = false;
float ballSpeedY = 1;
float ballSpeedX = 1;
float speedIncrease = 0;
float speedGapClose = 1/2;
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
boolean powerupsEnabled = true;
boolean gameClick = false;
boolean endCard = false;
int yellowTime = 0;
boolean gameStarted = false;

//Title Screen Variables
int gameState = 0;
float titleAdjust;
float titleStartX;
float titleStartY;
float titleStartWidth;
float titleStartHeight;
boolean titleClick = false;
float titleInstructX;
float titleInstructY;
float titleInstructWidth;
float titleInstructHeight;
float titleSettingsX;
float titleSettingsY;
float titleSettingsWidth;
float titleSettingsHeight;
float titleBackX;
float titleBackY;
float titleBackWidth;
float titleBackHeight;
color titleBack = color(227,120,57);
color titleBackHover = color(183,68,2);
color titleRed = color(234,63,91);
color titleDarkRed = color(206,19,19);
color titleGreen = color(61,232,113);
color titleDarkGreen = color(39,203,89);
color titleBlue = color (89,176,232);
color titleDarkBlue = color (42,137,198);
boolean startHover = false;
boolean instructHover = false;
boolean settingsHover = false;
boolean backHover = false;

//Brick Colours
color greenBrick = color(43,166,77);
color purpleBrick = color(156,0,207);
color blueBrick = color(0,113,255);
color orangeBrick = color(255,132,31);
color yellowBrick = color(255,255,25);
color redBrick = color(245,0,0);

void setup() {
  size(500,500);
  
  //Main Game Initialisation
  background(0);
  //noLoop();
  resetGame();
  frameRate(120);
  ballEdgeX = ballX;
  ballEdgeY = ballY;
  rectMode(CENTER);
  
  //Title Screen
  titleAdjust = width/6;
  titleStartX = width/2;
  titleStartY = height/6 + titleAdjust;
  titleStartWidth = titleStartX;
  titleStartHeight = height/6;
  titleInstructX = titleStartX;
  titleInstructY = 5*height/12 + titleAdjust;
  titleInstructWidth = titleStartWidth;
  titleInstructHeight = titleStartHeight;
  titleSettingsX = titleStartX;
  titleSettingsY = 4*height/6 + titleAdjust;
  titleSettingsWidth = titleStartWidth;
  titleSettingsHeight = titleStartHeight;
  titleBackWidth = width/4;
  titleBackHeight = height/10;
  titleBackX = titleBackWidth/2+3;
  titleBackY = height-titleBackHeight/2-3;
  
  //Instructions Screen
  
  
  //Settings Screen
  
}

void draw() {
  //Reset to default state to account for existing code
  background(backgroundColour);
  strokeWeight(5);
  stroke(backgroundColour);
  textAlign(BASELINE);
  rectMode(CENTER);
  
  //Title Screen***********************************
  if (gameState == 0) {
    //Set states for title screen
    strokeWeight(3);
    textAlign(CENTER);
    textSize(32);
    
    //Draw Start Button
    if (titleButtonCheck(titleStartX,titleStartY,titleStartWidth,titleStartHeight) == true) {
      fill(titleDarkRed);
      stroke(titleRed);
      startHover = true;
    } else {
      fill(titleRed);
      stroke(titleDarkRed);
      startHover = false;
    }
    rect(titleStartX, titleStartY, titleStartWidth, titleStartHeight,10);
    
    //Draw Instructions Button
    if (titleButtonCheck(titleInstructX,titleInstructY,titleInstructWidth,titleInstructHeight) == true) {
      fill(titleDarkGreen);
      stroke(titleGreen);
      instructHover = true;
    } else {
      fill(titleGreen);
      stroke(titleDarkGreen);
      instructHover = false;
    }
    rect(titleInstructX, titleInstructY, titleInstructWidth, titleInstructHeight,10);
    
    //Draw Settings Button
    if (titleButtonCheck(titleSettingsX,titleSettingsY,titleSettingsWidth,titleSettingsHeight) == true) {
      fill(titleDarkBlue);
      stroke(titleBlue);
      settingsHover = true;
    } else {
      fill(titleBlue);
      stroke(titleDarkBlue);
      settingsHover = false;
    }
    rect(titleSettingsX, titleSettingsY, titleSettingsWidth, titleSettingsHeight,10);
    
    //Change to game if a title button is clicked
    if ((titleClick==true) && (startHover == true)) {
      gameState = 1;
      titleClick = false;
    } 
    if ((titleClick==true) && (instructHover == true)) {
      gameState = 2;
      titleClick = false;
    }
    if ((titleClick==true) && (settingsHover == true)) {
      gameState = 3;
      titleClick = false;
    }
    fill(255);
    text("Start", titleStartX, titleStartY + titleStartHeight/7);
    text("Instructions", titleInstructX, titleInstructY + titleInstructHeight/7);
    text("Settings", titleSettingsX, titleSettingsY + titleSettingsHeight/7);
    
    
    //Game Name
    textSize(40);
    textAlign(CENTER);
    text("The Pebble of Destiny",width/2,height/7);
  } 
  
  
  //Instructions Page******************************************
  else if (gameState == 2) {
    backButton();
    
    //Titles
    textAlign(CENTER);
    textSize(40);
    text("Intructions",width/2,height/12);
    text("Power Ups",width/2,6*height/12+height/40);
       
    //Instructional Text
    textAlign(BASELINE);
    textSize(18);
    text("Control the paddle by moving the mouse left and right.", width/50, 2*height/14);
    text("Break all of the bricks to win.", width/50, 4*height/14);
    text("Collect the various power ups for an advantage.", width/50, 3*height/14);
    text("If you miss the ball with the paddle you lose a life.", width/50, 5*height/14);
    text("Lose all three (3) lives and you lose.", width/50, 6*height/14);
    
    textSize(14);
    //Powerup Text******************************************************************************************
    text("[Placeholder]",width/7,59*height/96);
    text("Breaks adjacent bricks",width/7,59*height/96+height/9);
    text("Randomly teleports the ball",width/7,59*height/96+2*height/9);
    text("Increases life by one",width/7+width/2,59*height/96);
    text("Breaks multiple bricks",width/7+width/2,59*height/96+height/9);
    text("Extends platform",width/7+width/2,59*height/96+2*height/9);
    
    //Draw Powerup squares
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        //Determine colours of the squares
        if (i == 0 && j == 0) {
          fill(greenBrick);
        } else if (i == 0 && j == 1) {
          fill(purpleBrick);
        } else if (i == 0 && j == 2) {
          fill(blueBrick);
        } else if (i == 1 && j == 0) {
          fill(orangeBrick);
        } else if (i == 1 && j == 1) {
          fill(yellowBrick);
        } else if (i == 1 && j == 2) {
          fill(redBrick);
        }
        noStroke();
        rect(width/12+i*width/2,29*height/48+j*height/9,width/10,height/20,5);
      }
    }
  } 
  
  
  //Settings Page**********************************************
  else if (gameState == 3) {
    backButton();
    
    
    
  }
  
  
  //Main Game**************************
  else if (gameState == 1) {
    
    checkGameState();
      
    //Ball Location Changes
    if (gameStarted == true) {
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
    } else {
      ballX = platformX;
    }
    
    //Window Edge Direction Changes
    if (ballEdgeX <= 0) {
      ballDX = 1;
    } else if (ballEdgeX >= width) {
      ballDX = -1;
    } 
    if (ballEdgeY <= 0) {
      ballDY = 1;
    } else if ((ballY >= height+ballSpeedY*120) && endCard == false) {
      //Will reset the game 2 seconds after the ball has gone off screen
      resetGame();
      life -= 1;
    } else if ((ballEdgeY >= height) && (endCard == true)) {
      ballRebound();
    }
    
    //Displays remaining lives for 7 seconds unless the endcard is enabled
    if (endCard == false) {
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
    }
      
    //Locks platform within the view window
    if (abs(mouseX - platformX) > 0.1) {
      platformX = platformX + (mouseX - platformX) * platformSpeed;
    }
    platformX = constrain(platformX, platformWidth/2, width-platformWidth/2);
    
    //Draw platform unless the endcard is enabled
    if (endCard == false) {
      noStroke();
      rect(platformX, 9*height/10, platformWidth, platformHeight,5);
      stroke(backgroundColour);
    
      //Check for hitting platform
      if (ballEdgeY-ballSpeedY >= height/500+9*height/10 - platformHeight && ballEdgeY <= height/500+9*height/10 + platformHeight 
      && ballEdgeX >= platformX - platformWidth/2 && ballEdgeX <= platformX + platformWidth/2) {
        ballRebound();
        hitPlatform = false;//********************CHECK THIS IF NEEDED**************************
      }
    }
    
    //Forces average ball speed to increase
    if (endCard == false) {
      ballSpeedIncreaseRate();
    }
    
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
        if (ballEdgeY <= (j+1)*height/20+height/13 && ballEdgeY >= j*height/20+height/13 
        && ballEdgeX >= i*width/10 && ballEdgeX <= (i+1)*width/10 && bricks[j][i] >= 1) {
          //Check Powers Here**********************************************************************************
          
          //Yellow Brick Powerup
          if (bricks[j][i] == 6) {
            yellowTime = 30;
          }
          bricks[j][i] = 0;
          //Check which way it is approaching from
          if(yellowTime == 0) {
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
        }
        
        //Draw brick if it is in play
        if (bricks[j][i] >= 1) {
          createBrick(bricks[j][i],i,j);
        }
        
      }
      
    }
    
    //Drains the time the yellow powerup is active
    if (yellowTime > 0) {
      yellowTime -= 1;
    }
    
    //Checks 1 frame head to see if ball will hit a brick
    for (int i = 0; i < bricks[0].length; i++) {
      for (int j = 0; j < bricks.length; j++) {
        //Check if hitting side of a brick
        if(bricks[j][i] >= 1) {
          if (ballDX == -1) {
            if (nextFrameCheck("RIGHT",j,i) == true) {
              sideRight = 1;
            }
          } else if (ballDX == 1) {
              if (nextFrameCheck("LEFT",j,i) == true) {
                sideLeft = 1;
            }
          } 
          if (ballDY == -1) {
              if (nextFrameCheck("DOWN",j,i) == true) {
                sideDown = 1;
            }
          } else if (ballDY == 1) {
              if (nextFrameCheck("UP",j,i) == true) {
                sideUp = 1;
            }
          }
        }
      }
    }
      
    //Draw Ball
    noStroke();
    if (endCard == false) {
      fill(255);
    } else {
      fill(255,255,255,100);
    }
    ellipse(ballX,ballY,2*ballRadius,2*ballRadius);
    stroke(0);
  }
}

//Checks if the game has been won or lost
void checkGameState() {
  
  //Checks losing Conditions
  if (life < 0) {
    powerupsEnabled = false;
    endCard = true;
    if (life == -1) {
      resetGame();
      life -= 1;
    }
    fill(255);
    textAlign(CENTER);
    text("You Lose!",width/2,height/2);
    text("Click to return to the title screen",width/2,height/2+height/12);
    textAlign(BASELINE);
    gameStarted = true; // SOMETHING CAUSE BALL TO FOLLOW MOUSE ON END SCREEN
    
    if (gameClick == true) {
      gameState = 0;
      life = 3;
      powerupsEnabled = true;
      endCard = false;
      resetGame();
    }
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
    //winning Event*******************************************************
    
  }
}

//Resets the active game state
void resetGame() {
  
  if (powerupsEnabled == true) {
    assignPower();
  } else {
    assignBricks(endCard);
  }
  
  ballX = width/2;
  ballY = 9*height/10-2*ballRadius;
  ballDX = DxRand();
  ballDY = -1;
  speedIncrease = 0;
  speedGapClose = 0;
  if (endCard == false) {
    ballSpeedX = random(1/2,2);
    ballSpeedY = random(3/4,2);
  } else if (endCard == true) {
    ballSpeedX = random(2,3);
    ballSpeedY = random(2,3);
  }
  lifeTimer = 840;
  lifeFade = 0;
  gameStarted = false;
}

void assignBricks(boolean trans) {
  //Set all bricks to exist
  //X-axis bricks
  for (int i = 0; i < bricks[0].length; i++) {
    //Y-axis bricks
    for (int j = 0; j < bricks.length; j++) {
      
      if (trans == false) {
        bricks[j][i] = 1;
      } else {
        bricks[j][i] = 8;
      }
            
    }
  }
}

void assignPower() {
  assignBricks(false);
  
  //Generates random brick location, checks if it is normal, then assigns a power
  for (int p = 2; p < 8; p++) {
    int xLocal = randomBrick('x');
    int yLocal = randomBrick('y');
    while (bricks[yLocal][xLocal] != 1) {
      xLocal = randomBrick('x');
      yLocal = randomBrick('y');
    }
    bricks[yLocal][xLocal] = p;
  }
  
}

int randomBrick(char direction) {
  int count = 0;
  if(direction == 'x') {
    //Selects random X brick, bounded to the existing bricks
    count = int(random(0,10));
    while(count < 0 || count > 9) {
      count = int(random(0,10));
    }
  } else if(direction == 'y') {
    //Selects random y brick, bounded to the existing bricks
    count = int(random(0,6));
    while(count < 0 || count > 5) {
      count = int(random(0,6));
    }
  } else {
    //Error if x or y are not selected
    println("Error: randomBrick function used incorrectly");
  }
  return count;
}

//Used for creating the 6x10 grid of bricks, can only be used in a for loop
void createBrick(int colour, int xRel, int yRel) {
  if (colour == 1) {
    fill(baseBrick);
  } else if (colour == 2) {
    fill(greenBrick);
  } else if (colour == 3) {
    fill(purpleBrick);
  } else if (colour == 4) {
    fill(blueBrick);
  } else if (colour == 5) {
    fill(orangeBrick);
  } else if (colour == 6) {
    fill(yellowBrick);
  } else if (colour == 7) {
    fill(redBrick);
  } else if (colour == 8) {
    fill (255,255,255,100);
  } else {
    text("Error",xRel*width/10+width/20,yRel*height/20+height/10);
  }
  rect(xRel*width/10+width/20,yRel*height/20+height/10,width/10,height/20,7);
  
}

//Increases ball average ball speed at rate of 1 pixel per 42 seconds
void ballSpeedIncreaseRate() {
  if (speedIncrease <= 3) {
    speedIncrease += 0.0002;
  }
  if (speedGapClose <= 1) {
    speedGapClose += 0.0001;
  }
}

//Generates a random speed for the ball
float randomSpeed() {
  float speed = random(0.5 + speedGapClose + speedIncrease, 2 + speedIncrease);
  return speed;
}

//For rebounding the ball randomly from the bottom of the screen/platform
void ballRebound() {
  ballDY = -1;
  ballDX = DxRand();
  ballSpeedX = randomSpeed();
  ballSpeedY = randomSpeed();
}

//Randomises the direction of the ball in the x direction
int DxRand() {
  //Randomly selects -1 or 1
  for (int i=0; i<1; i++) {
    ballDxRand = (float)random(-1, 1);
    if (ballDxRand <0) {
      ballDxRand = -1;
    } else if 
      (ballDxRand > 0) {
      ballDxRand = 1;
    }
    //Re-randomises the choice if it is not -1 or 1
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

//This must be used inside a for loop
boolean nextFrameCheck(String direction, int j, int i) {
  boolean checker = false;
  //Checks if hitting left or right side of bricks
  if (direction == "LEFT" || direction == "RIGHT") {  
    if (ballEdgeY <= (j+1)*height/20+height/13 && ballEdgeY >= j*height/20+height/13) {
      if (direction == "RIGHT" && ballEdgeX-ballSpeedX >= i*width/10 && ballEdgeX-ballSpeedX <= (i+1)*width/10) {
        checker = true;
      } else if(direction == "LEFT" && ballEdgeX+ballSpeedX >= i*width/10 && ballEdgeX+ballSpeedX <= (i+1)*width/10) {
        checker = true;
      }
    }
    //Check is hitting the top or bottom of the brick
  } else if (direction == "UP" || direction == "DOWN") {
    if (ballEdgeX >= i*width/10 && ballEdgeX <= (i+1)*width/10) {
      if (direction == "DOWN" && ballEdgeY-ballSpeedY <= (j+1)*height/20+height/13 && ballEdgeY+ballSpeedY >= j*height/20+height/13) {
        checker = true;
      } else if (direction == "UP" && ballEdgeY-ballSpeedY <= (j+1)*height/20+height/13 && ballEdgeY+ballSpeedY >= j*height/20+height/13) {
        checker = true;
      }
    }
  } else {
    println("frameCheck used incorrectly");
  }
  return checker;
}

void backButton() {
  strokeWeight(2); 
  
  //Back button
  if (titleButtonCheck(titleBackX,titleBackY,titleBackWidth,titleBackHeight) == true) {
    fill(titleBackHover);
    stroke(titleBack);
    backHover = true;
  } else {
    fill(titleBack);
    stroke(titleBackHover);
    backHover = false;
  }
  rect(titleBackX, titleBackY, titleBackWidth, titleBackHeight,8);
  
  if ((titleClick==true) && (backHover == true)) {
    gameState = 0;
    titleClick = false;
  }
  
  //Back Text
  textSize(40);
  textAlign(CENTER);
  fill(255);
  text("Back",titleBackX, titleBackY+height/32);
}

//
boolean titleButtonCheck(float X,float Y,float W,float H) {
  boolean hover = false;
  if ((mouseX>X-W/2) && (mouseX<X+W/2) && (mouseY>Y-H/2) && (mouseY<(Y+H/2))) {
    hover = true;
  }
  return hover;
}

//checks if the mouse has been clicked on the title screens
void mousePressed() {
  if (gameState != 1) {
    titleClick = true;
  } else if (gameState == 1) {
    gameClick = true;
    gameStarted = true;
  }
}

//
void mouseReleased() {
  titleClick = false;
  gameClick = false;
}