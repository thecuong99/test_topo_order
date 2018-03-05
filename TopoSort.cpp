
#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <string>
#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
	int V; // No. of vertices

	// Pointer trỏ đến list Neighbor của đồ thị
	list<int> *adj;

	// Hàm duyệt đồ thị theo chiều sâu DFS
	void topologicalSortUtil(int v, bool visited[], stack<int> &stack);

public:
	Graph(int V); // constructor

	// Hàm tạo cạnh đến graph
	void addEdge(int v, int w);

	// Gọi hàm duyệt tất cả các đỉnh trong đồ thị
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int a, int b)
{
	adj[a].push_back(b); // Hàm thêm cạnh từ đỉnh a đến đỉnh b.
}

// Hàm duyệt đồ thị theo chiều sâu tính từ đỉnh v được gọi
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;

	// Duyệt tất cả Neighbor của đỉnh v được gọi
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);

	// Lưu vào Stack
	Stack.push(v);
}

// Hàm duyệt qua tất cả các đỉnh có trong đồ thị
void Graph::topologicalSort()
{
	stack<int> Stack;

	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Duyệt qua tất cả các đỉnh trong đồ trị
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// In ra màn hình thứ tự Topo từ Stack
	while (Stack.empty() == false)
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

// driver program
int main()
{
	// Tạo đồ thị 10 đỉnh có hướng từ Chapter 11, trang 35/83
	Graph g(10);
	g.addEdge(0, 1);
	g.addEdge(0, 5);
	g.addEdge(6, 0);
	g.addEdge(6, 2);
	g.addEdge(6, 1);
	g.addEdge(1, 7);
	g.addEdge(8, 7);
	g.addEdge(8, 2);
	g.addEdge(3, 2);
	g.addEdge(3, 4);
	g.addEdge(3, 7);
	g.addEdge(3, 8);
	g.addEdge(4, 8);
	g.addEdge(9, 4);

	cout << "Following is a Topological Sort of the given graph \n";
	g.topologicalSort();
	cout << "\n";
	system("pause");
	return 0;
}