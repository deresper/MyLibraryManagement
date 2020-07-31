#pragma once

bool askToPrintAllBook(LLNodeBook lsbook); // In danh sách sách
void analyzingBook(); // Thống kế sách

bool askToPrintAllCato(LLNodeCategory lsCate); // In danh sách thể loại
void analyzingCatoBook(); // Thống kê thể loại

bool askToPrintAllReader(LLNodeReader lsreader); // In danh sách độc giả 
void analyzingReader(); // Thống kê độc giả

bool askToPrintAllSexReader(LLNodeReader lsMaleReader, LLNodeReader lsFemaleReader); // In danh sách độc giả theo giới tính
void analyzingSexReader(); // Thống kê độc giả theo giới tính

bool askToPrintAllBorrowingBook(LLNodeBorrowBook lsBorBook); // In danh sách sách mượn
void analyzingBorrowingBook(); // Thống kê sách mượn

bool askToPrintAllOverdueReader(LLNodeBorrowBook lsBorBook); // In danh sách độc giả trễ hạn
void analyzingOverdueReader(); // Thống kê độc giả trễ hạn

void runningAnalyzingForAdmin(); // Chạy chức năng thống kê với phần quyền Admin
void runningAnalyzingForExpert(); // Chạy chức năng thống kê với phần quyền Expert
void runningAnalyzingForManager(); // Chạy chức năng thống kê với phần quyền Manager
void runningAnalyzing(int typeAccount); // Chạy chức năng thống kê