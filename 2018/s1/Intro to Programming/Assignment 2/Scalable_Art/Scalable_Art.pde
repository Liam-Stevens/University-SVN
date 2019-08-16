//Initial Set-up
size(500,500);
background(0);

//Yellow Lines
stroke(255,255,0);
line(0,0,width,height);
line(0,height,width,0);
line(0,0.25*height,0.25*width,0);
line(0.75*width,0,width,0.25*height);
line(0,0.75*height,0.25*width,height);
line(0.75*width,height,width,0.75*height);

//Blue Diamond
noStroke();
fill(0,0,255);
quad(0.5*width,0,width,0.5*height,0.5*width,height,0,0.5*height);

//White Circles
fill(255);
ellipse(0.25*width,0.5*height,0.25*width,0.25*height);
ellipse(0.75*width,0.5*height,0.25*width,0.25*height);

//Red Triangles
fill(255,0,0);
triangle(0.25*width,0.25*height,0.75*width,0.25*height,0.5*width,0.5*height);
triangle(0.25*width,0.75*height,0.75*width,0.75*height,0.5*width,0.5*height);