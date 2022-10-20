#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "string.h"
#include <crtdbg.h>
#include <iostream>
#define HERO 0

#define VILLAN 1
#define MONSTER 2
#define MAXLEN 20

using namespace std;

int Rand(int, int);
int mscanf(const char* _f, void* _x);



class heroes
{
	int type;
	

public:
	heroes();

	~heroes();

	int get_type();
	

	void set_type(int _t);
	

	virtual void print() {};
	virtual void print_to_file(char*) {};
	virtual int edit() { return 0; };


};