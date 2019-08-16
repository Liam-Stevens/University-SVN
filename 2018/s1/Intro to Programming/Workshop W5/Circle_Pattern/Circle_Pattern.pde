size(1000,1000);
background(0);

int[] radius = new int[10];
String rtext = "0";
textAlign(CENTER);

for (int i=9; i>=0; i--) {
  radius[i]=i*50;
  stroke(0);
  fill(0+i*50,i*50-250,i*50-500);
  ellipse(width/2,height/2,radius[i]*2,radius[i]*2);
  if (i>5) {
    stroke(0);
    fill(0);
  } else {
    stroke(255);
    fill(255);
  }
  line(width/2,height/2,width/2+radius[i],height/2);
  rtext = "r= " + str(radius[i]);
  text(rtext,width/2+radius[i]-25,height/2-5);
}