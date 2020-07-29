#include "LibraryManagement.h"
#include "Menu.h"
#include "commonFunction.h"
#include "linkedListReaders.h"
#include "readerManagement.h"

Readers *findReaderWithNationID(char *personID)	// Tìm kiếm độc giả theo CMND
{
	Readers *reader = new Readers;

	FILE *fileReader = fopen(_DIR_DATA_FOLDER_READER, "rb");

	if (reader == NULL || fileReader == NULL)
		return NULL;
	
	while (fread(reader, sizeof(Readers), 1, fileReader) != 0){
		if (strcmp(reader->NationID, personID) == 0)
		{
			fclose(fileReader);
			return reader;
		}
	}

	fclose(fileReader);
	delete reader;
	return NULL;
}

Readers *findReaderWithEmail(char *Email)	// Tìm kiếm độc giả theo Email
{
	Readers *reader = new Readers;

	FILE* fileReader = fopen(_DIR_DATA_FOLDER_READER, "rb");

	if (reader == NULL || fileReader == NULL)
	{
		return NULL;
	}

	while (fread(reader, sizeof(Readers), 1, fileReader) != 0){
		if (strcmp(reader->Email, Email) == 0)
		{
			fclose(fileReader);
			return reader;
		}
	}

	fclose(fileReader);
	delete reader;
	return NULL;
}

Readers *findReaderWithID(char *ID)	// Tìm kiếm độc giả theo ID
{
	Readers *reader = new Readers;

	FILE* fileReader = fopen(_DIR_DATA_FOLDER_READER, "rb");

	if (reader == NULL || fileReader == NULL)
	{
		return NULL;
	}

	while (fread(reader, sizeof(Readers), 1, fileReader) != 0){
		if (strcmp(reader->ID, ID) == 0)

		{
			fclose(fileReader);
			return reader;
		}
	}

	fclose(fileReader);
	delete reader;
	return NULL;
}

void viewAllReader()	// đọc toàn bộ thông tin độc giả từ file và in ra
{
	Readers *reader = new Readers;
	FILE* fileReader = fopen(_DIR_DATA_FOLDER_READER, "rb");

	if (fileReader == NULL || reader == NULL)
	{
		return;
	}

	system(cls);
	showTitleViewReader();

	while (fread(reader, sizeof(Readers), 1, fileReader) != 0){
		viewInfAReader(*reader);
	}

	fclose(fileReader);

	delete reader;
	stopSceen();
}

bool findListReaderWithName(char *personName, LLNodeReader &lsReader){	// Tìm kiếm độc giả theo họ tên
	Readers *reader = new Readers;

	if (reader == NULL)
		return 0;

	FILE* fileReader = fopen(_DIR_DATA_FOLDER_READER, "rb");

	if (fileReader == NULL)
	{
		return 0;
	}
	int flag = 0;
	while (fread(reader, sizeof(Readers), 1 ,fileReader) != 0){
		if (_strcmpi(reader->Fullname, personName) == 0)
		{
			// thêm vào cuối danh sách
			addAtTail(lsReader, *reader);
			flag = 1;
		}

	}

	delete reader;
	fclose(fileReader);
	if (flag == 1)
		return 1;
	return 0;
}

bool printReaderFromLL(LLNodeReader ls){ // in ra thông tin độc giả từ Linked List
	NodeReader *pNow = ls.head;
	if (pNow == NULL)
	{
		return 0;
	}

	int index = 0;

	while(pNow != NULL){
		printf("\nDoc gia thu %d:\n", ++index);
		viewInfAReader(pNow->reader);
		pNow = pNow->next;
	}

	return 1;
}

Readers addReader() // Thêm độc giả
{
	Readers reader;
	Readers *temp = new Readers;
	FILE *f = fopen(_DIR_DATA_FOLDER_READER, "rb");
	
	long ID = 1l;
	fseek(f, 0L, SEEK_END);
	long size = ftell(f);

	char *strID = new char[9];
	if (size == 0)
	{
		// ID = 1;
		strcpy(strID, (char*)"00000001"); // nếu chưa có độc giả nào thì tự động khởi tạo là 1
	}
	else
	{
		rewind(f);
		while (fread(temp, sizeof(Readers), 1, f) != 0)
		{
			ID++; // nếu đã có độc giả thì tự động cộng thêm 1 
		}
	}

	fclose(f);

	// strcpy(reader.ID, toStr(ID));
	if ((strcmp(strID, (char*)"00000001")))
	{
		strcpy(strID, temp->ID);
		plusOneIntoAString(strID); 
	}

	delete temp;
	strID[8] = '\0';
	strcpy(reader.ID, strID);
	delete[] strID;

	//Nhập thông tin độc giả
	printf("ID:\t%s\n", reader.ID);
	_flushall();
	cin.ignore();
	printf("Nhap Ho va Ten: ");
	gets(reader.Fullname, 31);

	getNationalID(reader.NationID);

	getBirthday(reader.Birthday);

	getSex(reader.Sex);

	printf("Nhap Email: ");
	gets(reader.Email, 101);

	printf("Nhap dia chi: ");
	gets(reader.Address, 101);
	reader.creatCard = getToday();
	reader.expireCard = getExpiredDay(reader.creatCard);
	return reader;
}

