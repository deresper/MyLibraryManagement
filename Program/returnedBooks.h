#pragma once

bool findListBorrowedWithIDPerson(char *personID, LLNodeBorrowBook &lsBB);	// Tìm kiếm đọc giả theo id trả về danh sách
void returnBookBill(char *nameReader, char *nameBook, int numBor, int numRet, long moneyPayement); // hóa đơn trả sách
bool returnNumberBorrwedBook(char *isbnBook, int numRet); // trả lại kho số sách đã mượn trước đó
void returnBook(); // khởi chạy chức năng trả sách

