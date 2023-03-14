//顺序栈的入栈、出栈、查栈顶元素基本操作
#include<iostream>
const int MAXSIZE = 100;
//顺序栈类
class SeqStack
{
public:
	SeqStack()
	{
		top = -1;
	}
	~SeqStack()
	{
		std::cout << "销毁实例";
	}
	bool isEmpty()
	{
		return top == -1;//返回true则表示栈空
	}
	bool isFull()
	{
		//top栈顶指针初始值为-1,则栈满时top=MAXSIZE - 1
		return top == MAXSIZE - 1;
	}
	//入栈
	void push(int x)
	{
		if (isFull())
		{
			std::cout << "栈满。无法打击入栈。";
		}
		data[++top] = x;
	}
	void pop()
	{
		if (isEmpty())
		{
			std::cout << "栈空。";
		}
		top--;
	}
	int getTopElem()
	{
		if (isEmpty())
		{
			std::cout << "栈空。";
		}
		return data[top];
	}
private:
	int top;//栈顶指针
	int data[MAXSIZE] = { 0 };//栈的数据存储区域
};
int main()
{
	SeqStack seq;
	seq.push(10);
	seq.push(20);
	seq.push(30);
	seq.push(40);
	seq.push(50);

	std::cout << "此时栈顶元素为:" << seq.getTopElem()<<std::endl;//50
	seq.pop();
	std::cout << "此时栈顶元素为:" << seq.getTopElem() << std::endl;//40
	seq.pop();
	std::cout << "此时栈顶元素为:" << seq.getTopElem() << std::endl;//30
	seq.pop();
	std::cout << "此时栈顶元素为:" << seq.getTopElem() << std::endl;//20
	seq.pop();
	std::cout << "此时栈顶元素为:" << seq.getTopElem() << std::endl;//10
	
}
