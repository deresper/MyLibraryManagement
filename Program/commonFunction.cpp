#include "LibraryManagement.h"
#include "readerManagement.h"
#include "userManagement.h"
#include "commonFunction.h"

void textBgColor(int colorText, int colorBG) // cplusplus
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (colorBG << 4) | colorText);
}

void stopSceen()
{
	textBgColor(YELLOW, BLACK);
	printf("Nhan phim bat ky de quay lai...");
	textBgColor(WHITE, BLACK);
	_getch();
}

//Hàm kiểm tra số nhập từ bàn phím
int getNumberPressKey(int MAX, int MIN)
{
	int max = (MAX <= 9) ? MAX : 9;
	char ch = ' ';
	printf("\nNhap cac so de chon chuc nang: ");
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			printf("%c\n", ch);
			break;
		}
	}

	return int(ch - '0');
}

// Hàm kiểm tra năm nhuận
bool isLeapYear(int Year)
{
	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
	{
		return true;
	}
	return false;

}

// Hàm trả về số ngày trong tháng thuộc năm 
int numDaysOfMonth(int Month, int Year)
{
	int numOfDays; // Tổng số ngày

	switch (Month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		numOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		numOfDays = 30;
		break;
	case 2:
		if (isLeapYear(Year))
		{
			numOfDays = 29;
		}
		else
		{
			numOfDays = 28;
		}
		break;
	}

	return numOfDays;
}

// Hàm kiểm tra ngày dd/mm/yyyy cho trước có phải là ngày hợp lệ
bool isPossibleDay(int Day, int Month, int Year)
{
	// Kiểm tra năm
	if (Year < 0)
	{
		return false; // => Ngày không còn hợp lệ nữa
	}

	// Kiểm tra tháng
	if (Month < 1 || Month > 12)
	{
		return false; // => Ngày không còn hợp lệ nữa
	}

	// Kiểm tra ngày
	if (Day < 1 || Day > numDaysOfMonth(Month, Year))
	{
		return false; // => Ngày không còn hợp lệ nữa
	}

	return true;
}

void encryptPassword(char *name)
{
	char ch = ' ';
	int index = 0;
	while (1){
		if (_kbhit())
		{
			ch = _getch();
			if (ch != 10 && ch != 13)
			{
				if (ch == 8)
				{
					if (index >= 1)
					{
						printf("%c", ch);
						printf(" ");
						printf("%c", ch);
						*(name + index--) = '\0';
					}
				}
				else
				{
					printf("*");
					*(name + index++) = ch;
				}
			}
			else
				break;
		}
	}
	*(name + index) = '\0';
	printf("\n");
}

// Hàm nhập Username
void getUsername(char username[])
{
	do
	{
		cin.ignore();
		printf("Nhap Username (toi da 20 ky tu): ");
		gets(username, 21);

		if (!checkUsername(username)){
			textBgColor(RED, BLACK);
			printf("Username da ton tai. Vui long nhap Username khac.\n");
			textBgColor(WHITE, BLACK);
			continue;
		}
		else break;
	} while (true);
}

// Hàm nhập Ngày sinh
void getBirthday(Day &birthday)
{
	bool checkDay;
	do
	{
		printf("Nhap ngay sinh: ");
		scanf("%d", &birthday.Date);

		printf("Nhap thang sinh: ");
		scanf("%d", &birthday.Month);
	
		printf("Nhap nam sinh: ");
		scanf("%d", &birthday.Year);

		checkDay = isPossibleDay(birthday.Date, birthday.Month, birthday.Year);
		if (!checkDay)
		{
			textBgColor(RED, BLACK);
			printf("Ngay thang nam sinh khong hop le vui long nhap lai.\n");
			textBgColor(WHITE, BLACK);
		}
	} while (checkDay == false);
}

// Hàm nhập CMND
void getNationalID(char nationID[])
{
	int flag = 0;
	do
	{
		//cin.ignore();
		printf("Nhap CMND (9 so hoac 12 so): ");
		gets(nationID, 13);

		int i;
		if (strlen(nationID) != 9 && strlen(nationID) != 12)
		{
			textBgColor(RED, BLACK);
			printf("CMND khong hop le. Vui long nhap lai.\n");
			textBgColor(WHITE, BLACK);
			continue;
		}

		flag = 1;

		for (int i = 0; i < strlen(nationID); i++)
		{
			if (!isNumber(nationID[i]))
			{
				flag = 0;
				textBgColor(RED, BLACK);
				printf("CMND khong hop le. Vui long nhap lai.\n");
				textBgColor(WHITE, BLACK);
				break;
			}
		}
	} while (flag == 0);

}

