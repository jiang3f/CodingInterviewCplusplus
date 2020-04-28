// CodingInterviewCplusplus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AllQuestions.h"
#include <string>
using namespace std;


//#define card_rotation
#ifdef card_rotation
//
// https ://practice.geeksforgeeks.org/problems/card-rotation/0
//
#include <iostream>
#include <queue>

using namespace std;

void print(queue<int> &q)
{
	while (!q.empty())
	{
		int c = q.front();
		cout << c << " ";
		q.pop();
	}
	cout << endl;
}

int main() {
	//code
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;





	}
	return 0;
}
#endif

//#define combination 

#ifdef combination
//
// https://www.geeksforgeeks.org/print-all-the-combinations-of-a-string-in-lexicographical-order/ 
//
#include <map>
#include <string>

// C++ program to find all combinations 
// of a string in lexicographical order 

using namespace std;

class Set
{
public:
	Set(string s) : s(s) {};

	void PrintLine(char c, int start, int num);


private:
	string s;

};

void Set::PrintLine(char c, int start, int num)
{
	if (this->s.at[start] == c)    return;

	cout << c;

	for (int i; i < num; i++)
	{
		if (s.at[start] == c)   start++;
		else
		{
			if (start == s.length())    start = 0;
			cout << s.at[start++];
		}
	}
}

// Driver code 
int main()
{
	string str = "ABC";
	cin >> str;

	combination(str);

	return 0;
}

#endif

//#define bublesort 99999
#ifdef bublesort

void BubbleSort(int data[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			if (data[i] > data[j])
			{
				int value = data[i];
				data[i] = data[j];
				data[j] = value;
			}
		}
	}
}

void main()
{
	int data[] = { 6, -17, 200, -3, 1, 9, 2 };

	int length = sizeof(data) / sizeof(int);
	BubbleSort(data, length);

	for (int i = 0; i < length - 1; i++)
	{
		printf("%d,", data[i]);
	}

	if (length > 0)	printf("%d\n", data[length - 1]);
}
#endif

//#define Expression 999
#ifdef Expression

// { Driver Code Starts

//#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

void preorder(Node *root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}


Node *convertExpression(string str, int i);

int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		Node *root = convertExpression(str, 0);
		preorder(root);
		cout << endl;
	}
}

// } Driver Code Ends
/*Complete the function below
Node is as follows
struct Node{
char data;
Node *left,*right;
};
*/

bool convertExpressionSub(Node *& node, char* p, int* pos, int len)
{
	//if(*pos >= len) return false;
	//if(node != NULL)    return false;
	//if (p[*pos] == '?' || p[*pos] == ':')   return false;

	node = new struct Node(p[*pos]);
	node->left = NULL;
	node->right = NULL;

	(*pos)++;

	// left
	if (p[*pos] == ':' || p[*pos] == NULL)    return true;       //complete right

	if (p[*pos] == '?')
	{
		(*pos)++;
		if (convertExpressionSub(node->left, p, pos, len) == false)  return false;
	}
	//else return false;

	// right
	if (p[*pos] == ':')
	{
		(*pos)++;
		return convertExpressionSub(node->right, p, pos, len);
	}
	else    return false;

}

Node *convertExpression(string str, int i)
{
	//add code here.
	Node *root = NULL;

	char *string = (char *)str.c_str();
	int pos = 0;
	if (!convertExpressionSub(root, string, &pos, i))
	{
		printf("invalid data");
		return NULL;
	}

	return root;
}

#endif

//#define MaxRectangularArea
#ifdef MaxRectangularArea

//#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int w;
	int h;
	struct Node *next;

	Node(int width, int height) {
		w = width;
		h = height;
		next = NULL;
	}
};

int GetMaxRect(int *bars, int num);

#define MAXLEN 1024

int main() {
	char input[MAXLEN];

	cin.getline(input, sizeof(input));
	int t = atoi(input);

	while (t--) {
		cin.getline(input, sizeof(input));
		int n = atoi(input);

		cin.getline(input, sizeof(input));

		int *bars = new int[n];
		char* token = strtok(input, " ");
		int i = 0;
		while (token != NULL) {
			bars[i] = atoi(token);
			i++;
			token = strtok(NULL, " ");
		}
		int size = GetMaxRect(bars, n);
		cout << size;
		cout << endl;
	}
}

int MinHeight(int* bars, int left, int right)
{
	int min = bars[left];
	for (int i = left; i <= right; i++)
	{
		if (min > bars[i])	min = bars[i];
	}
	return min;

}

Node * GetAllRect(int* bars, int num)
{
	Node* root = NULL;

	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			int height = MinHeight(bars, i, j);

			Node * newN = new Node(j - i + 1, height);
			if (root == NULL)	root = newN;
			else
			{
				Node *cur = root;
				while (cur->next != NULL)	cur = cur->next;
				cur->next = newN;
			}
		}
	}

	return root;
};

