//循环队列，底层是数组
//有两个指针，队首指针，队尾指针
//队首指针(front)指向数组中的第一个元素，队尾指针(rear)指向数组中最后一个元素的下一个位置
//开始时，队列中front rear指向同一个位置，往队列中插入元素后rear+1,而front不动；删除队列中的元素，front向前移动。
#include<iostream>
const int MAXSIZE = 6;//循环队列容量为6
class CircleQueue
{
private:
	int *m_data =new int[MAXSIZE];
	int m_front;//队首指针
	int m_rear;//队尾指针
public:
	CircleQueue()
	{
		m_front = m_rear = 0;
	}
	~CircleQueue()
	{
		delete[] m_data;
	}
	bool IsEmpty()
	{
		return m_front == m_rear;
	}
	bool IsFull()
	{
		//队尾指针指向的下一个位置若为队首，队满
		return (m_rear + 1) % MAXSIZE == m_front;
	}
	bool Enqueue(int num)//入队
	{
		if (IsFull())
		{
			std::cout << "队满！" << std::endl;
			return false;
		}
		m_data[m_rear] = num;
		m_rear = (m_rear + 1) % MAXSIZE;//如果不取余MAXSIZE，则无法达到环形队列的目的
		return true;
	}
	bool DeQueue()//出队
	{

		if (IsEmpty())
		{
			std::cout << "队空！" << std::endl;
			return false;
		}
		m_front = (m_front + 1) % MAXSIZE;
		return true;
	}
	int GetQueueLength()
	{
		//例如rear=2,front=0,则有（2-0+6）%6=2个元素
		return (m_rear - m_front + MAXSIZE) % MAXSIZE;
	}
	int GetTopElem()//获取队头
	{
		if (IsEmpty())
		{
			std::cout << "队空！" << std::endl;
		}
		return m_data[m_front];
	}
	void PrintQueue()//打印队列里的元素
	{
		if (IsEmpty())
		{
			std::cout << "队空！" << std::endl;
		}
		for (int i = m_front; i != m_rear; i = (i + 1) % MAXSIZE)
		{
			std::cout << "队列里:" << m_data[i] << std::endl;
		}
	}
	
};
int main()
{
	CircleQueue cr;
	for (int i = 0; i < MAXSIZE; i++)
		cr.Enqueue(i);
	cr.PrintQueue();
	std::cout << "队列长度为："<<cr.GetQueueLength() << std::endl;//输出队列长度
	std::cout << "队头元素为："<<cr.GetTopElem() << std::endl;//输出队头元素
	cr.DeQueue();//出队
	std::cout << "出队后队头元素为："<<cr.GetTopElem() << std::endl;//输出队头元素
	std::cout << "此时队列长度为："<<cr.GetQueueLength() << std::endl;//输出队列长度
	cr.DeQueue();//出队
	std::cout <<  "再出队后队头元素为："<<cr.GetTopElem() << std::endl;//输出队头元素
	cr.Enqueue(89);
	cr.PrintQueue();
}