// Hàm nhập giới tính
void getSex(int &sex)
{
	do
	{
		printf("Nhap gioi tinh (Nam nhap 1; Nu nhap 0): ");
		scanf("%d", &sex);
		cin.ignore();

		if (sex != 0 && sex != 1)
		{
			textBgColor(RED, BLACK);
			printf("Vui long nhap lai. Nam nhap 1, Nu nhap 0.\n");
			textBgColor(WHITE, BLACK);
		}
	} while (sex != 0 && sex != 1);
}

// Hàm nhập tình trạng
void getStatus(bool &status)
{
	do
	{
		printf("Nhap tinh trang (Actived nhap 1; Blocked nhap 0): ");
		int sta = 0;
		scanf("%d", &sta);
		status = (bool)sta;

		if (status != 0 && status != 1)
		{
			textBgColor(RED, BLACK);
			printf("Vui long nhap lai. Actived nhap 1, Blocked nhap 0.\n");
			textBgColor(WHITE, BLACK);
		}
	} while (status != 0 && status != 1);
}

// Hàm nhập phân quyền
void getTypeAccount(Users &A)
{
	do
	{
		cin.ignore();
		printf("Nhap phan quyen (Chuyen vien nhap 2; quan ly nhap 3): ");
		scanf("%d", &A.typeAccount);

		if (A.typeAccount != 2 && A.typeAccount != 3)
		{
			textBgColor(RED, BLACK);
			printf("Vui long nhap lai. Chuyen vien nhap 2; quan ly nhap 3.\n");
			textBgColor(WHITE, BLACK);
		}
	} while (A.typeAccount != 2 && A.typeAccount != 3);
}

// Hàm nhập ID độc giả
void getReaderID(char ID[])
{
	int flag = 0;
	do
	{
		cin.ignore();
		printf("Nhap ma doc gia (8 so): ");
		gets(ID, 9);

		int i;
		if (strlen(ID) != 8)
		{
			textBgColor(RED, BLACK);
			printf("Ma doc gia khong hop le. Vui long nhap lai.\n");
			textBgColor(WHITE, BLACK);
			continue;
		}

		flag = 1;

		for (int i = 0; i < strlen(ID); i++)
		{
			if (!isNumber(ID[i]))
			{
				flag = 0;
				textBgColor(RED, BLACK);
				printf("Ma doc gia khong hop le. Vui long nhap lai.\n");
				textBgColor(WHITE, BLACK);
				break;
			}
		}
	} while (flag == 0);

}

// Hàm nhập ISBN sách
void getISBN(char *ISBN)
{
	int flag = 0;
	do
	{
		cin.ignore();
		printf("Nhap ISBN: ");
		gets(ISBN, 14);

		int i;
		if (strlen(ISBN) != 13)
		{
			textBgColor(RED, BLACK);
			printf("ISBN phai co 13 chu so. Vui long nhap lai.\n");
			textBgColor(WHITE, BLACK);
			continue;
		}

		flag = 1;

		for (int i = 0; i < strlen(ISBN); i++)
		{
			if (!isNumber(ISBN[i]))
			{
				flag = 0;
				textBgColor(RED, BLACK);
				printf("ISBN khong hop le. Vui long nhap lai.\n");
				textBgColor(WHITE, BLACK);
				break;
			}
		}
	} while (flag == 0);
}

// Hàm hỏi muốn mượn sách nữa không?
int wantBorrow()
{
	int borrow;
	do
	{
		textBgColor(YELLOW, BLACK);
		printf("Doc gia nay con muon muon them sach nua khong? Nhap 0 (Khong), Nhap 1 (Co): ");
		scanf("%d", &borrow);
		if (borrow == 1)
			return 1;
		else if (borrow == 0)
			return 0;
		else
		{
			textBgColor(RED, BLACK);
			printf("Vui long nhap 0 hoac 1\n");
			textBgColor(WHITE, BLACK);
			Sleep(1000);
		}
	} while (borrow != 0 && borrow != 1);
	return 1;
}

//Tạo chuỗi mã độc giả
char *toStr(long n)
{
	char str[9];
	sprintf(str, "%ld", n);
	char S[9];
	S[0] = '\0';
	int count = 8 - strlen(str);
	while (count > 0)
	{
		strcat(S, "0");
		count--;
	}
	strcat(S, str);
	S[8] = '\0';

	char *returnS = (char*)S;
	return returnS;
}

