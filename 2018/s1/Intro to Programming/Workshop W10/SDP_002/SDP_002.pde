int[] nums = new int[20];

void setup() {
  size(600,600);
  background(255);
  
  for (int i = 0; i < nums.length; i++) {
    nums[i] = int(random(5,600));
  }

}

void draw() {
  background(255);
  
  for (int i = 0; i < nums.length; i++) {
    rect(i*width/20,height-nums[i],width/20,nums[i]);
  }
  
}

void insertionSort(int[] a) {
  for (int i = 1; i < a.length; i++) {
    int j = i;

    while (j > 0 && a[j-1] > a[j]) {
      int tmp = a[j];
      a[j] = a[j-1];
      a[j-1] = tmp;
      j--;
    }
  }
}

void mousePressed() {
  insertionSort(nums);
}