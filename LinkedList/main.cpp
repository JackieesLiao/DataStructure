#include "LinkedList.h"
#include <iostream>

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

int main()
{
	testLinkedListFunc();
	return 0;
}