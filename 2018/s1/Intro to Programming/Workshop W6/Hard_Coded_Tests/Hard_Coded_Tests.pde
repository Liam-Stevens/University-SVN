//Define Array and token
int[] nums = new int[10];
int lowestNums = 100;
int lowestTest1 = 100;
int lowestTest2 = 100;
int lowestTest3 = 100;
int lowestTest4 = 100;
int lowestTest5 = 100;

//Hard Coded Arrays
int[] test1 = {22,91,57,80,11,46,30,74,88,100}; //11
int[] test2 = {30,84,90,10,7,29,55,99,84,27};   //7
int[] test3 = {100,99,98,97,96,95,94,93,92,91}; //91
int[] test4 = {1,2,3,4,5,6,7,8,9,10};           //1
int[] test5 = {23,23,23,23,23,23,23,23,23,23};  //23

//Initialise Array
for (int i = 0; i < 10; i++) {
  nums[i] = int(random(1,100));
}

//Find lowest number
for (int t = 0; t < 10; t++) {
  if (nums[t] < lowestNums) {
    lowestNums = nums[t];
  }
  if (test1[t] < lowestTest1) {
    lowestTest1 = test1[t];
  }
  if (test2[t] < lowestTest2) {
    lowestTest2 = test2[t];
  }
  if (test3[t] < lowestTest3) {
    lowestTest3 = test3[t];
  }
  if (test4[t] < lowestTest4) {
    lowestTest4 = test4[t];
  }
  if (test5[t] < lowestTest5) {
    lowestTest5 = test5[t];
  }
}

//Display lowest number in arrays
println("Lowest Number In Nums Array: " + lowestNums);
println("Lowest Number In Test 1 Array: " + lowestTest1);
println("Lowest Number In Test 2 Array: " + lowestTest2);
println("Lowest Number In Test 3 Array: " + lowestTest3);
println("Lowest Number In Test 4 Array: " + lowestTest4);
println("Lowest Number In Test 5 Array: " + lowestTest5);