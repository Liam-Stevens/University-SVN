// Set up our xs and ys arrays
float[] xs = new float[10];
float[] ys = new float[10];

// Using a for loop go through each element in the array and give
// it a random value between 0 and 500
for (int i = 0; i < xs.length; i++) {
  xs[i] = random(500);
  ys[i] = random(500);

  // Print each set of coordinates to the console for testing purposes
  println(i + ": (" + nf(xs[i],1,1) + ", " + nf(ys[i],1,1) + ")");
}

// Your code goes below here...
size(500,500);
background(255); 

fill(0,255,0);
ellipse(xs[0],ys[0],100,100);

fill(255,0,0);
point(xs[9],ys[9]);
String coodp = nf(xs[9],0,1) + ", " + nf(ys[9],0,1);
text(coodp,xs[9]+5,ys[9]+2.5);

println("Before: (" + nf(xs[3],0,1) + ", " + nf(ys[3],0,1) + ")");
xs[3] = xs[3]-20;
ys[3] = ys[3]-20;
println("After: (" + nf(xs[3],0,1) + ", " + nf(ys[3],0,1) + ")");

fill(255,0,255);
triangle(xs[0],ys[0],xs[2],ys[2],xs[4],ys[4]);

stroke(255,155,0);
strokeWeight(5);
line(xs[1],ys[1],xs[5],ys[5]);

point(xs[6],ys[6]);
stroke(0);
strokeWeight(1);
fill(255,0,0);
float hy = ys[6]*1.5;
float wx = xs[6]/2;
rectMode(CENTER);
rect(xs[6],ys[6],wx,hy);

xs[0] = xs[0]-40;
ys[0] = ys[0]+50;

fill(0,100,0);
ellipse(xs[0],ys[0],100,100);

println(" ");
println("Swaped Values: ");
println("Before 8: (" + nf(xs[7],0,1) + ", " + nf(ys[7],0,1) + ")");
println("Before 10: (" + nf(xs[9],0,1) + ", " + nf(ys[9],0,1) + ")");
float xtemp = xs[7];
float ytemp = ys[7];
xs[7] = xs[9];
ys[7] = ys[9];
xs[9] = xtemp;
ys[9] = ytemp;
println("After 8: (" + nf(xs[7],0,1) + ", " + nf(ys[7],0,1) + ")");
println("After 10: (" + nf(xs[9],0,1) + ", " + nf(ys[9],0,1) + ")");