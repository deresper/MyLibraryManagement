﻿#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAX_CHOICE  7
#define _MAX_DAY_EXPIRES_ 1462
#define _F_GOI_TINH_ int sex (sex == 1 ? (char*)"Nam" : (char*)"Nu")

#define gets gets_s

#define _NAME_FILE_READER_ "databaseReader.bin"

#define _DIR_DATA_FOLDER_READER "Database/Reader/databaseReader.bin"
#define _DIR_DATA_FOLDER_READER_TEMP "Database/Reader/readerTemp.bin"

#define _DIR_DATA_FOLDER_USER_CUR "Database/Current/currentUser.bin"
#define _DIR_DATA_FOLDER_USER_TEMP "Database/Users/userTemp.bin"
#define _DIR_DATA_FOLDER_USER "Database/Users/Users.bin"

#define _DIR_DATA_FOLDER_BOOK "Database/Book/databaseBook.bin"
#define _DIR_DATA_FOLDER_BOOK_TEMP "Database/Book/bookTemp.bin" 

#define _DIR_DATA_FOLDER_BOOK_BORROW "Database/BorrowBook/databaseBorrowBook.bin"
#define _DIR_DATA_FOLDER_BOOK_BORROW_TEMP "Database/BorrowBook/databaseBorrowBookTemp.bin"

#define _SO_TIEN_PHAT 5000
#define _SO_PHAN_TRAM_PHAT_KHI_MAT 2
#define _SO_LUONG_CHU_SO_TIEN_MAT 18

#define cls "cls"
#include <tchar.h>
#include "time.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

// Nguồn tham khảo: https://en.cppreference.com/w/cpp/language/enum
enum Color // Kiểu liệt kê
{
	BLACK,
	BLUE,
	GREEN,
	AQUA,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTAQUA,
	LIGHTRED,
	LIGHTPURPLE,
	LIGHTYELLOW,
	LIGHTWHITE,
};

struct Day
{
	int Date; 
	int Month;
	int Year;
};

struct Users // Cấu trúc thông tin người dùng
{
	char Username[21]; // Username tối đa 20 ký tự
	char Password[17]; // Password tối đa 16 ký tự
	char Fullname[31]; // Họ tên người dùng tối đa 30 ký tự 
	Day Birthday; 
	char NationID[13]; // CMND gồm 9 số hoặc 12 số
	char Address[101]; // Địa chỉ người dùng tối đa 100 ký tự
	int Sex; // 0: Giới tính nữ; 1: Giới tính nam
	bool Status; // Nếu Status = 1: Actived; Status = 0: Blocked
	int typeAccount; // 1 nếu là admin; 2 nếu là chuyên viên (Expert); 3 nếu là quản lý (Manager)
};

struct Readers // Cấu trúc thông tin độc giả
{
	char ID[9]; // Mã độc giả gồm 8 chữ số.
	char Fullname[31]; // Họ tên người dùng tối đa 30 ký tự  
	char NationID[13]; // CMND gồm 9 số hoặc 12 số
	Day Birthday;
	int Sex; // 0: Giới tính nữ; 1: Giới tính nam
	char Email[101]; // Email dài tối đa 100 ký tự
	char Address[101]; // Địa chỉ người dùng tối đa 100 ký tự
	Day creatCard; // Ngày lập thẻ
	Day expireCard; // Ngày hết hạn thẻ
};

struct Books
{
	char ISBN[14]; // Mã sách gồm 13 số
	char nameBook[51]; // Tên sách tối đa 50 ký tự
	char Author[51]; // Tên tác giả tối đa 50 ký tự
	char publishCompany[51]; // Tên nhà xuất bản tối đa 50 ký tự
	int yearPublish; // Năm xuất bản
	char Category[41]; // Thể loại
	long priceBook; // Giá sách (VNĐ)
	int numBook; // Số lượng sách
};

struct BorrowBooks
{
	char ID[9]; // Mã độc giả mượn sách
	char Fullname[31]; // Tên độc giả
	char ISBN[14]; // Mã sách gồm 13 số
	char nameBook[51]; // Tên sách
	int numBook; // Số lượng sách mượn
	Day borrowBookDay; // Ngày mượn sách
	Day returnBookDay; // Ngày trả sách dự kiến
};

// DANH SÁCH LIÊN KẾT CỦA CÁC CẤU TRÚC CẦN LƯU
//					||
//					||	
//					||
//					||
//                  \/ 
struct NodeReader
{
	Readers reader;
	NodeReader *next;
	NodeReader *prev;
};

struct LLNodeReader
{
	NodeReader *head;
	NodeReader *tail;
	int total;
};

struct NodeBook
{
	Books book;
	NodeBook *next;
	NodeBook *prev;
};

struct LLNodeBook
{
	NodeBook *head;
	NodeBook *tail;
	int total;
};

struct NodeBorrowBook
{
	BorrowBooks brBook;
	NodeBorrowBook *next;
	NodeBorrowBook *prev;
};

struct LLNodeBorrowBook
{
	NodeBorrowBook *head;
	NodeBorrowBook *tail;
	int total;
};

struct NodeCategory
{
	char Category[41];
	int numBookPerCategory;
	NodeCategory *next;
	NodeCategory *prev;
};

struct LLNodeCategory
{
	NodeCategory *head;
	NodeCategory *tail;
	int total;
};