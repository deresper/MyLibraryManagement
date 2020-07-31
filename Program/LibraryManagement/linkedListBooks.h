#pragma once

// Khởi tạo danh sách Books và Node Books
void Init(LLNodeBook &ls);
NodeBook *makeNode(Books data);
NodeBook* addAtTail(LLNodeBook &ls, Books data); // Thêm vào cuối danh sách một struct >> Books
void freeLinkListBook(LLNodeBook &ls);

