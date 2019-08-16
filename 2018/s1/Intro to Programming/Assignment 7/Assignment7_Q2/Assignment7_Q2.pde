int squares = 75;
//Global Variables
int[] squaresX = new int[squares];
int[] squaresY = new int[squares];
int[] squaresSides = new int[squares];
boolean reset = false;
boolean lineUp = true;
int lineY = 0;

//Initial Values
void setup() {
  size(500,500);
  background(255,0,0);
  frameRate(30);
  fill(0,0,0,100);
      
  //Generates values for the squares
  for (int i = 0; i < squaresX.length; i++) {
    squaresSides[i] = int(random(0,40));
    squaresX[i] = int(random(0,width-squaresSides[i]));
    squaresY[i] = int(random(0,height-squaresSides[i]));
  }
  lineY = height;
}

void draw() {
  background(255,0,0);
  noStroke();
  
  //Resets the space when the animation ends
  if (reset == true) {
    for (int i = 0; i < squaresX.length; i++) {
      squaresSides[i] = int(random(0,40));
      squaresX[i] = int(random(0,width-squaresSides[i]));
      squaresY[i] = int(random(0,height-squaresSides[i]));
    }
    reset = false;
  }
  
  //Draws the squares on screen
  for (int i = 0; i < squaresX.length; i++) {
    
    //Makes the squares follow the line
    if (squaresY[i] + squaresSides[i] >= lineY && lineUp == true) {
      squaresY[i] = lineY - squaresSides[i];
    } else if (squaresY[i] <= lineY && lineUp == false) {
      squaresY[i] = lineY;
    }
    
    //Draws squares
    rect(squaresX[i],squaresY[i],squaresSides[i],squaresSides[i]);
  }
  
  //Draws the white line
  stroke(255);
  line(0,lineY,width,lineY);
  
  //Moves the line
  if (lineUp == true) {
    lineY--;
  } else if (lineUp == false) {
    lineY++;
  }
  
  //Checks if the line is at the top or bottom
  if (lineY < 0) {
    lineUp = false;
    reset = true;
  } else if (lineY > height) {
    lineUp = true;
    reset = true;
  }
  
}