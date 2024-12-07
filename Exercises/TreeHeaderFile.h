#pragma once
template<typename ElemType>
struct BiTNode
{
	ElemType data;
	BiTNode<ElemType>* lchild, * rchild; 
	BiTNode() : lchild(nullptr), rchild(nullptr) {}
	BiTNode(ElemType value) : data(value), lchild(nullptr), rchild(nullptr) {}
};