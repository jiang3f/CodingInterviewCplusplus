//
// https://practice.geeksforgeeks.org/problems/geek-collects-the-balls/0/?category[]=Greedy&difficulty[]=1&page=1&query=category[]Greedydifficulty[]1page1
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>

using namespace std;

namespace GeekCollectsTheBalls
{
	void Run(int arr[], int n)
	{
	}
};

int GeekCollectsTheBalls_Test ()
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

		GeekCollectsTheBalls::Run(arr, n);

	}

	return 0;
}