void setup() {
  int[] arrayA = {1,2,3,4,5};
  int[] arrayB = {1,3,2,4,9};
  int counter = numDifference(arrayA,arrayB);
  int[] rev1 = reverseArray(arrayA);
  String reverse = "";
  for (int h = 0; h < rev1.length; h++) {
    reverse =  reverse + str(rev1[h]) + ",";
  }
  println("Difference: " + counter);
  println("Reverse: {" + reverse + "}");
}

int numDifference(int[] diff1,int[] diff2) {
  int counter =0;
  for (int i = 0; i < diff1.length; i++) {
    if(diff1[i] != diff2[i]){
      counter++;
    }
  }
  return counter;
}

int[] reverseArray(int[] rev1) {
  int[] temp = new int[rev1.length];
  for (int t = 0; t < rev1.length; t++) {
    temp[t] = rev1[t];
  }
  for (int l = 0; l < rev1.length; l++) {
    rev1[l] = temp[rev1.length-l-1];
  }
  return rev1;
}