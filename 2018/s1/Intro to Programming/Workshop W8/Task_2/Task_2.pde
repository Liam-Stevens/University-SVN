float startingHeight;
float currentHeight;
float radius;
int change = 0;

void setup() {
 size(400,400);
 startingHeight = height;
 currentHeight = startingHeight;
 radius = 10;
}

void draw() {
 background(0);
 ellipse(width/2.0, currentHeight, radius, radius);
 ellipse(2*width/3.0, currentHeight, radius, radius);
 ellipse(width/3.0, currentHeight, radius, radius);
 if (change == 0) {
   currentHeight = currentHeight - radius/10.0; 
 } else if (change == 1) {
   currentHeight = currentHeight + radius/10.0;
 }
 if (currentHeight < 0) {
   currentHeight = startingHeight;
 } else if (currentHeight > height) {
   currentHeight = 0;
 }
}
void mousePressed(){
 change = 1;
}
void mouseReleased(){
 change = 0;
}