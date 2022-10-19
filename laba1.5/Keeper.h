#pragma once
#define _CRT_SECURE_NO_WARNINGS


#include "hero.h"
#include "villan.h"
#include "monster.h"

class keeper
{
private:
	heroes** arr;
	int size;

public:

	keeper();
	~keeper();
	int print_menu();
	void print_all();

	void add();

	void del();

	void edit();

};