// LinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "LinkedList.h"
#include <memory>
#include <iostream>
static Status Visit(ElemType e) {
	std::cout << "elements: " << e << " ";
	return OK;
}
Status InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if (*L == nullptr) {
		return ERROR;
	}
	(*L)->data = 0;
	(*L)->next = nullptr;
	return OK;
}
Status IsListEmpty(LinkList* L) {
	return ((*L)->next == nullptr) ? TRUE : FALSE;
}
Status ClearList(LinkList* L) {
	LinkList p{}, q{};
	p = (*L)->next;
	while (p != nullptr) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = nullptr;
	return OK;
}
/// <summary>
/// 统计链表长度
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
ElemType ListLength(LinkList* L) {
	auto length = 0;
	LinkList p = (*L)->next;
	while (p) {
		length++;
		p = p->next;
	}
	return length;
}
/// <summary>
/// 获取指定元素
/// </summary>
/// <param name="L">链表</param>
/// <param name="index">元素位置</param>
/// <param name="e">元素</param>
/// <returns></returns>
Status GetItem(LinkList* L, int index, ElemType& e)
{
	auto j = 1;
	LinkList p{};
	p = (*L)->next;
	while (p && j < index) {
		p = p->next;
		j++;
	}
	//未找到
	if (p == nullptr || j > index) {
		return ERROR;
	}
	e = p->data;
	return OK;
}
ElemType LocateElem(LinkList* L, ElemType& e)
{
	auto i = 0;
	LinkList p = (*L)->next;
	while (p) {
		i++;
		if (p->data == e) {
			return i;
		}
		p = p->next;
	}
	return 0;
}
Status ListInsert(LinkList* L, int index, ElemType& e)
{
	auto j = 1;
	LinkList p{}, s{};
	p = (*L);//指向头节点
	//从头遍历到指定index位置处
	while (p && (j < index)) {
		p = p->next;
		++j;
	}
	if (!p || j > index)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	if (s == nullptr)
		return ERROR;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList* L, int index, ElemType& e)
{
	auto j = 1;
	LinkList p{}, s{};
	p = (*L);//指向头节点
	//从头遍历到指定index位置处
	while (p && (j < index)) {
		p = p->next;
		++j;
	}
	if (!p || j > index)
		return ERROR;
	s = p->next;
	if (s == nullptr)
		return ERROR;
	p->next = s->next;
	e = s->data;
	free(s); 
	return OK;
}

Status ListTraverse(LinkList* L)
{
	LinkList p = (*L)->next;
	while (p) {
		Visit(p->data);
		p = p->next;
	}
	std::cout << "\n";
	return OK;
}
/// <summary>
/// 头插法
/// </summary>
/// <param name="L"></param>
/// <param name="n"></param>
Status CreateListHead(LinkList* L, int n)
{
	LinkList p{};
	auto i = 0;
	srand((unsigned)time(nullptr));
	*L = (LinkList)malloc(sizeof(Node));
	if (*L == nullptr) {
		return ERROR;
	}
	(*L)->next = nullptr;
	for (; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		if (p == nullptr) {
			return ERROR;
		}
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;  //1.新创建的节点指向头节点指向的第一个节点
		(*L)->next = p;        //2.由于头节点永远指向第一个节点，则其指向新创建的节点
	}
	return OK;
}
/// <summary>
/// 尾插法
/// </summary>
/// <param name="L"></param>
/// <param name="n"></param>
Status CreateListTail(LinkList* L, int n)
{
	LinkList p{}, r{};
	auto u{ 0 };
	srand((unsigned)time(nullptr));
	*L = (LinkList)malloc(sizeof(Node));
	if (*L == nullptr) {
		return ERROR;
	}
	(*L)->next = nullptr;
	r = *L;           //r指向头节点
	for (; u < n; u++) {
		p = (LinkList)malloc(sizeof(Node));
		if (p == nullptr) {
			return ERROR;
		}
		p->data = rand() % 100 + 1;
		r->next = p;  //r指向新节点
		r = p;        //r不断更新指向使得保持每次添加新节点均为追加到尾部方式
	}
	r->next = nullptr;//插入到最后置空
	return OK;
}