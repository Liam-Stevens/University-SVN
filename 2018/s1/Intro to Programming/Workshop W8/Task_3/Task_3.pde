String message = "";

void setup() {
 size(400,400);
}

void draw() {
 background(0);
 text("press the 'a' key",100,50);
 text(message,100,100);
}

void keyPressed(){
  if(key=='a'){
   message = "\'a\' was pressed";
 }else{
   message = "some other key was pressed";
 }
}

void keyReleased() {
  message = "";
}