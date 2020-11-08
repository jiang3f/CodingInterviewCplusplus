//
// https://practice.geeksforgeeks.org/problems/water-connection-problem/0/?category[]=Greedy&difficulty[]=1&page=1&query=category[]Greedydifficulty[]1page11page1
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>

using namespace std;

namespace WaterConnectionProblem
{
	void Run(int arr[], int n)
	{
	}
};

int WaterConnectionProblem_Test ()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;

		int* arr = new int[n * n];

		for (int i = 0; i < n * n; i++)
		{
			cin >> arr[i];
		}

		WaterConnectionProblem::Run(arr, n);

	}

	return 0;
}