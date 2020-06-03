//
// https://practice.geeksforgeeks.org/problems/josephus-problem/1/
//


#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
namespace JosephusProblem
{
	struct Node
	{
		int data;
		Node *next;

		Node(int n)
		{
			data = n;
			next = nullptr;
		}
	};

	int GetPos(struct Node *list, int n, int k)
	{
		if (n == 1)	return list->data;

		for (int i = 0; i < k - 2; i++)
		{
			list = list->next;
		}

		Node *newList = list->next;
		list->next = newList->next;
		delete newList;
		return GetPos(list->next, n - 1, k);
	}
		

	int Run (int n, int k)
	{
		if (n == 1)	return 1;
		
		else if (k == 1)
		{
			return n;
		}
		else
		{
			Node *list = nullptr;
			Node *tail = nullptr;

			for (int i = n; i > 0; i--)
			{
				Node * elem = new Node(i);

				elem->next = list;

				if (i == n)	tail = elem;

				list = elem;
			}

			tail->next = list;

			return GetPos (list, n, k);
		}
	}
};

namespace JosephusProblem_simple
{
	int josephus(int n, int k)
	{
		vector <int> v;
		for (int i = 0; i<n; i++)
			v.push_back(i);
		if (v.size() == 1)
			return 1;
		int kill = k - 1;
		while (v.size()>1)
		{
			v.erase(v.begin() + kill);
			kill = (kill + k - 1) % v.size();
		}
		return v[0] + 1;

	}

};

int JosephusProblem_Test()
{
	int test;
	cin >> test;

	while (test--)
	{
		int n, k;
		cin >> n >> k;

		int ret = JosephusProblem::Run(n, k);

		cout << ret << endl;

		ret = JosephusProblem_simple::josephus(n, k);

		cout << ret << endl;
	}
	return 0;
}


