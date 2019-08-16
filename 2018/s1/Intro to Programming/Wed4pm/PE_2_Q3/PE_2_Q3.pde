//Variable initialisation
float circleX;
float circleY;
float circleDia;
float circleRad;
float circleEdge;
float circleColorChange = 0;
color circleColor = color(0);
boolean fPressed = false;
boolean click = false;

void setup() {
  size(500,500);
  circleDia = 1;
  circleRad = circleDia/2;
  circleX = width-circleRad;
  circleY = height/2;
}

void draw() {
  background(255);
  //Calculates the growing radius of the circle and the location of the right edge
  circleRad = circleDia/2;
  circleEdge = circleX + circleRad;
  
  //Switch between black and yellow stroke
  if (click == false) {
    stroke(0);
    strokeWeight(1);
  } else if (click == true) {
    stroke(255,255,0);
    strokeWeight(5);
  }
  
  //While f is held, no fill colour
  if (fPressed == false) {
    fill(circleColor);
  } else {
    noFill();
  }
  
  //Draw ellipse
  ellipse(circleX,circleY,circleDia,circleDia);
  
  //Check if the edge of the circle is off screen
  if (circleEdge < 0) {
    restart();
  } else {
    
    //Move the circle, enlarges radius and changes colour
    circleX--;
    circleDia++;
    circleColorChange++;
    circleColor = color(0,circleColorChange*255/width,0);
    
  }
}

//Resets all values to default
void restart() {
  circleDia = 1;
  circleRad = circleDia/2;
  circleX = width-circleRad;
  circleY = height/2;
  circleColorChange = 0;
  circleColor = color(0);
}

//Click switch
void mousePressed() {
  if (click == false) {
    click = true;
  } else if (click == true) {
    click = false;
  }
}

//Check if f is held
void keyPressed() {
  if (key == 'f') {
    fPressed = true;
  }
}

//Check if f is held
void keyReleased() {
  if (fPressed == true) {
    fPressed = false;
  }
}