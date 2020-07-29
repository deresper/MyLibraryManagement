#pragma once

// << Hàm khởi tạo danh sách Books theo Category
void Init(LLNodeCategory &ls);

NodeCategory *makeNode(char *Category, int numBookPerCategory);
NodeCategory* addAtTail(LLNodeCategory &ls, char *Category, int numBookPerCategory); // Thêm vào cuối danh sách một struct >> Books
void freeLinkListBook(LLNodeCategory &ls);
bool addBooksToExistCategory(LLNodeCategory &ls, char *Category, int numBookPerCategory);