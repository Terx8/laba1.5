#define _CRT_SECURE_NO_WARNINGS
#include "hero.h"
#include "string.h" 
#include <stdlib.h>
#include "stdio.h"


#include <string>
#include <iostream>
#include<fstream>

using namespace std;

hero::hero()
{
	cout << "hero()" << endl;
	name = getRandomName();
	weapon = getRandomWeapon();
	skills = nullptr;
	skill_num = 0;

	set_type(HERO);
}

hero::~hero() { cout << "~hero()" << endl; };


int hero::get_skill_num()
{
	return skill_num;
}

string hero::get_name()
{
	return name;
}

string* hero::get_name_ptr()
{
	return &name;
}

string hero::get_weapon()
{
	return weapon;
}

string* hero::get_skill(int _i)
{
	if (_i >= 0 && _i < skill_num)
		return skills[_i];
}


void hero::set_name(string* val)
{
	name = *val;
}

void hero::set_weapon(string* val)
{
	weapon = *val;
}


void hero::set_skill(int i, string* val)
{
	skills[i] = new string(*val);
}

void hero::add_skill()
{
	string val = { '\0' };
	printf("enter new skill name\n");
	getline(cin, val);

	skill_num += 1;

	string** new_skill_set = new string * [skill_num];
	for (int i = 0; i < skill_num - 1; i++) {
		new_skill_set[i] = new string(*skills[i]);
	}

	new_skill_set[skill_num - 1] = new string(val);

	skills = new_skill_set;
}

void hero::delete_skill()
{
	if (skill_num > 0)
	{
		printf("enter id of skill to edit (from 0 to %d)\n", skill_num - 1);
		int id = -1;
		while (id < 0 || id > skill_num - 1)
			mscanf("%d", &id);

		skill_num--;
		for (int i = id; i < skill_num; i++)
			skills[i] = skills[i + 1];
	}
	else
		printf("no skills added\n");

}



void hero::print()
{
	printf("HERO\n");
	std::cout << "\tname\t" << get_name() << std::endl;
	std::cout << "\tweapon\t" << get_weapon() << std::endl;
	printf("\tskills:\n");
	for (int i = 0; i < skill_num; i++)
	{
		std::cout << "\t" << *get_skill(i) << std::endl;
	}
	if (skill_num == 0)
		printf("\t___\n");

	printf("\n");
}



void hero::print_to_file(char* fn)
{
	ofstream fout(fn, ios_base::app);

	if (!fout.is_open())
	{
		cout << "could not open the file" << endl;
		return;
	}
	fout << get_type() << endl;
	fout << get_name() << endl;
	fout << get_weapon() << endl;

	fout << skill_num << endl;

	for (int i = 0; i < skill_num; i++)
		fout << *get_skill(i) << endl;

	fout.close();
}


int hero::edit()
{
	int input = 0;
	while (true)
	{
		printf("100\tback\n1\tedit existing value\n2\tadd new skill\n3\tdelete existing skill\n");
		mscanf("%d", &input);
		switch (input)
		{
		case 100:
			return 0;

		case 1:
			edit_exist();
			break;

		case 2:
			add_skill();
			break;

		case 3:
			delete_skill();
			break;
		default:
			printf("invalid input\n");
			break;
		}
	}
}

void hero::edit_exist()
{
	int input = -1;
	print();

	printf("what would you like to edit?\n");
	int max = skill_num + 2;
	if (skill_num > 0) printf("NAME 0\nWEAPON 1\nSKILLS 2-%d\n", max - 1);
	else
		printf("NAME 0\nWEAPON 1\nADD SKILLS 2\n");

	while (input < 0 || input > max)
	{
		printf("enter your choice\n");
		mscanf("%d", &input);
	}

	if (skill_num == 0 && input == 2)
		add_skill();
	else
	{
		string* new_value = new string;
		printf("enter new value\n");
		getline(cin, *new_value);

		if (input == 0)
			set_name(new_value);
		if (input == 1)
			set_weapon(new_value);
		if (input >= 2)
			set_skill(input - 2, new_value);

	}
}

string* hero::get_f(int i)
{

	return nullptr;
}

string hero::operator[](int i)
{
	if (i >= 0 && i < skill_num)
		return *skills[i];
	else
		return nullptr;
}