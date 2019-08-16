//Global Variables
boolean canvasClear = false;
color lineColour = 0;
boolean mouseDraw = false;

//Initial Setup
void setup() {
  size(600,600);
  background(255);  
}

void draw() {
  
  //Clears the canvas
  if (canvasClear == true) {
    background(255);
    canvasClear = false;
  }
  
  //Changes the line colour
  stroke(lineColour,0,0);
  
  //draws line between mouse position on previous frame and current frame
  if (mouseDraw == true) {
    line(pmouseX,pmouseY,mouseX,mouseY);
  }
}

void mousePressed() {
  //Start drawing
  mouseDraw = true;
}

void mouseReleased() {
  //End drawing
  mouseDraw = false;
}

void keyPressed() {
  //Change line colour
  if (key == 'r') {
    lineColour = 255;
  } else if (key == 'b') {
    lineColour = 0;
  }
  //Clear the canvas
  if (key == 'd') {
    canvasClear = true;
  }
  
  
}