#include "LinkedList.h"
#include <iostream>

static void testLinkedListFunc() {
	LinkList L{};
	ElemType e{};
	Status ret{};
	int j{}, k{};
	ret = InitList(&L);
	std::cout << "��ʼ���ĳ��ȣ�" << ListLength(&L) << std::endl;
	ret = IsListEmpty(&L);
	std::cout << "�Ƿ�Ϊ�գ�(1:�� 0:��) " << ret << std::endl;
	for (j = 1; j < 6; j++) {
		ret = ListInsert(&L, 1, j);
	}
	std::cout << "����һ��Ԫ��֮��:\n";
	ListTraverse(&L);
	ret = IsListEmpty(&L);
	std::cout << "�Ƿ�Ϊ�գ�(1:�� 0:��) " << ret << std::endl;
	ret = ClearList(&L);
	std::cout << "��պ�ĳ��ȣ�" << ListLength(&L) << std::endl;
	ret = IsListEmpty(&L);
	std::cout << "�Ƿ�Ϊ�գ�(1:�� 0:��) " << ret << std::endl;

	for (j = 1; j < 11; j++) {
		ret = ListInsert(&L, j, j);
	}
	std::cout << "�ٴβ���Ԫ��֮��ĳ��ȣ�" << ListLength(&L) << std::endl;
	ListTraverse(&L);

	GetItem(&L, 5, e);
	std::cout << "�����Ԫ��Ϊ��" << e << std::endl;
	k = ListLength(&L);
	for (j = k + 1; j >= k; j--) {
		ret = ListDelete(&L, j, e);
		if (ret == ERROR) {
			std::cout << "ɾ����" << j << "��Ԫ��ʧ��\n";
		}
		else {
			std::cout << "ɾ����" << j << "��Ԫ�سɹ�����ֵΪ��" << e << std::endl;
		}
	}
	std::cout << "ɾ��֮��\n";
	ListTraverse(&L);
	ret = ListDelete(&L, 5, e);
	if (ret == ERROR) {
		std::cout << "ɾ����" << j << "��Ԫ��ʧ��\n";
	}
	else {
		std::cout << "ɾ����" << 5 << "��Ԫ�سɹ�����ֵΪ��" << e << std::endl;
	}
	std::cout << "ɾ��֮��\n";
	ListTraverse(&L);

	ClearList(&L);

	//ͷ�巨
	CreateListHead(&L, kMaxSize);
	std::cout << "��ͷ������:\n";
	ListTraverse(&L);
	ClearList(&L);
	//β�巨
	CreateListTail(&L, kMaxSize);
	std::cout << "��β������:\n";
	ListTraverse(&L);
	ClearList(&L);
	free(L);
}

int main()
{
	testLinkedListFunc();
	return 0;
}