#include "LibraryManagement.h"

// << Hàm khởi tạo danh sách và node
void Init(LLNodeBook &ls)
{
	ls.head = NULL;
	ls.tail = NULL;
	ls.total = 0;
}

// Tạo 1 Node chứa data
NodeBook *makeNode(Books data){
	NodeBook *no = new NodeBook;
	no->book = data;
	no->next = NULL;
	no->prev = NULL;

	return no;
}


NodeBook* addAtTail(LLNodeBook &ls, Books data){ // Thêm vào cuối danh sách một struct >> Books
	NodeBook *no = makeNode(data);
	if (no == NULL)
	{
		return NULL;
	}

	// Tạo liên kết
	no->prev = ls.tail;
	no->next = NULL;
	if (ls.tail == NULL) // nếu danh sách rỗng
	{
		ls.head = no;
	}
	else {
		ls.tail->next = no;
	}
	ls.tail = no;
	ls.total += data.numBook;

	return no;
}


void freeLinkListBook(LLNodeBook &ls)
{
	NodeBook *p = ls.head;
	while (p != NULL)
	{
		NodeBook *q = p;
		p = p->next;
		delete q;
	}
	ls.head = NULL;
	ls.tail = NULL;
}

