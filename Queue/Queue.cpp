// Queue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "LinkedQueue.h"
#include "SqQueue.h"
#include <iostream>
static void testSqQueue() {
    Status status{};
    int i{ 0 }, l{};
    ElemType e{};
    SqQueue queue{};
    InitQueue(&queue);
    auto str_1 = QueueEmpty(queue) == TRUE ? "空" : "非空";
    std::cout << "初始化队列后，队列是否为空？" << str_1 << std::endl;
    do {
        e = i + 100;
        i++;
        EnQueue(&queue, e);
    } while (i < kMaxSize - 1);//最多插入到kMaxSize - 2处，因为下标从0开始
    std::cout << "队列的长度:" << QueueLength(queue) << std::endl;
    auto str_2 = QueueEmpty(queue) == TRUE ? "空" : "非空";
    std::cout << "初始化队列后，队列是否为空？" << str_2 << std::endl;
    QueueTraverse(queue);
    DeQueue(&queue, e);
    QueueTraverse(queue);
    std::cout << "队列的长度:" << QueueLength(queue) << std::endl;
    QueueTraverse(queue);
    GetHead(queue, e);
    std::cout << "头部是：" << e << std::endl;
    ClearQueue(&queue);
    auto str_3 = QueueEmpty(queue) == TRUE ? "空" : "非空";
    std::cout << "清空队列后，队列是否为空？" << str_3 << std::endl;
    std::cout << "队列的长度:" << QueueLength(queue) << std::endl;
}
static int testLinkedQueue() {
    LinkedQueue queue{};
    ElemType e{};
    auto ret = InitQueue(&queue);
    if (ret == OK) {
        std::cout << "成功构造了一个空队列。\n";
    }
    else return -1;
    auto str_1 = QueueEmpty(queue) == TRUE ? "空" : "非空";
    std::cout << "队列是否为空？" << str_1 << std::endl;
    std::cout << "队列的长度:" << QueueLength(queue) << std::endl;
    for (int i = { 0 }; i < 10; i++) EnQueue(&queue,i);
    auto str_2 = QueueEmpty(queue) == TRUE ? "空" : "非空";
    std::cout << "队列是否为空？" << str_2 << std::endl;
    std::cout << "队列的长度:" << QueueLength(queue) << std::endl;
    QueueTraverse(queue);
    std::cout << "队列头元素是：" << GetHead(queue, e) << std::endl;
    DeQueue(&queue, e);
    std::cout << "出队的值为：" << e << std::endl;
    std::cout << "此时队列头元素是：" << GetHead(queue, e) << std::endl;
    auto str_3 = QueueEmpty(queue) == TRUE ? "空" : "非空";
    std::cout << "队列是否为空？" << str_3 << std::endl;
    std::cout << "队列的长度:" << QueueLength(queue) << std::endl;
    DestroyQueue(&queue);
    std::cout << "销毁队列后：front=" << queue.front << ",rear=" << queue.rear << std::endl;
}
int main()
{
    //testSqQueue();
    testLinkedQueue();
}
