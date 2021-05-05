/*
* https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
* https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
*/

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <list>
#include <map>

using namespace std;

namespace DFS_and_BFS_for_Graph
{
	class Graph
	{
		// Pointer to an array containing adjacency
		map<int, bool> visited;
		map<int, list<int>> adj;
	public:
		Graph() // Constructor
		{
		}

		// function to add an edge to graph
		void addEdge(int v, int w)
		{
			this->adj[v].push_back(w);
		}

		// prints BFS traversal from a given source s
		void BFS(int s)
		{
			map<int, list<int>>::iterator it;
			for (it = this->adj.begin(); it != adj.end(); it++)
			{
				this->visited[it->first] = false;
			}

			queue<int> q;
			q.push(s);
			this->visited[s] = true;

			while (q.empty() == false)
			{
				int v = q.front();
				q.pop();

				cout << v << " ";

				list<int>::iterator it = this->adj[v].begin();
				for (it = this->adj[v].begin(); it != this->adj[v].end(); it++)
				{
					if (this->visited[*it] == false)
					{
						q.push(*it);
						this->visited[*it] = true;
					}
				}
			}
		}

		////////////// 
		void DFS_Sub(int s)
		{
			if (this->visited[s] == true)	return;

			cout << s << " ";
			this->visited[s] = true;

			list<int>::iterator it;
			
			for (it = this->adj[s].begin(); it != this->adj[s].end(); it++)
			{
				DFS_Sub(*it);
			}
		}

		void DFS()
		{
			map<int, list<int>>::iterator it;
			for (it = this->adj.begin(); it != this->adj.end(); it++)
			{
				this->visited[it->first] = false;
			}

			DFS_Sub(0);
		}
	};



};

int DFS_and_BFS_for_Graph_Test()
{
	// Create a graph given in the above diagram
	DFS_and_BFS_for_Graph::Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	cout << "\nFollowing is Depth First Traversal " << " \n";

	g.DFS();

	return 0;

}

