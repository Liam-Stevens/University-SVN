size(500,500);
background(255);
stroke(0);
fill(255);

for (int i = 0; i < 15; i++) {
  
  for (int t = 0; t < 15; t++) {
    
    if (i == 0 || i == 14 || t == 0 || t == 14) {
      fill(100,0,255,200);
    } else if ((i == 7 && t != 0 && t != 14 && i != t) 
    || (t == 7 && i!=0 && i != 14 && i != t)) {
      fill (0,100,200,100);      
    } else if (i == t || i == 14-t) {
      fill (250,100,200,200);
    } else {
      fill(255);
    }    
        
    rect(width*i/15,height*t/15,width/15,height/15);
    
  }
}