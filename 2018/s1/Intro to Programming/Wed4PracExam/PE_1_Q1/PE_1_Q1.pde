//Setup
size(500,500);
background(0);

//Black triangle with white stroke
fill(0);
stroke(255);
strokeWeight(3);
triangle(5*width/12,7*height/12,7*width/12,7*height/12,width/2,5*height/12);

//Central dividing line and second thirding line
line(0,height/2,width,height/2);
line(2*width/3,height/5,2*width/3,4*height/5);

//Blue Square with white stroke
rectMode(CENTER);
fill(0,0,255);
rect(5*width/6,height/2,width/5,height/5);

//First thirding line
strokeWeight(10);
stroke(0,255,0);
line(width/3,height/5,width/3,4*height/5);

//Red Circle with no stroke
fill(255,0,0);
noStroke();
ellipse(width/6,height/2,width/6,width/6);