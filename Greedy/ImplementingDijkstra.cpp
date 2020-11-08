//
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/?category[]=Greedy&difficulty[]=1&page=1&query=category[]Greedydifficulty[]1page1
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace ImplementingDijkstra
{
	void Run(int arr[], int n)
	{
	}
};

int ImplementingDijkstra_Test ()
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

		ImplementingDijkstra::Run(arr, n);

	}

	return 0;
}