int GetMaxSize(Node *root)
{
	Node *node = root;
	int max = 0;
	while (node != NULL)
	{
		int size = node->w * node->h;
		if (max < size)	max = size;

		node = node->next;
	}
	return max;
}

void FreeNode(Node *node)
{
}

int GetMaxRect(int *bars, int num)
{
	int size = 0;

	Node * root = GetAllRect(bars, num);

	size = GetMaxSize(root);

	FreeNode(root);

	return size;
}


#endif

//#define MaxRectangualrAREA_Stack
#ifdef MaxRectangualrAREA_Stack

//
//
//https ://ide.geeksforgeeks.org/8jA7QcI0Gl
//

#include <stack> 
using namespace std;

int main() {
	//code
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int *arr = new int[n];
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		arr[n] = 0;
		stack<int>st;
		int i = 0;
		int maxarea = -1; int area = 0;
		while (i<n + 1)
		{
			if (st.empty() || arr[i] >= arr[st.top()])
			{
				st.push(i++);
			}
			else
			{
				int tp = st.top(); st.pop();
				area = arr[tp] * (st.empty() ? i : i - st.top() - 1);
				if (maxarea<area)
				{
					maxarea = area;
				}
			}
		}
		cout << maxarea << '\n';
	}
	return 0;
}
#endif

//#define LargestsubsetofGraphverticeswithedgesof2ormorecolors_mysolution
#ifdef LargestsubsetofGraphverticeswithedgesof2ormorecolors_mysolution


//
// https://www.geeksforgeeks.org/largest-subset-graph-vertices-edges-2-colors/?ref=lbp
//

#define MAX	255
struct Node
{
	int num;
	int color[MAX];

	Node * next;
};

void DeleteNode(Node *& root, int color, int *nRmv, int *rmvColor)
{
	int nextcolor = color;

	while (nextcolor != 0)
	{
		nextcolor = 0;

		for (Node *cur = root; cur != NULL; cur = cur->next)
		{
			for (int i = 0; i < cur->num; i++)
			{
				if (color == cur->color[i])
				{
					for (int j = i; j < cur->num - 1; j++)
					{
						cur->color[j] = cur->color[j + 1];
					}
					cur->color[cur->num - 1] = 0;
					cur->num--;
				}
			}
			if (cur->num == 1)
			{
				nextcolor = cur->color[0];
				rmvColor[*nRmv] = nextcolor;
				(*nRmv)++;
				if (cur == root)
				{
					Node *newRoot = root->next;
					delete root;
					root = newRoot;
				}
				else
				{
					Node *node;
					for (node = root; node->next != cur; node = node->next);
					node->next = cur->next;
					delete cur;
					cur = node;
				}
			}
		}
	};

}

void main()
{

	/*int c[3][3] =
	{
	{ 0, 1, 2 },
	{ 1, 0, 3 },
	{ 2, 3, 0 }
	};

	int n = 3;*/

	/*int c[3][3] =
	{
	{ 0, 1, 1 },
	{ 1, 0, 3 },
	{ 1, 3, 0 }
	};
	int n = 3;*/

	int c[6][6] =
	{
		{ 0, 9, 2, 4, 7, 8 },
	{ 9, 0, 9, 9, 7, 9 },
	{ 2, 9, 0, 3, 7, 6 },
	{ 4, 9, 3, 0, 7, 1 },
	{ 7, 7, 7, 7, 0, 7 },
	{ 8, 9, 6, 1, 7, 0 }
	};
	int n = 6;

	if (n < 3)
	{
		printf("0\n");
		return;
	}

	int nRmvColor = 0;
	int rmvColor[MAX];
	Node *root = NULL;
	for (int i = 0; i < n; i++)
	{
		int nodeColor[MAX];
		int numNodeColor = 0;
		for (int j = 0; j < n; j++)
		{

			if (c[i][j] == 0)	continue;
			bool flag = false;
			int m = 0;
			for (m = 0; m < nRmvColor; m++)
			{
				if (c[i][j] == rmvColor[m])
				{
					flag = true;
					break;
				}
			}

			if (flag)	continue;

			for (int m = 0; m < numNodeColor; m++)
			{
				if (c[i][j] == nodeColor[m])
				{
					flag = true;
					break;
				}
			}
			if (flag)	continue;

			nodeColor[numNodeColor] = c[i][j];
			numNodeColor++;
		}
		if (numNodeColor > 1)
		{
			Node *newN = new Node;
			newN->num = numNodeColor;
			for (int i = 0; i < numNodeColor; i++)
			{
				newN->color[i] = nodeColor[i];
			}
			newN->next = NULL;

			if (root == NULL)
			{
				root = newN;
			}
			else
			{
				Node *cur = NULL;
				for (cur = root; cur->next != NULL; cur = cur->next);
				cur->next = newN;
			}
		}
		else
		{
			DeleteNode(root, nodeColor[0], &nRmvColor, rmvColor);
			rmvColor[nRmvColor] = nodeColor[0];
			nRmvColor++;
		}
	}

	if (root == NULL)	printf("0\n");
	else
	{
		Node *node;
		int size = 0;
		for (node = root; node != NULL; node = node->next)
		{
			size++;
		}
		printf("%d\n", size);
	}

}
#endif

