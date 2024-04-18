#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using Status = int;
using ElemType = int;
constexpr int kMaxSize = 20;
constexpr int OK = 1;
constexpr int ERROR = -1;
constexpr int TRUE = 1;
constexpr int FALSE = -1;
Status Visit(ElemType e);
typedef struct Node {
	ElemType data;
	struct Node* next = nullptr;
}Node,*LinkList;
static Status Visit(ElemType e);
extern Status InitList(LinkList* L);
extern Status IsListEmpty(LinkList* L);
extern Status ClearList(LinkList* L);
extern ElemType ListLength(LinkList* L);
extern Status GetItem(LinkList* L, int index, ElemType& e);
extern ElemType LocateElem(LinkList* L, ElemType& e);
extern Status ListInsert(LinkList* L, int index, ElemType& e);
extern Status ListDelete(LinkList* L, int index, ElemType& e);
extern Status ListTraverse(LinkList* L);
extern Status CreateListHead(LinkList* L, int n);
extern Status CreateListTail(LinkList* L, int n);
#endif // !LINKEDLIST_H