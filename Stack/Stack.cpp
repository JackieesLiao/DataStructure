// Stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "sequence_stack.h"
#include "linkedlist_stack.h"
#include <iostream>
static void testSqStatck() {
    SqStack* s = InitStack();
    ElemType e{};
    if (s == nullptr) {
        std::cout << "内存不足，停止操作\n";
        return;
    }
    for (auto i = 0; i < 10; i++) {
        Push(s, i);
    }
    StackTraverse(s); 
    GetTop(s, e);
    std::cout << "当前栈顶的值为：" << e << std::endl;
    Pop(s, e);
    std::cout << "当前出栈的值是：" << e << "\n";
    std::cout << "出栈后栈的数据为：\n";
    StackTraverse(s);
    GetTop(s, e);
    std::cout << "当前栈顶的值为：" << e << std::endl;
    ClearStack(s);
    std::cout << "清理栈之后，栈的数据为：\n";
    StackTraverse(s);
    std::cout << "当前是否为空：1:是,-1:不是 \t" << StackEmpty(s) << std::endl;
    DestroyStack(s);
    s = nullptr;
}
static void testLinkedStack() {
    LinkedStack stack{};
    ElemType e{};
    InitStack(&stack);
    std::cout << "栈中的元素为：\n";
    StackTraverse(&stack);
    if (Pop(&stack, e) == ERROR) {
        std::cout << "出栈失败\n";
    }
    else {
        std::cout << "出栈的元素为：" << e << "\n";
    }
    std::cout << "栈中的元素为：\n";
    StackTraverse(&stack);
    std::cout << "当前栈的状态：（1：空，0：有数据）" << StackEmpty(&stack) << std::endl;
    for (int i = 0; i < 10; i++) {
        Push(&stack, i * 10);
    } 
    std::cout << "栈的长度为:" << StackOfLength(&stack) << std::endl;
    std::cout << "栈中的元素为：\n";
    StackTraverse(&stack);
    std::cout << "当前栈的状态：（1：空，0：有数据）" << StackEmpty(&stack) << std::endl; 
    Pop(&stack, e);
    std::cout << "出栈的元素为：" << e << std::endl;
    std::cout << "栈的长度为:" << StackOfLength(&stack) << std::endl;
    std::cout << "栈中的元素为：\n";
    StackTraverse(&stack);
    std::cout << "当前栈的状态：（1：空，0：有数据）" << StackEmpty(&stack) << std::endl;
    if (GetTop(&stack, e) == ERROR) {
        std::cout << "获取失败\n";
    }
    else {
        std::cout << "栈顶的元素为"<<e<<"\n";
    }
    std::cout << "栈的长度为:" << StackOfLength(&stack) << std::endl;
    ClearStack(&stack); 
    std::cout << "清空栈之后的长度为:" << StackOfLength(&stack) << std::endl;
    std::cout << "当前栈的状态：（1：空，0：有数据）" << StackEmpty(&stack) << std::endl;
}
//栈的应用:递归调用
static int Fbi(int n) {
    if (n < 2) return n == 0 ? 0 : 1;
    return Fbi(n - 1) + Fbi(n - 2);
}
static void testFbi() {
    for (auto i = 1; i < 13; i++) {
        std::cout << "斐波那契数列(" << i << "), " << Fbi(i) << "\n";
    }
    std::cout << std::endl;

    //int a[40] = {};
    auto a = (int*)malloc(sizeof(int) * 40);
    a[0] = 0;
    a[1] = 1;
    std::cout << "a[" << 1 << "]=" << a[1] << std::endl;
    for (auto i = 2; i < 13; i++) {
        a[i] = a[i - 1] + a[i - 2];
        std::cout << "a[" << i << "]=" << a[i] << std::endl;
    }
    free(a);
}
int main()
{
    //testSqStatck();
    //testLinkedStack();
    testFbi();
}