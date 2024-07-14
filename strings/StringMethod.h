#ifndef STRINGMETHOD
#define STRINGMETHOD
#include "Public.h"
Status StrAssign(String T, const char* chars);
Status StrCopy(String T, String S);
Status StrEmpty(String S);
int StrCompare(String T, String S);//T > S return 1 ;if T == S ,return 0 ,else return -1
int StrLength(String S);
Status ClearString(String S);
Status Concat(String T, String S1,String S2); //T = S1 + S2
Status SubString(String Sub, String S, int pos, int len);//Sub = S[pos:pos+len]
int Index(String S, String T, int pos);       //������S�����Ӵ�T������λ�ô�pos��ʼ
int Index2(String S, String T, int pos);
Status StrInsert(String S, int pos, String T);//������S��POSλ�ò����Ӵ�T
Status StrDelete(String S, int pos, int len);  //���ַ���S��pos��ʼ��ɾ������len���ַ�
Status StrReplace(String S,String T ,String V);
void PrintStr(String T);
void GetNext(String T, int next[kMaxSize]);
int IndexKMP(String T, String S,int pos);
#endif // !STRINGMETHOD