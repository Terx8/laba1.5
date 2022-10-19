#define _CRT_SECURE_NO_WARNINGS

#include "keeper.h"


keeper::keeper()
{
	arr = nullptr;
	size = 0;
}

keeper::~keeper()
{

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
				if (arr[i]->getType() == HERO)
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
				if (arr[i]->getType() == VILLAN)
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
				if (arr[i]->getType() == MONSTER)
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

void  keeper::print_all()
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
	delete arr; // ?
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
