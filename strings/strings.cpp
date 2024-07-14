// strings.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "StringMethod.h"
#include <stdio.h>
#include <iostream>
static decltype(auto) testString() {
	Status k{};
	String t{}, s1{}, s2{};
	char s{};
	int i{}, j{}, ret = 0;
	k = StrAssign(s1, "abcd");
	if (k == FALSE) {
		printf("创建字符串失败!\n");
		return -1;
	}
	printf("串长度：%d 是否为空:%s\n", StrLength(s1), StrEmpty(s1) ? "空" : "非空");
	StrCopy(s2, s1);
	std::cout << "复制s1到s2:\n";
	PrintStr(s2);
	StrAssign(s2, "who care you?");
	ret = StrCompare(s1, s2);
	s = '=';
	if (ret < 0)      s = '<';
	else if (ret > 0) s = '>';
	std::cout << "串s1：" << s << " 串s2。\n";
	Concat(t, s1, s2);
	std::cout << "拼接串的结果：";
	PrintStr(t);
	if (ret == FALSE)
		std::cout << "串t有截断\n";
	ClearString(s1);
	std::cout << "清理s1之后,s1为：";
	PrintStr(s1);
	printf("串长度：%d 是否为空:%s\n", StrLength(s1), StrEmpty(s1) ? "空" : "非空");

	i = 2, j = 3;
	ret = SubString(s1, t, i, j);//从拼接的字符串t的i位置处获取长度为j的子串
	if (ret) {
		PrintStr(s1);
	}

	i = 4, j = 2;
	StrDelete(t, i, j);
	std::cout << "删除子串t之后:";
	PrintStr(t);
	i = 2;
	std::cout << "插入之前，s2为：";
	PrintStr(s2);
	StrInsert(s2, i, t);
	std::cout << "插入之后，s2为：";
	PrintStr(s2);
	auto index = Index(s2, t, 1);
	std::cout << "s2的第" << index << "个字符起和t第一次匹配\n";
	StrReplace(s2, t, s1);//将s2中的t子串替换成s1
	std::cout << "替换之后，s2为：";
	PrintStr(s2);
	ClearString(s1);
	ClearString(s2);
	ClearString(t);
	std::cout << "清理之后，分别为：\n";
	PrintStr(s1);
	PrintStr(s2);
	PrintStr(t);
	StrAssign(s1, "121241234234324");
	StrAssign(s2, "1212");
	index = IndexKMP(s1, s2, 1);
	std::cout << "index_kmp :" << index << std::endl;
	StrAssign(s2, "23465");
	index = IndexKMP(s1, s2, 1);
	std::cout << "index_kmp :" << index << std::endl;
	return 0;
}
int main()
{
	testString();
}