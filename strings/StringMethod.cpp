#include "StringMethod.h"
#include "string.h"
Status StrAssign(String T, const char* chars)
{
	auto len = strlen(chars);
	if (len > kMaxSize) return ERROR;
	T[0] = (char)len;
	for (auto i = 1; i <= len; i++) {
		T[i] = chars[i - 1];
	}
	return OK;
}
//字符数组第一个位置存放长度
Status StrCopy(String T, String S)
{
	for (auto i = 0; i <= S[0]; i++) {
		T[i] = S[i];
	}
	return OK;
}

Status StrEmpty(String S)
{
	return S[0] == 0 ? TRUE : FALSE;
}

int StrCompare(String T, String S)
{
	for (auto i = 1; (i <= T[0]) && (i <= S[0]); i++) {
		if (T[i] != S[i]) {
			return T[i] - S[i];
		}
	}
	return T[0] - S[0];//如果T串长度更大则大于0，相等则等于0，否则小于0
}

int StrLength(String S)
{
	return S[0] & 0xFF;
}

Status ClearString(String S)
{
	S[0] = 0;
	return OK;
}

Status Concat(String T, String S1, String S2)
{
	if ((int)(0xFF & S1[0]) + S2[0] <= kMaxSize) {
		T[0] = S1[0] + S2[0];//主串长度为两子串长度
		for (auto i = 1; i <= S1[0]; i++) {
			T[i] = S1[i];
		}
		for (auto i = 1; i <= S2[0]; i++) {
			T[S1[0]+i] = S2[i];
		}
		return TRUE;
	}
	//截断
	T[0] = kMaxSize;
	for (auto i = 1; i <= S1[0]; i++) {
		T[i] = S1[i];
	}
	for (auto i = 1; i <= kMaxSize - S1[0]; i++) {
		T[S1[0] + i] = S2[i];
	}
	return FALSE;
}
//子串
//Sub = S[pos:pos+len]
Status SubString(String Sub, String S, int pos, int len)
{
	if ((pos < 1) || (pos > S[0]) || (len < 0) || (len > S[0] - pos + 1)) {
		return ERROR;
	}
	for (auto i = 1; i <= len; i++) {
		Sub[i] = S[pos + i - 1];//如果不-1则从pos的下一个位置开始
	}
	Sub[0] = (char)len;
	return OK;
}
//朴素匹配
int Index(String S, String T, int pos)
{
	//两个串如果为空或者子串长度比主串大无法匹配
	if (S[0] == 0 || T[0] == 0 || T[0] > S[0] 
		|| pos <= 0 || pos > S[0]) return 0;
	int i = pos;//指向主串
	int j = 1;  //指向子串
	while (i <= S[0] && j <= T[0]) {
		if (S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2;//回退i指针指向上次遍历之后的最后一个字符的下一个字符
			j = 1;        //从头开始遍历
		}
	}
	if (j > T[0]) return i - T[0];
	return 0;
}
//利用已经实现的方法进行匹配
int Index2(String S, String T, int pos)
{
	//两个串如果为空或者子串长度比主串大无法匹配
	if (S[0] == 0 || T[0] == 0 || T[0] > S[0]
		|| pos <= 0 || pos > S[0]) return 0;
	auto n = StrLength(S);
	auto m = StrLength(T);
	auto i = pos;
	String sub{};
	while (i <= n - m + 1) {
		SubString(sub, S, i, m);//从主串S中找出pos到m的子串
		if (StrCompare(sub, T) == 0) return i;
		i++;
	}
	return 0;
}

Status StrInsert(String S, int pos, String T)
{
	if (pos < 1 || pos > S[0] + 1) return ERROR;
	int i{};
	if ((static_cast<int>((S[0] & 0xFF) + (T[0] & 0xFF))) <= kMaxSize) {
		for (i = S[0]; i >= pos; i--) {
			S[i + T[0]] = S[i];//把主串T往后挪T[0]个位置，方便T从pos处插入 
		}
		for (i = pos; i < pos + T[0]; i++) {
			S[i] = T[i - pos + 1];
		}
		S[0] += T[0];
		return TRUE;
	}
	//如果插入后的长度超过了 kMaxSize，则截断插入
	for (i = kMaxSize; i >= pos; i--) {
		S[i] = S[i - T[0]];/// 将主串 S 中的元素向后移动，为插入 T 做准备
	}
	//将串T截断后插入到主串S的POS处
	for (i = pos; i < pos + T[0]; i++) {
		S[i] = T[i - pos + 1];
	}
	S[0] = kMaxSize;
	return FALSE;
}

Status StrDelete(String S, int pos, int len)
{
	if (pos < 1 || pos > S[0] - len + 1 || len < 0) return ERROR;
	for (int i = pos + len; i <= S[0]; i++) {
		S[i - len] = S[i];
	}
	S[0] -= len;
	return OK;
}

Status StrReplace(String S, String T, String V)
{
	auto i = 1;
	if (StrEmpty(T)) return ERROR;
	do {
		i = Index(S, T, i);
		if (i != 0) {
			StrDelete(S, i, StrLength(T));
			StrInsert(S, i, V);
			i += StrLength(V);
		}
	} while (i != 0);
	return OK;
}

void PrintStr(String T)
{
	for (auto i = 1; i <= T[0]; i++) {
		std::cout << T[i];
	}
	std::cout << std::endl;
}
/// <summary>
/// 获取next数组
/// </summary>
/// <param name="T"></param>
/// <param name="next"></param>
void GetNext(String T, int next[kMaxSize])
{
	int i = 1, j = 0;//均指向子串,1是第一个字符位置，0为无效位
	//Begin1:
	//      j i
	//        |
	//        1 2 3 1 2 3
	//next :0 0
	//Begin2: j++,i++
	//      j(1) i(2)
	//        1    2  3 1 2 3
	//next:0  0    1
	next[0] = next[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}

}

int IndexKMP(String T, String S, int pos)
{
	int next[kMaxSize] = { 0 };
	int i = pos;
	int j = 1;
	GetNext(T, next);
	while (i <= S[0] && j<=T[0]) {
		if (j == 0 || S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j > T[0]) return i - T[0];
	return 0;
}
