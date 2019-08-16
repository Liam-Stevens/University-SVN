void setup(){
 size(400,400);
 background(255);
 noLoop();
}

void draw(){
 displayHue(-4,700,true,300,-21,5,300); 
}

void displayHue(float x, float y, boolean o, int hv, int s, int c, float d){
  //Check for syntax
  int syntaxError = 0;
  if (x < 0 || x > width) {
    println("X must be within the canvas: 0 <= x <= " + width);
    syntaxError = 1;
  } else if (d + x > width && o == true) {
    d = width - x;
    println("Width of gradient wider than canvas - auto correcting");
  } if (y < 0 || y > height) {
    println("Y must be within the canvas: 0 <= y <= " + height);
    syntaxError = 1;
  } else if (d + y > height && o == false) {
    d = height - y;
    println("Height of gradient lower than canvas - auto correcting");
  } if (o != true && o != false) {
    println("o must be either 'true' (Draw Vertically) or 'false' (Draw Horizontally)");
    syntaxError = 1;
  } if (hv < 0 || hv > 255) {
    println("hv must be within 0 and 255: 0 <= hv <= 255");
    syntaxError = 1;
  } if (s < 0 || s > 255) {
    println("s must be within 0 and 255: 0<= s <= 255");
    syntaxError = 1;
  } if (c != 0 && c != 1 && c != 2 && c != 3) {
    println("c must be either 0 (greyscale), 1 (yellow), 2 (cyan), or 3 (purple)");
    syntaxError = 1;
  }
  
  //Start Display
  if (syntaxError == 1) {
    println("Syntax Error");
    println("Correct Syntax: displayHue(x, y, o, hv, s, c, d)");
  } else {
    if (o == true) {
      //Draw Vertically - expand on this to include other variables
      for(int i = 0; i <= hv; i++){
        stroke(i);
        line(10,i,60,i);
      }
    } else if (o == false) {
      //Draw Horizontally - later copy code to here and change x and y modifiers
      
    }
  }
}