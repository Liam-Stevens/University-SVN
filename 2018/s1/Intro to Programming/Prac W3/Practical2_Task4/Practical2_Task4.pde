size(500,500);
background(255);

float diameter = random(width-250,width-50);
float radius = diameter/2;
float perimeter = 2*PI*radius;
float area = PI*radius*radius;
String r = "R: " + nf(radius,0,1);
String a = "A: " + nf(area,0,1);
String p = "P: " + nf(perimeter,0,1);

stroke(0);
fill(255,0,0);
ellipse(width/2,height/2,diameter,diameter);
fill(0);
ellipse(width/2,height/2,radius/40,radius/40);
line(width/2,height/2,width/2+radius,height/2);
textAlign(CENTER);
text(r,width/2+radius/2,height/2-height/50);
text(a,width/2,height/2+radius/2);
text(p,width/2,height/2+radius+radius/10);