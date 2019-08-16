size(500,500);
background(255);

strokeWeight(4);
float[][] coords = new float[100][2];

for (int i=0; i<100; i++) {
  
  for(int t=0; t<2; t++) {
    
   coords[i][t]=random(0,250)+random(0,250);
   
  }

  point(coords[i][0],coords[i][1]);
  
}