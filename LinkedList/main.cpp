#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include <iostream>
//单链表
static void testLinkedListFunc() {
	LinkList L{};
	ElemType e{};
	Status ret{};
	int j{}, k{};
	ret = InitList(&L);
	std::cout << "初始化的长度：" << ListLength(&L) << std::endl;
	ret = IsListEmpty(&L);
	std::cout << "是否为空：(1:是 0:否) " << ret << std::endl;
	for (j = 1; j < 6; j++) {
		ret = ListInsert(&L, 1, j);
	}
	std::cout << "插入一个元素之后:\n";
	ListTraverse(&L);
	ret = IsListEmpty(&L);
	std::cout << "是否为空：(1:是 0:否) " << ret << std::endl;
	ret = ClearList(&L);
	std::cout << "清空后的长度：" << ListLength(&L) << std::endl;
	ret = IsListEmpty(&L);
	std::cout << "是否为空：(1:是 0:否) " << ret << std::endl;

	for (j = 1; j < 11; j++) {
		ret = ListInsert(&L, j, j);
	}
	std::cout << "再次插入元素之后的长度：" << ListLength(&L) << std::endl;
	ListTraverse(&L);

	GetItem(&L, 5, e);
	std::cout << "第五个元素为：" << e << std::endl;
	k = ListLength(&L);
	for (j = k + 1; j >= k; j--) {
		ret = ListDelete(&L, j, e);
		if (ret == ERROR) {
			std::cout << "删除第" << j << "个元素失败\n";
		}
		else {
			std::cout << "删除第" << j << "个元素成功，且值为：" << e << std::endl;
		}
	}
	std::cout << "删除之后：\n";
	ListTraverse(&L);
	ret = ListDelete(&L, 5, e);
	if (ret == ERROR) {
		std::cout << "删除第" << j << "个元素失败\n";
	}
	else {
		std::cout << "删除第" << 5 << "个元素成功，且值为：" << e << std::endl;
	}
	std::cout << "删除之后：\n";
	ListTraverse(&L);

	ClearList(&L);

	//头插法
	CreateListHead(&L, kMaxSize);
	std::cout << "从头部创建:\n";
	ListTraverse(&L);
	ClearList(&L);
	//尾插法
	CreateListTail(&L, kMaxSize);
	std::cout << "从尾部创建:\n";
	ListTraverse(&L);
	ClearList(&L);
	free(L);
}
//双链表
static void testDoubleLinkedListFunc() {
	int index{};
	ElemType e{};
	DoubleLinkedList L{};
	std::cout << "请输入节点的数据，输入-1表示终止\n";
	L = InitList();
	std::cout << "双链表的长度：" << ListLength(L) << std::endl;
	Print(L);
	std::cout << "请输入想要知道的第几个位置：";
	std::cin >> index;
	GetElemByIndex(L, index, e);
	std::cout << "该位置上的数为：" << e << std::endl;
	std::cout << "请输入想要知道的链表是否存在该元素的值：";
	std::cin >> e;
	GetItem(L, e);
	std::cout << "请输入想在第几个位置插入元素：";
	std::cin >> index;
	std::cout << "请输入该元素的值：";
	std::cin >> e;
	ListInsert(L, index, e);
	Print(L);

	std::cout << "请输入想要删除的节点位置：";
	std::cin >> index;
	ListDelete(L, index);
	Print(L);

	ListClear(L);
	std::cout << "清空之后的双链表的长度:" << ListLength(L) << std::endl;
}
int main()
{
#if 0
	testLinkedListFunc();
#endif
	testDoubleLinkedListFunc();
	return 0;
}