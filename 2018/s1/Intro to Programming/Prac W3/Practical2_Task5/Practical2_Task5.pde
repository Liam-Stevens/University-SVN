size(500,500);
background(0);

float rwidth = random(150,300);
float rheight = random(150,300);
float perimeter = 2*rwidth+2*rheight;
float area = rwidth*rheight;
float xcen = width/2-rwidth/2;
float ycen = height/2-rheight/2;

String a = "a: " + nf(rwidth,0,1);
String b = "b: " + nf(rheight,0,1);
String p = "P: " + nf(perimeter,0,1);
String A2 = "A: " + nf(area,0,1);
fill(255,255,0);
rect(xcen,ycen,rwidth,rheight);

fill(255);
textAlign(CENTER);
text(a,xcen+rwidth/2,ycen-height/50);
text(b,xcen-rwidth/6,ycen+rheight/2);
text(p,xcen+rwidth/2,ycen+rheight+rheight/10);
fill(0);
text(A2,xcen+rwidth/2,ycen+rheight/2);