//#define LargestsubsetofGraphverticeswithedgesof2ormorecolors
#ifdef LargestsubsetofGraphverticeswithedgesof2ormorecolors
// C++ program to find size of subset of graph vertex 
// such that each vertex has more than 1 color edges 
#include <set> 
using namespace std;

// Number of vertices 
const int N = 6;

// function to calculate max subset size 
int subsetGraph(int C[][N])
{
	// set for number of vertices 
	set<int> vertices;
	for (int i = 0; i < N; ++i)
		vertices.insert(i);

	// loop for deletion of vertex from set 
	while (!vertices.empty())
	{
		// if subset has only 1 vertex return 0 
		if (vertices.size() == 1)
			return 1;

		// for each vertex iterate and keep removing 
		// a vertix while we find a vertex with all 
		// edges of same color. 
		bool someone_removed = false;
		for (int x : vertices)
		{
			// note down different color values 
			// for each vertex 
			set<int> values;
			for (int y : vertices)
				if (y != x)
					values.insert(C[x][y]);

			// if only one color is found 
			// erase that vertex (bad vertex) 
			if (values.size() == 1)
			{
				vertices.erase(x);
				someone_removed = true;
				break;
			}
		}

		// If no vertex was removed in the 
		// above loop. 
		if (!someone_removed)
			break;
	}

	return (vertices.size());
}

// Driver program 
int main()
{
	int C[][N] = { { 0, 9, 2, 4, 7, 8 },
	{ 9, 0, 9, 9, 7, 9 },
	{ 2, 9, 0, 3, 7, 6 },
	{ 4, 9, 3, 0, 7, 1 },
	{ 7, 7, 7, 7, 0, 7 },
	{ 8, 9, 6, 1, 7, 0 }
	};
	cout << subsetGraph(C);
	return 0;
}

#endif

//#define DEPTH_FIRST_SEARCH_GRAPH_MySolution
#ifdef DEPTH_FIRST_SEARCH_GRAPH_MySolution
#include <list>
using namespace std;

//
//https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/?ref=rp
// 
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
int main()
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
#endif

//#define DEPTH_FIRST_SEARCH_GRAPH_UNDirected
#ifdef DEPTH_FIRST_SEARCH_GRAPH_UNDirected

#include <list>
// C++ program to print DFS traversal for a given given graph 

using namespace std;

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

int main()
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

#endif
//#define DEPTH_FIRST_SEARCH_GRAPH_UNDirected_stack
#ifdef DEPTH_FIRST_SEARCH_GRAPH_UNDirected_stack
#include <queue>
#include <stack>
using namespace std;

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

int main()
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

#endif
//#define BREADTH_FIRST_SEARCH_GRAPH_UNDirected_stack
#ifdef BREADTH_FIRST_SEARCH_GRAPH_UNDirected_stack

#include <queue>

class Graph
{
	int n;
	queue<int> * edges;

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

	void BFS(int v)
	{
		queue<int> vertices;
		bool *visited = new bool[n];
		for (int i = 0; i < n; i++)	visited[i] = false;

		vertices.push(v);
		visited[v] = true;

		while (vertices.empty() == false)
		{
			while (edges[v].empty() == false)
			{
				int next = edges[v].front();
				edges[v].pop();
				if (visited[next] != true)
				{
					vertices.push(next);
					visited[next] = true;
				}
			}
			v = vertices.front();
			vertices.pop();
			printf("%d ", v);

		}

	}
};

// Driver program to test methods of graph class 
int main()
{
	// Create a graph given in the above diagram 
	Graph g(4);
	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(1, 2);
	g.AddEdge(2, 0);
	g.AddEdge(2, 3);
	g.AddEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}

#endif

//#define Look_and_say_sequence
#ifdef Look_and_say_sequence

//
//https://practice.geeksforgeeks.org/problems/decode-the-pattern/0
// result:
//Runtime Error :
//Runtime ErrorSegmentation Fault(SIGSEGV)
//Learn More about Seg Fault


#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#define MAX 65535

struct Node
{
	int num;
	int v;
	Node *next;
};

