//Initialisation of test arrays
int[] testArray1 = {-3,-2,-1,0,1,2,3};
int[] testArray2 = {0,0,0,0,0,0,0};
int[] testArray3 = {5,5,5,5,5,5,5};
int[] testArray4 = null;

void setup() {
  noLoop();
}

void draw() {
  //Prints the array name and what is different
  println("testArray1: " + countDiffs(testArray1, 1) + " entries are different to 1");
  println("testArray2: " + countDiffs(testArray2, 0) + " entries are different to 0");
  println("testArray3: " + countDiffs(testArray3, 0) + " entries are different to 0");
  println("testArray4: " + countDiffs(testArray4, 1) + " entries are different to 1");
  
}

//counts the amount of entries different from val in nums
int countDiffs(int[] nums, int val) {
  int numDiffs = 0;
  
  //Check if the array is valid
  if (nums != null) {
    for (int i = 0; i < nums.length; i++) {
      //Check if number is different to val
      if (nums[i] != val) {
        numDiffs++;
      }
    }
  } else {
    println("The following array is not valid");
  }
  
  return numDiffs;
}