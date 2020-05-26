//
// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace FloodFillAlgorithm
{
	void PrintArray(int arr[], int n, int m)
	{
		for (int row = 0; row < n; row ++)
		{
			for (int col = 0; col < m; col ++)
			{
				cout << arr[row * m + col] << " ";
			}
		}
		cout << endl;
	}

	void ChangeColor(int arr[], int n, int m, int x, int y, int color, int k)
	{
		if (x < 0 || x == n || y < 0 || y == m)	return;

		if (arr[y + x * m] != color)	return;

		arr[y + x * m] = k;

		ChangeColor(arr, n, m, x - 1, y, color, k);

		ChangeColor(arr, n, m, x + 1, y, color, k);

		ChangeColor(arr, n, m, x, y - 1, color, k);

		ChangeColor(arr, n, m, x, y + 1, color, k);

	}

	int Run(int arr[], int n, int m, int x, int y, int k)
	{
		int color = arr[x * m + y];

		ChangeColor(arr, n, m, x, y, color, k);

		PrintArray(arr, n, m);

		return 0;
	}
};

int FloodFillAlgorithm_Test()
{
	int test;
	cin >> test;

	while (test--)
	{
		int n, m;
		cin >> n >> m;

		int count = n * m;
		int *arr = new int[count];
		for (int i = 0; i < count; i++)
		{
			cin >> arr[i];
		}

		int x, y, k;
		cin >> x >> y >> k;


		FloodFillAlgorithm::Run(arr, n, m, x, y, k);
	}
	return 0;
}
