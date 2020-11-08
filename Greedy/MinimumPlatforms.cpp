//
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1/?category[]=Greedy&difficulty[]=1&page=1&query=category[]Greedydifficulty[]1page1
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace MinimumPlatforms
{
	void Run(int arr[], int n)
	{
	}
};

int MinimumPlatforms_Test ()
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

		MinimumPlatforms::Run(arr, n);

	}

	return 0;
}