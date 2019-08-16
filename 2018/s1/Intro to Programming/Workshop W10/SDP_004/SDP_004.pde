int[] nums = new int[20];
color fade = 0;
int fadeMove = 1;
int remove = 0;
int keyR = 0;
int reset = 1;

void setup() {
  size(600,600);
  background(255);
  frameRate(120);
  for (int i = 0; i < nums.length; i++) {
    nums[i] = int(random(5,600));
  }

}

void draw() {
  background(255);
  
  fill(fade,0,0);
  for (int i = 0; i < nums.length; i++) {
    rect(i*width/20,height-nums[i] + remove,width/20,nums[i]);
  }
  
  if (fade == 0) {
    fadeMove = 1;
  } else if (fade == 255) {
    fadeMove = -1;
  }
  if (fadeMove == 1) {
    fade += 1;
  } else if (fadeMove == -1) {
    fade -= 1;
  }
  if (keyR == 1) {
      remove++;
  }
  if (remove == nums[19]) {
    keyR = 0;
    reset = 0;
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
  if (reset == 1) {
    insertionSort(nums);
  } else if (reset == 0) {
    for (int i = 0; i < nums.length; i++) {
    nums[i] = int(random(5,600));
    }
    remove = 0;
    reset = 1;
  }  
}

void keyPressed() {
  if (key == 'r') {
    keyR = 1;
  }
}