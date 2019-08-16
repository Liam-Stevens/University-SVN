//Set-up
size(400,945);
background(255);
stroke(0);
fill(255);
textAlign(LEFT);

//Define Arrays
String[] teamNames = {"AFC Bournemouth", "Arsenal", "Brighton and Hove Albion", "Burnley", "Chelsea", "Crystal Palace", 
                      "Everton", "Huddersfield Town", "Leicester City", "Liverpool", "Manchester City", "Manchester United", 
                      "Newcastle United", "Southampton", "Stoke City", "Swansea City", "Tottenham Hotspur", "Watford", 
                      "West Bromwich Albion", "West Ham United"};
int[] teamStats = new int[20];

//Initialise Stats Array
for (int t = 0; t > 20; t++) {
  teamStats[t] = int(random(0,10));
}
//Insert Initialisation Here, Random Numbers with mean of 5

//Draw Scorecard
rect(0,0,width*2/3,height/21);
rect(width*2/3,0,width*2/3,height/21);
for (int i = 0; i < 20; i++) {
  if (teamStats[i] < 2) {
    fill(255,255,0);
  } else if (teamStats[i] < 4) {
    fill(0,255,255);
  } else if (teamStats[i] < 6) {
    fill(0,255,0);
  } else if (teamStats[i] < 8) {
    fill(150,0,255);
  } else if (teamStats[i] < 11) {
    fill(255,0,0);
  }
  
  rect(0,(i+1)*height/21,width*2/3,height/21);
  rect(width*2/3,(i+1)*height/21,width*2/3,height/21);
}