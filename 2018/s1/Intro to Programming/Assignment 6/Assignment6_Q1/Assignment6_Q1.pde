//Global variable initialisation
float coinX;
float coinY;
float wellX;
float wellY;
float wellDiam;
float coinDiam;
float coinRad;
float wellRad;
int coinXMove = 0;
int coinYMove = 0;
int coinSpeed = 1;
int coinXSpeed = 1;
int coinYSpeed = 1;


//Setup variables
void setup() {
  size(500,500);
  background(0);
  fill(255);
  noStroke();
  frameRate(120);
  
  wellDiam = height/5;
  coinDiam = 3*wellDiam/4;
  coinRad = coinDiam/2;
  wellRad = wellDiam/2;
  
  coinX = width-coinRad;
  coinY = height-coinRad;
  wellX = random(wellRad,width-wellRad); //CHECK FOR COIN
  wellY = random(wellRad,height-wellRad);
  
  //Check if overlapping coin
  while (wellX + wellRad > coinX - coinRad && wellY + wellRad > coinY - coinRad) {
    wellX = random(wellRad, width-wellRad);
    wellY = random(wellRad, height-wellRad);
  }
  
}

void draw() {
   
  //Draw colour based on coin in well
  if(isWishMade() == false) {
    
    background(0);
    fill(255);
    
  } else if(isWishMade() == true) {
    
    background(255,0,0);
    fill(0,255,0);
    
  }
  
  //Draw coin and well
  ellipse(wellX,wellY,wellDiam,wellDiam);
  fill(255,255,0);
  ellipse(coinX,coinY,coinDiam,coinDiam);
  
  if (coinYMove == -1 && coinY - coinRad - coinSpeed >= 0) {
      coinY -= coinSpeed;
    } 
    if (coinYMove == 1 && coinY + coinRad + coinSpeed <= height) {
      coinY += coinSpeed;
    } 
    if (coinXMove == -1 && coinX - coinRad - coinSpeed >= 0) {
      coinX -= coinSpeed;
    } 
    if (coinXMove == 1 && coinX + coinRad + coinSpeed <= width) {
      coinX += coinSpeed;
    }
  
}

//Check for key presses
void keyPressed() { //MAKE THIS A VELOCITY TO START MOVEMENT AND END IT ON RELEASE - FIXES LATERAL MOVEMENT
  
  if(keyCode == UP) {
    coinYMove = -1;
  }
  if(keyCode == DOWN) {
    coinYMove = 1;
  }
  if(keyCode == LEFT) {
    coinXMove = -1;
  }
  if(keyCode == RIGHT) {
    coinXMove = 1;
  }  
  
}

void keyReleased() { //Check if works for opposite keys releases
  
  if(keyCode == UP) {
    coinYMove = 0;
  }
  if(keyCode == DOWN) {
    coinYMove = 0;
  }
  if(keyCode == LEFT) {
    coinXMove = 0;
  }
  if(keyCode == RIGHT) {
    coinXMove = 0;
  } 
  
}

//Check for coin in well
boolean isWishMade() {
  boolean wishMade;
  //Check if the coin is in the well
  if (dist(wellX,wellY,coinX,coinY) <= wellRad - coinRad ) {
    wishMade = true;
  } else {
    wishMade = false;
  }
  
  return wishMade;
}