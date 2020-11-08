//
// https://practice.geeksforgeeks.org/problems/7-segment-display/0/?category[]=Greedy&difficulty[]=1&page=1&query=category[]Greedydifficulty[]1page1
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>

using namespace std;

namespace SevenSegmentDisplay
{
	void Run(int arr[], int n)
	{
	}
};

int SevenSegmentDisplay_Test ()
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

		SevenSegmentDisplay::Run(arr, n);

	}

	return 0;
}