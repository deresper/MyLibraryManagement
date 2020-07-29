#pragma once

Readers *findReaderWithNationID(char *personID);	// Tìm kiếm độc giả theo CMND
Readers *findReaderWithEmail(char *Email); // Tìm kiếm độc giả theo Email
Readers *findReaderWithID(char *ID);	// Tìm kiếm độc giả theo ID
bool findListReaderWithName(char *personName, LLNodeReader &lsReader); // Tìm kiếm đọc giả theo họ tên và thêm vào danh sách
void viewAllReader(); // xem thông tin độc giả trong thư viện
bool printReaderFromLL(LLNodeReader ls); // in ra thông tin độc giả từ Linked List
Readers addReader(); // Thêm độc giả 
int askToUpdateReaderToFile(); // hỏi xem có muốn cập nhật hay không
bool writeInfReaderToFile(); // cập nhật thông tin độc giả vào file
void viewInfAReader(Readers reader); // Xem thông tin của một người cụ thể
bool editReader(Readers &reader); // chỉnh sửa thông tin độc giả 
void editReaderToFile(); // chỉnh sửa thông tin độc giả qua mã độc giả
void deleteReaderToFile(); // xóa thông tin độc giả qua mã độc giả 
void searchNationID(); // Tìm kiếm qua CMND
void searchFullName(); // Tìm kiếm qua tên độc giả
void runReaderManagement(int typeAccount); // khởi chạy quản lý đọc giả

