//Setup
size(500, 500);
background(255);
noStroke();
textAlign(CENTER);
int grade = int(random(-10, 110));

//Checking whether the grade exists
if (grade < 0) {
  println("Error: Grade is less than 0.");
} else if (grade > 100) {
  println("Error: Grade is greater than 100.");
} else {
  
  //Finding which category the grade falls into
  if (grade < 50) {
    fill(0);
    text(grade + " - Fail", 3*width/4, height/2);
    fill(255,0,0);
  } else if (grade < 65) {
    fill(0);
    text(grade + " - Pass", 3*width/4, height/2);
    fill(255,0,255);
  } else if (grade < 75) {
    fill(0);
    text(grade + " - Credit", 3*width/4, height/2);
    fill(0,0,255);
  } else if (grade < 85) {
    fill(0);
    text(grade + " - Distinction", 3*width/4, height/2);
    fill(255,255,0);
  } else {
    fill(0);
    text(grade + " - High Distinction", 3*width/4, height/2);
    fill(0,255,0);
  }
  
  //Draw ellipse
  ellipse(250, 250, 100, 100);
}