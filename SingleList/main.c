#define _CRT_SECURE_NO_WARNINGS 1
#include "include.h"

void Loding()
{
	char option1 = 0;
	ListMenu();
	Sleep(1);
	printf("Start Loading...\n");
	proc();
	printf("Loading Have Done!\n");
	printf(" - If you are using the program for the first time, you should type (y / Y) to get the basics\n");
	printf(" - If not, type (n / N) to enter the program directly\n");
	printf("Please Enter Your Option:> ");
	int key = scanf("%c", &option1);
	char ch = getchar();
	if (option1 == 'y' || option1 == 'Y')
	{
		printf("Now, press any key to enter the manual\n\n");
		system("pause");
		system("cls");
		ListManual();
		printf("\t1.该程序的确认是ENTER键，也就是回车键，没有撤销！！！因此请谨慎输入！\n");
	}
}

int main()
{
	int option = 0;
	Loding();
	do
	{
		int key = scanf("%d", &option);
		switch (option)
		{
		case PUSHBACK:
			break;
		case PUSHFRONT:
			break;
		case POPBACK:
			break;
		case POPFRONT:
			break;
		case FIND:
			break;
		case PRINT:
			break;
		case INSERT:
			break;
		case ERASE:
			break;
		case EXIT:
			break;
		default:
			printf("Your Option Is Wrong! Please Enter Again!\n");
			break;
		}	
	} while (option);
	return 0;
}