Node * Look(char * p)
{
	Node * root = NULL;
	char ch = *p;
	int num = 0;
	bool flag = true;

	while (flag)
	{
		if (*p == 0x0)	flag = false;

		if (*p == ch)
		{
			num++;
		}
		else
		{
			char buf[2];
			buf[0] = ch;
			buf[1] = 0x0;
			Node *newN = new Node();
			newN->num = num;
			newN->v = atoi(buf);
			newN->next = NULL;

			if (root == NULL)
			{
				root = newN;
			}
			else
			{
				Node *cur;
				for (cur = root; cur->next != NULL; cur = cur->next);
				cur->next = newN;
			}
			ch = *p;
			num = 1;
		}
		p++;
	}
	return root;
}

char * Read(Node *root)
{
	char buf[MAX];
	memset(buf, 0x00, MAX);

	char *p = buf;
	for (Node * cur = root; cur != NULL; cur = cur->next)
	{
		sprintf(p, "%d", cur->num);
		p = buf + strlen(buf);
		sprintf(p, "%d", cur->v);
		p = buf + strlen(buf);
	};

	return (char *)buf;
}

void LookAndRead(char * _line, int ln)
{
	char *line = _line;

	for (int i = 0; i < ln; i++)
	{
		printf("%s\n", line);

		Node * root = Look(line);
		line = Read(root);

		Node *cur = root;
		while (cur != NULL)
		{
			Node *next = cur->next;
			delete cur;
			cur = next;
		}
		root = NULL;


	}
}

int main()
{
	LookAndRead("1", 8);
	return 0;
}

#endif

//#define StockBuyAndSell
#ifdef StockBuyAndSell
//
// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1
//

// Program to find best buying and selling days
#include <iostream>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, i;
		cin >> n;
		int *price = new int[n];
		for (i = 0; i < n; i++) cin >> price[i];
		// function call
		stockBuySell(price, n);
		delete price;
	}
	return 0;
}
// } Driver Code Ends
// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{
	// code here

	int begin = 0;

	for (int i = 1; i < n; i++)
	{
		if (price[i] < price[i - 1])
		{
			if (begin < (i - 1))
			{
				cout << "(" << begin << " " << i - 1 << ")";
			}
			begin = i;
		}
		if (i == n - 1)
		{
			if (begin < i)
			{
				cout << "(" << begin << " " << i << ")";
			}
		}

	}
	cout << endl;
}
#endif

//#define LargestFibonacciSubsequence 
#ifdef LargestFibonacciSubsequence

//
// https://practice.geeksforgeeks.org/problems/largest-fibonacci-subsequence/0
//

// Program to find best buying and selling days
#include <iostream>

using namespace std;
struct Node
{
	int v;
	Node *next;
};

void LBS(int *, int);

// Driver program to test above functions
int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, i;
		cin >> n;
		int *price = new int[n];
		for (i = 0; i < n; i++) cin >> price[i];
		// function call
		LBS(price, n);
		delete price;
	}
	return 0;
}

void LBSSub(Node *root, int n)
{
	if (root == nullptr)
	{
		Node *s = new Node;
		s->v = 0;
		root = s;
		s = new Node;
		s->v = 1;
		s->next = nullptr;
		root->next = s;
	}

	Node *cur = root;
	int v0 = 0;
	int v1 = 1;
	while (cur->v < n)
	{
		if (cur->next == nullptr)
		{
			Node *s = new Node;
			s->v = v0 + v1;
			s->next = nullptr;
			cur->next = s;
		}
		v0 = cur->v;
		v1 = cur->next->v;
		cur = cur->next;
	}

	if (cur->v == n)
	{
		printf("%d ", n);
	}
}

void LBS(int *array, int num)
{
	Node * root = nullptr;

	for (int i = 0; i < num; i++)
	{
		LBSSub(root, array[i]);
	}
	printf("\n");
}
#endif

//#define FindTripletsWithZeroSum 
#ifdef  FindTripletsWithZeroSum 
#include <iostream>

using namespace std;
bool findTriplets(int arr[], int n);

// Driver program to test above functions
int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, i;
		cin >> n;
		int *price = new int[n];
		for (i = 0; i < n; i++) cin >> price[i];
		// function call
		bool ret = findTriplets(price, n);
		if (ret)	printf("true\n");
		else
		{
			printf("false\n");
		}
		delete price;
	}
	return 0;
}

bool findSub(int *p, int n, int v)
{
	for (int i = 0; i < n; i++)
	{
		if ((p[i] + v) == 0)	return true;
	}
	return false;

}

bool findTriplets(int arr[], int num)
{
	int *p = new int[num];
	int np = 0;

	int *n = new int[num];
	int nn = 0;
	int nZero = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] < 0)	n[nn++] = arr[i];
		else
		{
			p[np++] = arr[i];
			if (arr[i] == 0) nZero++;
		}
	}
	if (nZero > 2)   return true;

	bool flag = false;

	for (int i = 0; i < np; i++)
	{
		for (int j = i + 1; j < np; j++)
		{
			if (findSub(n, nn, p[i] + p[j]) == true)
			{
				flag = true;
			}
		}
	}

	for (int i = 0; i < nn; i++)
	{
		for (int j = i + 1; j < nn; j++)
		{
			if (findSub(p, np, n[i] + n[j]) == true)
			{
				flag = true;
			}
		}
	}
	delete p;
	delete n;
	return flag ? true : false;
}

