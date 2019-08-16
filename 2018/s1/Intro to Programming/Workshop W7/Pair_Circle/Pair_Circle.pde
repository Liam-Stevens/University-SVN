void setup() {
  size(500,500);
  fill(255,0,0);
  drawCircleGrid(0,0,50,2,6);
  fill(0,255,0);
  drawCircleGrid(350,0,50,3,3);
  fill(0,0,255);
  drawCircleGrid(width/2-25,height/3,50,3,1);
  fill(255,255,0);
  drawCircleGrid(0,200,50,6,4);
  fill(255,0,255);
  drawCircleGrid(350,300,50,4,3);
  }

void drawCircleGrid(float x, float y, float d, int r, int c){
  for (int i = 0; i < c; i++) {
    for (int t = 0; t < r; t++) {
      ellipse(x+i*d+d/2,y+t*d+d/2,d,d);
    }
  }
}