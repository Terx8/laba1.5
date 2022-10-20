#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "class_heroes.h"
#include <stdlib.h>
#include "time.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class villan : public heroes
{
private:

	string name;
	string weapon;
	string evil_deed;
	string residence;
	string** skills;
	int skill_num;

	string getRandomName()
	{
		srand(time(0));
		int rand_val = Rand(0, 3);
		switch (rand_val)
		{
		case 0:
			return (string)"RAY";
		case 1:
			return (string)"GREG";
		case 2:
			return (string)"LILLY";
		case 3:
			return (string)"FERB";
		}
	}

	string getRandomWeapon()
	{
		srand(time(0));
		int rand_val = Rand(0, 3);
		switch (rand_val)
		{
		case 0:
			return (string)"dagger";
		case 1:
			return (string)"sword";
		case 2:
			return (string)"bow";
		case 3:
			return (string)"gun";
		}
	}

	string getRandomEvilDeed()
	{
		srand(time(0));
		int rand_val = Rand(0, 3);
		switch (rand_val)
		{
		case 0:
			return (string)"treason";
		case 1:
			return (string)"murder";
		case 2:
			return (string)"theft";
		case 3:
			return (string)"kidnapping";
		}
	}

	string getRandomResidence()
	{
		srand(time(0));
		int rand_val = Rand(0, 3);
		switch (rand_val)
		{
		case 0:
			return (string)"down town";
		case 1:
			return (string)"country side";
		case 2:
			return (string)"expensive mantion";
		case 3:
			return (string)"small hut";
		}
	}

public:
	int get_skill_num();

	string get_name();

	string get_weapon();
	string get_evil_deed();
	string get_residence();
	string* get_skill(int _i);


	void set_name(string* val);
	void set_weapon(string* val);
	void set_evil_deed(string* val);
	void set_residence(string* val);
	void set_skill(int i, string* val);


	void add_skill();

	void delete_skill();

	void print() override;
	void print_to_file(char*) override;
	int edit() override;
	void edit_exist();


	villan();
	villan(ifstream* f);
	~villan();

	string operator[](int i);


};


