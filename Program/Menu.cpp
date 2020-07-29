#include "LibraryManagement.h"
#include "commonFunction.h"
#include "Menu.h"
#include "userManagement.h"
#include "readerManagement.h"
#include "bookManagement.h"
#include "borrowedBooks.h"
#include "returnedBooks.h"
#include "statistic.h"
// Thay đổi kích thước Console
void resizeConsole(int width, int height) // http://www.cplusplus.com/forum/beginner/1481/
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Menu(int &typeAccount)
{
	bool continueSwit = true;
	while (continueSwit){
		int choice = printLoginMenu();
		switch (choice){
		case 0:
			continueSwit = false;
			Logout(typeAccount);
			system(cls);
			return;
		case 1:
			runMenuUser(typeAccount);
			break;
		case 2:
			runReaderManagement(typeAccount);
			break;
		case 3:
			runBookManagement(typeAccount);
			break;
		case 4:
			borrowBook();
			break;
		case 5:
			returnBook();
			break;
		case 6:
			runningAnalyzing(typeAccount);
			break;
		case 7:
			continueSwit = false;
			Logout(typeAccount);
			textBgColor(GREEN, BLACK);
			printf("Ban da dang xuat thanh cong!\n");
			Sleep(1000);
			launch();
			break;
		default:
			break;
		}
	}
}

void launch()
{
	do {
		textBgColor(WHITE, BLACK);
		system("cls");
		resizeConsole(660, 400);
		int accoutType = Login();
		if (accoutType == 0)
		{
			textBgColor(RED, BLACK);
			printf("Dang nhap that bai. Vui long thu lai!\n");
			textBgColor(WHITE, BLACK);
			Sleep(1000);
			system("cls");
		}
		else if (accoutType == -1)
		{
			textBgColor(RED, BLACK);
			printf("Khong the dang nhap. Tai khoan cua ban dang o trong trang thai Blocked.\n");
			textBgColor(WHITE, BLACK);
			Sleep(1000);
			system("cls");
		}
		else
		{
			textBgColor(GREEN, BLACK);
			printf("Dang nhap thanh cong!\n");
			textBgColor(WHITE, BLACK);
			Sleep(1000);
			Menu(accoutType);
			break;
		}
	} while (1);
}

int printLoginMenu(){
	 printf("*******************************************\n");

	bool checkUsername = 1;
	bool checkPassword = 1;

	if (checkUsername && checkPassword)
	{
		system(cls);
		printfMainMenu();
		return getNumberPressKey(MAX_CHOICE, 0);
	}
	else {
		textBgColor(RED, BLACK);
		printf("Tai khoan khong ton tai!\n");
		textBgColor(WHITE, BLACK);
		return printLoginMenu();
	}

}

void printfMainMenu(){
	showTitleHeader();
	textBgColor(WHITE, BLACK);
	printf("1. Quan ly nguoi dung.\n");
	printf("2. Quan ly doc gia.\n");
	printf("3. Quan ly sach.\n");
	printf("4. Lap phieu muon sach.\n");
	printf("5. Lap phieu tra sach.\n");
	printf("6. Thong ke co ban.\n");
	printf("7. Dang xuat.\n");
	printf("0. Thoat\n");

}

void showTitleUser(){
	printf("QUAN LY NGUOI DUNG\n");
	textBgColor(WHITE, BLACK);
}

int printUserMenu(int typeAccount)
{
	system(cls);
	showTitleUser();
	printf("1. Thay doi mat khau.\n");
	printf("2. Cap nhat thong tin ca nhan.\n");

	if (typeAccount == 1)
	{
		printf("3. Tao nguoi dung.\n");
		printf("4. Phan quyen nguoi dung.\n");
		printf("5. Chinh sua trang thai nguoi dung.\n");
		printf("0. Quay ve.\n");
		return 5;
	}
	else
	{
		printf("0. Quay ve.\n");
		return 2;
	}
}

void showTitleReader(){
	printf("QUAN LY DOC GIA\n");
}

int printfMenuReaderManagementForAdmin(){
	system(cls);
	showTitleReader();
	printf("1. Xem danh sach doc gia trong thu vien.\n");
	printf("2. Them doc gia.\n");
	printf("3. Chinh sua thong tin mot doc gia.\n");
	printf("4. Xoa thong tin mot doc gia.\n");
	printf("5. Tim kiem doc gia qua CMND.\n");
	printf("6. Tim kiem doc gia qua ho ten.\n");
	printf("0. Quay ve\n");

	return 6;
}

