//Setup
size(500,200);
background(255);
stroke(0);
fill(0);
textAlign(CENTER);

//Initialisation of variables
int sum = 0;
int finalSum = 0;
int days = 0;
float average = 0;
int[] products = {82,7,42,103,241,97,-71,11,93,-21,80,149,0,-789};

//Summing products
for (int t = 0; t < products.length; t++) {
  if (products[t] == -789) {
    finalSum = sum;
    days = t + 1;
  }
  sum = sum + products[t];
}
//can't assume it has -789, check to see if works without

//Average results
average = float(finalSum/days);

//Results
String resultAverage = "In " + days + 
" days, the average products sold is " + nf(average,0,0) + " units.";
text(resultAverage, 250, 100);