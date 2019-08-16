void setup() {
  println(inRange("yes", 1, 4));
  println(countVowels("Jypsy"));
  println(cipher("please"));
}

void draw() {
  
} 

boolean inRange(String str, int lower, int higher) {
  
  if (str.length() >= lower && str.length() <= higher) {
    return true;
  } else {
    return false;
  }
  
}

int countVowels(String str) {
  str = str.toLowerCase();
  char[] arrayStr = new char[str.length()];
  arrayStr = str.toCharArray();
  int vowels = 0;
  
  for (int j = 0; j < str.length(); j++) {
    if(arrayStr[j] == 97 && arrayStr[j] == 101 && arrayStr[j] == 105 && arrayStr[j] == 111 && arrayStr[j] == 117) {
      vowels++;
    }
  }
  
  return vowels;
}

String cipher(String str) {
  str = str.toLowerCase();
  char[] arrayStr = new char[str.length()];
  arrayStr = str.toCharArray();
  
  //Needs to be changed to work within the range of a-z
  for (int j = 0; j < str.length(); j++) {
    arrayStr[j] = char(int(arrayStr[j]) + 5);
  }
  
  String result = new String(arrayStr);
  
  return result;
}