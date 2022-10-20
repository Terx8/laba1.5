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
	char* fileName;
public:

	keeper();
	~keeper();
	int print_menu();
	void print_all();
	void print_all_to_file();

	char* getFileName();
	void  setFileName(char* v);
	void add();

	void del();

	void edit();

	void load();

};