#endif

//#define CountDistinctPairsWithWifferenceK 
#ifdef  CountDistinctPairsWithWifferenceK
#include <iostream>
#include <set>

using namespace std;
void CDPWithK(int arr[], int n, int k);

// Driver program to test above functions
int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, i;
		cin >> n;
		int *price = new int[n];
		for (i = 0; i < n; i++) cin >> price[i];
		int k;
		cin >> k;
		// function call
		CDPWithK(price, n, k);
		delete price;
	}
	return 0;
}

void CDPWithK(int arr[], int n, int k)
{
	set<pair<int, int>> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)	continue;

			int a = arr[i];
			int b = arr[j];
			if (arr[j] > arr[i])
			{
				b = arr[i];
				a = arr[j];
			}
			if (a - b == k)
			{

				r.insert(pair<int, int>(a, b));
			}
		}
	}

	printf("%d\n", r.size());

}

#endif


//#define MergeSortforLinkedList 
#ifdef MergeSortforLinkedList 

//
// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
//
// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
int data;
struct Node* next;
Node(int x) { data = x;  next = NULL; }
};
*/
void push(struct Node** head_ref, int new_data);

Node * merge(Node * left, Node *right)
{
	Node *leftCur = left;
	Node *rightCur = right;
	Node * out = NULL;
	Node * cur = NULL;
	while (leftCur != NULL && rightCur != NULL)
	{
		int data;
		if (leftCur->data < rightCur->data)
		{
			data = leftCur->data;
			leftCur = leftCur->next;
		}
		else
		{
			data = rightCur->data;
			rightCur = rightCur->next;
		}
		if (out == NULL)
		{
			out = new Node(data);
			cur = out;
		}
		else
		{
			cur->next = new Node(data);
			cur = cur->next;
		}
	}
	while (leftCur != NULL)
	{
		cur->next = new Node(leftCur->data);
		cur = cur->next;
		leftCur = leftCur->next;

	}
	while (rightCur != NULL)
	{
		cur->next = new Node(rightCur->data);
		cur = cur->next;
		rightCur = rightCur->next;
	}

	return out;
}

/* Function to mergesort the linked list
It should return head of the modified list  */
Node* mergeSort(Node* head) {
	// your code here
	int n = 0;
	Node * cur = head;
	Node * out = NULL;
	while (cur != nullptr)
	{
		n++;
		cur = cur->next;
	}
	if (n < 2)
	{
		push(&out, head->data);
		return out;
	}

	Node * left = NULL;
	cur = head;
	for (int i = 0; i < n / 2; i++)
	{
		push(&left, cur->data);
		cur = cur->next;
	}
	Node *right = NULL;
	while (cur != NULL)
	{
		push(&right, cur->data);
		cur = cur->next;
	}
	Node *l = mergeSort(left);
	Node *r = mergeSort(right);

	out = merge(l, r);

	// free left
	// free right

}


// { Driver Code Starts.