int askToUpdateReaderToFile() // cập nhật thông tin đọc giả vào trong file
{	
	printf("\nBan co chan muon cap nhat khong?\n");
	printf("1. Co\n");
	printf("2. Khong\n");

	return (getNumberPressKey(2, 1));
}

bool writeInfReaderToFile() // thêm độc giả vào database
{
	system(cls);
	showTitleAddNewReader();

	Readers	reader = addReader();
	Readers *temp1 = findReaderWithNationID(reader.NationID);
	Readers *temp2 = findReaderWithEmail(reader.Email);

	switch (askToUpdateReaderToFile()){
	case 1:
		if (temp1 != NULL || temp2 != NULL)
		{
			system(cls);
			showTitleAddNewReader();
			textBgColor(RED, BLACK);
			printf("Doc gia nay da ton tai do trung CMND/Email voi doc gia khac.\n");
			textBgColor(WHITE, BLACK);
			Sleep(1000);
			delete temp1;
			delete temp2;
			return 0;
		}
		else
		{
			FILE *f = fopen(_DIR_DATA_FOLDER_READER, "ab");

			if (f == NULL)
				return 0;

			fwrite(&reader, sizeof(Readers), 1, f);
			fclose(f);
			system(cls);
			showTitleAddNewReader();
			textBgColor(GREEN, BLACK);
			printf("Them doc gia thanh cong.\n");
			textBgColor(WHITE, BLACK);
			Sleep(1000);
			delete temp1;
			delete temp2;
			break;
		}
	default:
			delete temp1;
			delete temp2;
			return 0;
	}
	return 1;
}

void viewInfAReader(Readers reader) // Xem thông tin của một độc giả cụ thể
{
	textBgColor(WHITE, BLACK);
	
	printf("------------------------------------------------------------------------------------\n");
	printf("|    ID:\t%-63s    |\n", reader.ID);
	printf("|    Ten:\t%-31s CMND:\t%-23s    |\n", reader.Fullname, reader.NationID);
	printf("|    Ngay sinh:\t\t%2d . %2d . %4d\t|  \tGioi tinh:\t%-15s    |\n", reader.Birthday.Date, reader.Birthday.Month, reader.Birthday.Year, (reader.Sex == 1 ? (char*)"Nam" : (char*)"Nu"));
	printf("|    Email:\t%-63s    |\n", reader.Email);
	printf("|    Dia chi:\t%-63s    |\n", reader.Address);
	printf("|    Ngay lap the:\t%2d . %2d . %4d  |\tNgay het han:\t%2d . %2d . %4d     |\n", reader.creatCard.Date, reader.creatCard.Month, reader.creatCard.Year, reader.expireCard.Date, reader.expireCard.Month, reader.expireCard.Year);
	printf("------------------------------------------------------------------------------------\n");
	textBgColor(WHITE, BLACK);
}

bool editReader(Readers &reader){ // sửa thông tin độc giả
	int edit;
	bool end = false;
	int choice = editInfReaderMenu();
	do
	{
		textBgColor(WHITE, BLACK);
		switch (getNumberPressKey(choice, 0)){
		case 0: 
			return 0;
		case 1: // Sửa Họ và tên
			printf("Nhap Ho va Ten: ");
			gets(reader.Fullname);
			edit = wantEdit();
			if (edit == 0)
				end = true;
			//cin.ignore();
			break;
		case 2: // Đổi CMND
			cin.ignore();
			getNationalID(reader.NationID);
			edit = wantEdit();
			if (edit == 0)
				end = true;
			break;
		case 3: // Đổi ngày sinh
			getBirthday(reader.Birthday);
			edit = wantEdit();
			if (edit == 0)
				end = true;
			break;
		case 4: // Đổi giới tính
			getSex(reader.Sex);
			edit = wantEdit();
			if (edit == 0)
				end = true;
			break;
		case 5: // Đổi email
			printf("Nhap dia chi email / thu dien tu: ");
			gets(reader.Email);
			edit = wantEdit();
			if (edit == 0)
				end = true;
			cin.ignore();
			break;
		case 6: // Đổi địa chỉ
			printf("Nhap dia chi: ");
			gets(reader.Address);
			edit = wantEdit();
			if (edit == 0)
				end = true;
			cin.ignore();
			break;
		case 7: // Gia hạn thẻ
			printf("Gia han the toi ngay: ");
			reader.expireCard = getExpiredDay(getToday());
			textBgColor(BLUE, BLACK);
			printfDay(reader.expireCard);
			textBgColor(WHITE, BLACK);
			edit = wantEdit();
			if (edit == 0)
				end = true;
			cin.ignore();
			break;
		default:
			break;
		}
	} while (end == false);
	return 1;
}

