// SequenceTable.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cassert>
#include "LinkedList.h"
//用顺序表实现线性表
#if 1
using Status = int;
using ElemType = int;
constexpr int kMaxSize = 20;
constexpr int OK = 1;
constexpr int ERROR = -1;
constexpr int TRUE = 1;
constexpr int FALSE = -1;
typedef struct {
    ElemType data[kMaxSize];
    ElemType length;
}SqList;
#endif
/// <summary>
/// 初始化顺序表
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
static Status InitList(SqList* L) {
    if (L == nullptr)
    {
        return ERROR;
    }
    L->length = 0;
    return OK;
}
/// <summary>
/// 清空顺序表
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
static Status ClearList(SqList* L) {
    if (L == nullptr) {
        return ERROR;
    }
    L->length = 0;
    return OK;
}
/// <summary>
/// 顺序表是否为空
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
static Status IsListEmpty(SqList* L) {
    if (L == nullptr) {
        return TRUE;
    }
    if (L->length == 0) {
        return TRUE;
    }
    return FALSE;
}
/// <summary>
/// 表长
/// </summary>
/// <param name="L"></param>
/// <returns></returns>
static int ListLength(SqList* L){
    return L->length;
}
/// <summary>
/// 插入元素
/// </summary>
/// <param name="L"></param>
/// <param name="index"></param>
/// <param name="e"></param>
/// <returns></returns>
static Status ListInsert(SqList* L, int index, const ElemType e) {
    if ((index >= 1) && (L->length < kMaxSize)) {
        if (index <= L->length) {
            for (auto i = L->length - 1; i >= index - 1; i--) {
                L->data[i + 1] = L->data[i];
            }
        }
        //将新元素插入到空出来的位置
        L->data[index - 1] = e;
        L->length++;
        return OK;
    }
    return ERROR;
}
/// <summary>
/// 删除
/// </summary>
/// <param name="L"></param>
/// <param name="index"></param>
/// <param name="e"></param>
/// <returns></returns>
static Status ListDelete(SqList* L, int index, ElemType& e) {
    if (L->length == 0) {
        return ERROR;
    }
    if (index < 1 || index > L->length) {
        return ERROR;
    }
    e = L->data[index - 1];
    if (index < L->length) {
        for (auto k = index; k < L->length; k++) {
            L->data[k - 1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}
static Status Visit(ElemType e) {
    std::cout << "elements: " << e << " ";
    return OK;
}
static Status ListTraverse(SqList* L) {
    for (auto k = 0; k < L->length; k++) {
        Visit(L->data[k]);
    }
    std::cout << "\r\n";
    return OK;
}
static Status GetItem(SqList* L, int index, ElemType& e) {
    if ((L->length == 0) || (index < 1) || (index > L->length)) {
        return ERROR;
    }
    e = L->data[index - 1];
    return OK;
}

static void TestListTable() {
    SqList L{};
    ElemType e{};
    Status ret{};
    int j{}, k{};
    ret = InitList(&L);
    std::cout << "初始化前：L.length= " << L.length << std::endl;
    for (j = 1; j < 6; j++) {
        ret = ListInsert(&L, 1, j);
    }
    ListTraverse(&L);
    ret = IsListEmpty(&L);
    assert(ret == -1);
    std::cout << "顺序表不为空：" << ret << std::endl;
    ClearList(&L);
    ret = IsListEmpty(&L);
    assert(ret == 1);
    std::cout << "顺序表为空：" << ret << std::endl;
    for (j = 1; j < 10; j++) {
        ret = ListInsert(&L, 1, j);
    }
    ListTraverse(&L);
    ListInsert(&L, 1, 0);
    ListTraverse(&L);
    GetItem(&L, 5,e);
    std::cout << "第五元素是：" << e << std::endl;
    k = ListLength(&L);
    std::cout << "表长为 ：" << k << std::endl;
    for (j = k + 1; j >= k; j--) {
        ret = ListDelete(&L, j, e);
        if (ret == ERROR) {
            std::cout << "删除第" << j << "个元素失败\n";
        }
        else {
            std::cout << "删除第" << j << "个元素成功\n";
        }
    }
    ListTraverse(&L);
    ListDelete(&L, 5, e);
    std::cout << "删除第5个元素成功\n";
}
int main()
{
    TestListTable();
}
