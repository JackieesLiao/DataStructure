#include "DoubleLinkedList.h"
#include <iostream>
/// <summary>
/// 初始化双向链表
/// </summary>
/// <returns>链表头节点</returns>
DoubleLinkedList InitList()
{
	int data{}, size{0};
	DoubleLinkedList L{}, Last{}, p{};
	L = (DoubleLinkedList)malloc(sizeof(DoubleNode));
	L->prior = nullptr;
	L->next = nullptr;
	Last = L;                   //1.Last指针指向头节点
	std::cout << "当前链表大小:" << size << std::endl;
	std::cout << "请输入节点值(输入-1表示输入完成):\n";
	while (true) {
		if (std::cin >> data) {
			//if (data != 1) break;
			if (data == -1) break;
			p = (DoubleLinkedList)malloc(sizeof(DoubleNode));
			if (p == nullptr) {
				std::cout << "内存不足，停止操作\n";
				break;
			}
			p->data = data;    //存储节点值
			Last->next = p;    //2.Last指向新节点
			p->prior = Last;   //3.新节点的前驱指针指向Last
			p->next = nullptr; //4.新节点的后继指针指向空
			Last = p;          //5.新节点成为Last方便后续继续插入
		}
	}
	Last->next = nullptr;      //6.插入完成后让Last指向尾空
	return L;                  //返回头节点
}
/// <summary>
/// 表长
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
ElemType ListLength(DoubleLinkedList L)
{
	auto length{ 0 };
	if (L == nullptr || L->next == nullptr) return 0;//头节点为空或者只有一个头节点
	while (L->next) {//存在除了头节点之外的节点
		L = L->next;
		length++;
	}
	return length;
}
/// <summary>
/// 获取元素位置
/// </summary>
/// <param name="L"></param>
/// <param name="e"></param>
/// <returns></returns>
Status GetItem(DoubleLinkedList L, ElemType e)
{
	auto index{ 1 };
	auto found{ 0 };
	if (L == nullptr || L->next == nullptr) return ERROR;//头节点为空或者只有一个头节点
	L = L->next;//从第一个节点开始遍历
	do{
		if (L->data == e) {
			std::cout << "找到指定节点，位置在" << index << std::endl;
			found = 1;
		}
		L = L->next;
		index++;
	} while (L->next);
	if (found == 0) {
		std::cout << "未找到指定元素\n";
		return ERROR;
	}
	return OK;
}

ElemType GetElemByIndex(DoubleLinkedList L, int index, ElemType& e)
{
	auto i{ 0 };
	if (L == nullptr || L->next == nullptr || index < 1) return ERROR;
	while (L->next && i < index) {
		L = L->next;
		i++;
	}
	if (i == index) {
		e = L->data;
		return OK;
	}
	return ERROR;
}
/// <summary>
/// 双向链表插入
/// </summary>
/// <param name="L"></param>
/// <param name="index"></param>
/// <param name="e"></param>
/// <returns>插入状态：成功或失败</returns>
Status ListInsert(DoubleLinkedList L, int index, ElemType e)
{
	auto i{ 0 };
	auto length = ListLength(L);
	if ((L == nullptr) || (index > length + 1)|| (index < 0)) {
		return ERROR;
	}
	
	if (L->next != nullptr && (i < index-1)) {
		L = L->next;
		i++;
	}
	DoubleLinkedList insert_node = (DoubleLinkedList)malloc(sizeof(DoubleNode));
	insert_node->data = e;
	insert_node->next = L->next;//1.新插入的节点指向头节点的后继节点
	insert_node->prior = L;     //2.新插入的节点的前驱指针指向头节点
	if (L->next) {              //如果L的后继节点不为空
		L->next->prior = insert_node;//3.头节点的后继节点的前驱指针指向新插入的节点
	}
	L->next = insert_node;      //4.头节点的后继指针指向新插入的节点
	return OK;
}
/// <summary>
/// 双向链表删除
/// </summary>
/// <param name="L"></param>
/// <param name="index"></param>
/// <returns>删除状态：成功或失败</returns>
Status ListDelete(DoubleLinkedList L, int index)
{
	auto i{ 0 };
	auto length = ListLength(L);
	if (index <= 0 || (index > length)
		|| (L == nullptr) || (L->next == nullptr)) {
		return ERROR;
	}
	while (L->next && i < index) {
		L = L->next;
		i++;
	}
	//1.让需要删除的元素的前一个节点的后继指针指向本节点的后继节点
	L->prior->next = L->next;
	if (L->next) {
		L->next->prior = L->prior;//2.让需要删除的元素的后继节点的前驱指针指向本节点的前一个节点
	}
	free(L);
	return OK;
}
/// <summary>
/// 清空链表
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
Status ListClear(DoubleLinkedList& L)
{
	if (L == nullptr) return ERROR;
	DoubleLinkedList p = L;
	while (p->next) {
		p = p->next;
		free(p->prior);
	}
	free(p);
	L = nullptr;
	return OK;
}

void Print(DoubleLinkedList L)
{
	auto index{ 0 };
	while (L->next) {
		L = L->next;
		if (index > 0) std::cout << "->";
		std::cout <<L->data;
		index++;
	}
	std::cout << "\n";
}
