#include "stdio.h"
#include "Keeper.h"

#define EXIT 100
#define CLEAN 10
#define COMMANDS -1
#define PRINT 1
#define ADD 2
#define EDIT 3
#define DELETE 4
#define SAVE 5
#define LOAD 6

void print_menu_settings()
{
	printf("EXIT\t%d\n", EXIT);
	printf("CLEAN\t%d\n", CLEAN);
	printf("COMMANDS\t%d\n", COMMANDS);
	printf("PRINT\t%d\n", PRINT);
	printf("ADD\t%d\n", ADD);
	printf("EDIT\t%d\n", EDIT);
	printf("DELETE\t%d\n", DELETE);
	printf("SAVE\t%d\n", SAVE);
	printf("LOAD\t%d\n", LOAD);
}


int menu()
{
	keeper Keep;
	print_menu_settings();
	int input = 0;
	while (true)
	{

		printf("enter command\n");
		mscanf("%d", &input);

		switch (input)
		{
		default:
			printf("invalis input, try again\n");
			break;
		case CLEAN:
			system("cls");
			break;

		case COMMANDS:
			print_menu_settings();
			break;
		case EXIT:
			return 0;

		case PRINT:
			Keep.print_menu();
			break;

		case ADD:
			Keep.add();
			break;

		case EDIT:
			Keep.edit();
			break;

		case DELETE:
			Keep.del();
			break;

		case SAVE:
			Keep.print_all_to_file();
			break;

		case LOAD:
			printf("ATENTION: ALL NOT SAVED DATA WILL BE LOST. WANT TO PROCEED?\n 1 YES; 0 NO\n"); 
			{
				int in = -1;
				while (in < 0 || in > 1) mscanf("%d", &in);
				if (in == 1)
					Keep.load();
			}
			break;

		}
	}



}

int main()
{
	menu();
	return 0;
}