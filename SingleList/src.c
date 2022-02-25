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

void ListMenu()
{
	printf("%s%s%s\n\n\n", BOLD, TITLE, RESET);
}

void ListManual()
{
	printf("%s%s%s\n\n\n", BOLD, MANUAL, RESET);
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