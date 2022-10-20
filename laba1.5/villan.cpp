#define _CRT_SECURE_NO_WARNINGS
#include "villan.h"
#include "string.h" 
#include <stdlib.h>
#include "stdio.h"
#include <string>
#include <iostream>
#include<fstream>

using namespace std;


villan::villan()
{
	cout << "villan()" << endl;
	name = getRandomName();
	weapon = getRandomWeapon();
	evil_deed = getRandomEvilDeed();
	residence = getRandomResidence();

	skills = nullptr;
	skill_num = 0;

	set_type(VILLAN);
}

villan::~villan() { cout << "~villan()" << endl; };

int villan::get_skill_num()
{
	return skill_num;
}

string villan::get_name()
{
	return name;
}

string villan::get_weapon()
{
	return weapon;
}

string villan::get_evil_deed()
{
	return evil_deed;
}

string villan::get_residence()
{
	return residence;
}

string* villan::get_skill(int _i)
{
	if (_i >= 0 && _i < skill_num)
		return skills[_i];
}


void villan::set_name(string* val)
{
	name = *val;
}

void villan::set_weapon(string* val)
{
	weapon = *val;
}

void villan::set_evil_deed(string* val)
{
	evil_deed = *val;
}

void villan::set_residence(string* val)
{
	residence = *val;
}

void villan::set_skill(int i, string* val)
{
	skills[i] = val;
}

void villan::add_skill()
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

void villan::delete_skill()
{
	if (skill_num > 0)
	{
		printf("enter id of skill to edit (from 0 to %d)\n", skill_num - 1);
		int id = -1;
		while (id < 0 || id >= skill_num - 1)
			mscanf("%d", &id);


		skill_num--;
		for (int i = id; i < skill_num; i++)
			skills[i] = skills[i + 1];
	}
	else
		printf("no skills added\n");

}


void villan::print()
{
	printf("VILLAN\n");
	std::cout << "\tname\t" << get_name() << std::endl;
	std::cout << "\tweapon\t" << get_weapon() << std::endl;
	std::cout << "\tevil deed\t" << get_evil_deed() << std::endl;
	std::cout << "\tresidence\t" << get_residence() << std::endl;
	printf("\tskills:\n");
	for (int i = 0; i < skill_num; i++)
	{
		std::cout << "\t" << *get_skill(i) << std::endl;
	}
	if (skill_num == 0)
		printf("\t___\n");

	printf("\n");
}

void villan::print_to_file(char* fileName)
{
	ofstream fout(fileName, ios_base::app);

	if (!fout.is_open())
	{
		cout << "could not open the file" << endl;
		return;
	}
	fout << get_type() << endl;
	fout << get_name() << endl;
	fout << get_weapon() << endl;
	fout << get_evil_deed() << endl;
	fout << get_residence() << endl;
	fout << skill_num << endl;
	
	for (int i = 0; i < skill_num; i++)
		fout << *get_skill(i) << endl;
	
	fout.close();
}



villan::villan(ifstream* f)
{
	string s;
	getline(*f, s); if (s.empty()) throw (char*)"something is wrong with data"; set_name(&s);
	getline(*f, s); if (s.empty()) throw (char*)"something is wrong with data"; set_name(&s);
	getline(*f, s); if (s.empty()) throw (char*)"something is wrong with data"; set_weapon(&s);
	getline(*f, s); if (s.empty()) throw (char*)"something is wrong with data"; set_evil_deed(&s);
	getline(*f, s); if (s.empty()) throw (char*)"something is wrong with data"; set_residence(&s);
	*f >> skill_num;
	
	skills = new string*[skill_num];
	if (skills == nullptr) throw (char*)"memory error in load";
	for (int i = 0; i < skill_num; i++)
	{
		skills[i] = new string;
		//*f >> *skills[i];
		getline(*f, s); if (s.empty()) throw (char*)"something is wrong with data"; *skills[i] = s;
	}

	set_type(VILLAN);
}

int villan::edit()
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

void villan::edit_exist()
{
	int input = -1;
	print();

	printf("what would you like to edit?\n");
	int max = skill_num + 3;
	if (skill_num > 0) printf("NAME 0\nWEAPON 1\nEVIL DEED 2\nRESIDENCE 3\nSKILLS 4-%d\n", max);
	else
		printf("NAME 0\nWEAPON 1\nEVIL DEED 2\nRESIDENCE 3\nSKILLS 4\n");

	while (input < 0 || input > max)
	{
		printf("enter your choice\n");
		mscanf("%d", &input);
	}

	if (skill_num == 0 && input == 4)
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
		if (input == 2)
			set_evil_deed(new_value);
		if (input == 3)
			set_residence(new_value);
		if (input >= 4)
			set_skill(input - 4, new_value);
		}
}

string villan::operator[](int i)
{
	if (i >= 0 && i < skill_num)
		return *skills[i];
	else
		return nullptr;
}

