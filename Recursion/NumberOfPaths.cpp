//
// https://practice.geeksforgeeks.org/problems/number-of-paths/0/
//


#include "stdafx.h"
#include <iostream>

using namespace std;

namespace NumberOfPaths
{

	int GetPath (int x, int y, int n, int m)
	{
		int sum = 0;

		if (x == n - 1 && y == m - 1)	return 1;

		if (x < n - 1)	sum += GetPath(x + 1, y, n, m);

		if (y < m - 1)	sum += GetPath(x, y + 1, n, m);

		return sum;
	}
};

int NumberOfPaths_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n, m;
		cin >> n >> m;

		int ret = NumberOfPaths::GetPath (0, 0, n, m);

		cout << ret << endl;
	}

	return 0;
}