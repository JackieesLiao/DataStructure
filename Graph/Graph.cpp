// Graph.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// Author  : jeanxliao
// Communication : jeanxliao1018@gmail.com
// Time    : 2024/05/28
// LICENSE  : MIT LICENSE
#include <iostream>
#include <vector>
#include <queue>
namespace Graph
{
	using namespace std;
	/// BFS 优先搜索图的广度，即先访问与起点距离最近的节点。
	/// BFS 相当于二叉树中的层序遍历
	static void BFS(int start, vector<vector<int>>& graph)
	{
		//定义一个辅助数组判断节点是否已访问
		vector<bool> visited(graph.size(), false);
		queue<int> queue;
		//首先顶点入队
		visited[start] = true;
		queue.push(start);
		while (!queue.empty()) {
			int node = queue.front();
			queue.pop();
			cout << node << " ";
			for (auto& neighbor : graph[node]) {//顶点的邻接节点
				if (!visited[neighbor]) {
					visited[neighbor] = true;
					queue.push(neighbor);
				}
			}
		}
	}
	static void testBFS1()
	{
		//vector<vector<int>> graph = {
		//{1, 2},
		//{0, 3, 4},
		//{0, 4},
		//{1, 5},
		//{1, 2},
		//{3}
		//};
		/*
		* Graph:
		*    0
		*   / \
		*  1   2
		* / \ / \
		* 3 4 5 6
		*   
		*/
		vector<vector<int>> graph = {
			{1,2},
			{0,3,4},
			{0,5,6},
			{1},
			{1},
			{2},
			{2},
			{4}
		};
		BFS(0, graph);
	}
	/// DFS 优先搜索图的深度，即尽可能深入到图的叶节点。
	/// DFS 使用栈(可以使用递归实现)来存储待访问的节点，首先将起点入栈，然后重复以下步骤直到栈为空：
	/// 1.从栈中取出一个节点进行访问。
	/// 2.将该节点的所有未访问的邻居节点入栈。
	/// <summary>
	/// DFS遍历相当于二叉树中的先序遍历
	/// </summary>
	/// <param name="node">图里的各节点</param>
	/// <param name="visited">辅助数组用于判断是否已经遍历</param>
	/// <param name="graph">图</param>
	static void DFSUtil(int node, vector<bool>& visited, const vector<vector<int>>& graph)
	{
		visited[node] = true;
		cout << node << " ";
		for (auto& neighbor : graph[node]) {
			if (!visited[neighbor]) {
				DFSUtil(neighbor, visited, graph);
			}
		}
	}
	static void DFS(int start, const vector<vector<int>>& graph) {
		vector<bool> visited(graph.size(), false);
		DFSUtil(start, visited, graph);
	}
	static void testDFS1()
	{
		vector<vector<int>> graph = {
			{1,2},
			{0,3,4},
			{0,5,6},
			{1},
			{1},
			{2},
			{2},
			{4}
		};
		DFS(0, graph);
	}
}//Graph
namespace GraphUtilmate {
	using namespace std;
	/// 1）使用邻接矩阵实现BFS
	static void BFS_AdjMatrix(int start, const vector<vector<int>>& graph)
	{
		vector<bool> visited(graph.size(), false);
		queue<int> queue{};
		visited[start] = true;
		queue.push(start);
		while (!queue.empty()) {
			auto node = queue.front();
			queue.pop();
			cout << node << " ";
			/// 扫描顶点的每一行
			for (auto i{ 0 }; i < graph[node].size(); i++) {
				// 检查当前节点 node 和节点 i 之间是否存在边（graph[node][i] == 1）
				// 并且 i 是否未被访问过（!visited[i]）
				if (graph[node][i] == 1 && !visited[i]) {
					visited[i] = true;
					queue.push(i);
				}
			}
		}
	}
	/// 2）使用邻接表实现BFS
	static void BFS_Adjlist(int start, const vector<vector<int>>& graph)
	{
		vector<bool> visited(graph.size(), false);
		queue<int> queue{};
		visited[start] = true;
		queue.push(start);
		while (!queue.empty()) {
			auto node = queue.front();
			queue.pop();
			cout << node << " ";
			for (auto& neighbor : graph[node]) {
				if (!visited[neighbor]) {
					visited[neighbor] = true;
					queue.push(neighbor);
				}
			}
		}
	}
	/// 3）使用邻接矩阵实现DFS
	static void DFSUtil_AdjMatrix(int node, vector<bool>& visited, const vector<vector<int>>& graph)
	{
		visited[node] = true;
		cout << node << " ";
		for (auto i{ 0 }; i < graph[node].size(); i++) {
			if (graph[node][i] == 1 && !visited[i]) {
				DFSUtil_AdjMatrix(i, visited, graph);
			}
		}
	}
	static void DFS_AdjMatrix(int start, const vector<vector<int>>& graph) {
		vector<bool> visited(graph.size(), false);
		DFSUtil_AdjMatrix(start, visited, graph);
	}
	/// 4）使用邻接表实现DFS
	static void DFSUtil_AdjList(int node, vector<bool>& visited, const vector<vector<int>>& graph)
	{
		visited[node] = true;
		cout << node << " ";
		for (auto& neighbor : graph[node]) {
			if (!visited[neighbor]) {
				DFSUtil_AdjList(neighbor, visited, graph);
			}
		}
	}
	static void DFS_AdjList(int node, const vector<vector<int>>& graph)
	{
		vector<bool> visited(graph.size(), false);
		DFSUtil_AdjList(node, visited, graph);
	}
	/// 5）使用BFS求解单源最短路径问题
	static void BFSForShortestPath(int start, const vector<vector<int>>& graph)
	{
		auto n = graph.size();
		vector<int> distance(n, INT_MAX);//初始化距离为无穷大
		queue<int> queue;
		distance[start] = 0;             //起点到自己的距离为0
		queue.push(start);
		while (!queue.empty()) {
			auto node = queue.front();
			queue.pop();
			for (auto i{ 0 }; i < n; i++) {
				if (graph[node][i] == 1 && distance[i] == INT_MAX) {// 若为1则两个顶点之间存在边并且i这个位置的节点还未访问过
					distance[i] = distance[node] + 1;
					queue.push(i);
				}
			}
		}
		//逐个打印起点到所有节点的最短距离
		for (auto i{ 0 }; i < n; i++) {
			if (distance[i] == INT_MAX) {
				cout << "Node " << i << " is not reachable from start node " << start << "." << endl;
			}
			else {
				cout << "Shortest distance from node " << start << " to node " << i << " is " << distance[i] << "." << endl;
			}
		}
	}
	static void testShortPath() {
		vector<vector<int>> graph = {
			 {0, 1, 1, 0, 0, 0, 0},
			 {1, 0, 0, 1, 1, 0, 0},
			 {1, 0, 0, 0, 0, 1, 1},
			 {0, 1, 0, 0, 0, 0, 0},
			 {1, 0, 0, 0, 0, 0, 0},
			 {0, 0, 1, 0, 0, 0, 0},
			 {0, 0, 1, 0, 0, 0, 0}
		};
		BFSForShortestPath(0, graph);
	}
	/// <summary>
	///  测试邻接表和邻接矩阵下实现的BFS与DFS遍历
	/// </summary>
	namespace BFS_DFS_Test {
		static void testBFS_AdjMatrix()
		{
			vector<vector<int>> graph = {
			 {0, 1, 1, 0, 0, 0, 0},
			 {1, 0, 0, 1, 1, 0, 0},
			 {1, 0, 0, 0, 0, 1, 1},
			 {0, 1, 0, 0, 0, 0, 0},
			 {1, 0, 0, 0, 0, 0, 0},
			 {0, 0, 1, 0, 0, 0, 0},
			 {0, 0, 1, 0, 0, 0, 0}
			};
			BFS_AdjMatrix(0, graph);
		}
		static void testBFS_Adjlist()
		{
			vector<vector<int>> graph = {
			{1,2},
			{0,3,4},
			{0,5,6},
			{1},
			{1},
			{2},
			{2},
			{4}
			};
			BFS_Adjlist(0, graph);
		}
		static void testDFSUtil_AdjMatrix()
		{
			vector<vector<int>> graph = {
			 {0, 1, 1, 0, 0, 0, 0},
			 {1, 0, 0, 1, 1, 0, 0},
			 {1, 0, 0, 0, 0, 1, 1},
			 {0, 1, 0, 0, 0, 0, 0},
			 {1, 0, 0, 0, 0, 0, 0},
			 {0, 0, 1, 0, 0, 0, 0},
			 {0, 0, 1, 0, 0, 0, 0}
			};
			DFS_AdjMatrix(0, graph);
		}
		static void testDFSUtil_AdjList()
		{
			vector<vector<int>> graph = {
			{1,2},
			{0,3,4},
			{0,5,6},
			{1},
			{1},
			{2},
			{2},
			{4}
			};
			DFS_AdjList(0, graph);
		}
	}//BFS_DFS_Test

}//GraphUtilmate
int main()
{
#if 1
	std::cout << "BFS遍历：\n";
	Graph::testBFS1();
	std::cout << std::endl;
	std::cout << "DFS遍历：\n";
	Graph::testDFS1();
#endif
#if 1
	std::cout << "邻接矩阵：BFS遍历:\n";
	GraphUtilmate::BFS_DFS_Test::testBFS_AdjMatrix();
	std::cout << std::endl;
	std::cout << "邻接表：BFS遍历:\n";
	GraphUtilmate::BFS_DFS_Test::testBFS_Adjlist();
	std::cout << std::endl;
	std::cout << "邻接矩阵：DFS遍历:\n";
	GraphUtilmate::BFS_DFS_Test::testDFSUtil_AdjMatrix();
	std::cout << std::endl;
	std::cout << "邻接表：DFS遍历:\n";
	GraphUtilmate::BFS_DFS_Test::testDFSUtil_AdjList();
	std::cout << std::endl;
#endif
	std::cout << "使用BFS求单源最短距离：\n";
	GraphUtilmate::testShortPath();
}