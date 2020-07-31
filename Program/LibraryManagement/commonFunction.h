#pragma once

void textBgColor(int colorText, int colorBG); // Thay đổi màu nền và màu chữ
void stopSceen(); // dừng màn hình
int getNumberPressKey(int MAX, int MIN); // kiếm tra người dùng có nhấn phím không
bool isLeapYear(int Year); // kiểm tra năm nhuận
int numDaysOfMonth(int Month, int Year); // số ngày của tháng
bool isPossibleDay(int Day, int Month, int Year); // kiểm tra tính hợp lệ của ngày

void encryptPassword(char *name); // Mã hóa mật khẩu thành dấu *

void getUsername(char username[]); // Nhập username
void getBirthday(Day &birthday); // nhập ngày sinh
void getNationalID(char nationID[]); // Nhập CMND người dùng
void getSex(int &sex); //  Nhập giới tính người dùng
void getStatus(bool &status); // Nhập trạng thái người dùng
void getTypeAccount(Users &A); // Nhập phân quyền người dùn
void getReaderID(char ID[]); // Nhập mã đọc giả
void getISBN(char *ISBN); // Nhập ISBN sách

int wantEdit(); // hỏi có muốn chỉnh sửa nữa không?
int wantBorrow(); // hỏi có muốn mượn sách nữa không?

char *toStr(long n); // chuyển số sang chuỗi

Day getExpiredDay(Day orginDay); // tạo ngày hết hạn
Day getToday(); // lấy ngày hệ thống
bool isNumber(char c); // kiểm tra phải là số hay không?
Day getDayFrmUser();  
void printfDay(Day day);

char *getStringFrmUser(char *note);
int getNumber(char *note);

int plusOneIntoAChar(char &numch);
bool plusOneIntoAString(char *numStr);

int toDays(Day dayt);

int operator-(Day d1, Day d2); // nạp chồng toán tử -
bool operator==(Day d1, Day d2); // nạp chồng toán tử == 
bool operator==(BorrowBooks borBook1, BorrowBooks borBook2);
char *intMoneyToStringMoney(long moneyPayement);
