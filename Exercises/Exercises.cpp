// Exercises.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "QueueHeader.h"
#include "StackHeader.h"
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <tuple>
#include <unordered_set>
#include <vector>
static void TestSeqStackHeader()
{
	SequentialStack::Stack stack;
	for (auto i = 10; i < 100; i += 10) {
		stack.push(i);
	}
	int value{};
	while (!stack.isEmpty()) {
		stack.pop(value);
		std::printf("%d\n", value);
	}
}
static void TestLinkedStackHeader()
{
	LinkedStack::LinkedStack<int> stack;
	for (auto i = 10; i < 100; i += 10) {
		stack.push(i * 2);
	}
	int value{};
	while (!stack.isEmpty()) {
		stack.pop(value);
		std::cout << value << " ";
	}
	std::cout << std::endl;
}
static void TestDoubleLinkedStackHeader() {
	DoubleLinkedListStack::DoublyLinkedStack<double> stack;
	for (auto i = 0; i < 100; i += 10) {
		stack.pushHead(static_cast<double>(i * 1.5));
	}
	double value{};
	while (!stack.isEmpty()) {
		stack.popHead(value);
		std::cout << value << " ";
	}
	std::cout << std::endl;
}
template<typename T, std::size_t N>
static void print(const T(&array)[N]) {
	for (std::size_t i = 0; i < N; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
#if 1
#include <vector>
//模板
namespace QuickSort {
	static int Partition(std::vector<int>& array, int L, int R) {
		int mid = array[L];
		while (L < R) {
			while (array[R] >= mid && L < R) {//只要R指针指向的元素一直比mid大且L<R，R就一直向左递减
				R--;
			}
			array[L] = array[R];
			while (array[L] <= mid && L < R) {//只要L指针指向的元素一直比mid小且L<R，L就一直向右递增
				L++;
			}
			array[R] = array[L];
		}
		//递归结束
		array[L] = mid;
		return L;//返回中间值下标
	}
	static void QuickSort(std::vector<int>& array, int L, int R) {
		if (L >= R) return;
		int mid = Partition(array, L, R);
		QuickSort(array, L, mid - 1);//递归处理左部分
		QuickSort(array, mid + 1, R);//递归处理右部分
	}
	static void testQS() {
		std::vector<int> array{ 1,9,-2,34,8 };
		for (auto A : array) {
			std::cout << A << " ";
		}
		std::cout << std::endl;
		QuickSort(array, 0, array.size() - 1);
		for (auto A : array) {
			std::cout << A << " ";
		}
		std::cout << std::endl;
	}
	//408-DS-2011-method1
	static int GetMid(std::vector<int>& S1, int N, std::vector<int>& S2, int M) {
		std::vector<int> S_Answer(N + M);
		for (int i = 0; i < N; i++) {
			S_Answer[i] = S1[i];
		}
		for (int j = 0; j < M; j++) {
			S_Answer[j + N] = S2[j];
		}
		QuickSort(S_Answer, 0, N + M - 1);
		return S_Answer[(N + M - 1) / 2];
	}
	static void TestGetMid()
	{
		std::vector<int> S1{};
		std::vector<int> S2 = { 2,4,6,8,20 };
		for (int i = 11; i < 20; i += 2) {
			S1.push_back(i);
		}
		auto n = GetMid(S1, S1.size(), S2, S2.size());
		std::cout << "中位数:" << n << std::endl;
	}
	//408-DS-2013
	static int GetMainElem(std::vector<int>& array, int n)
	{
		QuickSort(array, 0, n - 1); //将无序数组先使用快排排成有序数组
		int pm = array[n / 2];      //找n/2处元素（可能主元素）
		int mainElemNum{ 0 };       //主元素个数
		for (int i = n / 2 - 1; i >= 0; i--) {//从n/2左侧开始遍历
			if (pm == array[i]) {
				mainElemNum++;
			}
		}
		for (int j = n / 2; j < n; j++) {    //从n/2右侧开始遍历
			if (pm == array[j]) {
				mainElemNum++;
			}
		}
		if (mainElemNum > n / 2) {  //如果某元素个数大于n/2则为主元素，否则返回-1
			return pm;
		}
		else return -1;
	}
	static void TestGetMainElem()
	{
		std::vector<int> A{ 0,5,5,3,5,7,5,5 };
		std::cout << "MainElem:" << GetMainElem(A, A.size()) << std::endl;
		std::vector<int> B{ 0,5,5,3,5,1,5,7 };
		std::cout << "MainElem:" << GetMainElem(B, B.size()) << std::endl;
	}
	//408-DS-2018
	static int CalMinElem(std::vector<int>& array, int n) {
		QuickSort(array, 0, n - 1); //将无序数组先使用快排排成有序数组
		int m = -1;
		for (int i = 0; i < n; i++) {
			if (array[i] > 0) {
				m = i;
				break;
			}
		}
		//若一直找不到大于0的元素或者第一个大于0的元素不等于1，直接返回 1
		if (m == -1 || array[m] != 1) return 1;
		//从元素等于1位置后开始遍历
		for (int j = m + 1; j < n; j++) {
			//若差值 > 1，则最小正整数等于比较的元素中较小的值+1
			if ((array[j] - array[j - 1]) > 1) {
				return array[j - 1] + 1;
			}
		}
		//否则若差值一直 = 1，则最小正整数等于最后一个元素+1
		return array[n - 1] + 1;
	}
	static void TestCalMinElem()
	{
		std::vector<int> A{-5,3,2,3};
		std::cout << "MinElem:" << CalMinElem(A, A.size()) << std::endl;/*输出1*/
		std::vector<int> B{1,2,3};
		std::cout << "MinElem:" << CalMinElem(B, B.size()) << std::endl;/*输出4*/
	}
	//使用划分函数找到数组中第K小的元素
	//数组下标从0开始，排序后即K-1处的元素
	static int GetKMinElem(std::vector<int>& array,int n,int K) {
		int L = 0, R = n - 1;
		int PartitionM{ 0 };
		while (true) {
			PartitionM = Partition(array, L, R);
			if (PartitionM == K - 1) break;
			else if (PartitionM > K - 1) {
				R = PartitionM - 1;
			}
			else if (PartitionM < K - 1) { 
				L = PartitionM + 1; 
			}
		}
		return array[K - 1];
	}
	static void TestGetKMinElem() {
		std::vector<int> A{ 1,3,2,3,45,-108,30,9,-9,-99,-901};
		int k{ 1 };
		std::cout << "第K小的元素为："<<GetKMinElem(A, A.size(), k);
	}
	using Vector = std::vector<int>;
	static void Merge(Vector&A,int N,Vector&B,int M,Vector&C) {
		int i{ 0 }, j{ 0 }, p{ 0 };//三个指针分别指向ABC数组的首部
		while (i < N && j < M) {
			if (A[i] <= B[j]) {
				C[p++] = A[i++];
			}
			else {
				C[p++] = B[j++];
			}
		}
		while (i < N) {
			C[p++] = A[i++];
		}
		while (j < M) {
			C[p++] = B[j++];
		}
	}
	static void TestMerge() {
		Vector A = { 9,10,223,87,65,12 };
		Vector B = { 43,65,12,-1};
		QuickSort(A, 0, A.size() - 1);
		QuickSort(B, 0, B.size() - 1);
		Vector C(A.size() + B.size());
		Merge(A, A.size(), B, B.size(), C);
		for (const auto& elem : C) {
			std::cout << elem << "\n";
		}
		std::cout << std::endl;
	}
	//408-DS-2011-method2
	static int GetMidMerge(std::vector<int>& A, int N, std::vector<int>& B, int M) {
		std::vector<int> C(N + M);
		Merge(A, N, B, M, C);
		//PrintVector(C);
		return C[(N + M) / 2];
	}
	static void TestGetMidMerge() {
		Vector A = { 19,10,23,-12,7,65,12 };
		Vector B = { 3,65,12,-1 };
		QuickSort(A, 0, A.size() - 1);
		QuickSort(B, 0, B.size() - 1);
		auto ans = GetMidMerge(A, A.size(), B, B.size());
		std::cout << "中位数：" << ans << std::endl;
	}
}//namespace QuickSort 
#endif 
namespace LinkedList {
	//定义单链表节点
    struct LinkList{
		int data;
		struct LinkList* next;
		LinkList(int val):data(val),next(nullptr){}
	};

	//打印单链表
	static void printList(LinkList* head) {
		while (head != nullptr) {
			std::cout << head->data << " ";
			head = head->next;
		}
		std::cout << std::endl;
	}
	//求单链表长度
	static int getLength(LinkList* head) {
		int length{ 0 };
		while(head != nullptr) {
			length++;
			head = head->next;
		}
		return length;
	}
	//返回单链表中间节点
	static LinkList* getMiddleNode(LinkList* head) {
		int length = getLength(head);
		int mid = length / 2;
		for (int i = 0; i < mid; i++) {
			head = head->next;
		}
		return head;
	}
	using ListNode = LinkList;
	static void TestLinkList() {
		// 创建单链表：1 -> 2 -> 3 -> 4 -> 5
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(4);
		head->next->next->next->next = new ListNode(5);
		std::cout << "原始链表: ";
		printList(head);
		// 求链表长度
		int length = getLength(head);
		std::cout << "链表长度: " << length << std::endl;
		// 找到链表的中间节点
		ListNode* middle = getMiddleNode(head);
		std::cout << "中间节点值: " << middle->data << std::endl;
	}
	//408-DS-2009
	static int findKNode(LinkList* head, int k) {
		int length = 0;
		LinkList* p = head->next;   //保存链表头节点
		while (p != nullptr) {//统计出链表的长度
			p = p->next;
			length++;
		}
	    p = head->next;             //为了从头开始遍历
		int count = 0;        //计数
		while (p != nullptr) {
			if (count == length - k + 1) {//若计数等于总长度减去要找的元素的下标k，跳出循环
				std::cout << p->data << std::endl;
				break;
			}
			count++;
			p = p->next;
		}
		if (count == length - k + 1) return 1;
		else if (k > length) return 0;
	}
	static void TestfindKNode() {
		// 创建单链表：1 -> 2 -> 3 -> 4 -> 5
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(4);
		head->next->next->next->next = new ListNode(5);
		std::cout << "原始链表: ";
		printList(head);
		findKNode(head, 3);
	}
	//408-DS-2012
#include<math.h>
	typedef struct SNode {
		char data;
		struct SNode* next;
	}SNode;
	static SNode* findCommonFirstAddr(SNode* s1, SNode* s2) {
		SNode* p1 = s1;
		SNode* p2 = s2;
		int length1 = 0, length2 = 0;
		while (p1 != nullptr) {
			length1++;
			p1 = p1->next;
		}
		while (p2 != nullptr) {
			length2++;
			p2 = p2->next;
		}
		p1 = s1;
		p2 = s2;
		int len = abs(length1 - length2);
		//指向的字符串的长度的指针步进len个长度
		if (length1 > length2) {
			for (int i = 0; i < len && p1 != nullptr; i++) {
				p1 = p1->next;
			}
		}
		else {
			for (int j = 0; j < len && p2 != nullptr; j++) {
				p2 = p2->next;
			}
		}
		while (p1 != nullptr && p2 != nullptr) {
			if (p1 == p2) return p1;//找到两链表共同后缀的起始位置
			p1 = p1->next;
			p2 = p2->next;
		}
		return nullptr;
	}
	// 打印链表
	void printList(SNode* head) {
		SNode* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data;
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	static void testfindCommonFirstAddr()
	{
		// 构建测试链表 "loading" 和 "being"
		SNode* common = new SNode{ 'i', new SNode{'n', new SNode{'g', nullptr}} };

		// 构建 "loading" 链表: l -> o -> a -> d -> i -> n -> g
		SNode* s1 = new SNode{ 'l', new SNode{'o', new SNode{'a', new SNode{'d', common}}} };

		// 构建 "being" 链表: b -> e -> i -> n -> g
		SNode* s2 = new SNode{ 'b', new SNode{'e', common} };

		// 打印链表
		std::cout << "链表1: ";
		printList(s1);
		std::cout << "链表2: ";
		printList(s2);

		// 查找共同后缀
		SNode* commonNode = findCommonFirstAddr(s1, s2);

		if (commonNode) {
			std::cout << "公共后缀的起始节点值: " << commonNode->data << std::endl;
		}
		else {
			std::cout << "没有公共后缀" << std::endl;
		}
	}

    //删除值为x的节点
	static void DeleteX(LinkList* head, int x) {
		LinkList* pre = head;//p的前驱指针
		LinkList* p = head->next;
		while (p != nullptr) {
			if (p->data == x) {
				LinkList* q = p;//保存p指向的节点
				p = p->next;    //p向前移动
				pre->next = p;  //pre指向p指针新的位置以达到删除节点x的目的
				free(q);        //释放需删除节点空间
			}
			else {//没找到x
				pre = p;        //pre指向p
				p = p->next;    //p向前移动
			}
		}
	}
	//插入值为x的节点
	static void insertX(LinkList* head, int x) {
		LinkList* pre = head;//p的前驱指针
		LinkList* p = head->next;
		while (p != nullptr) {
			if (p->data > x) {//只有当前指针指向的节点值大于x时，才能在其前面插入
				break;
			}
			else {
				pre = p;        //pre指向p
				p = p->next;    //p向前移动
			}
		}
		//找到了
		//创建一个新节点
		LinkList* newNode = (LinkList*)malloc(sizeof(LinkList));
		if (newNode != nullptr) {
			newNode->data = x;
			newNode->next = p;
			pre->next = newNode;
		}
	}
	static void TestDeleteX() {
		// 创建单链表：1 -> 2 -> 3 -> 4 -> 5 -> 3 -> 4
		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(4);
		head->next->next->next->next = new ListNode(5);
		head->next->next->next->next->next = new ListNode(3);
		head->next->next->next->next->next->next = new ListNode(4);
		std::cout << "原始链表: ";
		printList(head);
		DeleteX(head, 3);
		DeleteX(head, 4);
		std::cout << "删除之后的链表: ";
		printList(head);
		insertX(head, 8);
		printList(head);
	}

	//408-DS-2015


	//使用头插法实现元素原地逆置
	static void LinkListReverse(LinkList* linklist) {
		LinkList* head = new LinkList(0); // 创建辅助头节点
		head->next = nullptr;
		while (linklist->next != nullptr) {
			LinkList* p = linklist->next;//按照单链表顺序拆下每个结点
			linklist->next = linklist->next->next;
			p->next = head->next;//让单链表中的结点依次插入辅助结点head指向的单链表中
			head->next = p;      //让p插在链表头部
		}
		linklist->next = head->next;// 将逆置后的链表连接回原链表
		delete head;
	}
	static void testLinkListReverse() {
		LinkList* headx = new LinkList(1);
		headx->next = new LinkList(2);
		headx->next->next = new LinkList(3);
		std::cout << "原始链表: ";
		printList(headx);
		LinkListReverse(headx);
		std::cout << "逆置之后的链表: ";
		printList(headx);
	}
	//尾插法
	LinkList* A = nullptr;//单链表A
	LinkList* B = nullptr;//单链表B
	static void LinkListReverseTail(LinkList* C/*单链表C*/) {
		A = (LinkList*)malloc(sizeof(LinkList));
		A->next = nullptr;
		LinkList* TailA = A;//使用一个尾指针永远指向A的尾部方便尾插法
		B = (LinkList*)malloc(sizeof(LinkList));
		B->next = nullptr;
		int count = 1;//使用一个计数器用于在取单链表C时根据奇偶分别取出单链表A B的结点
		while (C->next != nullptr) {
			LinkList* p = C->next;//指向C的头结点然后依次取
			C->next = C->next->next;
			if (count % 2 == 1) {//奇数
				//尾插法
				TailA->next = p;
				p->next = nullptr;
				TailA = p;//将链尾指针移动到新的链尾
			}
			else {
				//头插法
				p->next = B->next;
				B->next = p;
			}
			count++;
		}
	}

	// 测试函数
	static void testLinkListReverseTail() {
		// 创建单链表C
		LinkList* C = new LinkList(0); // 创建一个辅助头节点
		LinkList* temp = C;
		for (int i = 1; i <= 6; ++i) {
			temp->next = new LinkList(i);
			temp = temp->next;
		}

		std::cout << "原始链表C: ";
		printList(C->next); // 打印C链表

		// 调用分配函数，将链表C的节点分配到A和B
		LinkListReverseTail(C);

		std::cout << "链表A (尾插法): ";
		printList(A->next); // 打印A链表

		std::cout << "链表B (头插法): ";
		printList(B->next); // 打印B链表
	}
}//namespace LinkedList
namespace BinaryTree {
	typedef struct BiTNode {
		int data;                        //数据域
		struct BiTNode* lchild, * rchild;//左右孩子指针
	}BiTNode,*BiTree;
	//前序递归代码
	static void preOrderTraversal(BiTree root) {
		if (!root) return;
		std::cout << root->data << " ";
		preOrderTraversal(root->lchild);
		preOrderTraversal(root->rchild);
	}
	//中序递归代码
	static void inOrderTraversal(BiTree root) {
		if (!root) return;
		inOrderTraversal(root->lchild);
		std::cout << root->data << " ";
		inOrderTraversal(root->rchild);
	}
	//后序递归代码
	static void postOrderTraversal(BiTree root) {
		if (!root) return;
		postOrderTraversal(root->lchild);
		postOrderTraversal(root->rchild);
		std::cout << root->data << " ";
	}
	//创建二叉树
	/*
	*        1   //(root)
	*       / \
	*      2   3
	*     / \ / \
	*    4  5 6  7
	*/
	static BiTree CreateTree() {
		BiTree root = new BiTNode{ 1, nullptr, nullptr };
		root->lchild = new BiTNode{ 2, nullptr, nullptr };
		root->rchild = new BiTNode{ 3, nullptr, nullptr };
		root->lchild->lchild = new BiTNode{ 4, nullptr, nullptr };
		root->lchild->rchild = new BiTNode{ 5, nullptr, nullptr };
		root->rchild->lchild = new BiTNode{ 6, nullptr, nullptr };
		root->rchild->rchild = new BiTNode{ 7, nullptr, nullptr };
		return root;
	}
	
	//层序遍历
	//1.根节点入队
	//2.循环遍历队列，如果非空，取出队头结点并访问
	//3.如果该节点的左右孩子非空则入队
	static void LevelOrderTraversal(BiTree root) {
		if (root == nullptr) return;
		std::queue<BiTree> treeQueue;
		treeQueue.push(root);
		while (!treeQueue.empty()) {
			auto node = treeQueue.front();
			treeQueue.pop();
			std::cout << node->data << " ";//访问当前结点
			if (node->lchild != nullptr) {
				treeQueue.push(node->lchild);
			}
			if (node->rchild != nullptr) {
				treeQueue.push(node->rchild);
			}
		}
	}
	//求二叉树的高度
	static int TreeHeight(BiTree root) {
		if (root == nullptr) return 0;
		int l = TreeHeight(root->lchild);
		int r = TreeHeight(root->rchild);
		return std::max(l, r) + 1;
	}
	//求二叉树的宽度
	static int TreeWidth(BiTree root) {
		if (root == nullptr) return 0;
		std::queue<BiTree> queue;
		queue.push(root);//入根节点
		int maxWidth = 0;
		while (!queue.empty()) {
			//统计每层的结点
			int levelsize = queue.size();
			if (levelsize > maxWidth) {
				maxWidth = levelsize;
			}
			for (int i = 0; i < levelsize; i++) {
				BiTree node = queue.front();
				queue.pop();
				if (node->lchild != nullptr) {
					queue.push(node->lchild);
				}
				if (node->rchild != nullptr) {
					queue.push(node->rchild);
				}
			}
		}
		return maxWidth;
	}
	//求WPL
	static int PreOrderForWPL(BiTree T, int n) {
		if (T == nullptr) return 0;
		if (T->lchild == nullptr && T->rchild == nullptr) {
			return T->data * n;
		}
	    return PreOrderForWPL(T->lchild, n + 1) + PreOrderForWPL(T->rchild, n + 1);
	}
	//二叉排序树判定
	static bool isBSTUtil(BiTree T, int minValue, int maxValue) {
		if (T == nullptr) return true;//空树必为二叉排序树
		if (T->data <= minValue || T->data >= maxValue) {
			return false;
		}
		//递归判定左子树与右子树
		//左<根<右
		return isBSTUtil(T->lchild, minValue, T->data) && isBSTUtil(T->rchild, T->data, maxValue);
	}
	static bool isBSTTree(BiTree root) {
		return isBSTUtil(root, INT_MIN, INT_MAX);
	}
	static void testisBSTTree()
	{
		BiTree root = new BiTNode{ 4, nullptr, nullptr };
		root->lchild = new BiTNode{ 2, nullptr, nullptr };
		root->rchild = new BiTNode{ 6, nullptr, nullptr };
		root->lchild->lchild = new BiTNode{ 1, nullptr, nullptr };
		root->lchild->rchild = new BiTNode{ 3, nullptr, nullptr };
		root->rchild->lchild = new BiTNode{ 5, nullptr, nullptr };
		root->rchild->rchild = new BiTNode{ 7, nullptr, nullptr };
		if (isBSTTree(root)) {
			std::cout << "该树是BST" << std::endl;
		}
		else {
			std::cout << "该树不是BST" << std::endl;
		}
	}
	//二叉平衡树判定
	static int checkBalanceAndHeight(BiTree T) {
		if (T == nullptr) return 0;
		int leftHeight = checkBalanceAndHeight(T->lchild);
		if (leftHeight == -1) {//左子树不平衡
			return -1;
		}
		int rightHeight = checkBalanceAndHeight(T->rchild);
		if (rightHeight == -1) {//右子树不平衡
			return -1;
		}
		if (std::abs(leftHeight - rightHeight) > 1) {//高度之差超过1则必不平衡
			return -1;
		}
		return std::max(leftHeight, rightHeight) + 1;
	}
	static bool isBalancedTree(BiTree T) {
		return checkBalanceAndHeight(T) != -1;
	}
	//完全二叉树判定
	static bool isCompleteBinaryTree(BiTree root) {
		if (root == nullptr) return 0;
		std::queue<BiTree> queue;
		queue.push(root);//入根节点
		bool ismustLeaf = false;//是否必须是叶子结点
		while (!queue.empty()) {
			auto node = queue.front();
			queue.pop();
			if (ismustLeaf && ((node->lchild != nullptr) || (node->rchild != nullptr))){
				//如果要求后面的结点是叶子结点而当前结点不是叶子结点
				return false;
			}
			//如果当前结点的左右孩子不为空则入队，否则若为空则后续的结点也必须为空
			if (node->lchild != nullptr) {
				queue.push(node->lchild);
			}
			else {
				ismustLeaf = true;
			}
			if (node->rchild != nullptr) {
				queue.push(node->rchild);
			}
			else {
				ismustLeaf = true;
			}
		}
		return true;
	}
	static void TestTree() {
		BiTree root = CreateTree();
		std::cout << "前序遍历:";
		preOrderTraversal(root); //1 2 4 5 3 6 7
		std::cout << std::endl;
		std::cout << "中序遍历:";
		inOrderTraversal(root);  //4 2 5 1 6 3 7
		std::cout << std::endl;
		std::cout << "后序遍历:";
		postOrderTraversal(root);//4 5 2 6 7 3 1
		std::cout << std::endl;
		std::cout << "层序遍历:";
		LevelOrderTraversal(root);
		std::cout << std::endl;
		std::cout << "树的高度:" << TreeHeight(root) << std::endl;
		std::cout << "树的宽度:" << TreeWidth(root) << std::endl;
		std::cout << "树的WPL：" << PreOrderForWPL(root, 0) << std::endl;
		if (isCompleteBinaryTree(root)) {
			std::cout << "是完全二叉树" << std::endl;
		}
		if (isBalancedTree(root)) {
			std::cout << "是平衡二叉树" << std::endl;
		}
	}
}//namespace BinaryTree
namespace Graph {
	//图的数据结构定义--邻接矩阵
	constexpr int MAXV = 8;//顶点数目的最大值
	typedef struct {
		int numV, numE;//实际的顶点数与边数
		char VerticesList[MAXV];//顶点表
		int Edge[MAXV][MAXV];   //边表，用来存储各顶点之间的边的连接关系
	}MGraph;
	//初始化有向图
	static void initMGraph(MGraph& graph) {
		graph.numV = 4;
		graph.numE = 5;
		char vertices[] = { 'a', 'b', 'c', 'd' };
		for (int i = 0; i < graph.numV; i++) {
			graph.VerticesList[i] = vertices[i];
		}
		for (int i = 0; i < MAXV; i++) {
			for (int j = 0; j < MAXV; j++) {
				graph.Edge[i][j] = 0;
			}
		}
		/*
		* 有向图G
		*    a
		*   / \
		*  b - d
		*   \ /
		*    c
		*/
		graph.Edge[0][1] = 1;//a到b有边
		graph.Edge[0][3] = 1;//a到d有边
		graph.Edge[1][2] = 1;//b到c有边
		graph.Edge[1][3] = 1;//b到d有边
		graph.Edge[2][3] = 1;//c到d有边
	}
	// 初始化无向图邻接矩阵
	static void initUndirectedGraph(MGraph& graph) {
		graph.numV = 4;  // 设置顶点数
		graph.numE = 5;  // 设置边数
		char vertices[] = { 'a', 'b', 'c', 'd' };
		for (int i = 0; i < graph.numV; i++) {
			graph.VerticesList[i] = vertices[i];
		}

		// 初始化邻接矩阵，将所有边置为0
		for (int i = 0; i < MAXV; i++) {
			for (int j = 0; j < MAXV; j++) {
				graph.Edge[i][j] = 0;
			}
		}

		// 无向图的边（对称添加边）
		/*
		*    a
		*   / \
		*  b - d
		*   \ /
		*    c
		*/
		graph.Edge[0][1] = 1; // a - b
		graph.Edge[1][0] = 1; // b - a (对称边)

		graph.Edge[0][3] = 1; // a - d
		graph.Edge[3][0] = 1; // d - a (对称边)

		graph.Edge[1][2] = 1; // b - c
		graph.Edge[2][1] = 1; // c - b (对称边)

		graph.Edge[1][3] = 1; // b - d
		graph.Edge[3][1] = 1; // d - b (对称边)

		graph.Edge[2][3] = 1; // c - d
		graph.Edge[3][2] = 1; // d - c (对称边)
	}
	// 打印邻接矩阵
	static void printMGraph(const MGraph& graph) {
		std::cout << "Adjacency Matrix:\n";
		for (int i = 0; i < graph.numV; i++) {
			for (int j = 0; j < graph.numV; j++) {
				std::cout << graph.Edge[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	static void testMGraph() {
		MGraph graph{};
		initMGraph(graph);	
		printMGraph(graph);
	}
	//计算邻接矩阵下有向图顶点的出度与入度
	static void calculateOutDegree(const MGraph& graph) {//出度
		std::cout << "Out-degree of vertices:\n";
		for (int i = 0; i < graph.numV; i++) {
			int outDegree = 0;
			for (int j = 0; j < graph.numV; j++) {
				if (graph.Edge[i][j] != 0) {//统计每行非0元素个数即为该行顶点的出度
					outDegree++;
				}
			}
			std::cout << "顶点" << graph.VerticesList[i] << "出度：" << outDegree << std::endl;
		}
	}
	static void calculateInDegree(const MGraph& graph) {//入度
		std::cout << "In-degree of vertices:\n";
		for (int i = 0; i < graph.numV; i++) {
			int inDegree = 0;
			for (int j = 0; j < graph.numV; j++) {
				if (graph.Edge[j][i] != 0) {//统计每列非0元素个数即为该行顶点的入度
					inDegree++;
				}
			}
			std::cout << "顶点" << graph.VerticesList[i] << "入度：" << inDegree << std::endl;
		}
	}
	static void testDegree() {
		MGraph graph{};
		initMGraph(graph);
		// 计算并输出出度和入度
		calculateOutDegree(graph);
		calculateInDegree(graph);
	}
	//图的数据结构定义--邻接表
	typedef struct EdgeNode{   //边表结点
		int index;             //这条边所指向的顶点的位置
		struct EdgeNode* next; //指向下一条边的指针
	}EdgeNode;
	typedef struct VertexNode {//顶点表结点
		char data;             //顶点信息
		EdgeNode* first;       //指向第一条依附该顶点的边的指针
	}VertexNode,*VertexList[MAXV];
	typedef struct {
		VertexList list;       //邻接表
		int numV, numE;        //图的实际顶点数与边数
	}ALGraph;
	//计算邻接表下有向图顶点的出度与入度
	static void calculateInOutDegrees(ALGraph& graph, int inDegree[], int outDegree[]) {
		for (int i = 0; i < graph.numV; i++) {//初始化每个结点的入度与出度
			inDegree[i] = 0;
			outDegree[i] = 0;
		}
		//计算出度入度
		for (int i = 0; i < graph.numV; i++) {
			auto edge = graph.list[i]->first;
			while (edge != nullptr) {
				outDegree[i]++;         //当前顶点的出度即为该行指向的元素
				inDegree[edge->index]++;//被指向的元素入度加1
				edge = edge->next;
			}
		}
	}
	int printVertices(ALGraph G);
	static void testInOutDegrees() {
		ALGraph graph{};
		graph.numV = 4;
		graph.numE = 5;

		// 顶点信息初始化
		for (int i = 0; i < graph.numV; i++) {
			graph.list[i] = new VertexNode;
			graph.list[i]->data = 'a' + i;
			graph.list[i]->first = nullptr;
		}

		// 添加边 (使用指针方式将边添加到邻接表)
		/*
		*    a → b
		*    ↓   ↓
		*    d ← c
		*/
		// a -> b
		EdgeNode* edge1 = new EdgeNode{ 1, nullptr };
		graph.list[0]->first = edge1;

		// a -> d
		EdgeNode* edge2 = new EdgeNode{ 3, nullptr };
		edge1->next = edge2;

		// b -> c
		EdgeNode* edge3 = new EdgeNode{ 2, nullptr };
		graph.list[1]->first = edge3;

		// b -> d
		EdgeNode* edge4 = new EdgeNode{ 3, nullptr };
		edge3->next = edge4;

		// c -> d
		EdgeNode* edge5 = new EdgeNode{ 3, nullptr };
		graph.list[2]->first = edge5;

		int inDegree[MAXV], outDegree[MAXV];
		calculateInOutDegrees(graph, inDegree, outDegree);
		auto kNodeNum = printVertices(graph);
		std::cout << "KNode num:" << kNodeNum << std::endl;
		// 打印每个顶点的入度和出度
		for (int i = 0; i < graph.numV; i++) {
			std::cout << "Vertex " << graph.list[i]->data << ": OutDegree = "
				<< outDegree[i] << ", InDegree = " << inDegree[i] << std::endl;
		}
	}
	//408-DS-2021
	//判断图G是否存在EL路径（G中度为奇数的顶点个数为不大于2的偶数时，G存在包含所有边且长度为|E|的路径），存在返回1否则返回0
	/*
	* 假设有以下无向连通图G （在无向图中，入度和出度相同，等于该顶点所在行或列中非零元素的总和）
	*     a
	*    / \
	*   b   c
	*    \ /
	*     d
	* 1.若度为奇数的顶点个数为0个或2个，则存在EL路径
	* 2.计算各节点的度以判断奇偶
	*/
	static int IsExistEL(MGraph G) {
		int countOdds = 0;    //度为奇数的顶点个数
		for (int i = 0; i < G.numV; i++) {
			int degree = 0;   //度
			for (int j = 0; j < G.numV; j++) {
				degree += G.Edge[i][j];//计算顶点i的度即统计所在行的非0元素总和
			}
			if (degree % 2 != 0) {//奇数
				countOdds++;
			}
		}
		if (countOdds == 0 || countOdds == 2) return 1;
		else return 0;
	}
	static void testIsExistEL() {
		MGraph graph{};
		initUndirectedGraph(graph);
		if (IsExistEL(graph)) {
			std::cout << "The undirected graph has an EL path or circuit.\n";
		}
		else {
			std::cout << "The undirected graph does not have an EL path or circuit.\n";
		}
	}
	//408-DS-2023
	//G为有向图
	//图中出度大于入度的顶点称为K顶点，统计K结点个数并输出
	//时间复杂度为O(n^2)
	//空间复杂度为O(n^2)
	static int printVertices(MGraph G) {
		int countKNode = 0;             //K结点个数
		for (int i = 0; i < G.numV; i++) {
			int inDegree = 0;
			int outDegree = 0;
			for (int j = 0; j < G.numV; j++) {
				inDegree += G.Edge[j][i]; //统计顶点i的入度
			}
			for (int j = 0; j < G.numV; j++) {
				outDegree += G.Edge[i][j];//统计顶点i的出度
			}
			if (outDegree > inDegree) {
				std::cout << "KNode:" << G.VerticesList[i] << std::endl;
				countKNode++;
			}
		}
		return countKNode;
	}
	static void testprintVertices() {
		MGraph graph{};
		initMGraph(graph);
		auto kNodeNum = printVertices(graph);
		std::cout << "KNode num:" << kNodeNum << std::endl;
	}
	//408-DS-2021 Modified
	//时间复杂度：O(|V|+|E|)
	//空间复杂度：O(1)
	static int IsExistEL(ALGraph G) {
		int countOdds = 0;    //度为奇数的顶点个数
		for (int i = 0; i < G.numV; i++) {
			int degree = 0;
			for (auto p = G.list[i]->first; p != nullptr; p = p->next) {
				degree++;
			}
			if (degree % 2 != 0) {//奇数
				countOdds++;
			}
		}
		if (countOdds == 0 || countOdds == 2) return 1;
		else return 0;
	}
	//408-DS-2023Modified
	static int printVertices(ALGraph G) {
		int countKNode = 0;
		std::vector<int> inDegree(G.numV,0);
		std::vector<int> outDegree(G.numV,0);
		for (int i = 0; i < G.numV; i++) {
			for (EdgeNode* p = G.list[i]->first; p != nullptr; p = p->next) {
				outDegree[i]++;
				inDegree[p->index]++;//被指向的元素入度加1
			}
		}
		for (int i = 0; i < G.numV; i++) {
			if (outDegree[i] > inDegree[i]) {
				std::cout << "KNode:" << G.list[i]->data << std::endl;
				countKNode++;
			}
		}
		return countKNode;
	}

}//namespace Graph
namespace string {
	//KMP算法
	//1.计算next数组
	/*
	* j(0) i(1)
	*  |     |
	*  A     B A B C
	*/
	static std::vector<int> calNext(const std::string&pattern/*eg:ABABCABAB*/) {
		int i = 1, j = 0;//j为最长公共前缀长度
		int pattern_size = pattern.size();
		std::vector<int> next(pattern_size, 0);//创建next数组
		for (; i < pattern_size; i++) {
			while (j > 0 && pattern[i] != pattern[j]) {
				j = next[j - 1];
			}
			if (pattern[i] == pattern[j]) {
				++j;
			}
			/*
			* i = 1 ,j = 0 时,pattern[1] != pattern[0] next[1] = 0
			* i = 2 ,j = 0 时,pattern[2] == pattern[0],j++,next[2] = 1 
			* i = 3 ,j = 1 时,pattern[3] == pattern[1],j++,next[3] = 2 
			* i = 4 ,j = 2 时,pattern[4] != pattern[2] j = next[2 - 1] = 0 ,next[4] = 0
			* i = 5 ,j = 0 时,pattern[5] == pattern[0] ,j++,next[5] = 1
			* i = 6 ,j = 1 时,pattern[6] == pattern[1] ,j++,next[6] = 2
			* i = 7 ,j = 2 时,pattern[7] == pattern[2] ,j++,next[7] = 3
			* i = 8 ,j = 3 时,pattern[8] == pattern[3] ,j++,next[7] = 4
			*/
			next[i] = j; 
		}
		return next;
	}
	//KMP Search函数
	static std::vector<int> KMP_(const std::string& mainString/*eg:ABABDABACD*/, const std::string& pattern) {
		std::vector<int> next = calNext(pattern);//next数组
		std::vector<int> result;
		int n = mainString.size();
		int m = pattern.size();
		int j = 0;//模式串指针
		for (int i = 0; i < n; i++) {//遍历主串
			while (j > 0 && mainString[i] != pattern[j]) {//主串与模式串失配后，模式串指针只需跳转到next数组中记录的可跳过匹配的字符个数的下一位
				j = next[j - 1];
			}
			if (mainString[i] == pattern[j]) {
				j++;
			}
			if (j == m) {
				result.push_back(i - m + 1);
				j = next[j - 1];
			}
		}
		return result;
	}
	static void testKMP() {
		std::string text = "ABABDABACDABABCABAB";
		std::string pattern = "ABABCABAB";
		std::vector<int> matches = KMP_(text, pattern);

		std::cout << "Pattern found at indices: ";
		for (auto& i : matches) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}//namespace string
static int f1(unsigned n) {
	for (unsigned i = 0; i <= n - 1; i++) {

	}
}
static void datafloat() {
	int m = 13;
	float a = 12.6, x;
	x = m / 2 + a / 2;
	printf_s("%f\n", x);
}
static int call_count = 0;
static int Facl(int n) {
	call_count++;
	if (n <= 3) {
		return 1;
	}
	else return Facl(n - 2) + Facl(n - 4) + 1;
}
// 重置计数函数
static void reset_count() {
	call_count = 0;
}
namespace Tree {
#include "TreeHeaderFile.h"
	//01.后序遍历二叉树(递归)
	template<typename ElemType>
	static void postOrderTraversal1(BiTNode<ElemType>* root) {
		if (root == nullptr) return;
		postOrderTraversal1(root->lchild);
		postOrderTraversal1(root->rchild);
		std::cout << root->data << " ";
	}
	//01.后序遍历二叉树(非递归)
	/*
	*    1
	*   / \
	*  2   3
	* / \ / \
	* 4 5 6 7
	* 后序遍历：4 5 2 6 7 3 1 
	*/
	template<typename ElemType>
	static std::vector<ElemType> postOrderTraversal2(BiTNode<ElemType>* root) {
		std::vector<ElemType> result;
		if (!root) return result;
		std::stack<BiTNode<ElemType>*> traversalStack;//遍历栈
		std::stack<BiTNode<ElemType>*> outputStack;   //输出栈
		traversalStack.push(root);
		while (!traversalStack.empty()) {
			BiTNode<ElemType>* node = traversalStack.top();
			traversalStack.pop();
			outputStack.push(node);
			if (node->lchild) {
				traversalStack.push(node->lchild);
			}
			if (node->rchild) {
				traversalStack.push(node->rchild);
			}
		}
		while (!outputStack.empty()) {
			result.push_back(outputStack.top()->data);
			outputStack.pop();
		}
		return result;
	}
	//创建一棵完全二叉树
	template<typename ElemType>
	static BiTNode<ElemType>* CreaBitNode() {
		BiTNode<ElemType>* root = new BiTNode<ElemType>(1);
		root->lchild = new BiTNode<ElemType>(2);
		root->rchild = new BiTNode<ElemType>(3);
		root->lchild->lchild = new BiTNode<ElemType>(4);
		root->lchild->rchild = new BiTNode<ElemType>(5);
		root->rchild->lchild = new BiTNode<ElemType>(6);
		root->rchild->rchild = new BiTNode<ElemType>(7);
		return root;
	}
	static void postOrder1() {
		// 创建一个简单的二叉树
		BiTNode<int>* root = CreaBitNode<int>();
		std::cout << "后序遍历结果(递归): ";
		postOrderTraversal1(root);
		std::cout << std::endl;
	}
	static void postOrder2() {
		// 创建一个简单的二叉树
		BiTNode<int>* root = CreaBitNode<int>();
		// 进行后序遍历
		std::vector<int> result = postOrderTraversal2(root);
		std::cout << "后序遍历结果(非递归): ";
		for (int val : result) {
			std::cout << val << " "; 
		}
		std::cout << std::endl;
	}
	//02.自下而上从右至左的层次遍历算法
	template<typename ElemType>
	std::vector<std::vector<ElemType>> levelOrderBottomRightToLeft(BiTNode<ElemType>* root) {
		std::vector<std::vector<ElemType>> result;//存储遍历结果
		if (!root) return result;
		std::queue<BiTNode<ElemType>*> queueLevel;//用于层次遍历
		queueLevel.push(root);
		while (!queueLevel.empty()) {
			std::vector<ElemType> curNodeData;   //存放本层数据
			int curLevelSize = queueLevel.size();//统计本层结点个数
			for (auto i = 0; i < curLevelSize; i++) {
				BiTNode<ElemType>* curNode = queueLevel.front();
				queueLevel.pop();
				curNodeData.push_back(curNode->data);
				if (curNode->rchild) {//先添加右子树
					queueLevel.push(curNode->rchild);
				}
				if (curNode->lchild) {//再添加左子树
					queueLevel.push(curNode->lchild);
				}
			}
			result.insert(result.begin(), curNodeData);//将结果插入到前面以实现自下而上
		}
		return result;
	}
	static void levelOrderTest() {
		BiTNode<int>* root = CreaBitNode<int>();
		std::vector<std::vector<int>> result = levelOrderBottomRightToLeft<int>(root);
		std::cout << "自下而上从右至左的层次遍历结果: " << std::endl;
		for (const auto& level:result) {
			for (auto data : level) {
				std::cout << data << " ";
			}
		}
		std::cout << std::endl;
	}
	//并查集
	class UnionFind {
	public:
		
	private:
		std::vector<int> parent;
		std::vector<int> rank;//用于按秩合并
	};
}//namespace Tree
namespace F408{
	namespace FEx10 {
		static void reverse(std::vector<int>& a, int start, int end) {
			//双指针扫描
			for (int i = start, j = end; i < j; i++, j--) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		static void traversal(std::vector<int>& a, int p, int n) {
			reverse(a, 0, p - 1);
			reverse(a, p, n - 1);
			reverse(a, 0, n - 1);
		}
		static void testtraversal() {
			std::vector<int> a;
			for (int i = 0; i < 10; i++) {
				if (i % 2 == 0) {
					a.push_back(i + 1);
				}
				else
				{
					a.push_back(i - 1);
				}
			}
			for (const auto& b : a) {
				std::cout << b << " ";
			}
			std::cout << std::endl;
			traversal(a, a.size() / 2, a.size());
			for (const auto& b : a) {
				std::cout << b << " ";
			}
			std::cout << std::endl;
		}
	}//FEx10
	namespace FEx12 {
		struct Node
		{
			char a;
			struct Node* next;
		};
		// 计算链表的长度
		size_t getLength(Node* head) {
			size_t length = 0;
			while (head != nullptr) {
				length++;
				head = head->next;
			}
			return length;
		}
		static Node* common(Node* a/*str1*/, Node* b/*str2*/) {
			size_t lena = getLength(a);
			size_t lenb = getLength(b);
			Node* p = a;
			Node* q = b;
			// 让较长的链表先走，直到两个链表长度相等
			while (lena > lenb) {//When lena is equal to lena ,break while
				p = p->next;
				lena--;
			}
			while (lena < lenb) {//When lena is equal to lena ,break while
				q = q->next;
				lenb--;
			}
			// 同时遍历两个链表，直到找到公共后缀
			while (p != nullptr && q != nullptr && p != q) {
				p = p->next;
				q = q->next;
			}
            // 返回公共后缀的起始位置
			return p;
		}
		static void testcommon() {
			// 创建链表
			 // 创建公共后缀 "ing"
			Node commonNode3 = { 'g', nullptr };
			Node commonNode2 = { 'n', &commonNode3 };
			Node commonNode1 = { 'i', &commonNode2 };

			// 创建链表 "loading"
			Node listA4 = { 'd', &commonNode1 };
			Node listA3 = { 'a', &listA4 };
			Node listA2 = { 'o', &listA3 };
			Node listA1 = { 'l', &listA2 };

			// 创建链表 "being"
			Node listB2 = { 'e', &commonNode1 };
			Node listB1 = { 'b', &listB2 };

			// 测试查找公共后缀
			Node* result = common(&listA1, &listB1);

			if (result != nullptr) {
				std::cout << "Common suffix starts at node with char: " << result->a << std::endl;
			}
			else {
				std::cout << "No common suffix found." << std::endl;
			}
		}
	}//FEx12
	namespace FEx13 {
		/*
		* 时间复杂度为O(n)
		* 空间复杂度为O(1)
		*/
		static int findMainElem(std::vector<int>& A, int n) {
			std::vector<int> count(n);
			for (int i = 0; i < n; i++) {
				count[A[i]]++;
			}
			for (int i = 0; i < n; i++) {
				if (count[i] > n / 2) {
					return i;//i即为主元素
				}
			}
			return -1;
		}
		static void testfindMainElem() {
			std::vector<int> A{ 0,5,5,3,5,7,5,5 };
			std::cout << "主元素为：" << findMainElem(A, A.size()) << std::endl;
			std::vector<int> B{ 0,5,5,3,5,1,5,7 };
			std::cout << "主元素为：" << findMainElem(B, B.size()) << std::endl;
		}
	}//namespace FEx13 
	namespace FEx15 {
		struct LinkNode
		{
			int data;
			struct LinkNode* next;
		};
		static LinkNode* deleteed(LinkNode* head) {
			if (head == nullptr || head->next == nullptr) {
				return head;
			}
			std::unordered_set<int> visited;
			LinkNode* prev = head;      //指向头结点
			LinkNode* curr = head->next;//指向第一个实际结点
			while (curr != nullptr) {
				int absdata = std::abs(curr->data);
				if (visited.find(absdata) != visited.end()) {
					prev->next = curr->next;//跳过当前结点
				}
				else {
					visited.insert(absdata);//值第一次出现则插入set集合
					prev = curr;            //继续遍历
				}
				curr = prev->next;
			}
			return head;
		}
		static void printList(LinkNode* head) {
			LinkNode* curr = head->next; // 跳过头节点
			while (curr != nullptr) {
				std::cout << curr->data << " ";
				curr = curr->next;
			}
			std::cout << std::endl;
		}
		static void test() {
			// 创建一个带头节点的链表
			LinkNode* head = new LinkNode{ 0, nullptr }; // 头节点，数据域为 0 但不会用到
			LinkNode* node1 = new LinkNode{ 21, nullptr };
			LinkNode* node2 = new LinkNode{ -15, nullptr };
			LinkNode* node3 = new LinkNode{ -15, nullptr };
			LinkNode* node4 = new LinkNode{ -7, nullptr };
			LinkNode* node5 = new LinkNode{ 15, nullptr };

			head->next = node1;
			node1->next = node2;
			node2->next = node3;
			node3->next = node4;
			node4->next = node5;
			LinkNode* result = deleteed(head);
			printList(result);
		}
	}//namespace FEx15 
	namespace FEX16 {

	}//namespace FEx16
	//2019
	namespace FEx19 {
		/*
		* 设线性表L=(a1,a2,a3,...,an-2,an-1,an)采用带头节点的单链表保存，链表中的结点定义如下：
          typedef struct node{
            int data;
            struct node*next;
          }Node;
          设计一个空间复杂度为O(1)且时间上尽可能高效的算法，
		  重新排列L中各节点，得到线性表L1=（a1,an,a2,an-1,a3,an-2...）
          1)给出算法的基本设计思想
          2)使用C++描述算法，给出注释
          3)说明时间复杂度
		*/
		typedef struct Node {
			int data;
			struct Node* next;
		};
		static void rearrangeList(Node* head) {
			if (!head || !head->next || !head->next->next) {
				return; // 如果链表为空、只有一个元素或两个元素，直接返回
			}

			// 找到链表的尾节点
			Node* tail = head;
			while (tail->next) {
				tail = tail->next;
			}

			// 使用双指针重新排列节点
			Node* current = head->next; // current指向第一个有效元素
			while (current != tail && current->next != tail) {
				// 保存当前节点的下一个节点
				Node* nextNode = current->next;

				// 断开尾节点和倒数第二个节点之间的链接
				tail->next = current->next;
				current->next = nullptr;  // current节点指向null，避免环路

				// 将 current 插入到尾节点后面
				tail->next->next = nextNode;

				// 移动 current 和 tail
				current = nextNode;
				tail = tail->next;
			}
		}
	}
	//2020
	namespace FEx20 {
		//计算当前最小距离
		static int calculateDistance(int a, int b, int c) {
			return std::abs(a - b) + std::abs(b - c) + std::abs(c - a);
		}
		static std::tuple<int, int, int> findMinimumDistance(const std::vector<int>& S1, const std::vector<int>& S2, const std::vector<int>& S3) {
			int i{ 0 }, j{ 0 }, k{ 0 };//三个指针分别指向三个数组的首位置
			int minDistance = INT_MAX;
			int min_a = S1[0], min_b = S2[0], min_c = S3[0];
			while (i < S1.size() && j < S2.size() && k < S3.size()) {
				int a = S1[i];
				int b = S2[j];
				int c = S3[k];
				//计算当前三元组的距离
				int curDistance = calculateDistance(a, b, c);
				//如果比之前记录的最小距离更小，则更新最小距离和当前三元组。
				if (curDistance < minDistance) {
					min_a = a;
					min_b = b;
					min_c = c;
					minDistance = curDistance;
				}
				//比较当前三元组中S1[i],S2[j],S3[k]的最小值，将最小值的指针向前移动异步，以便进一步缩小距离
				if (a <= b && a <= c) {
					i++;
				}
				else if (b <= a && b <= c) {
					j++;
				}
				else {
					k++;
				}
			}
			return { min_a,min_b,min_c };
		}
		static void testTupleMinelem() {
			std::vector<int> S1 = { -1, 0, 9 };
			std::vector<int> S2 = { -25, -10, 10, 11 };
			std::vector<int> S3 = { 2, 9, 17, 30, 41 };

			auto [a, b, c] = findMinimumDistance(S1, S2, S3);
			int minDistance = calculateDistance(a, b, c);

			std::cout << "最小距离: " << minDistance << std::endl;
			std::cout << "对应的三元组: {" << a << ", " << b << ", " << c << "}" << std::endl;
		}
	}//namespace FEx20
}//F408
namespace Sorting {
	void printArray(const std::vector<int>& arr);
	//1.直接插入排序
	static void DirectInsertion(std::vector<int>& arr) {
		int n = arr.size();
		for (int i = 1; i < n; i++) {
			int key = arr[i];//保存当前下标元素
			int j = i - 1;
			while (j >= 0 && arr[j] > key) {//如果已排序序列大于当前元素
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;//插入key
 		}
	}
	static void testDirectInsertion() {
		std::vector<int> arr = { 12, 11, 13, 5, 6 };
		std::cout << "排序前的数组: ";
		printArray(arr);
		DirectInsertion(arr);
		std::cout << "排序后的数组: ";
		printArray(arr);
	}
	//2.选择排序
	
	// 打印数组
	static void printArray(const std::vector<int>& arr) {
		for (int num : arr) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
}//namespace Sorting
static void testnamespaceSorting() {
	Sorting::testDirectInsertion();
}
//链表
namespace LinkedNode {
	//using namespace std;
	struct LNode
	{
		int data;
		struct LNode* next; 
	};
	//1.判断是否有环
	static LNode* findCycle(LNode* head) {
		if (head == nullptr) return nullptr;
		LNode* slow = head;
		LNode* fast = head;
		while (fast && fast->next) {
			slow = slow->next;//慢指针走一步
			fast = fast->next->next;
			if (fast == slow) break;//找到相遇点
		}
		// 如果无环，返回 nullptr
		if (!fast || !fast->next) return nullptr;
		slow = head;//慢指针回到原点
		while (fast != slow) {
			slow = slow->next;
			fast = fast->next;//快指针只走一步
		}//fast=slow
		return fast;
	}
#if 1
	// 辅助函数：创建无环链表
	static LNode* createList(const std::vector<int>& values) {
		if (values.empty()) return nullptr;

		LNode* head = new LNode(values[0]);
		LNode* current = head;

		for (size_t i = 1; i < values.size(); ++i) {
			current->next = new LNode(values[i]);
			current = current->next;
		}
		return head;
	}

	// 辅助函数：创建有环链表
	static LNode* createCycleList(const std::vector<int>& values, int pos) {
		if (values.empty()) return nullptr;

		LNode* head = new LNode(values[0]);
		LNode* current = head;
		LNode* cycleNode = nullptr;

		for (size_t i = 1; i < values.size(); ++i) {
			current->next = new LNode(values[i]);
			current = current->next;
			if (static_cast<int>(i) == pos) {
				cycleNode = current;
			}
		}
		// 形成环
		if (cycleNode) {
			current->next = cycleNode;
		}

		return head;
	}

	// 辅助函数：释放链表内存
	static void freeList(LNode* head) {
		if (!head) return;

		std::unordered_set<LNode*> visited; // 避免死循环（有环）
		while (head && visited.find(head) == visited.end()) {
			visited.insert(head);
			LNode* temp = head;
			head = head->next;
			delete temp;
		}
	}

	// 测试函数
	static void testFindCycle() {
		std::cout << "测试用例 1：无环链表" << std::endl;
		LNode* list1 = createList({ 1, 2, 3, 4, 5 });
		LNode* result1 = findCycle(list1);
		std::cout << "结果: " << (result1 ? "有环，入口点值：" + (result1->data) : "无环") << std::endl;
		freeList(list1);

		std::cout << "测试用例 2：有环链表，环从第 2 个节点开始" << std::endl;
		LNode* list2 = createCycleList({ 1, 2, 3, 4, 5 }, 1); // 环入口在值为 2 的节点
		LNode* result2 = findCycle(list2);
		std::cout << "结果: " << (result2 ? "有环，入口点值：" + (result2->data) : "无环") << std::endl;
		freeList(list2);

		std::cout << "测试用例 3：有环链表，环从第 4 个节点开始" << std::endl;
		LNode* list3 = createCycleList({ 1, 2, 3, 4, 5 }, 3); // 环入口在值为 4 的节点
		LNode* result3 = findCycle(list3);
		std::cout << "结果: " << (result3 ? "有环，入口点值：" + (result3->data) : "无环") << std::endl;
		freeList(list3);

		std::cout << "测试用例 4：空链表" << std::endl;
		LNode* list4 = nullptr;
		LNode* result4 = findCycle(list4);
		std::cout << "结果: " << (result4 ? "有环，入口点值：" + (result4->data) : "无环") << std::endl;
	}
#endif
	//2.删除链表中所有值为 x 的节点
	static void deleteNodesWithValue(LNode* head, int x) {
		if (!head) return;
		LNode* prev = head, * curr = head->next;//prev指向头结点，curr指向第一个实际结点
		while (curr) {
			if (curr->data == x) {      //找到要删除的结点
				prev->next = curr->next;//保存要删除的结点的下一个结点，即断开连接
				delete curr;            //物理删除当前结点
				curr = prev->next;      //更新当前结点
			}
			else {                      //不是要删除的结点
				prev = curr;            //更新前驱结点
				curr = curr->next;      //更新当前结点
			}
		}
	}
	static void printList(LNode* head) {
		LNode* current = head->next;    // 跳过头节点
		while (current) {
			std::cout << current->data << " -> ";
			current = current->next;
		}
		std::cout << "NULL" << std::endl;
	}

	static void testdeleteNode() {
		LNode* head = new LNode(0); // 头节点（不存储数据）
		head->next = new LNode(1);
		head->next->next = new LNode(2);
		head->next->next->next = new LNode(1);
		head->next->next->next->next = new LNode(3);

		std::cout << "Original List: ";
		printList(head);

		// 删除所有值为 1 的节点
		deleteNodesWithValue(head, 1);

		std::cout << "After Deleting 1s: ";
		printList(head);

		// 释放链表内存
		LNode* current = head;
		while (current) {
			LNode* temp = current;
			current = current->next;
			delete temp;
		}
	}
}
int main()
{
#if 0
#if 0
	TestSeqStackHeader();
	TestLinkedStackHeader();
	TestDoubleLinkedStackHeader();
	QuickSort::TestGetMid();
	QuickSort::TestGetMainElem();
	QuickSort::TestCalMinElem();
	QuickSort::TestGetKMinElem();
	QuickSort::TestMerge();
	QuickSort::TestGetMidMerge();
#endif
#if 0
	LinkedList::TestLinkList();
	LinkedList::TestfindKNode();
	LinkedList::testfindCommonFirstAddr();
	LinkedList::TestDeleteX();
	LinkedList::testLinkListReverse();
	LinkedList::testLinkListReverseTail();
#endif
#if 0
	BinaryTree::TestTree();
	BinaryTree::testisBSTTree();
#endif
#if 0
	Graph::testMGraph();
	Graph::testDegree();
	Graph::testIsExistEL();
	Graph::testprintVertices();
	Graph::testInOutDegrees();
	string::testKMP();
	datafloat();
#endif
	reset_count();
	int result = Facl(8);
	std::cout << "Result: " << result << ", Call Count: " << call_count << std::endl;
#endif
#if 0
	Tree::postOrder1();
	Tree::postOrder2();
	Tree::levelOrderTest();
#endif
	//F408::FEx10::testtraversal();
	//F408::FEx12::testcommon();
	//F408::FEx13::testfindMainElem();
	//F408::FEx15::test();
	//F408::FEx20::testTupleMinelem();
	//testnamespaceSorting();
	unsigned short x = 65530;
	unsigned int y = x;
	std::cout << std::hex << x <<" "  <<  y << std::endl;
	//LinkedNode::testFindCycle();
	LinkedNode::testdeleteNode();
	return 0;
	
}

