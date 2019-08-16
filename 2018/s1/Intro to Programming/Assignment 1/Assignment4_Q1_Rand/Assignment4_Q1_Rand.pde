//Setup
size(500,200);
background(255);
stroke(0);
fill(0);
textAlign(CENTER);

//Controling variables
int numProd = 20;
int daysBefore = 5;

//Initialisation of variables
int sum = 0;
int finalSum = 0;
int days = 0;
float average = 0;
int[] products = new int[numProd];

//Define products
for (int i = 0; i < numProd; i++) {
  products[i] = int(random(-100,200));
  if (products[i] < 0) {
    products[i] = 0;
  }
}

//Define end
products[numProd-daysBefore] = -789;

//Summing products
for (int t = 0; t < numProd; t++) {
  if (products[t] == -789) {
    finalSum = sum;
    days = t;
  }
  sum = sum + products[t];
}

//Average results
average = float(finalSum/days);

//Results
String resultAverage = "In " + days + 
" days, the average products sold is " + nf(average,0,0) + " units.";
text(resultAverage, 250, 100);