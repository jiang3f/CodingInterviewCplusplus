//
// https://www.geeksforgeeks.org/largest-subset-graph-vertices-edges-2-colors/?ref=lbp
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set> 

using namespace std;

namespace LargestsubsetofGraphverticeswithedgesof2ormorecolors
{
	const int MAX = 255;

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

	void Run_mine()
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

	//
	// other solution
	//

	// C++ program to find size of subset of graph vertex 
	// such that each vertex has more than 1 color edges 

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
	int Run_solution1()
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

}

int LargestsubsetofGraphverticeswithedgesof2ormorecolors_Test()
{
	LargestsubsetofGraphverticeswithedgesof2ormorecolors::Run_mine();
	
	LargestsubsetofGraphverticeswithedgesof2ormorecolors::Run_solution1();

	cout << endl;

	return 0;
}