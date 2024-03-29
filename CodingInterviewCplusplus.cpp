// CodingInterviewCplusplus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AllQuestions.h"
#include <string>
#include <vector>
#include <map>
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

typedef int (*foo)(void); 

int main(int argc, char* argv[])
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
	else if (s == "InversionCountForAnArray")
	{
		InversionCountForAnArray_Test();
	}
	else if (s == "MergeSortLinkedList")
	{
		MergeSortLinkedList_Test();
	}
	else if (s == "MergeSortArray")
	{
		MergeSortArray_Test();
	}
	else if (s == "MergeSortInversions")
	{
		MergeSortInversions_Test();
	}
	else if (s == "PreorderTravesalBTree")
	{
		PreorderTravesalBTree_Test();
	}
	else if (s == "LruCachePageFault")
	{
		LruCachePageFault_Test();
	}
	else if (s == "MinNumPlatformsRequiredRailwayBusStation")
	{
		MinNumPlatformsRequiredRailwayBusStation_Test();
	}
	else if (s == "LargestsubsetofGraphverticeswithedgesof2ormorecolors")
	{
		LargestsubsetofGraphverticeswithedgesof2ormorecolors_Test();
	}
	else if (s == "DepthFirstSearchGraph")
	{
		DepthFirstSearchGraph_Test();
	}
	else if (s == "CloneLinkedListWithNextAndArbitPointer")
	{
		CloneLinkedListWithNextAndArbitPointer_Test();
	}
	else if (s == "ConstructSpecialTreeFromGivenPreorderTraversal")
	{
		ConstructSpecialTreeFromGivenPreorderTraversal_Test();
	}
	else if (s == "FindAllTripletsWithZeroSum")
	{
		FindAllTripletsWithZeroSum_Test();
	}
	else if (s == "FindUnionAndIntersectionOfTwoTnsortedArrays")
	{
		FindUnionAndIntersectionOfTwoTnsortedArrays_Test();
	}
	else if (s == "FindPrimeNumbersInARange")
	{
		FindPrimeNumbersInARange_Test();
	}
	else if (s == "RomanNumbertoInteger")
	{
		RomanNumbertoInteger_Test();
	}
	else if (s == "Anagram")
	{
		Anagram_Test();
	}
	else if (s == "ConvertStringToCharArray")
	{
		ConvertStringToCharArray_Test();
	}
	else if (s == "NQueenProblem")
	{
		NQueenProblem_Test();
	}
	else if (s == "ReverseBits")
	{
		ReverseBits_Test();
	}
	else if (s == "WordBoggle")
	{
		WordBoggle_Test();
	}
	else if (s == "MinimumOperations")
	{
		MinimumOperations_Test();
	}
	else if (s == "ShopinCandyStore")
	{
		ShopinCandyStore_Test();
	}
	else if (s == "KadanesAlgorithm")
	{
		KadanesAlgorithm_Test();
	}
	else if (s == "MissingNumberInArray")
	{
		MissingNumberInArray_Test();
	}
	else if (s == "SubarrayWithGivenSum")
	{
		SubarrayWithGivenSum_Test();
	}
	else if (s == "SortArrayOf0s1snd2s")
	{
		SortArrayOf0s1snd2s_Test();
	}
	else if (s == "EquilibriumPoint")
	{
		EquilibriumPoint_Test();
	}
	else if (s == "FloodFillAlgorithm")
	{
		FloodFillAlgorithm_Test();
	}
	else if (s == "NumberOfPaths")
	{
		NumberOfPaths_Test();
	}
	else if (s == "JosephusProblem")
	{
		JosephusProblem_Test();
	}
	else if (s == "ActivitySelection")
	{
		ActivitySelection_Test();
	}
	else if (s == "NMeetingsInOneRoom")
	{
		NMeetingsInOneRoom_Test();
	}
	else if (s == "JobSequencingProblem")
	{
		JobSequencingProblem_Test();
	}
	else if (s == "CoinPiles")
	{
		CoinPiles_Test();
	}
	else if (s == "MinimumNumberOfCoins")
	{
		MinimumNumberOfCoins_Test();
	}
	else if (s == "MaximizeToys")
	{
		MaximizeToys_Test();
	}
	else if (s == "PageFaultsinLRU")
	{
		PageFaultsinLRU_Test();
	}
	else if (s == "LargestNumberPossible")
	{
		LargestNumberPossible_Test();
	}
	else if (s == "MinimizeTheHeights")
	{
		MinimizeTheHeights_Test();
	}
	else if (s == "MinimizeTheSumOfProduct")
	{
		MinimizeTheSumOfProduct_Test();
	}
	else if (s == "SmallestNumber")
	{
		SmallestNumber_Test();
	}
	else if (s == "MinimumCostOfRopes")
	{
		MinimumCostOfRopes_Test();
	}
	else if (s == "Consecutive1isNotAllowed")
	{
		Consecutive1isNotAllowed_Test();
	}
	else if (s == "TotalDecodingMessages")
	{
		TotalDecodingMessages_Test();
	}
	else if (s == "SumTree")
	{
		SumTree_Test();
	}
	else if (s == "AncestorsInBinaryTree")
	{
		AncestorsInBinaryTree_Test();
	}
	else if (s == "LevelOfANodeInBinaryTree")
	{
		LevelOfANodeInBinaryTree_Test();
	}
	else if (s == "KDistanceFromRoot")
	{
		KDistanceFromRoot_Test();
	}
	else if (s == "MaximumWidthOfTree")
	{
		MaximumWidthOfTree_Test();
	}
	else if (s == "RootToLeafPaths")
	{
		RootToLeafPaths_Test();
	}
	else if (s == "RootToLeafPthSum")
	{
		RootToLeafPthSum_Test();
	}
	else if (s == "CheckforBalancedTree")
	{
		CheckforBalancedTree_Test();
	}
	else if (s == "DiameterOfBinaryTree")
	{
		DiameterOfBinaryTree_Test();
	}
	else if (s == "CountLeavesinBinaryTree")
	{
		CountLeavesinBinaryTree_Test();
	}
	else if (s == "PostorderTraversal")
	{
		PostorderTraversal_Test();
	}
	else if (s == "LevelOrderTraversall")
	{
		LevelOrderTraversall_Test();
	}
	else if (s == "LevelOrderTraversalLineByLine")
	{
		LevelOrderTraversalLineByLine_Test();
	}
	else if (s == "ReverseLevelOrderTraversal")
	{
		ReverseLevelOrderTraversal_Test();
	}
	else if (s == "LevelOrderTraversalInSpirallForm")
	{
		LevelOrderTraversalInSpirallForm_Test();
	}
	else if (s == "ConnectNodesAtSameLevel")
	{
		ConnectNodesAtSameLevel_Test();
	}
	else if (s == "CountBSTNodesThatLieInAGivenRange")
	{
		CountBSTNodesThatLieInAGivenRange_Test();
	}
	else if (s == "CheckForBST")
	{
		CheckForBST_Test();
	}
	else if (s == "BottomViewOfBinaryTree")
	{
		BottomViewOfBinaryTree_Test();
	}
	else if (s == "TopViewOfBinaryTree")
	{
		TopViewOfBinaryTree_Test();
	}
	else if (s == "RightViewOfBinaryTree")
	{
		RightViewOfBinaryTree_Test();
	}
	else if (s == "LeftViewOfBinaryTree_Test")
	{
		LeftViewOfBinaryTree_Test();
	}
	else if (s == "MaximumPathSumBetween2LeafNodes")
	{
		MaximumPathSumBetween2LeafNodes_Test();
	}
	else if (s == "ReverseAlternateLevelsOfAPerfectBinaryTree")
	{
		ReverseAlternateLevelsOfAPerfectBinaryTree_Test();
	}
	else if (s == "MaxAndMinElementInBinaryTree_Test")
	{
		MaxAndMinElementInBinaryTree_Test();
	}
	else if (s == "SizeOfBinaryTree")
	{
		SizeOfBinaryTree_Test();
	}
	else if (s == "InorderTraversal")
	{
		InorderTraversal_Test();
	}
	else if (s == "CountNonLeafNodesInTree")
	{
		CountNonLeafNodesInTree_Test();
	}
	else if (s == "MirrorTree")
	{
		MirrorTree_Test();
	}
	else if (s == "SumOfLeafNodes")
	{
		SumOfLeafNodes_Test();
	}
	else if (s == "PrintAllNodesThatDonnotHaveSibling")
	{
		PrintAllNodesThatDonnotHaveSibling_Test();
	}
	else if (s == "TwoMirrorTrees")
	{
		TwoMirrorTrees_Test();
	}
	else if (s == "DetermineIfTwoTreesAreIdentical")
	{
		DetermineIfTwoTreesAreIdentical_Test();
	}
	else if (s == "SymmetricTree")
	{
		SymmetricTree_Test();
	}
	else if (s == "HeightOfBinaryTree")
	{
		HeightOfBinaryTree_Test();
	}
	else if (s == "SumOfBinaryTree")
	{
		SumOfBinaryTree_Test();
	}
	else if (s == "SumOfLeftLeafNodes")
	{
		SumOfLeftLeafNodes_Test();
	}
	else if (s == "")
	{
		SumOfRightLeafNodes_Test();
	}
	else if (s == "SumOfLeafNodesInBST")
	{
		SumOfLeafNodesInBST_Test();
	}
	else if (s == "MedianOfBST")
	{
		MedianOfBST_Test();
	}
	else if (s == "FindAPairWithGivenTargetInBST")
	{
		FindAPairWithGivenTargetInBST_Test();
	}
	else if (s == "FrequenciesOfLimitedRangeArrayElements")
	{
		FrequenciesOfLimitedRangeArrayElements_Test();
	}
	else if (s == "SumOfArrayElements")
	{
		SumOfArrayElements_Test();
	}
	else if (s == "GameOfCells")
	{
		GameOfCells_Test();
	}
	else if (s == "NumberOfUniquePaths")
	{
		NumberOfUniquePaths_Test();
	}
	else if (s == "ReverseAnArray")
	{
		ReverseAnArray_Test();
	}
	else if (s == "PrintDiagonally")
	{
		PrintDiagonally_Test();
	}
	else if (s == "HuffmanDecoding")
	{
		HuffmanDecoding_Test();
	}
	else if (s == "ImplementingDijkstra")
	{
		ImplementingDijkstra_Test();
	}
	else if (s == "MinimumSpanningTree")
	{
		MinimumSpanningTree_Test();
	}
	else if (s == "MaxLengthChain")
	{
		MaxLengthChain_Test();
	}
	else if (s == "MinimumPlatforms")
	{
		MinimumPlatforms_Test();
	}
	else if (s == "GeekCollectsTheBalls")
	{
		GeekCollectsTheBalls_Test();
	}
	else if (s == "SevenSegmentDisplay")
	{
		SevenSegmentDisplay_Test();
	}
	else if (s == "MinCoin")
	{
		MinCoin_Test();
	}
	else if (s == "WaterConnectionProblem")
	{
		WaterConnectionProblem_Test();
	}
	else if (s == "LongestIncreasingSubsequence")
	{
		LongestIncreasingSubsequence_Test ();
	}
	else if (s == "UglyNumbers")
	{
		UglyNumbers_Test();
	}
	else if (s == "LobbNumber")
	{
		LobbNumber_Test();
	}
	else if (s == "CatalanNumber")
	{
		CatalanNumber_Test();
	}
	else if (s == "BellNumbers")
	{
		BellNumbers_Test();
	}
	else if (s == "BinomialCoefficient")
	{
		BinomialCoefficient_Test();
	}
	else if (s == "PermutationCoefficient")
	{
		PermutationCoefficient_Test();
	}
	else if (s == "TilingProblem")
	{
		TilingProblem_Test();
	}
	else if (s == "GoldMineProblem")
	{
		GoldMineProblem_Test();
	}
	else if (s == "PalindromicPatitioning")
	{
		PalindromicPatitioning_Test();
	}
	else if (s == "MatrixChainMultiplication")
	{
		MatrixChainMultiplication_Test();
	}
	else if (s == "PrintAllCombinationsOfBalancedParentheses")
	{
		PrintAllCombinationsOfBalancedParentheses_Test();
	}
	else if (s == "WordWrap")
	{
		WordWrap_Test();
	}
	else if (s == "MobileNumericKeypad")
	{
		MobileNumericKeypad_Test();
	}
	else if (s == "ThePaintersPartition")
	{
		ThePaintersPartition_Test();
	}
	else if (s == "BooleanParenthesization")
	{
		BooleanParenthesization_Test();
	}
	else if (s == "BridgeAndTorch")
	{
		BridgeAndTorch_Test();
	}
	else if (s == "LargestNumberFormedFromAnArray")
	{
		LargestNumberFormedFromAnArray_Test();
	}
	else if (s == "LongestCommonPrefixInAnArray")
	{
		LongestCommonPrefixInAnArray_Test();
	}
	else 
	{
		map<string, foo> funcPtr;

		funcPtr.insert(make_pair("DeleteWithoutHeadPointer", DeleteWithoutHeadPointer_Test));

		funcPtr.insert(make_pair("MaximumOfAllSubarraysOfSizeK", MaximumOfAllSubarraysOfSizeK_Test));

		funcPtr.insert(make_pair("SerializeAndDeserializeABinaryTree", SerializeAndDeserializeABinaryTree_Test));

		funcPtr.insert(make_pair("KthLargestElementInAStream", KthLargestElementInAStream_Test));

		funcPtr.insert(make_pair("SpecialKeyboard", SpecialKeyboard_Test));

		funcPtr.insert(make_pair("CheckIfFrequenciesCanBeEqual", CheckIfFrequenciesCanBeEqual_Test));

		funcPtr.insert(make_pair("SnakeAndLadder", SnakeAndLadder_Test));

		funcPtr.insert(make_pair("NumberOfRectangles", NumberOfRectangles_Test));
		
		funcPtr.insert(make_pair("ShortestCommonSupersequence", ShortestCommonSupersequence_Test));

		funcPtr.insert(make_pair("LongestCommonSubsequence", LongestCommonSubsequence_Test));

		funcPtr.insert(make_pair("KthElementOfTwoSortedArrays", KthElementOfTwoSortedArrays_Test));

		funcPtr.insert(make_pair("GenerateIPAddresses", GenerateIPAddresses_Test));

		funcPtr.insert(make_pair("MaximumSubsetXOR", MaximumSubsetXOR_Test));

		funcPtr.insert(make_pair("MaximumSubarraytXOR", MaximumSubarraytXOR_Test));

		funcPtr.insert(make_pair("FindFirstSetBit", FindFirstSetBit_Test));

		funcPtr.insert(make_pair("RightmostDifferentBit", RightmostDifferentBit_Test));

		funcPtr.insert(make_pair("CheckWhetherKthBitIsSetOrNot", CheckWhetherKthBitIsSetOrNot_Test));

		funcPtr.insert(make_pair("ToggleBitsGivenRange", ToggleBitsGivenRange_Test));

		funcPtr.insert(make_pair("SetKthBit", SetKthBit_Test));

		funcPtr.insert(make_pair("PowerOf2", PowerOf2_Test));

		funcPtr.insert(make_pair("RotateBits", RotateBits_Test));

		funcPtr.insert(make_pair("SwapAllOddAndEvenBits", SwapAllOddAndEvenBits_Test));

		funcPtr.insert(make_pair("FindAllSequenceThatSumEqualToTarget", FindAllSequenceThatSumEqualToTarget_Test));

		funcPtr.insert(make_pair("SubarraySumEqualsK", SubarraySumEqualsK_Test));

		funcPtr.insert(make_pair("PairsOfPrimeNumberint", PairsOfPrimeNumberint_Test));

		funcPtr.insert(make_pair("ThreeWayPartitioning", ThreeWayPartitioning_Test));

		funcPtr.insert(make_pair("PantsShirtsShoesSkirts", PantsShirtsShoesSkirts_Test));

		funcPtr.insert(make_pair("CopyBinaryTree", CopyBinaryTree_Test));

		funcPtr.insert(make_pair("DFSOfGraph", DFSOfGraph_Test));

		funcPtr.insert(make_pair("BFSOfGraph", BFSOfGraph_test));

		funcPtr.insert(make_pair("DFS_and_BFS_for_Graph", DFS_and_BFS_for_Graph_Test));

		funcPtr.insert(make_pair("CompressStrings", CompressStrings_Test));

		funcPtr.insert(make_pair("CountsTheNumberOfOccurrencesOfKinTheList", CountsTheNumberOfOccurrencesOfKinTheList_Test));

		funcPtr.insert(make_pair("MaximumPathSumBetween2LeafNodes", MaximumPathSumBetween2LeafNodes_Test));

		funcPtr.insert(make_pair("StockBuyAndSel", StockBuyAndSel_Test));

		funcPtr.insert(make_pair("KthSmallestElement", KthSmallestElement_Test));

		funcPtr.insert(make_pair("BalancedParentheses", BalancedParentheses_Test));

		funcPtr.insert(make_pair("CompairListContentCombination", CompairListContentCombination_Test));

		funcPtr.insert(make_pair("PrerequisiteTasks", PrerequisiteTasks_Test));

		funcPtr.insert(make_pair("AddTwoNumbers", AddTwoNumbers_Test));

		funcPtr.insert(make_pair("LongestSubstringWithoutRepeatingCharacters", LongestSubstringWithoutRepeatingCharacters_Test));

		funcPtr.insert(make_pair("KthLargestElementInAnArray", KthLargestElementInAnArray_Test));

		funcPtr.insert(make_pair("NQueensII", NQueensII_Test));

		funcPtr.insert(make_pair("RatInAMazeProblem", RatInAMazeProblem_Test));

		funcPtr.insert(make_pair("KnightsTour", KnightsTour_Test));

		funcPtr.insert(make_pair("AllPossibleReArrangementsOfThelettersInAString", AllPossibleReArrangementsOfThelettersInAString_Test));

		funcPtr.insert(make_pair("AllSubsetsOfGivenSet", AllSubsetsOfGivenSet_Test));

		funcPtr.insert(make_pair("ValidSudoku", ValidSudoku_Test));

		funcPtr.insert(make_pair("MinimumIncompatibility", MinimumIncompatibility_Test));

		funcPtr.insert(make_pair("MedianOfTwoSortedArraysOfSsameSize", MedianOfTwoSortedArraysOfSsameSize_Test));

		funcPtr.insert(make_pair("MedianOfTwoSortedArraysOfDifferentSizes", MedianOfTwoSortedArraysOfDifferentSizes_Test));

		funcPtr.insert(make_pair("RegularExpressionMatching", RegularExpressionMatching_Test));

		funcPtr.insert(make_pair("MergeKSortedLists", MergeKSortedLists_Test));

		funcPtr.insert(make_pair("ReverseNodesInkGroup", ReverseNodesInkGroup_Test));

		funcPtr.insert(make_pair("SubstringWithConcatenationOfAllWords", SubstringWithConcatenationOfAllWords_Test));

		funcPtr.insert(make_pair("LongestValidParentheses", LongestValidParentheses_Test));

		funcPtr.insert(make_pair("CountSubIslands", CountSubIslands_Test));

		funcPtr.insert(make_pair("EquilibriumIndexOfAnArray", EquilibriumIndexOfAnArray_Test));

		funcPtr.insert(make_pair("SubarrayWith0Sum", SubarrayWith0Sum_Test));

		funcPtr.insert(make_pair("AllSubarraysOfThatSizeHaveSumLessThanK", AllSubarraysOfThatSizeHaveSumLessThanK_Test));

		funcPtr.insert(make_pair("FindSubarrayWithGivenSum", FindSubarrayWithGivenSum_Test));

		funcPtr.insert(make_pair("SumOfMostConsecutivePrimesSmallerThanLimit", SumOfMostConsecutivePrimesSmallerThanLimit_Test));

		funcPtr.insert(make_pair("RandomNumberGenerator", RandomNumberGenerator_Test));

		funcPtr.insert(make_pair("MinimumCostForAcquiringAllCoinsWithKExtraCoinsAllowedWithEveryCoin", MinimumCostForAcquiringAllCoinsWithKExtraCoinsAllowedWithEveryCoin_Test));

		funcPtr.insert(make_pair("MaximumValueInAnArrayAfterMRangeIncrementOperations", MaximumValueInAnArrayAfterMRangeIncrementOperations_Test));

		funcPtr.insert(make_pair("MaximumOccuredInteger", MaximumOccuredInteger_Test));

		funcPtr.insert(make_pair("MultipleArrayRangeIncrementOperations", MultipleArrayRangeIncrementOperations_Test));

		funcPtr.insert(make_pair("SegTreeSumOfGivenRange", SegTreeSumOfGivenRange_Test));

		funcPtr.insert(make_pair("SegTreeLazyPropagatioin", SegTreeLazyPropagatioin_Test));

		funcPtr.insert(make_pair("PersistentSegmentTree", PersistentSegmentTree_Test));

		funcPtr.insert(make_pair("CountFrequenciesOfArrayElements", CountFrequenciesOfArrayElements_Test));

		funcPtr.insert(make_pair("CountNumberOfPairsWithAbsoluteDifferenceK", CountNumberOfPairsWithAbsoluteDifferenceK_Test));

		funcPtr.insert(make_pair("SumOfBeautyInTheArray", SumOfBeautyInTheArray_Test));

		funcPtr.insert(make_pair("DetectSquares", DetectSquares_Test));

		funcPtr.insert(make_pair("test", test));

		funcPtr.insert(make_pair("LongestSubsequenceRepeatedkTimes", LongestSubsequenceRepeatedkTimes_Test));

		funcPtr.insert(make_pair("MaxDiffBetweenIncElements", MaxDiffBetweenIncElements_Test));

		funcPtr.insert(make_pair("ProcessRestrictedFriendRequests", ProcessRestrictedFriendRequests_Test));

		funcPtr.insert(make_pair("QueriesTheSumOfElementsInRangeLeftToRight", QueriesTheSumOfElementsInRangeLeftToRight_Test));

		funcPtr.insert(make_pair("CountFertilePyramidsInaLand", CountFertilePyramidsInaLand_Test));

		funcPtr.insert(make_pair("ShortestPathinBinaryMatrix", ShortestPathinBinaryMatrix_Test));

		map<string, foo>::iterator it = funcPtr.find(s);

		if (it != funcPtr.end())	it->second();

	}
    return 0;
}

namespace Contest
{
	class Solution {
	public:
		int finalValueAfterOperations(vector<string>& operations) {
			return 0;

		}
	};
};

int test()
{
	return 0;
}
