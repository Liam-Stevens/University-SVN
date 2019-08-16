void setup() {
  size(500,500);
  background(0);
  
  drawStar(250,250,50,100,true);
  
}

void drawStar(int x, int y, int s, int o, boolean sh) {
  stroke(255,255,0);
  line(x+s/2,y,x-s/2,y);
  line(x,y+s/2,x,y-s/2);
  line(x+s/4,y-s/4,x-s/4,y+s/4);
  line(x-s/4,y-s/4,x+s/4,y+s/4);
  
  if (sh == true) {
    stroke(255,150,0);
    line(x+3*s/4,y-s/4,x+3*s,y-s/4);
  }
}