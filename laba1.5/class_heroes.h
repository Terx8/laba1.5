#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "string.h"
#include <crtdbg.h>



#define HERO 0
#define VILLAN 1
#define MONSTER 2
#define MAXLEN 20

int Rand(int, int);
int mscanf(const char* _f, void* _x);



class heroes
{
	int type;
public:
	heroes();

	~heroes();

	int getType();

	void setType(int _t);

	virtual void print() {};
	virtual int edit() { return 0; };


};