void editReaderToFile() // Chỉnh sửa thông tin độc giả trong file
{
	FILE *fo = fopen(_DIR_DATA_FOLDER_READER, "rb");
	FILE *ftemp = fopen(_DIR_DATA_FOLDER_READER_TEMP, "wb");

	if (fo == NULL || ftemp == NULL)
		return;

	Readers temp;
	Readers *reader = new Readers;
	if (reader == NULL)
		return;
	system(cls);
	showTitleEditReader();

	getReaderID(reader->ID);
	reader = findReaderWithID(reader->ID);
	if (reader == NULL)
	{
		system(cls);
		showTitleEditReader();
		textBgColor(RED, BLACK);
		printf("Doc gia khong ton tai.\n");
		textBgColor(WHITE, BLACK);
		Sleep(1000);
		fclose(fo);
		fclose(ftemp);
		delete reader;
		return;
	}

	viewInfAReader(*reader);
	// chọn ra để chỉnh
	while (fread(&temp, sizeof(Readers), 1, fo) != 0)
	{
		if (strcmp(reader->ID, temp.ID) != 0)
			fwrite(&temp, sizeof(Readers), 1, ftemp);
		else
		{
			if (editReader(*reader))
			{
				fwrite(reader, sizeof(Readers), 1, ftemp);
				textBgColor(GREEN, BLACK);
				printf("Chinh sua thanh cong.\n");
				textBgColor(WHITE, BLACK);
				Sleep(1000);
				system(cls);
				showTitleAfterEditReader();
				viewInfAReader(*reader);
				stopSceen();
			}
			else
				fwrite(reader, sizeof(Readers), 1, ftemp);
		}
	}
	fclose(fo);
	fclose(ftemp);
	delete reader;
	remove((char*)_DIR_DATA_FOLDER_READER);
	rename((char*)_DIR_DATA_FOLDER_READER_TEMP, (char*)_DIR_DATA_FOLDER_READER);
}

void deleteReaderToFile() // Xóa độc giả trong file
{

	FILE *fo = fopen(_DIR_DATA_FOLDER_READER, "rb");
	FILE *ftemp = fopen(_DIR_DATA_FOLDER_READER_TEMP, "wb");

	if (fo == NULL || ftemp == NULL)
		return;

	Readers temp;
	Readers *reader = new Readers;
	if (reader == NULL)
		return;

	system(cls);
	showTitleDeleteReader();

	_flushall();
	getReaderID(reader->ID);
	reader = findReaderWithID(reader->ID);
	if (reader == NULL)
	{
		system(cls);
		showTitleDeleteReader();
		textBgColor(RED, BLACK);
		printf("Doc gia khong ton tai.\n");
		textBgColor(WHITE, BLACK);
		Sleep(1000);
		delete reader;
		fclose(fo);
		fclose(ftemp);
		return;
	}

	textBgColor(YELLOW, BLACK);
	printf("Thong tin doc gia chuan bi xoa: \n");
	viewInfAReader(*reader);

	textBgColor(YELLOW, BLACK);
	printf("Ban co chac chan muon xoa? \n- 1. Dong y \n- 0. Huy\n");
	textBgColor(WHITE, BLACK);
	switch (getNumberPressKey(1, 0)){
		case 1:
			break;
		default:
			fclose(fo);
			fclose(ftemp);
			delete reader;
			remove((char*)_DIR_DATA_FOLDER_READER_TEMP);
			return;
	}


	while (fread(&temp, sizeof(Readers), 1, fo) != 0)
	{
		if (strcmp(reader->ID, temp.ID) != 0)
			fwrite(&temp, sizeof(Readers), 1, ftemp);
	}
	system(cls);
	showTitleDeleteReader();
	textBgColor(GREEN, BLACK);
	printf("Xoa thanh cong.\n");
	Sleep(1000);
	textBgColor(WHITE, BLACK);
	
	fclose(fo);
	fclose(ftemp);
	delete reader;
	remove((char*)_DIR_DATA_FOLDER_READER);
	rename((char*)_DIR_DATA_FOLDER_READER_TEMP, (char*)_DIR_DATA_FOLDER_READER);
}

