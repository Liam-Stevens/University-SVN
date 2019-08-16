//Setup
size(400,400);
background(0);
stroke(0,255,0,100);
strokeWeight(5);
textAlign(CENTER,CENTER);
int[] points = new int[50];
int pattern = 6;
int sum = 0;

//Array initialisation
for (int i = 0; i < points.length; i++) {
  points[i] = pattern;
  pattern = pattern + 6;
}

//Calculating numbers divisible by 4
for (int t = 0; t < points.length; t++) {
  if (points[t] % 4 == 0) {
    sum = sum + points[t];
  }
}

//Drawing 'sum' number of circles
for (int n = 0; n < sum; n++) {
  point(int(random(0,400)),int(random(0,400)));
}

//Displaying the number 'sum'
noStroke();
fill(255);
ellipse(width/2,height/2,50,50);
fill(0);
text(sum,width/2,height/2);