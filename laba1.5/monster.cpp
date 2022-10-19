#define _CRT_SECURE_NO_WARNINGS
#include "monster.h"
#include "string.h" 
#include <stdlib.h>
#include "stdio.h"


#include <string>
#include <iostream>
#include <sstream>

using namespace std;
string monster::get_name()
{
	return name;
}

string monster::get_description()
{
	return description;
}




void monster::set_name(string* val)
{
	name = *val;
}

void monster::set_description(string* val)
{
	description = *val;
}


monster::monster()
{
	name = getRandomName();

	description = getRandomDescription();

	setType(MONSTER);
}

monster::~monster() {};



void monster::print()
{
	printf("NONSTER\n");
	std::cout << "\tname\t" << get_name() << std::endl;
	std::cout << "\tdescription\t" << get_description() << std::endl;
}

int monster::edit()
{
	int input = 0;
	while (true)
	{
		printf("100\tback\n1\tedit existing value\n");
		mscanf("%d", &input);
		switch (input)
		{
		case 100:
			return 0;

		case 1:
			edit_exist();
			break;

		default:
			printf("invalid input\n");
			break;
		}


	}
}

void monster::edit_exist()
{
	int input = -1;
	print();

	printf("what would you like to edit?\n");
	printf("NAME 0\nDESCRIPTION 1\n");


	while (input < 0 || input > 1)
	{
		printf("enter your choice\n");
		mscanf("%d", &input);
	}


	string* new_value = new string;
	printf("enter new value\n");
	getline(cin, *new_value);
	if (input == 0)
		set_name(new_value);
	if (input == 1)
		set_description(new_value);


}

string monster::operator[](int i)
{
	if (i == 0)
		return get_name();
	if (i == 1)
		return get_description();

}