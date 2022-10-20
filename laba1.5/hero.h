#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "class_heroes.h"
#include <stdlib.h>
#include "time.h"


#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class hero: public heroes
{
private:

	string name;
	string weapon;

	string** skills;
	int skill_num;

	string getRandomName()
	{
		srand(time(0));
		int rand_val = Rand(0, 3);
		switch (rand_val)
		{
		case 0:
			return (string)"BOBBY";
		case 1:
			return (string)"ALEX";
		case 2:
			return (string)"MILLY";
		case 3:
			return (string)"ALICE";
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


public:
	int get_skill_num();

	string get_name();
	string* get_name_ptr();

	string get_weapon();
	string* get_weapon_ptr() { return &weapon; };

	string* get_skill(int _i);


	void set_name(string* val);

	void set_weapon(string* val);

	void set_skill(int i, string* val);

	void add_skill();

	void delete_skill();

	void print() override;
	int edit() override;
	void edit_exist();

	void print_to_file(char* fn) override;

	hero();
	~hero();

	string  operator[](int i);
	
	string* get_f(int i);
	
};


