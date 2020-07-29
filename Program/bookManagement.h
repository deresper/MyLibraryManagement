#pragma once

Books *findBookWithISBN(char *ISBN);	// Tìm kiếm sách theo ISBN
void viewAllBook(); // xem thông tin sách trong thư viện
Books addBook(); // Thêm sách
int askToUpdateBookToFile(); // hỏi xem có muốn cập nhật không
bool writeInfBookToFile(); // ghi thông tin sách vào file
void viewInfABook(Books book); // Xem thông tin sách
bool editBook(Books &book); // chỉnh sửa sách
void editBookToFile(); // chỉnh sửa thông tin sách qua ISBN
void searchISBN(); // Tìm kiếm qua ISBN
void searchBookName(); // Tìm kiếm qua tên sách
void runBookManagementForAdmin();
void runBookManagementForExpert();
void runBookManagementForManager();
void runBookManagement(int typeAccount); // khởi chạy quản lý sách