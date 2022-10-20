#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "class_heroes.h"
#include <stdlib.h>
#include "time.h"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class monster : public heroes
{
private:

	string name;
	string description;


	string getRandomName()
	{
		srand(time(0));
		int rand_val = Rand(0, 3);
		switch (rand_val)
		{
		case 0:
			return (string)"DRAGON";
		case 1:
			return (string)"SPIDER";
		case 2:
			return (string)"GRIPHON";
		case 3:
			return (string)"UNICORN";
		}
	}

	string getRandomDescription()
	{
		srand(time(0));
		int rand_val = Rand(0, 3);
		switch (rand_val)
		{
		case 0:
			return (string)"giant";
		case 1:
			return (string)"ugly";
		case 2:
			return (string)"tiny";
		case 3:
			return (string)"hideous";
		}
	}


public:


	string get_name();

	string get_description();


	void set_name(string* val);

	void set_description(string* val);



	void print() override;
	int edit() override;
	void edit_exist();
	void print_to_file(char*) override;


	monster();
	~monster();

	string operator[](int i);


};


