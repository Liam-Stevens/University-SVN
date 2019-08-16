size(500,500);
background(0);

int change = int(random(100,2000));
int totalch = change;
int dollar100 = change/100;
change = change%100;
String hundred = "$100 note(s) required: ";
println(hundred + dollar100);

int dollar50 = change/50;
change = change%50;
String fifty = "$50 note(s) required: ";
println(fifty + dollar50);

int dollar20 = change/20;
change = change%20;
String twenty = "$20 note(s) required: ";
println(twenty + dollar20);

int dollar10 = change/10;
change = change%10;
String ten = "$10 note(s) required: ";
println(ten + dollar10);

int dollar5 = change/5;
change = change%5;
String five = "$5 note(s) required: ";
println(five + dollar5);

int dollar2 = change/2;
change = change%2;
String two = "$2 coin(s) required: ";
println(two + dollar2);

int dollar1 = change;
String one = "$1 coin(s) required: ";
println(one + dollar1);

String total = "Total Change: $";
println(total + totalch);