Day getExpiredDay(Day orginDay){ 

	Day plusDay;
	plusDay = orginDay;
	plusDay.Date += _MAX_DAY_EXPIRES_;

	while (!isPossibleDay(plusDay.Date, plusDay.Month, plusDay.Year)){
		if (plusDay.Date > numDaysOfMonth(plusDay.Month, plusDay.Year))
		{
			plusDay.Date -= numDaysOfMonth(plusDay.Month, plusDay.Year);
			if ((++plusDay.Month) > 12)
			{
				plusDay.Month = 1;
				plusDay.Year++;
			}
		}
	}

	return plusDay;

}

Day getToday(){
    time_t rawtime;
    struct tm * timeinfo; // khai bao mot con tro cua struct thoi gian

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    Day days;
    days.Date 	= timeinfo->tm_mday;
    days.Month 	= timeinfo->tm_mon + 1;
    days.Year 	= timeinfo->tm_year + 1900;

    return days;
}

bool isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

Day getDayFrmUser(){
	Day day;
	do
	{
		printf("Nhap ngay: ");
		scanf("%d", &day.Date);
		int temp = getchar();

		printf("Nhap thang: ");
		scanf("%d", &day.Month);
		temp = getchar();

		printf("Nhap nam: ");
		scanf("%d", &day.Year);
		temp = getchar();

		if (!isPossibleDay(day.Date, day.Month, day.Year))
		{
			textBgColor(RED, BLACK);
			printf("Ngay thang nam sinh khong hop le vui long nhap lai.\n");
			textBgColor(WHITE, BLACK);
		}
		else break;
	} while (1);
	return day;
}

void printfDay(Day day){
	printf("%d / %d / %d\n", day.Date, day.Month, day.Year);
}

char *getStringFrmUser(char *note){
	/*printf("%s:\t", note);
	char *strGet = new char();
	int getEnter = getchar();
	gets(strGet);

	return strGet;*/

	printf("%s:\t", note);

	char temp[101];
	int getEnter = getchar();
	gets_s(temp);
	char* strGet = new char[strlen(temp) + 1];
	strcpy(strGet, temp);
	//gets(strGet);

	return strGet;
}

int getNumber(char *note){
	printf("%s\n", note);
	int x = 0;
	scanf("%d", &x);
	return x;
}


int plusOneIntoAChar(char &numch){
	if (numch < '0' && numch > '9')
	{
		return -1;
	}
	else if (numch == '9')
	{
		numch = '0';
		return 1;
	}
	else {
		numch += 1;
		return 0;
 	}
}
bool plusOneIntoAString(char* numStr){

	int length = strlen(numStr) -1;
	while (length >= 0){
		switch(plusOneIntoAChar(numStr[length])){
			case -1:
				return false;
				break;
			case 0:
				length = -1;
				break;
		}
		length--;
	}

	return true;
}

int toDays(Day dayt){
	int numDay = 0;

	for (int i = 2000; i < dayt.Year; ++i)
	{
	if (isLeapYear(i))
	{
		numDay += 366;
	}
		else numDay += 365;
	}

	for (int i = 1; i < dayt.Month; ++i)
	{
		numDay += numDaysOfMonth(i, dayt.Year);
	}

	numDay += dayt.Date;

	return numDay;
}

//Quá tải toán tử
int operator-(Day d1, Day d2){
	 int dayt1 = toDays(d1);
	int dayt2 = toDays(d2);

	 return dayt1 - dayt2;
}
bool operator==(Day d1, Day d2){
	return (d1 - d2 == 0);
}
bool operator==(BorrowBooks borBook1, BorrowBooks borBook2){
	return (strcmp(borBook1.ID, borBook1.ID) == 0 && strcmp(borBook1.ISBN, borBook2.ISBN) == 0 && borBook1.borrowBookDay == borBook2.borrowBookDay);
}

char *intMoneyToStringMoney(long moneyPayement){

    char *zeroStr = new char(_SO_LUONG_CHU_SO_TIEN_MAT);
    for (int i = 0; i < _SO_LUONG_CHU_SO_TIEN_MAT; ++i)
	{
		zeroStr[i] = '\0';
	}

	sprintf(zeroStr, "%ld", moneyPayement);

	char *pch;
	while ((moneyPayement / 1000) > 0){
		pch = strchr(zeroStr, ',');
		if (pch != NULL)
		{
			memmove(pch -3 +1, pch -3, strlen(zeroStr) - (pch - zeroStr ) +3);
			*(pch -3) = ',';
		}
		else
		{
			memmove(zeroStr +strlen(zeroStr) -2, zeroStr +strlen(zeroStr) -3, 3);
			*(zeroStr +strlen(zeroStr) -4) = ',';
		}
		moneyPayement /= 1000;
	}

	return zeroStr;
}