int printfMenuReaderManagementForExpert(){
	system(cls);
	showTitleReader();
	printf("1. Xem danh sach doc gia trong thu vien.\n");
	printf("2. Them doc gia.\n");
	printf("3. Chinh sua thong tin mot doc gia.\n");
	printf("4. Tim kiem doc gia qua CMND.\n");
	printf("5. Tim kiem doc gia qua ho ten.\n");
	printf("0. Quay ve\n");

	return 5;
}

int printfMenuReaderManagementForManager(){
	system(cls);
	showTitleReader();
	printf("1. Xem danh sach doc gia trong thu vien.\n");
	printf("2. Them doc gia.\n");
	printf("3. Chinh sua thong tin mot doc gia.\n");
	printf("4. Xoa thong tin mot doc gia.\n");
	printf("5. Tim kiem doc gia qua CMND.\n");
	printf("6. Tim kiem doc gia qua ho ten.\n");
	printf("0. Quay ve\n");

	return 6;
}

int editInfReaderMenu(){
	textBgColor(WHITE, BLACK);
	printf("\n");
	printf("1. Sua Ho va ten\n");
	printf("2. Doi CMND\n");
	printf("3. Doi ngay sinh\n");
	printf("4. Doi gioi tinh\n");
	printf("5. Doi Email\n");
	printf("6. Doi dia chi\n");
	printf("7. Gia han the\n");
	printf("0. Quay ve\n");

	return 7;
}

void showTitleBook(){
	printf("QUAN LY SACH\n");
}

int printfMenuBookManagementForAdmin(){
	system(cls);
	showTitleBook();
	printf("1. Xem danh sach sach trong thu vien.\n");
	printf("2. Them sach.\n");
	printf("3. Chinh sua thong tin mot quyen sach.\n");
	printf("4. Xoa thong tin mot quyen sach.\n");
	printf("5. Tim kiem sach qua ISBN.\n");
	printf("6. Tim kiem sach qua ten sach.\n");
	printf("0. Quay ve\n");

	return 6;
}

int printfMenuBookManagementForExpert(){
	system(cls);
	showTitleBook();
	printf("1. Tim kiem sach qua ISBN.\n");
	printf("2. Tim kiem sach qua ten sach.\n");
	printf("0. Quay ve\n");

	return 2;
}

int printfMenuBookManagementForManager(){
	system(cls);
	showTitleBook();
	printf("1. Xem danh sach sach trong thu vien.\n");
	printf("2. Them sach.\n");
	printf("3. Chinh sua thong tin mot quyen sach.\n");
	printf("4. Xoa thong tin mot quyen sach.\n");
	printf("5. Tim kiem sach qua ISBN.\n");
	printf("6. Tim kiem sach qua ten sach.\n");
	printf("0. Quay ve\n");

	return 6;
}

int editInfBookMenu(){
	textBgColor(WHITE, BLACK);
	printf("\n");
	printf("1. Chinh sua ten sach\n");
	printf("2. Chinh sua ten tac gia\n");
	printf("3. Chinh sua nha xuat ban\n");
	printf("4. Chinh sua nam xuat ban\n");
	printf("5. Chinh sua the loai sach\n");
	printf("6. Chinh sua gia sach\n");
	printf("7. Chinh sua so luong sach\n");
	printf("0. Quay ve\n");

	return 7;
}

int askYesNoQuestion(char *note){
	printf("%s?\n", note);
	printf("1. Co\n");
	printf("2. Khong\n");
	printf("0. Quay ve\n");

	return 2;
}

void showTitleAnalyzing(){
	printf("THONG KE\n");
}

int analyzingMenuForAdmin(){
	system(cls);
	showTitleAnalyzing();
	printf("1. Thong ke so luong sach trong thu vien.\n");
	printf("2. Thong ke so luong sach theo the loai.\n");
	printf("3. Thong ke so luong doc gia.\n");
	printf("4. Thong ke so luong doc gia theo gioi tinh.\n");
	printf("5. Thong ke so luong sach dang duoc muon.\n");
	printf("6. Thong ke danh sach doc gia bi tre han.\n");
	printf("0. Quay ve.\n");

	return 6;
}

int analyzingMenuForExpert(){
	system(cls);
	showTitleAnalyzing();
	printf("1. Thong ke so luong sach dang duoc muon.\n");
	printf("2. Thong ke danh sach doc gia bi tre han.\n");
	printf("0. Quay ve.\n");

	return 2;
}

