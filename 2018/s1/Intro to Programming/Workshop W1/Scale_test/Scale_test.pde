void setup() {
size(1000,1000);
background(#0B7C06);
noStroke();
}

int value=0;

void draw() {
scale(value);
fill(#623E30);
rect(width*0.375,height*0.0,width*0.250,height*1.000);
fill(#292929);
rect(width*0.400,height*0.0,width*0.200,height*1.000);
fill(255);
rect(width*0.495,height*0.050,width*0.010,height*0.100);
rect(width*0.495,height*0.200,width*0.010,height*0.100);
rect(width*0.495,height*0.350,width*0.010,height*0.100);
rect(width*0.495,height*0.500,width*0.010,height*0.100);
rect(width*0.495,height*0.650,width*0.010,height*0.100);
rect(width*0.495,height*0.800,width*0.010,height*0.100);
rect(width*0.495,height*0.950,width*0.010,height*0.100);
fill(#BABBBC);
ellipse(width*0.300,height*0.898,width*0.010,height*0.010);
ellipse(width*0.360,height*0.898,width*0.010,height*0.010);
fill(#0E81CB);
rect(width*0.280,height*0.900,width*0.100,height*0.0075);
fill(#00DE2A);
ellipse(width*0.300,height*0.100,width*0.100,height*0.100);
ellipse(width*0.330,height*0.150,width*0.100,height*0.100);
ellipse(width*0.290,height*0.180,width*0.100,height*0.100);
ellipse(width*0.250,height*0.140,width*0.100,height*0.100);
}

void mousePressed() {
  if (mouseButton == LEFT) {
    (value == 0);
  } else if (mouseButton == RIGHT) {
    scale(0.5);
  } else {
    scale(0.1);
  }
}