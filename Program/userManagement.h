#pragma once

// CHỨC NĂNG 1.1 VÀ 1.2 - ĐĂNG NHẬP, ĐĂNG XUẤT
int checkLogin(char *Username, char *Password); //  Kiểm tra Username và Password có trong database hay không? 
void Logout(int &typeAccount); // Hàm đăng xuất
void Menu(int &typeAccount);
int Login(); // Hàm đăng nhập


// CHỨC NĂNG 1.5 - TẠO NGƯỜI DÙNG
bool checkUsername(char *Username); // Kiểm tra Username đã tồn tại hay chưa?
Users addUser(); // Nhập các thông tin về User
void writeInfUsertoFile(); // Ghi thông tin User vào file.
void getUser(); // Tạo User

// CHỨC NĂNG 1.3 - ĐỔI MẬT KHẨU
void updateFile(Users curUser); // Cập nhật lại file khi đã cập nhật thông tin cá nhân
void changePassword(); // Đổi mật khẩu

// CHỨC NĂNG 1.4 - CẬP NHẬT THÔNG TIN CÁ NHÂN
void viewProfile(); // Xem thông tin cá nhân
void editProfile(); // Chỉnh sửa thông tin cá nhân

// CHỨC NĂNG 1.6 - PHÂN QUYỀN NGƯỜI DÙNG
void inforDecentraliseUser();
void decentraliseUser();

// CHỨC NĂNG CHỈNH SỬA TRẠNG THÁI NGƯỜI DÙNG: ACTIVATED / BLOCKED
void inforStatusUser();
void changeStatusUser();

// CHẠY MENU CHỨC NĂNG 1 - QUẢN LÝ NGƯỜI DÙNG
void runMenuUser(int typeAccount);