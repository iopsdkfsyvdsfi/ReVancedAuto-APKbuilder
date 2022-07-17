#include <iostream>
#include <limits>
#include "errorInputHandling.h"

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}