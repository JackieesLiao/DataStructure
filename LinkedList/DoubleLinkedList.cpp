#include "DoubleLinkedList.h"
#include <iostream>
/// <summary>
/// ��ʼ��˫������
/// </summary>
/// <returns>����ͷ�ڵ�</returns>
DoubleLinkedList InitList()
{
	int data{}, size{0};
	DoubleLinkedList L{}, Last{}, p{};
	L = (DoubleLinkedList)malloc(sizeof(DoubleNode));
	L->prior = nullptr;
	L->next = nullptr;
	Last = L;                   //1.Lastָ��ָ��ͷ�ڵ�
	std::cout << "��ǰ�����С:" << size << std::endl;
	std::cout << "������ڵ�ֵ(����-1��ʾ�������):\n";
	while (true) {
		if (std::cin >> data) {
			//if (data != 1) break;
			if (data == -1) break;
			p = (DoubleLinkedList)malloc(sizeof(DoubleNode));
			if (p == nullptr) {
				std::cout << "�ڴ治�㣬ֹͣ����\n";
				break;
			}
			p->data = data;    //�洢�ڵ�ֵ
			Last->next = p;    //2.Lastָ���½ڵ�
			p->prior = Last;   //3.�½ڵ��ǰ��ָ��ָ��Last
			p->next = nullptr; //4.�½ڵ�ĺ��ָ��ָ���
			Last = p;          //5.�½ڵ��ΪLast���������������
		}
	}
	Last->next = nullptr;      //6.������ɺ���Lastָ��β��
	return L;                  //����ͷ�ڵ�
}
/// <summary>
/// ��
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
ElemType ListLength(DoubleLinkedList L)
{
	auto length{ 0 };
	if (L == nullptr || L->next == nullptr) return 0;//ͷ�ڵ�Ϊ�ջ���ֻ��һ��ͷ�ڵ�
	while (L->next) {//���ڳ���ͷ�ڵ�֮��Ľڵ�
		L = L->next;
		length++;
	}
	return length;
}
/// <summary>
/// ��ȡԪ��λ��
/// </summary>
/// <param name="L"></param>
/// <param name="e"></param>
/// <returns></returns>
Status GetItem(DoubleLinkedList L, ElemType e)
{
	auto index{ 1 };
	auto found{ 0 };
	if (L == nullptr || L->next == nullptr) return ERROR;//ͷ�ڵ�Ϊ�ջ���ֻ��һ��ͷ�ڵ�
	L = L->next;//�ӵ�һ���ڵ㿪ʼ����
	do{
		if (L->data == e) {
			std::cout << "�ҵ�ָ���ڵ㣬λ����" << index << std::endl;
			found = 1;
		}
		L = L->next;
		index++;
	} while (L->next);
	if (found == 0) {
		std::cout << "δ�ҵ�ָ��Ԫ��\n";
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
/// ˫���������
/// </summary>
/// <param name="L"></param>
/// <param name="index"></param>
/// <param name="e"></param>
/// <returns>����״̬���ɹ���ʧ��</returns>
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
	insert_node->next = L->next;//1.�²���Ľڵ�ָ��ͷ�ڵ�ĺ�̽ڵ�
	insert_node->prior = L;     //2.�²���Ľڵ��ǰ��ָ��ָ��ͷ�ڵ�
	if (L->next) {              //���L�ĺ�̽ڵ㲻Ϊ��
		L->next->prior = insert_node;//3.ͷ�ڵ�ĺ�̽ڵ��ǰ��ָ��ָ���²���Ľڵ�
	}
	L->next = insert_node;      //4.ͷ�ڵ�ĺ��ָ��ָ���²���Ľڵ�
	return OK;
}
/// <summary>
/// ˫������ɾ��
/// </summary>
/// <param name="L"></param>
/// <param name="index"></param>
/// <returns>ɾ��״̬���ɹ���ʧ��</returns>
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
	//1.����Ҫɾ����Ԫ�ص�ǰһ���ڵ�ĺ��ָ��ָ�򱾽ڵ�ĺ�̽ڵ�
	L->prior->next = L->next;
	if (L->next) {
		L->next->prior = L->prior;//2.����Ҫɾ����Ԫ�صĺ�̽ڵ��ǰ��ָ��ָ�򱾽ڵ��ǰһ���ڵ�
	}
	free(L);
	return OK;
}
/// <summary>
/// �������
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
