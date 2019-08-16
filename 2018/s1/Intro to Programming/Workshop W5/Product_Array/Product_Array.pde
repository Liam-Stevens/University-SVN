size(500,500);
background(0);

int product = 1;

int[] nums = new int[10];
for  (int i=0; i<10; i++) {
  nums[i]=i+1;
  product = product*nums[i];
}

println(product);