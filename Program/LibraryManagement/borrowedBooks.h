#pragma once

Day returnBookExpectDay(Day borrowBookDay); // trả về ngày trả sách dự kiến (7 ngày kể từ ngày mượn)
bool possibleReader(Day expiredDay); // Thẻ độc giả còn hạn hay không? - 1 còn hạn; 0 là hết hạn
void updateBookFile(Books book); // cập nhật sách vào file
void borrowBookBill(char *ID, char *Fullname); // Phiếu mượn sách
void borrowBook(); // Khởi chạy chức năng mượn sách
bool checkBookIsBorrowed(BorrowBooks borBook); // Kiếm tra có đúng sách mượn không?