int analyzingMenuManager(){
	system(cls);
	showTitleAnalyzing();
	printf("1. Thong ke so luong sach trong thu vien.\n");
	printf("2. Thong ke so luong sach theo the loai.\n");
	printf("3. Thong ke so luong doc gia.\n");
	printf("4. Thong ke so luong doc gia theo gioi tinh.\n");
	printf("0. Quay ve.\n");

	return 4;
}

void showTitleHeader(){
	textBgColor(GREEN, BLACK);
	printf(">> PHAN MEM QUAN LY THU VIEN <<\n");
	textBgColor(WHITE, BLACK);
}


void showTitleBorrow(){
	printf("LAP PHIEU MUON SACH\n");
}

void showTitleReturn(){
	printf("LAP PHIEU TRA SACH\n");
}


// Hiển thị tiêu đề sub menu
void showTitleAnalyzingBooks()
{
	printf("THONG KE SACH TRONG THU VIEN\n");
}
void showTitleAnalyzingCato()
{
	printf("THONG KE THE LOAI SACH TRONG THU VIEN\n");
}
void showTitleAnalyzingReaders()
{
	printf("THONG KE DOC GIA TRONG THU VIEN\n");
	textBgColor(WHITE, BLACK);
}
void showTitleAnalyzingSex()
{
	printf("THONG KE DOC GIA THEO GIOI TINH TRONG THU VIEN\n");
	textBgColor(WHITE, BLACK);
}
void showTitleAnalyzingBorrowBook()
{
	printf("THONG KE SO SACH DANG MUON TRONG THU VIEN\n");
}
void showTitleAnalyzingOverdue()
{
	printf("THONG KE DANH SACH DOC GIA TRE HAN TRA SACH\n");
}
void showTitleOverdue(){
	printf("DANH SACH TRE HAN TRA SACH\n");
}
void showTitleListBook(){
	printf("DANH SACH SACH TRONG THU VIEN\n");
}
void showTitleCategory(){
	printf("DANH SACH THE LOAI\n");
}
void showTitleListReader(){
	printf("DANH SACH DOC GIA\n");
}
void showTitleMaleReader(){
	printf("DANH SACH DOC GIA THEO GIOI TINH NAM\n");
}
void showTitleFemaleReader(){
	printf("DANH SACH DOC GIA THEO GIOI TINH NU\n");
}
void showTitleListBorrowing(){
	printf(" DANH SACH CAC SACH DA DUOC MUON\n");
}

// Hiển thị tiêu đề chức năng 2
void showTitleViewReader(){
	printf("XEM THONG TIN DOC GIA\n");
}
void showTitleAddNewReader(){
	printf("THEM DOC GIA\n");
}
void showTitleEditReader(){
	printf("CHINH SUA THONG TIN DOC GIA\n");
}
void showTitleAfterEditReader(){
	printf("THONG TIN DOC GIA SAU CHINH SUA\n");
}
void showTitleDeleteReader(){
	printf("XOA DOC GIA\n");
}
void showTitleFindReaderByNationId(){
	printf("TIM KIEM DOC GIA QUA CMND\n");
}
void showTitleFindReaderByName(){
	printf("TIM KIEM DOC GIA QUA HO TEN\n");
}


// Hiển thị tiêu đề chức năng 1
void showTitleCreatUser(){
	printf("TAO NGUOI DUNG\n");
}
void showTitleDecentraliseUser(){
	printf("PHAN QUYEN NGUOI DUNG\n");
}
void showTitleChangePassUser(){
	printf("THAY DOI MAT KHAU\n");
}
void showTitleStatusUser(){
	printf("CHINH SUA TRANG THAI NGUOI DUNG\n");
}
void showTitleAfterEditUser(){
	printf("CAP NHAT THONG TIN CA NHAN\n");
}


// Hiển thị tiêu đề chức năng 3
void showTitleViewBook(){
	printf("XEM THONG TIN SACH\n");
}
void showTitleAddNewBook(){
	printf("THEM SACH\n");
}
void showTitleEditBook(){
	printf("CHINH SUA THONG TIN SACH\n");
}
void showTitleAfterEditBook(){
	printf("THONG TIN SACH SAU CHINH SUA\n");
}
void showTitleDeleteBook(){
	printf("XOA SACH\n");
}
void showTitleFindBookByISBN(){
	printf("TIM KIEM SACH QUA ISBN\n");
}
void showTitleFindBookByName(){
	printf("TIM KIEM SACH QUA TEN SACH\n");
}