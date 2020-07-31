#include "LibraryManagement.h"

// << Hàm khởi tạo danh sách và node
void Init(LLNodeReader &ls)
{
	ls.head = NULL;
	ls.tail = NULL;
	ls.total = 0;
}

// Tạo 1 Node chứa data
NodeReader *makeNode(Readers data){
	NodeReader *no = new NodeReader;
	no->reader = data;
	no->next = NULL;
	no->prev = NULL;

	return no;
}

NodeReader* addAtTail(LLNodeReader &ls, Readers data){ // Thêm vào cuối danh sách một struct >> Readers
	NodeReader *no = makeNode(data);
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
	ls.total++;

	return no;
}

void freeLinkListReader(LLNodeReader &ls)
{
	NodeReader *p = ls.head;
	while (p != NULL)
	{
		NodeReader *q = p;
		p = p->next;
		delete q;
	}
	ls.head = NULL;
	ls.tail = NULL;

}
