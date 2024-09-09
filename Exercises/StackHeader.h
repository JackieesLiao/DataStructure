#ifndef STACKHEADER_H
#define STACKHEADER_H
#include <type_traits>
constexpr int MaxSize = 100;
//顺序栈
namespace SequentialStack {
	class Stack {
	private:
		int data[MaxSize];
		int top;//栈顶指针
	public:
		Stack() :top(-1)
		{}
		bool isEmpty() const;
		bool isFull() const;
		bool push(int value);
		bool pop(int& value);
	};
}//SequentialStack
//链栈（单链表实现）
namespace LinkedStack {
	template<typename ElemType>
	class Node {
	public:
		ElemType data;  //数据域
		Node* next;//指针域
		Node(ElemType value):data(value),next(nullptr){}
	};
	template<typename ElemType>
	class LinkedStack {
	private:
		Node<ElemType>* top;//栈顶指针
	public:
		LinkedStack():top(nullptr){}
		bool isEmpty() const
		{
			return top == nullptr;			
		}
		//单链栈能动态增长，不考虑栈满
		bool isFull() const
		{
			return false;
		}
		//头插法
		bool push(ElemType value)
		{
			Node<ElemType>* newNode = new Node < ElemType >(value);
			if (!newNode) {
				return false;
			}
			newNode->next = top;//新节点指向栈顶
			top = newNode;      //更新栈顶指针为新节点
			return true;   
		}
		bool pop(ElemType& value)
		{
			if (isEmpty()) return false;
			Node<ElemType>* temp = top;//临时保存栈顶
			value = top->data;
			top = top->next;           //更新栈顶指针为新节点
			delete(temp);
			return true;
		}
		bool getTopVal(ElemType& value) const {
			if (isEmpty()) return false;
			value = top->data;
			return true;
		}
		// 析构函数，释放所有节点,防止内存泄漏
		~LinkedStack() {
			while (!isEmpty()) {
				ElemType value;
				pop(value); // 不断出栈，释放节点
			}
		}
	};
}//LinkedStack
namespace DoubleLinkedListStack {
	template<typename ElemType>
	class DNode {
	public:
		ElemType Data;
		DNode* prev;//前驱指针
		DNode* next;//后继指针
		DNode(ElemType value):Data(value),prev(nullptr),next(nullptr){}
	};
	template<typename ElemType>
	class DoublyLinkedStack {
	private:
		DNode<ElemType>* top;   //指向双向链表中栈顶元素
		DNode<ElemType>* tail;   //指向双向链表中栈顶元素
	public:
		DoublyLinkedStack():top(nullptr),tail(nullptr){}
		bool isEmpty() const
		{
			return top == nullptr;
		}
		//链栈能动态增长，不考虑栈满
		bool isFull() const
		{
			return false;
		}
		bool pushHead(ElemType value) {
			DNode<ElemType>* newNode = new DNode<ElemType>(value);
			if (!newNode) {
				return false;
			}
			if (!top) {
				top = tail = newNode;// 如果栈为空，新节点是栈顶也是栈底
			}
			else {
				newNode->next = top;// 新节点的next指向当前栈顶
				top->prev = newNode;// 当前栈顶的prev指向新节点
				top = newNode;      // 更新栈顶指针
			}
			return true;
		}
		bool popHead(ElemType& value) {
			if (isEmpty()) return false;
			DNode<ElemType>* temp = top;
			value = top->Data;
			top = top->next;
			if (top) {
				top->prev = nullptr;
			}
			else {
				tail = nullptr;
			}
			delete temp;
			return true;
		}
		~DoublyLinkedStack() {
			DNode<ElemType>* cur = top;
			while (cur) {
				DNode<ElemType>* next = cur->next;
				delete cur;
				cur = next;
			}
		}
	};
}//DoubleLinkedListStack
#endif