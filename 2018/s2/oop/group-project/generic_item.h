#ifndef GENERICITEM_H
#define GENERICITEM_H

#include "item.h"
#include <string>

class generic_item : public item
{
 public:
	generic_item();
	generic_item(std::string createName, int createItemID, double createPrice);

	virtual void setPrice(double newPrice);


	~generic_item();

};

#endif