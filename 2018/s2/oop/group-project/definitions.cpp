#include "item.h"
#include "weapon.h"
#include "stall.h"
#include "player.h"
#include <string>

using namespace std;

void setDefinitions()
{
	string home = "home";
	player player(500);
	stall bakery("Bakery", "bakery", 500);
	stall forge("Forge", "forge", 500);
}