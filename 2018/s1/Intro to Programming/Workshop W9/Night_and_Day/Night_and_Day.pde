int cloudMove = 0;
int cloudXPos = -100;
int cloudYPos = 200;
int grow = -200;
int time = 0;

void setup() {
  size(500,500);
  noStroke();
}

void draw() {
  if(time==0){
    background(50,170,250);
    fill(250,250,50);
    ellipse(8*width/10,height/10,width/10,height/10);
    fill(100,70,50);
  } else if(time==1){
    background(15,40,80);
    fill(200);
    ellipse(2*width/10,height/10,width/10,height/10);
    fill(40,25,5);
  }
  triangle(width/3,4*height/5-grow,2*width/3,4*height/5-grow,width/2,height/3-grow);
  if(grow<0) {
    grow++;
  }
  if(time==0) {
    fill(40,230,40);
  } else if(time==1) {
    fill(40,100,40);
  }
  rect(0,2*height/3,width,height/2);
  if(time==0) {
    fill(255);
  } else if(time==1) {
    fill(150);
  }
  if(cloudMove==1) {
    ellipse(cloudXPos,cloudYPos,width/5,height/10);
    if(cloudXPos<6*height/5) {
      cloudXPos+=3;
    } else if(cloudXPos>=6*height/5) {
      cloudMove=0;
      cloudXPos=-100;
    }
  }
}

void mousePressed() {
  if(time==0) {
    time=1;
  } else if(time==1) {
    time=0;
  } 
}

void keyPressed() {
  if(key=='c' && cloudMove==0) {
    cloudMove=1;
    cloudYPos = int(random(0,300));
  }
}