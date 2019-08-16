//Set-up data
size(500,500);
background(0);

//Generate coordinate values for triangle
float x1 = random(100,200);
float y1 = random(100,200);
float x2 = random(300,400);
float y2 = random(100,200);
float x3 = random(200,300);
float y3 = random(300,400);

//create triangle
fill(0,0,255);
triangle(x1,y1,x2,y2,x3,y3);

//create offset coordinates for labels against lines
fill(255,0,0);
textAlign(CENTER);
float lx1 = ((x1+x2)/2)+5;
float ly1 = ((y1+y2)/2)-10;
float lx2 = ((x2+x3)/2)+5;
float ly2 = ((y2+y3)/2)+15;
float lx3 = ((x3+x1)/2)-15;
float ly3 = ((y3+y1)/2)+15;
text("a",lx1,ly1);
text("b",lx2,ly2);
text("c",lx3,ly3);

//display coordinates for points
fill(255);
String point1 = "(" + nf(x1,0,1) + ", " + nf(y1,0,1) + ")";
String point2 = "(" + nf(x2,0,1) + ", " + nf(y2,0,1) + ")";
String point3 = "(" + nf(x3,0,1) + ", " + nf(y3,0,1) + ")";
text(point1,x1-20,y1-10);
text(point2,x2+50,y2-10);
text(point3,x3+10,y3+20);

//calculate and display sides and area
textAlign(RIGHT);
fill(255,255,0);
float side1 = pow(pow((x2-x1),2)+pow((y2-y1),2),0.5);
float side2 = pow(pow((x3-x2),2)+pow((y3-y2),2),0.5);
float side3 = pow(pow((x3-x1),2)+pow((y3-y1),2),0.5);
float area1 = (side1*side2)/2;
String sidea = "Side a: " + nf(side1,0,1);
String sideb = "Side b: " + nf(side2,0,1);
String sidec = "Side c: " + nf(side3,0,1);
String areat = "Area: " + nf(area1,0,1);
text(sidea,490,430);
text(sideb,490,450);
text(sidec,490,470);
text(areat,490,490);