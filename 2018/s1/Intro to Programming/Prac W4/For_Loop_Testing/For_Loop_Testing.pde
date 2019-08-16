size(500,500);
background(0);

stroke(0);
for (int i = 5; i < 500; i = i+50) {
  strokeWeight(i/20);
  stroke(i/2,0,0);
  line(i,0,i,height);
}