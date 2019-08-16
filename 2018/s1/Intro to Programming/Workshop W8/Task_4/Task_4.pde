int r;
int c;
int[][] redBlue;
float rh;
float cw;
int click = 1;
int blueSquares;
int redSquares;

void setup(){
 size(500,500);
 r = 4;
 c = 3;
 redBlue = new int[r][c];
 textAlign(CENTER);
 
 rh = height/int(r);
 cw = width/int(c);
 
 for(int i=0; i<r; i++){
  for(int j=0; j<c; j++){
   redBlue[i][j] = round(random(1));
  }
 }
}

void draw() {
  blueSquares = 0;
  redSquares = 0;
 for(int i=0; i<r; i++){
  for(int j=0; j<c; j++){
   if(redBlue[i][j]==0){
    fill(255,0,0);
    redSquares += 1;
   } else if(redBlue[i][j]==1) {
    fill(0,0,255);
    blueSquares += 1;
   }
   rect(j*cw,i*rh,cw,rh);
  }
 }
 fill(255);
 if (keyPressed) {
  if(keyCode==SHIFT) {
    text("There are " + redSquares + " red squares.", width/2,height/2);
  }
  if(keyCode==CONTROL) {
    text("There are " + blueSquares + " blue squares.", width/2,height/2-20);
  }
 }
}

void mousePressed() {
  for (int i = 0; i<r; i++){
    for (int j = 0; j<c; j++) {
      if (redBlue[i][j]==0){
        redBlue[i][j]=1;
      } else if (redBlue[i][j]==1) {
        redBlue[i][j]=0;
      }
    }
  }
}

void keyPressed() {
  if(keyCode==SHIFT) {
    text("There are " + redSquares + " red squares.", width/2,height/2);
  }
  if(keyCode==CONTROL) {
    text("There are " + blueSquares + " blue squares.", width/2,height/2-20);
  }
}