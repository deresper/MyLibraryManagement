#include "LibraryManagement.h"

// << Hàm khởi tạo danh sách và node
void Init(LLNodeCategory &ls)
{
	ls.head = NULL;
	ls.tail = NULL;
	ls.total = 0;
}

// Tạo 1 Node chứa data
NodeCategory *makeNode(char* Category, int numBookPerCategory){
	NodeCategory *no = new NodeCategory;
	strcpy(no->Category, Category);
	no->numBookPerCategory = numBookPerCategory;
	no->next = NULL;
	no->prev = NULL;

	return no;
}

//======================================================

NodeCategory* addAtTail(LLNodeCategory &ls, char *Category, int numBookPerCategory){ // Thêm vào cuối danh sách một struct >> Books
	NodeCategory *no = makeNode(Category, numBookPerCategory);
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

void freeLinkListBook(LLNodeCategory &ls)
{
	NodeCategory *pNow = ls.head;
	while (pNow != NULL)
	{
		NodeCategory *pDel = pNow;
		pNow = pNow->next;
		delete pDel;
	}
	ls.head = NULL;
	ls.tail = NULL;
}

//=============================================================================================
//=============================================================================================

bool addBooksToExistCategory(LLNodeCategory &ls, char *Category, int numBookPerCategory){
	NodeCategory *pNow = ls.head;
	while (pNow != NULL)
	{
		if (strcmp(pNow->Category, Category) == 0)
		{
			pNow->numBookPerCategory += numBookPerCategory;
			return true;
		}

		pNow = pNow->next;
	}
	return false;
}
