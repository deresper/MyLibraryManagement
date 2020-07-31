#pragma once

void resizeConsole(int width, int height); // Thay đổi kích thước console

void Menu(int &typeAccount); // giao diện màn hình chính
void launch(); // Khởi chạy chương trình

int printLoginMenu();
void printfMainMenu();

void showTitleUser();
int printUserMenu(int typeAccount);

void showTitleReader();
int printfMenuReaderManagementForAdmin();
int printfMenuReaderManagementForExpert();
int printfMenuReaderManagementForManager();
int editInfReaderMenu();

void showTitleBook();
int printfMenuBookManagementForAdmin();
int printfMenuBookManagementForExpert();
int printfMenuBookManagementForManager();
int editInfBookMenu();

int askYesNoQuestion(char *note);

void showTitleAnalyzing();
int analyzingMenuForAdmin();
int analyzingMenuForExpert();
int analyzingMenuManager();

void showTitleHeader();

void showTitleBorrow();
void showTitleReturn();

// hiển thị tiêu đề sub meunu
void showTitleAnalyzingBooks();
void showTitleAnalyzingCato();
void showTitleAnalyzingReaders();
void showTitleAnalyzingSex();
void showTitleAnalyzingBorrowBook();
void showTitleAnalyzingOverdue();
void showTitleOverdue();
void showTitleListBook();
void showTitleCategory();
void showTitleListReader();
void showTitleMaleReader();
void showTitleFemaleReader();
void showTitleListBorrowing();

// Hiển thị tiêu đề chức năng 2
void showTitleViewReader();
void showTitleAddNewReader();
void showTitleEditReader();
void showTitleAfterEditReader();
void showTitleDeleteReader();
void showTitleFindReaderByNationId();
void showTitleFindReaderByName();

// Hiển thị tiêu đề chức năng 1
void showTitleCreatUser();
void showTitleDecentraliseUser();
void showTitleChangePassUser();
void showTitleStatusUser();
void showTitleAfterEditUser();

// Hiển thị tiêu đề chức năng 3
void showTitleViewBook();
void showTitleAddNewBook();
void showTitleEditBook();
void showTitleAfterEditBook();
void showTitleDeleteBook();
void showTitleFindBookByISBN();
void showTitleFindBookByName();