void printList(Node* node) {
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void push(struct Node** head_ref, int new_data) {
	Node* new_node = new Node(new_data);

	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

int main() {
	long test;
	cin >> test;
	while (test--) {
		struct Node* a = NULL;
		long n, tmp;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			push(&a, tmp);
		}
		a = mergeSort(a);
		printList(a);
	}
	return 0;
}  // } Driver Code Ends

#endif

   //#define RearrangeAString
#ifdef RearrangeAString
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;

char * Merge(char *ls, char *rs)
{
	char *out = new char[strlen(ls) + strlen(rs) + 1];
	char *p = out;
	while (*ls != 0x0 && *rs != 0x0)
	{
		if (*ls < *rs)
		{
			*p++ = *ls++;
		}
		else
		{
			*p++ = *rs++;
		}

	}
	while (*ls != 0x0)
	{
		*p++ = *ls++;
	}
	while (*rs != 0x0)
	{
		*p++ = *rs++;
	}
	*p = 0x0;
	return out;
}
char * MergeSort(char * s)
{
	int len = strlen(s);
	if (len == 1)
	{
		char *out = new char[2];
		out[0] = s[0];
		out[1] = 0x0;
		return out;
	}
	int mid = len / 2;
	char *ls = new char[mid + 1];
	strncpy(ls, s, mid);
	ls[mid] = 0x0;
	char *l = MergeSort(ls);

	char *rs = new char[len - mid + 1];
	strncpy(rs, s + mid, len - mid);
	rs[len - mid] = 0x0;
	char *r = MergeSort(rs);

	char *out = Merge(l, r);
	return out;

}
void Rearrange(char * s)
{
	char *out = MergeSort(s);
	char *p = out;
	char buf[2];
	buf[1] = 0x0;
	int sum = 0;
	while (*p < 'A')
	{
		buf[0] = *p++;
		sum += atoi(buf);
	}
	printf("%s%d\n", p, sum);
}

int main()
{
	//code
	int c;
	cin >> c;

	while (c--)
	{
		string s;
		cin >> s;

		Rearrange((char *)s.c_str());

	}


	return 0;
}
#endif

//#define FindSequenceWithTargetSum
#ifdef  FindSequenceWithTargetSum

#include <iostream>
using namespace std;
#define MAX 1024

struct Node
{
	long v;
	char formula[MAX];
	Node *next;
	Node(long _v)
	{
		v = _v;
		next = nullptr;
	}
};

// { Driver Code Starts.

void printList(Node* node) {
	while (node != NULL) {
		printf("%s ", node->formula);
		node = node->next;
	}
	printf("\n");
}

Node * Merge(long cur, long target, Node *s, Node *&out)
{
	Node *ret = nullptr;

	Node *out0 = new Node(cur);
	sprintf(out0->formula, "%d", cur);
	out0->next = ret;
	ret = out0;

	while (s != nullptr)
	{

		Node *out1 = new Node(s->v);
		strcpy(out1->formula, s->formula);
		out1->next = ret;

		Node *out2 = new Node(cur + s->v);
		sprintf(out2->formula, "%s+%d", s->formula, cur);
		out2->next = out1;
		ret = out2;

		if (ret->v == target)
		{
			Node *tmp = new Node(ret->v);
			strcpy(tmp->formula, ret->formula);
			tmp->next = out;
			out = tmp;
		}

		s = s->next;
	}

	return ret;
}

Node * Search(long target, Node * root, Node *&out)
{
	long cur = root->v;

	if (root->next == nullptr)
	{
		Node *tmp1 = new Node(root->v);
		sprintf(tmp1->formula, "%d", root->v);

		if (target == tmp1->v)
		{
			Node *tmpOut = new Node(out->v);
			strcpy(tmpOut->formula, tmp1->formula);
			tmpOut->next = out;
			out = tmpOut;
		}

		return tmp1;
	}
	Node *tmp2 = Search(target, root->next, out);

	Node* ret = Merge(cur, target, tmp2, out);

	return ret;

}
int main() {
	long test;
	cin >> test;
	while (test--) {
		struct Node* root = NULL;
		long n, tmp;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			Node *a = new Node(tmp);
			a->next = root;
			root = a;
		}

		if (root == NULL)
		{
			printf("Invalid test case\n");
			return 0;
		}

		long target;
		cin >> target;

		Node *out = nullptr;

		Search(target, root, out);

		if (out == nullptr)	printf("Not found\n");
		else
			printList(out);
	}
	return 0;
}

#endif

//#define LargestSumSubarrayofSizeatleastK 
#ifdef LargestSumSubarrayofSizeatleastK 

//
// https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k/0/
//
#define MAX 8000
#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
	long v;
	int elements;
	//char formula[MAX];
	Node *next;
	Node(long _v, int _n)
	{
		v = _v;
		elements = _n;
		next = nullptr;
	}
};

Node * Merge(int minElement, long cur, Node *s, long& sum)
{
	Node *root = nullptr;
	Node *curNode = new Node(cur, 1);
	//sprintf(curNode->formula, "%d", cur);
	curNode->next = root;
	root = curNode;

	while (s != nullptr)
	{
		Node * tmp = new Node(s->v, s->elements);
		//strcpy(tmp->formula, s->formula);
		tmp->next = root;

		Node * tmp1 = new Node(s->v + cur, s->elements + 1);
		//sprintf(tmp1->formula, "%s+%d",  s->formula,cur);
		tmp1->next = tmp;
		root = tmp1;

		if (minElement <= root->elements)
		{
			if (sum < root->v)	sum = root->v;
		}
		s = s->next;
	}

	return root;
}

Node *Search(int minElement, Node * root, long &sum)
{
	int leftValue = root->v;

	if (root->next == nullptr)
	{
		Node *out = new Node(root->v, 1);
		//sprintf(out->formula, "%d", out->v);
		if (minElement == out->elements)
		{
			if (sum < (out->v))	sum = out->v;
		}
		return out;
	}

	Node *  allNode = Search(minElement, root->next, sum);

	Node * ret = Merge(minElement, leftValue, allNode, sum);

	return ret;

}
int main() {
	long test;
	cin >> test;
	while (test--) {
		struct Node* root = NULL;
		long n, tmp;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			Node *a = new Node(tmp, 1);
			a->next = root;
			root = a;
		}

		if (root == NULL)
		{
			printf("Invalid test case\n");
			return 0;
		}

		long minElement;
		cin >> minElement;

		long sum = -655535;

		Search(minElement, root, sum);

		printf("%d\n", sum);
	}
	return 0;
}


