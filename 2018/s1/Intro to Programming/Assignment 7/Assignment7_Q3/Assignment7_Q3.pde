int[][] array1 = {
  {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}
};
int[][] arrayTest1 = {
  {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}
};
int[][] arrayTest2 = {
  {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}
};
int[][] arrayTest3 = {
  {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}
};
int[][] arrayTest4 = {
  {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}
};
boolean rotated = false;
//Fill in the test arrays with test numbers

void setup() {
  noLoop();
}

void draw() {
  
  //Checks if the array can be used
  if (checkArray(array1) == true) {
    arrayPrint(array1);
    rotateArray(array1);
    arrayPrint(array1);
  }
}

void rotateArray(int[][] rotateArray) {

  //Rotate the array

  rotated = true;
}

void arrayPrint(int[][] print) {
  
  //Checks what type of array is being printed
  if (rotated == true) {
    println("Before Rotation:");
  } else if (rotated == false) {
    println("After Rotation:");
  }
  //prints each array
  for (int i = 0; i < print.length; i++) {
    println("[", print[i][0], print[i][2], print[i][3], print[i][4], "]");
  }
  println("");
  
  
}

boolean checkArray(int[][] check) {

  //NEED TO MAKE IT CHECK IF IT IS EMPTY
  //Checks if the array is not 4x5 in size
  if (check[0].length == 5 && check.length == 4) {
    return true;
  } else {
    //prints error message
    println("Error: Matrix is not 4x5");
    return false;
  }
}