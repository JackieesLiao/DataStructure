// Trees.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "treeStructre.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
//前序非递归遍历
static std::vector<int> preOrderTraversal(TreeNode* root)
{
    std::vector<int> result;
    if (!root) return result;
    std::queue<TreeNode*> node_queue;
    node_queue.push(root);
    while (!node_queue.empty()) {
        TreeNode* node = node_queue.front();
        node_queue.pop();
        result.push_back(node->val);
        if (node->left) {
            node_queue.push(node->left);
        }
        if (node->right) {
            node_queue.push(node->right);
        }
    }
    return result;
}
//中序非递归遍历
static std::vector<int> midOrderTraversal(TreeNode* root)
{
    std::vector<int> result;
    if (!root) return result;
    std::stack<TreeNode*> node_stack;
    TreeNode* current = root;
    while (current != nullptr || !node_stack.empty()) {
        while (current != nullptr) {//遍历到左子树的最左边一个节点
            node_stack.push(current);
            current = current->left;
        }
        current = node_stack.top();//取出栈顶元素
        node_stack.pop();
        result.push_back(current->val);
        current = current->right;
    }
    return result;
}
//后序非递归遍历
static std::vector<int> postOrderTraversal(TreeNode* root)
{
    std::vector<int> result;
    if (!root) return result;
    std::stack<TreeNode*> node_stack;   //遍历节点
    std::stack<TreeNode*> output_stack; //存储遍历结果
    node_stack.push(root);
    while (!node_stack.empty())
    {
        TreeNode* node = node_stack.top();
        node_stack.pop();
        output_stack.push(node);
      
        if (node->left) {
            node_stack.push(node->left);
        }  
        if (node->right) {
            node_stack.push(node->right);
        }
    }
    while (!output_stack.empty()) {
        result.push_back(output_stack.top()->val);
        output_stack.pop();
    }
    return result;
}
/// <summary>
/// 求以孩子兄弟表示法存储森林的叶节点数
/// </summary>
static int CountLeafNode(TreeNodes * root)
{
    if (!root) return 0;
    if (!root->leftChild) {
        return  1 + CountLeafNode(root->rightSibling);
    }
    return CountLeafNode(root->leftChild) + CountLeafNode(root->rightSibling);
}
/// <summary>
/// 以孩子兄弟链表为存储结构，设计递归算法求树的深度
/// </summary>
static int getTreeDepth(TreeNodes* root)
{
    if (!root) return 0;
    auto leftDepth = getTreeDepth(root->leftChild);
    auto rightDepth = getTreeDepth(root->rightSibling);
    return std::max(1 + leftDepth,rightDepth);
}
static void testCountLeafNode()
{
    TreeNodes* root = new TreeNodes(1);
    root->leftChild = new TreeNodes(2);
    root->leftChild->rightSibling = new TreeNodes(3);
    root->leftChild->leftChild = new TreeNodes(4);
    root->leftChild->leftChild->rightSibling = new TreeNodes(5);
    std::cout << "LeafNodes of the tree:" << CountLeafNode(root) << std::endl;
}
static void testGetTreeDepth()
{
    TreeNodes* root = new TreeNodes(1);
    root->leftChild = new TreeNodes(2);
    root->leftChild->rightSibling = new TreeNodes(3);
    root->leftChild->leftChild = new TreeNodes(4);
    root->leftChild->leftChild->rightSibling = new TreeNodes(5);
    std::cout << "Depth of the tree:" << getTreeDepth(root) << std::endl;
}
#if 1
static void testPreOrder()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    std::vector<int> result = preOrderTraversal(root);
    std::cout << "pre order traversal:\n";
    for (auto& value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    delete root;
}
static void testMidOrder()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    std::vector<int> result = midOrderTraversal(root);
    std::cout << "middle order traversal:\n";
    for (auto& value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    delete root;
}
static void testPostOrder()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    std::vector<int> result = postOrderTraversal(root);
    std::cout << "post order traversal:\n";
    for (auto& value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    delete root;
}
#endif
 
int main()
{
#if 0
    testPreOrder();
    testMidOrder();
    testPostOrder();
#endif
    //testCountLeafNode(); 
    testGetTreeDepth();
    return 0;
}