void searchNationID() // Tìm kiếm qua CMND
{
	Readers *reader = new Readers;
	if (reader == NULL)
		return; 

	system(cls);
	showTitleFindReaderByNationId();

	getNationalID(reader->ID);
	reader = findReaderWithNationID(reader->ID);

	if (reader == NULL)
	{
		system(cls);
		showTitleFindReaderByNationId();
		textBgColor(RED, BLACK);
		printf("Doc gia khong ton tai.\n");
		textBgColor(WHITE, BLACK);
		Sleep(1000);
	}
	else
	{
		viewInfAReader(*reader);
		stopSceen();
	}
	delete reader;
}

void searchFullName() // Tìm kiếm qua họ tên
{
	Readers *reader = new Readers;
	if (reader == NULL)
		return;

	system(cls);
	showTitleFindReaderByName();

	_flushall();
	printf("Nhap ten doc gia: ");
	gets(reader->Fullname);

	LLNodeReader lsReader;
	Init(lsReader);

	if (!(findListReaderWithName(reader->Fullname, lsReader)))
	{
		system(cls);
		showTitleFindReaderByName();
		textBgColor(RED, BLACK);
		printf("Doc gia khong ton tai.\n");
		textBgColor(WHITE, BLACK);
		Sleep(1000);
	}

	else
	{
		system(cls);
		showTitleFindReaderByName();
		printReaderFromLL(lsReader);
		stopSceen();
	}

	freeLinkListReader(lsReader);
	delete reader;
}

void runReaderManagementForAdmin(){
	int choice = 0;
	do {
		choice = getNumberPressKey(printfMenuReaderManagementForAdmin(), 0);
		system(cls);
		switch (choice){
		case 1: // Xem danh sách độc giả trong thư viện
			viewAllReader();
			break;
		case 2: // Thêm độc giả
			writeInfReaderToFile();
			break;
		case 3: // Chỉnh sửa thông tin một độc giả
			editReaderToFile();
			break;
		case 4: // Xóa thông tin một độc giả
			deleteReaderToFile();
			break;
		case 5: // Tìm kiếm độc giả qua CMND
			searchNationID();
			break;
		case 6: // Tìm kiếm độc giả qua họ tên
			searchFullName();
			break;
		default:
			break;
		}
		// Sleep(1);
	} while (choice != 0);
}

void runReaderManagementForExpert(){
	int choice = 0;
	do {
		choice = getNumberPressKey(printfMenuReaderManagementForExpert(), 0);
		system(cls);
		switch (choice){
		case 1: // xem danh sách độc giả trong thư viện
			viewAllReader();
			break;
		case 2: // Thêm độc giả
			writeInfReaderToFile();
			break;
		case 3: // Chỉnh sửa thông tin 1 độc giả
			editReaderToFile();
			break;
		case 4: // Tìm kiếm độc giả qua CMND
			searchNationID();
			break;
		case 5: // Tìm kiếm độc giả qua họ tên
			searchFullName();
			break;
		default:
			break;
		}
	} while (choice != 0);
}

void runReaderManagementManager(){
	int choice = 0;
	do {
		choice = getNumberPressKey(printfMenuReaderManagementForManager(), 0);
		system(cls);
		switch (choice){
		case 1: // xem danh sách độc giả trong thư viện
			viewAllReader();
			break;
		case 2: // Thêm độc giả
			writeInfReaderToFile();
			break;
		case 3: // Chỉnh sửa thông tin một độc giả
			editReaderToFile();
			break;
		case 4: // Xóa thông tin một độc giả
			deleteReaderToFile();//<<<<<
			break;
		case 5: // Tìm kiếm độc giả qua CMND
			searchNationID();
			break;
		case 6: // Tìm kiếm độc giả qua họ tên
			searchFullName();
			break;
		default:
			break;
		}
	} while (choice != 0);
}

void runReaderManagement(int typeAccount)
{
	switch(typeAccount){
		case 1:
			runReaderManagementForAdmin();
			break;
		case 2:
			runReaderManagementForExpert();
			break;
		default:
			runReaderManagementManager();
			break;
	}
}