//
// https://practice.geeksforgeeks.org/problems/print-diagonally/0/?difficulty[]=1&page=2&query=difficulty[]1page2
//
#include "stdafx.h"
#include <iostream>

using namespace std;

namespace PrintDiagonally
{
	void Run(int arr[], int n)
	{
		int xStart = 0;
		for (int s = 0; s <= (2 * n - 2); s++)
		{
			int y = s - xStart;
			int x = xStart;
			while (y <= xStart)
			{
				cout << arr[y * n + x] << " ";
				y++;
				x--;
			}
			if (xStart < n - 1)	xStart++;
		}
		cout << endl;
	}
};

int PrintDiagonally_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;

		int* arr = new int[n*n];

		for (int i = 0; i < n*n; i++)
		{
			cin >> arr[i];
		}

		PrintDiagonally::Run(arr, n);

	}

	return 0;
}
