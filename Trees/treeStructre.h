#ifndef TREESTRUCTURE_H
#define TREESTRUCTURE_H
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

struct TreeNodes {
	int val;
	TreeNodes* leftChild;
	TreeNodes* rightSibling;

	TreeNodes(int x) : val(x), leftChild(nullptr), rightSibling(nullptr) {}
};
#endif // !TREESTRUCTURE_H
