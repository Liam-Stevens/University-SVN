//Setup
size(500,500);
background(0);
stroke(0);
fill(255,255,0);
int distance;

//Creating 4 random numbers
int[] randNum = new int[4];
for (int i = 0; i < randNum.length; i++) {
  randNum[i] = int(random(100,250));
}

//Drawing the two ellipses
ellipse(width/2,randNum[1]/2,randNum[0],randNum[1]);
ellipse(width/2,height-randNum[3]/2,randNum[2],randNum[3]);

//Calculating distance between the two ellipses
distance = height-randNum[3]-randNum[1];
fill(0);
textSize(15);
textAlign(CENTER);
text("D:" + distance,width/2,height-randNum[3]/2);