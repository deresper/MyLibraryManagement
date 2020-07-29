#pragma once
// << Hàm khởi tạo danh sách và node Readers

void Init(LLNodeReader &ls);
NodeReader *makeNode(Readers data);
NodeReader* addAtTail(LLNodeReader &ls, Readers data); // Thêm vào cuối danh sách một struct >> Readers
void freeLinkListReader(LLNodeReader &ls);

