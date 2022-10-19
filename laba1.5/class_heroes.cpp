#define _CRT_SECURE_NO_WARNINGS
#include "class_heroes.h"
#include <stdlib.h>
#include "time.h"

#include <string>
#include <iostream>
#include <sstream>

int Rand(int min, int max)
{
	return min + rand() % (max - min);
}

int mscanf(const char*  _f, void* _x)
{
	while (1)
	{
		printf("\t: ");
		if (scanf(_f, _x) != 1)
			printf("invalid input, try again\n");
		else
		{
			if (getchar());
			return 1;
		}
		if (getchar());
	}
}

heroes::heroes() 
{ 
	type = 0; 
};

heroes::~heroes() 
{

};

int heroes::getType()
{
	return type;
}

void heroes::setType(int _t)
{
	type = _t;
}

