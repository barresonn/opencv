#pragma once
# include <iostream>
#include "image.h"

class input :public image
{
private:
	int instance ;
public:

	input();
	void action();
};
