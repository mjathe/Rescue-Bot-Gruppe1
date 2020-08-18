#pragma once
#include <iostream>
#include "..\..\Rescue-Bot\Rescue-Bot\AutoMode.h"
#include <conio.h>
using namespace std;
int main()
{
	AutoMode autMo;
	while (32 != _getch())
	{
		autMo.startAutoMode();

	}

};