#endif

//#define ReverseBits_mysolution 
#ifdef ReverseBits_mysolution
#include <iostream>

using namespace std;

unsigned long Merge(unsigned long cur, unsigned long n, int shift)
{
	unsigned long ret = (cur << shift) + n;
	return ret;
}

unsigned long ReverseBits(unsigned long num, int shift)
{
	unsigned long cur = (num >> shift) & 1;

	if (shift == 31)
	{
		return cur;
	}
	unsigned long right = ReverseBits(num, shift + 1);
	unsigned long ret = Merge(cur, right, 32 - shift - 1);
	return ret;

}
int main() {
	long test;
	cin >> test;
	while (test--) {
		unsigned long num;
		cin >> num;
		unsigned long ret = ReverseBits(num, 0);

		cout << ret << endl;
	}
	return 0;
}

#endif

//#define FindPrimeNumbersInARange 
#ifdef FindPrimeNumbersInARange 

//
// Find Prime numbers in a range 
// https://practice.geeksforgeeks.org/problems/find-prime-numbers-in-a-range/0/
//
#include <iostream>

using namespace std;

struct Node
{
	unsigned long v;
	Node *next;
	Node(unsigned long _v)
	{
		v = _v;
		next = nullptr;
	}
};

Node *Merge(unsigned long n, Node *s)
{
	bool flag = false;
	Node *ret = s;

	while (s != NULL)
	{
		if (n % (s->v) == 0)	flag = true;
		s = s->next;
	}

	if (flag == false)
	{
		Node *out = new Node(n);
		out->next = ret;
		ret = out;
	}
	return ret;
}

Node * FindPirmeNumber(unsigned long highest)
{
	if (highest == 2)
	{
		Node *out = new Node(2);
		return out;
	}
	Node * primes = FindPirmeNumber(highest - 1);

	Node *ret = Merge(highest, primes);

	return ret;
}

int main()
{
	long test;
	cin >> test;
	while (test--) {

		unsigned long num[2];
		for (int i = 0; i < 2; i++)			cin >> num[i];
		unsigned long count = 0;
		Node *ret = FindPirmeNumber(num[1]);

		Node * out = NULL;
		while (ret != NULL)
		{
			if (ret->v >= num[0])
			{
				Node *ret1 = new Node(ret->v);
				ret1->next = out;
				out = ret1;
			}
			ret = ret->next;
		}
		while (out->next != NULL)
		{
			cout << out->v << " ";
			out = out->next;
		}
		cout << out->v << " " << endl;

	}
	return 0;
}
#endif

//#define FindPrimeNumbersInARange_SieveOfEratosthenes
#ifdef FindPrimeNumbersInARange_SieveOfEratosthenes

//
//https ://www.geeksforgeeks.org/sieve-of-eratosthenes/
//

void FindPirmeNumber(unsigned long highest)
{
	bool * mark = new bool[highest + 1];
	for (unsigned long i = 0; i < highest + 1; i++)	mark[i] = true;

	for (unsigned long i = 2; i * i <= highest; i++)
	{
		if (mark[i] == true)
		{
			for (unsigned long j = i * i; j <= highest; j += i)
			{
				mark[j] = false;
			}
		}
	}

	for (unsigned long i = 2; i <= highest; i++)
	{
		if (mark[i] == true)	cout << i << " ";
	}
}

int main()
{
	long test;
	cin >> test;
	while (test--) {

		unsigned long num;
		cin >> num;
		FindPirmeNumber(num);
	}
	return 0;
}

#endif

//#define ReturnTwoPrimeNumbers 
#ifdef ReturnTwoPrimeNumbers 

//
// https://practice.geeksforgeeks.org/problems/return-two-prime-numbers/0/
//
#include <iostream>
#include <set>

using namespace std;


struct Node
{
	unsigned long v;
	Node *next;
	Node(unsigned long _v)
	{
		v = _v;
		next = nullptr;
	}
};

bool Merge(unsigned long cur, set<unsigned long>& primeNumSet, unsigned long sum, unsigned long &ret)
{
	set<unsigned long>::iterator itr;
	for (itr = primeNumSet.begin(); itr != primeNumSet.end(); itr++)
	{
		if (*itr == cur)	continue;
		if ((*itr + cur) == sum)
		{
			ret = cur;
			return true;
		}
	}
	return false;
}

bool FindTwoPrimeNumbersSub(Node *s, set<unsigned long>& primeNumSet, unsigned long sum, unsigned long &ret)
{
	unsigned long cur = s->v;

	primeNumSet.insert(cur);

	if (s->next == nullptr)
	{
		return Merge(s->v, primeNumSet, sum, ret);
	}

	if (FindTwoPrimeNumbersSub(s->next, primeNumSet, sum, ret) == true)	return true;

	return Merge(cur, primeNumSet, sum, ret);

}

