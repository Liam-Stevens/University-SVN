size(500,500);
background(0);

//Values
String value1 = "Toyota";
String value2 = "Prius";
String value3 = "Red";
int value4 = 2012;
int value5 = 4;
float value6 = 12293.50;
boolean value7 = true;

//fields
String field1 = "Make:";
String field2 = "Model:";
String field3 = "Colour:";
String field4 = "Year:";
String field5 = "4Door/2Door:";
String field6 = "Price ($):";
String field7 = "Used:";

fill(255);
textAlign(LEFT);

//output - fields
text(field1,10,20);
text(field2,10,40);
text(field3,10,60);
text(field4,10,80);
text(field5,10,100);
text(field6,10,120);
text(field7,10,140);

//output - values
int buffer = 100;
text(value1,buffer,20);
text(value2,buffer,40);
text(value3,buffer,60);
text(value4,buffer,80);
text(value5,buffer,100);
text(nf(value6,0,2),buffer,120);
text(str(value7),buffer,140);