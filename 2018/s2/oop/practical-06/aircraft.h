#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "person.h"
#include <string>

class aircraft
{
  static int count2;
  int id2;
  person inCraft[2];
  std::string sign;

 public:
	// a pilot and copilot must be provided when creating an aircraft
	aircraft();
	aircraft(std::string callsign,person thePilot,person theCoPilot);
	void setPilot(person thePilot);      // change the pilot
	person getPilot();
	void setCoPilot(person theCoPilot);  // change the co-pilot
	person getCoPilot();
	void printDetails();                 // print the callsign, a new line, the pilot name,
	                                     // a new line, the co-pilot name and a final newline.

  ~aircraft();
};

#endif