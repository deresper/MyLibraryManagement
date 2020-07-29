#include "LibraryManagement.h"
#include "Menu.h"
#include "commonFunction.h"

int main(int argc, char *agrv[])
{
	int typeAccount;
	if (argc == 2)
	{
		if (_strcmpi(agrv[1], "login") == 0)
		{
			launch();
		}
		else
		{
			textBgColor(RED, BLACK);
			printf("Vui long nhap theo cu phap: LibraryManagement.exe login\n");
			textBgColor(WHITE, BLACK);
			Sleep(2000);
		}
	}
	else
	{
		textBgColor(RED, BLACK);
		printf("Vui long nhap theo cu phap: LibraryManagement.exe login\n");
		textBgColor(WHITE, BLACK);
		Sleep(2000);
	}
	return 0;
}
	