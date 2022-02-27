#define _CRT_SECURE_NO_WARNINGS 1
#include "include.h"
#include "src.h"

static const char* TITLE = "\
\t   _____ _             _        _      _     _   _ \n\
\t  / ____(_)           | |      | |    (_)   | | | |\n\
\t | (___  _ _ __   __ _| | ___  | |     _ ___| |_| |\n\
\t  \\___ \\| | '_ \\ / _` | |/ _ \\ | |    | / __| __| |\n\
\t  ____) | | | | | (_| | |  __/ | |____| \\__ \\ |_|_|\n\
\t |_____/|_|_| |_|\\__, |_|\\___| |______|_|___/\\__(_)\n\
\t                  __/ |                            \n\
\t                 |___/                             \n\
";

static const char* MANUAL = "\
\t\t  __  __                         _ \n\
\t\t |  \\/  |                       | |\n\
\t\t | \\  / | __ _ _ __  _   _  __ _| |\n\
\t\t | |\\/| |/ _` | '_ \\| | | |/ _` | |\n\
\t\t | |  | | (_| | | | | |_| | (_| | |\n\
\t\t |_|  |_|\\__,_|_| |_|\\__,_|\\__,_|_|\n\
";

static const char* MENU = "\
\t          _____                    _____                    _____                    _____          \n\
\t         /\     \\                  /\     \\                  /\     \\                  /\     \\\n\
\t        /::\\____\\                /::\\    \\                /::\\____\\                /::\\____\\        \n\
\t       /::::|   |               /::::\\    \\              /::::|   |               /:::/    /        \n\
\t      /:::::|   |              /::::::\\    \\            /:::::|   |              /:::/    /         \n\
\t     /::::::|   |             /:::/\\:::\\    \\          /::::::|   |             /:::/    /          \n\
\t    /:::/|::|   |            /:::/__\\:::\\    \\        /:::/|::|   |            /:::/    /           \n\
\t   /:::/ |::|   |           /::::\\   \\:::\\    \\      /:::/ |::|   |           /:::/    /            \n\
\t  /:::/  |::|___|______    /::::::\\   \\:::\\    \\    /:::/  |::|   | _____    /:::/    /      _____  \n\
\t /:::/   |::::::::\\    \\  /:::/\\:::\\   \\:::\\    \\  /:::/   |::|   |/\\    \\  /:::/____/      /\\ \n\
\t/:::/    |:::::::::\\____\\/:::/__\\:::\\   \\:::\\____\\/:: /    |::|   /::\\____\\|:::|    /      /::\\____\\\n\
\t\\::/    / ~~~~~/:::/    /\\:::\\   \\:::\\   \\::/    /\\::/    /|::|  /:::/    /|:::|____\\     /:::/    /\n\
\t \\/____/      /:::/    /  \\:::\\   \\:::\\   \\/____/  \\/____/ |::| /:::/    /  \\:::\\    \\   /:::/    / \n\
\t             /:::/    /    \\:::\\   \\:::\\    \\              |::|/:::/    /    \\:::\\    \\ /:::/    /  \n\
\t            /:::/    /      \\:::\\   \\:::\\____\\             |::::::/    /      \\:::\\    /:::/    /   \n\
\t           /:::/    /        \\:::\\   \\::/    /             |:::::/    /        \\:::\\__/:::/    /    \n\
\t          /:::/    /          \\:::\\   \\/____/              |::::/    /          \\::::::::/    /     \n\
\t         /:::/    /            \\:::\\    \\                  /:::/    /            \\::::::/    /      \n\
\t        /:::/    /              \\:::\\____\\                /:::/    /              \\::::/    /       \n\
\t        \\::/    /                \\::/    /                \\::/    /                \\::/____/        \n\
\t         \\/____/                  \\/____/                  \\/____/                  ~~              \n\
\t                                                                                                    ";

void ListTITLE()
{
	printf("%s%s%s\n\n\n", BOLD, TITLE, RESET);
}

void ListManual()
{
	printf("%s%s%s\n\n\n", BOLD, MANUAL, RESET);
}

void ListMenu()
{
	printf("%s%s%s\n\n\n", BOLD, MENU, RESET);
}

void proc()
{
	char bar[NUM] = {0};
	memset(bar, '\0', sizeof(bar));
	const char* lable = "|/-\\";
	int i = 0;
	while (i < 50)
	{
		fflush(stdout);
		bar[i++] = '#';
		Sleep(1);
		printf("[%-50s][%3d%%][%c]\r", bar, i * 2, lable[i % 4]);
	}
	printf("\n");
}

void Api_Manual()
{
	printf("\t\t-0)Eixt      : %sExit the program in the normal manner%s\n\n", FRONT_RED, RESET);

	printf("\t\t-1)PUSHBACK  : %sInsert the data you want at the end of the data%s\n", FRONT_GREEN, RESET);
	printf("\t\t\t\t*%svoid Push_Back(SLNode** pphead, SLTData x)%s*\n\n", TWINKLING, RESET);

	printf("\t\t-2)PUSHFRONT : %sInsert the data you want at the beginning of the data%s\n", FRONT_GREEN, RESET);
	printf("\t\t\t\t*%svoid Push_Front(SLNode** pphead, SLTData x)%s*\n\n", TWINKLING, RESET);

	printf("\t\t-3)POPBACK   : %sDeletes the last data content of the data%s\n", FRONT_YELLOW, RESET);
	printf("\t\t\t\t*%svoid Pop_Back(SLNode** pphead)%s*\n\n", TWINKLING, RESET);

	printf("\t\t-4)POPFRONT  : %sDelete the first data content of the data%s\n", FRONT_YELLOW, RESET);
	printf("\t\t\t\t*%svoid Pop_Front(SLNode** pphead)%s*\n\n", TWINKLING, RESET);

	printf("\t\t-5)FIND      : %sFind the corresponding data you entered%s\n", FRONT_BLUE, RESET);
	printf("\t\t\t\t*%sSLNode* Find(SLNode* phead, SLTData x)%s*\n\n", TWINKLING, RESET);

	printf("\t\t-6)PRINT     : %sPrints all current data content%s\n", FRONT_WHITE, RESET);
	printf("\t\t\t\t*%svoid Print(SLNode* const phead)%s*\n\n", TWINKLING, RESET);

	printf("\t\t-7)INSERT    : %sInserts the specified data at the specified location%s\n", FRONT_PURPLR, RESET);
	printf("\t\t\t\t*%svoid Insert(SLNode* phead, SLTData index, SLTData insert_val)%s*\n\n", TWINKLING, RESET);

	printf("\t\t-8)ERASE     : %sDeletes data at the specified location%s\n", FRONT_YELLOW, RESET);
	printf("\t\t\t\t*%svoid Erase(SLNode* phead, SLTData index)%s*\n\n", TWINKLING, RESET);
}