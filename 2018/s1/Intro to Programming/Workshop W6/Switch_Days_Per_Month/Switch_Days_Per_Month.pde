int monthNum = int(random(1,12));
int days = 0;
String month = "Month";

switch(monthNum) {
  case 1:
    month = "January";
    days = 31;
    break;
  case 2:
    month = "Febuary";
    days = 28;
    break;
  case 3:
    month = "March";
    days = 31;
    break;
  case 4:
    month = "April";
    days = 30;
    break;
  case 5:
    month = "May";
    days = 31;
    break;
  case 6:
    month = "June";
    days = 30;
    break;
  case 7:
    month = "July";
    days = 31;
    break;
  case 8:
    month = "August";
    days = 31;
    break;
  case 9:
    month = "September";
    days = 30;
    break;
  case 10:
    month = "October";
    days = 31;
    break;
  case 11:
    month = "November";
    days = 30;
    break;
  case 12:
    month = "December";
    days = 31;
    break;
}

println(month + " has " + days + " days.");