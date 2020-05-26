//
// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0/
//

#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;

namespace SortArrayOf0s1snd2s
{
	void PrintList(list<int> myList)
	{
		list<int>::iterator it;
		for (it = myList.begin(); it != myList.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	
	int Run(list<int> myList, int n)
	{
		list<int>::iterator it = myList.begin();

		for (int i = 0; i < n; i++)
		{
			list<int>::iterator tmp = it;
			tmp++;

			if (*it == 0)
			{
				myList.push_front(0);
				myList.erase(it);
			}
			else if (*it == 2)
			{
				myList.push_back(2);
				myList.erase(it);
			}
			it = tmp;
		}

		PrintList(myList);

		return 0;
	}
};

int SortArrayOf0s1snd2s_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;

		list<int> myList;
		for (int i = 0; i < n; i++)
		{
			int v;
			cin >> v;
			myList.push_back(v);
		}

		SortArrayOf0s1snd2s::Run(myList, n);
		
	}
	return 0;
}