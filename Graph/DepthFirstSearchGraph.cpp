//
//https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/?ref=rp
// 
#include "stdafx.h"
#include <list>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;


namespace DepthFirstSearchGraph_Mine
{
	class Graph
	{
		list<int> *edges;
		int n;
	public:
		Graph(int _n)
		{
			this->edges = new list<int>[_n];
			this->n = _n;
		}

		void AddEdge(int start, int end)
		{
			this->edges[start].push_back(end);
		}


		void DfsSub(int start, bool *visited, int *v, int *n)
		{
			v[*n] = start;
			(*n)++;
			visited[start] = true;

			for (list<int>::iterator it = this->edges[start].begin(); it != this->edges[start].end(); it++)
			{
				if (visited[*it] == true)	continue;
				DfsSub(*it, visited, v, n);
			}
		}

		void DFS(int start)
		{
			bool *visited = new bool[this->n];
			for (int i = 0; i < this->n; i++)	visited[i] = false;

			int *v = new int[this->n];
			for (int i = 0; i < this->n; i++)	v[i] = 0;

			int n = 0;
			DfsSub(start, visited, v, &n);

			for (int i = 0; i < n; i++)	printf("%d ", v[i]);

			printf("\n");
		}

	};

	// Driver code 
	int Run ()
	{
		// Create a graph given in the above diagram 
		Graph g(4);
		g.AddEdge(0, 1);
		g.AddEdge(0, 2);
		g.AddEdge(1, 2);
		g.AddEdge(2, 0);
		g.AddEdge(2, 3);
		g.AddEdge(3, 3);

		cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";
		g.DFS(2);

		return 0;
	}
};


namespace DepthFirstSearchGraph_Undirected
{
	class Graph
	{
		int V; // No. of vertices 
		list<int> *adj; // Pointer to an array containing adjacency lists 
		void DFSUtil(int v, bool visited[]); // A function used by DFS 
	public:
		Graph(int V); // Constructor 
		void addEdge(int v, int w); // function to add an edge to graph 
		void DFS(); // prints DFS traversal of the complete graph 
	};

	Graph::Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}

	void Graph::addEdge(int v, int w)
	{
		adj[v].push_back(w); // Add w to v’s list. 
	}

	void Graph::DFSUtil(int v, bool visited[])
	{
		// Mark the current node as visited and print it 
		visited[v] = true;
		cout << v << " ";

		// Recur for all the vertices adjacent to this vertex 
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
			if (!visited[*i])
				DFSUtil(*i, visited);
	}

	// The function to do DFS traversal. It uses recursive DFSUtil() 
	void Graph::DFS()
	{
		// Mark all the vertices as not visited 
		bool *visited = new bool[V];
		for (int i = 0; i < V; i++)
			visited[i] = false;

		// Call the recursive helper function to print DFS traversal 
		// starting from all vertices one by one 
		for (int i = 0; i < V; i++)
			if (visited[i] == false)
				DFSUtil(i, visited);
	}

	int Run ()
	{
		// Create a graph given in the above diagram 
		Graph g(4);
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
		g.addEdge(2, 0);
		g.addEdge(2, 3);
		g.addEdge(3, 3);

		cout << "Following is Depth First Traversaln";
		g.DFS();

		return 0;
	}

};



namespace DepthFirstSearchGraph_Undirected_Stack
{

	class Graph
	{
		int n;
		queue <int> *edges;

	public:
		Graph(int _n)
		{
			edges = new queue<int>[_n];
			n = _n;
		}

		void AddEdge(int v1, int v2)
		{
			edges[v1].push(v2);
		}

		void DFS(int v)
		{
			bool *visited = new bool[n];
			for (int i = 0; i < n; i++)	visited[i] = false;

			stack<int> vertices;
			bool next = true;
			vertices.push(v);

			while (vertices.empty() == false)
			{
				if (visited[v] == false)
				{
					printf(" %d", v);
					visited[v] = true;
				}
				else
				{
					v = vertices.top();
					vertices.pop();
				}

				next = false;
				int v2 = -1;
				while (!edges[v].empty())
				{
					v2 = edges[v].front();
					edges[v].pop();
					if (visited[v2] == false)
					{
						next = true;
						vertices.push(v2);
						v = v2;
						break;
					}
				}
				if (next == false && vertices.empty() != true)
				{
					v = vertices.top();
					vertices.pop();
				}
			}


		}
	};

	int Run ()
	{
		// Create a graph given in the above diagram 
		Graph g(4);
		g.AddEdge(0, 1);
		g.AddEdge(0, 2);
		g.AddEdge(1, 2);
		g.AddEdge(2, 0);
		g.AddEdge(2, 3);
		g.AddEdge(3, 3);

		cout << "Following is Depth First Traversaln";
		g.DFS(0);

		return 0;
	}


};


int DepthFirstSearchGraph_Test()
{
	DepthFirstSearchGraph_Mine::Run ();

	cout << endl;

	DepthFirstSearchGraph_Undirected::Run ();

	cout << endl;

	DepthFirstSearchGraph_Undirected_Stack::Run();

	cout << endl;

	return 0;

}