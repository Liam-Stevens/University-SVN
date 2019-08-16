//Canvas Setup
void setup() {
  size(500,500);
  background(255);
  fill(0);
  noLoop();
}

//Draw of the line functions
void draw() {
  lines(15,200,10,300);
  lines(-1,80,0,50);
  lines(5,300,400,150);
}

//Line functions
void lines(int num, int x, int y, int len) {
  
  //Check if num is negative
  if(num < 0) {
    println("Error: nums less than 0");
  } else {
    //iterates over num number of lines
    for (int i = 0; i < num; i++) {
      line(x+10*i,y,x+10*i,y+len);
    }
    
  }
  
}