void FindTwoPrimesNumbers(unsigned long even_num)
{
	bool *arr = new bool[even_num];
	for (unsigned long i = 0; i < even_num; i++)	arr[i] = false;

	for (unsigned long i = 2; i * i < even_num; i++)
	{
		for (unsigned long j = i * i; j < even_num; j += i)
		{
			arr[j] = true;
		}
	}

	Node *root = nullptr;
	for (unsigned long i = 2; i < even_num; i++)
	{
		if (arr[i] == false)
		{
			Node * s = new Node(i);
			s->next = root;
			root = s;
		}
	}
	unsigned long n = -1;
	set<unsigned long> primeNumSet;

	FindTwoPrimeNumbersSub(root, primeNumSet, even_num, n);

	if (n != -1)
		cout << n << " " << even_num - n << endl;
	else
		cout << "not found" << endl;

}

int main()
{
	long test;
	cin >> test;
	while (test--) {

		unsigned long num;
		cin >> num;
		FindTwoPrimesNumbers(num);
	}
	return 0;
}


#endif

//#define MaximumIndex 
#ifdef MaximumIndex
#include <iostream>
using namespace std;

void FindMaximumIndex(unsigned long *arr, unsigned long num)
{
	unsigned long max = 0;
	for (unsigned long n = num - 1; n > max; n--)
	{
		for (unsigned long i = 0; i < n - max; i++)
		{
			if (arr[n] > arr[i])
			{
				unsigned long diff = n - i;
				if (diff > max)	max = diff;
			}
		}
	}

	cout << max << endl;
}

int main()
{
	long test;
	cin >> test;
	while (test--) {

		unsigned long num;
		cin >> num;
		unsigned long *arr = new unsigned long[num];
		for (unsigned long i = 0; i < num; i++)	cin >> arr[i];
		FindMaximumIndex(arr, num);
	}
	return 0;
}

#endif

//#define MaximumIndex_Solution_O_nLgN
#ifdef MaximumIndex_Solution_O_nLgN
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

void FindMaximumIndex(unsigned long* arr, unsigned long num)
{
	map<unsigned long, list<unsigned long>> dict;
	vector<unsigned long>sortarr;

	for (unsigned long i = 0; i < num; i++)
	{
		map<unsigned long, list<unsigned long>>::iterator it = dict.find(arr[i]);

		sortarr.push_back(arr[i]);

		if (it != dict.end())
		{
			it->second.push_back(i);
		}
		else
		{
			list<unsigned long> index;
			index.push_back(i);
			dict.insert(make_pair(arr[i], index));
		}
	}

	sort(sortarr.begin(), sortarr.end());

	unsigned tmp = num;

	for (int i = 0; i < num; i++)
	{

	}
}
int main()
{
	long test;
	cin >> test;
	while (test--) {

		unsigned long num;
		cin >> num;
		unsigned long *arr = new unsigned long[num];
		for (unsigned long i = 0; i < num; i++)	cin >> arr[i];
		FindMaximumIndex(arr, num);
	}
	return 0;
}

#endif



//#define InterpolateAudio
#ifdef InterpolateAudio

void SplitterChannels(unsigned char *buffer, int maxSamples, int bytesPerSample, int channels, unsigned char *output[])
{
	for (int i = 0; i < channels; i++)
	{
		output[i] = new unsigned char[maxSamples * bytesPerSample];
	}

	unsigned char *out[2];
	out[0] = output[0];
	out[1] = output[1];
	unsigned char *in = buffer;

	for (int i = 0; i < maxSamples; i++)
	{
		memcpy(out[0], in, bytesPerSample);
		in += bytesPerSample;
		out[0] += bytesPerSample;

		memcpy(out[1], in, bytesPerSample);
		in += bytesPerSample;
		out[1] += bytesPerSample;
	}
}

int main()
{
	int maxSamples = 512;
	int channels = 2;
	int bytesPerSample = 2;

	int frameLength = bytesPerSample * channels * maxSamples;

	unsigned char *buffer = new unsigned char[frameLength];
	unsigned char *p = buffer;

	for (int i = 0; i < maxSamples; i++)
	{
		for (int j = 0; j < channels; j++)
		{
			if (j % 2)
			{
				memset(p, 0x0, bytesPerSample);
			}
			else
			{
				memset(p, 0xff, bytesPerSample);
			}
			p += bytesPerSample;
		}
	}

	unsigned char *output[2];

	SplitterChannels(buffer, maxSamples, bytesPerSample, channels, output);

	delete buffer;

	return 1;

}
#endif

int main(int argc, char * argv[])
{
	string s = string(argv[1]);

	if (s == "permutation_of_string")
	{
		PermutationOfString_Test();
	}
	else if (s == "FindTheMaximumj_i")
	{
		FindTheMaximumj_i_Test();
	}

    return 0;
}

