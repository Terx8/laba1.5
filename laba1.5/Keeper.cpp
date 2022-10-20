#define _CRT_SECURE_NO_WARNINGS

#include "keeper.h"
#include<fstream>

keeper::keeper()
{
	arr = nullptr;
	size = 0;
	setFileName((char*)"allheroes.txt");
}

keeper::~keeper()
{

}


char* keeper::getFileName()
{
	return fileName;
}

void keeper::setFileName(char* v)
{
	fileName = v;
}

int  keeper::print_menu()
{
	int t = -1;

	int count = 0;
	while (t == -1)
	{
		printf("100 EXIT\n0 PRINT ALL\n1 PRINT ONLY HEROES\n2 PRINT ONLY VILLANS\n3 PRINT ONLY MONSTERS\n");

		mscanf("%d", &t);

		switch (t)
		{
		case 100:
			return 0;

		case 0:
			print_all();
			break;

		case 1:
			count = 0;
			for (int i = 0; i < size; i++)
			{
				if (arr[i]->get_type() == HERO)
				{
					arr[i]->print();
					count++;
				}
			}
			if (count == 0)
				printf("EMPTY\n");
			break;

		case 2:
			count = 0;
			for (int i = 0; i < size; i++)
			{
				if (arr[i]->get_type() == VILLAN)
				{
					arr[i]->print();
					count++;
				}
			}
			if (count == 0)
				printf("EMPTY\n");
			break;

		case 3:
			count = 0;
			for (int i = 0; i < size; i++)
			{
				if (arr[i]->get_type() == MONSTER)
				{
					arr[i]->print();
					count++;
				}
			}
			if (count == 0)
				printf("EMPTY\n");
			break;

		default:
			printf("invalid type, try again\n");
			t = -1;
		}
	}

}

void keeper::print_all()
{
	printf("ALL:\n");
	if (size == 0)
		printf("\tEMPTY\n");
	else
		for (int i = 0; i < size; i++)
		{
			arr[i]->print();
		}
}

void keeper::print_all_to_file()
{
	ofstream fout(getFileName(), ios_base::trunc);

	if (!fout.is_open())
	{
		cout << "could not open the file" << endl;
		return;
	}
	fout.close();
	fout.open(getFileName(), ios_base::app);

	if (!fout.is_open())
	{
		cout << "could not open the file" << endl;
		return;
	}
	fout << size << endl;
	fout.close();
	
	for (int i = 0; i < size; i++)
		arr[i]->print_to_file(getFileName());
	
}

void keeper::load()
{
	char buff[50];
	ifstream fin(getFileName());

	if (!fin.is_open())
	{
		cout << "could not open the file" << endl;
		return;
	}
	int s = 0;
	fin >> s;
	if (s <= 0)
	{
		fin.close();
		cout << "something is wrong with data" << endl;
		return;
	}


	int tip = 0;

	delete[] arr;
	heroes** new_arr = new heroes * [s];
	if (new_arr == nullptr)
		throw (char*)"memory error in load";

	for (int i = 0; i < s; i++)
	{

		fin >> tip;
		switch (tip)
		{
		case VILLAN:
			try {
				new_arr[i] = new villan(&fin);
			}
			catch (char* l)
			{
				fin.close();
				throw l;
			}
			break;

		case HERO:
			try {
			new_arr[i] = new hero(&fin);
			}
			catch (char* l)
			{
				fin.close();
				throw l;
			}
			break;

		case MONSTER:
			try {
			new_arr[i] = new monster(&fin);
			}
			catch (char* l)
			{
				fin.close();
				throw l;
			}
			break;

		default:
			fin.close();
			cout << "something is wrong with data" << endl;
			return;
		}

	}

	arr = new_arr;
	size = s;

	fin.close(); 
}



void  keeper::add()
{
	int t = -1;
	heroes* hero_add = nullptr;

	while (t == -1)
	{
		printf("enter type you would like to create\n");
		printf("HERO %d\n", HERO);
		printf("VILLAN %d\n", VILLAN);
		printf("MONSTER %d\n", MONSTER);
		mscanf("%d", &t);


		switch (t)
		{
		case HERO:
			hero_add = new hero;
			break;
		case VILLAN:
			hero_add = new villan;
			break;
		case MONSTER:
			hero_add = new monster;
			break;
		default:
			printf("invalid type, try again\n");
			t = -1;
		}
	}



	heroes** new_arr = new heroes * [size + 1];

	for (int i = 0; i < size; i++)
	{
		new_arr[i] = new heroes;
		new_arr[i] = arr[i];
	}

	new_arr[size] = hero_add;
	arr = new_arr;

	size++;
}

void  keeper::del()
{
	printf("delete called\n");
	if (size > 0)
	{
		printf("enter id of element to delete (from 0 to %d)\n", size - 1);
		int id = -1;
		while (id < 0 || id >= size)
			mscanf("%d", &id);
		delete arr[id];

		size--;
		for (int i = id; i < size; i++)
			arr[i] = arr[i + 1];
	}
	else
		printf("no heroes added!\n");
}

void  keeper::edit()
{
	printf("edit called\n");
	if (size > 0)
	{
		printf("enter id of element to edit (from 0 to %d)\n", size - 1);
		int id = -1;
		while (id < 0 || id >= size)
			mscanf("%d", &id);

		arr[id]->edit();
	}
	else
		printf("no heroes added!\n");

}
