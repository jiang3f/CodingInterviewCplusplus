//
// https://practice.geeksforgeeks.org/problems/min-coin5549/1/?category[]=Greedy&difficulty[]=1&page=1&query=category[]Greedydifficulty[]1page1
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>

using namespace std;

namespace MinCoin
{
	void Run(int arr[], int n)
	{
	}
};

int MinCoin_Test ()
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

		MinCoin::Run(arr, n);

	}

	return 0;
}