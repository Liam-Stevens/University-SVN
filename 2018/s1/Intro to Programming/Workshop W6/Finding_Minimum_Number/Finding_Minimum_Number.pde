//Define Array and token
int[] nums = new int[10];
int lowest = 100;

//Initialise Array
for (int i = 0; i < 10; i++) {
  nums[i] = int(random(1,100));
}

//Find lowest number
for (int t = 0; t < 10; t++) {
  if (nums[t] < lowest) {
    lowest = nums[t];
  }
}

//Display lowest number
println("Lowest Number In Array: " + lowest);