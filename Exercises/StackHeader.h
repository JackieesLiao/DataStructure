#ifndef STACKHEADER_H
#define STACKHEADER_H
#include <type_traits>
constexpr int MaxSize = 100;
//˳��ջ
namespace SequentialStack {
	class Stack {
	private:
		int data[MaxSize];
		int top;//ջ��ָ��
	public:
		Stack() :top(-1)
		{}
		bool isEmpty() const;
		bool isFull() const;
		bool push(int value);
		bool pop(int& value);
	};
}//SequentialStack
//��ջ��������ʵ�֣�
namespace LinkedStack {
	template<typename ElemType>
	class Node {
	public:
		ElemType data;  //������
		Node* next;//ָ����
		Node(ElemType value):data(value),next(nullptr){}
	};
	template<typename ElemType>
	class LinkedStack {
	private:
		Node<ElemType>* top;//ջ��ָ��
	public:
		LinkedStack():top(nullptr){}
		bool isEmpty() const
		{
			return top == nullptr;			
		}
		//����ջ�ܶ�̬������������ջ��
		bool isFull() const
		{
			return false;
		}
		//ͷ�巨
		bool push(ElemType value)
		{
			Node<ElemType>* newNode = new Node < ElemType >(value);
			if (!newNode) {
				return false;
			}
			newNode->next = top;//�½ڵ�ָ��ջ��
			top = newNode;      //����ջ��ָ��Ϊ�½ڵ�
			return true;   
		}
		bool pop(ElemType& value)
		{
			if (isEmpty()) return false;
			Node<ElemType>* temp = top;//��ʱ����ջ��
			value = top->data;
			top = top->next;           //����ջ��ָ��Ϊ�½ڵ�
			delete(temp);
			return true;
		}
		bool getTopVal(ElemType& value) const {
			if (isEmpty()) return false;
			value = top->data;
			return true;
		}
		// �����������ͷ����нڵ�,��ֹ�ڴ�й©
		~LinkedStack() {
			while (!isEmpty()) {
				ElemType value;
				pop(value); // ���ϳ�ջ���ͷŽڵ�
			}
		}
	};
}//LinkedStack
namespace DoubleLinkedListStack {
	template<typename ElemType>
	class DNode {
	public:
		ElemType Data;
		DNode* prev;//ǰ��ָ��
		DNode* next;//���ָ��
		DNode(ElemType value):Data(value),prev(nullptr),next(nullptr){}
	};
	template<typename ElemType>
	class DoublyLinkedStack {
	private:
		DNode<ElemType>* top;   //ָ��˫��������ջ��Ԫ��
		DNode<ElemType>* tail;   //ָ��˫��������ջ��Ԫ��
	public:
		DoublyLinkedStack():top(nullptr),tail(nullptr){}
		bool isEmpty() const
		{
			return top == nullptr;
		}
		//��ջ�ܶ�̬������������ջ��
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
				top = tail = newNode;// ���ջΪ�գ��½ڵ���ջ��Ҳ��ջ��
			}
			else {
				newNode->next = top;// �½ڵ��nextָ��ǰջ��
				top->prev = newNode;// ��ǰջ����prevָ���½ڵ�
				top = newNode;      // ����ջ��ָ��
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