//
// https://practice.geeksforgeeks.org/problems/largest-number-possible/0/
//

#include "stdafx.h"
#include <iostream>


using namespace std;

namespace LargestNumberPossible
{
	int Run(int n, int s)
	{
		if (s == 0)
		{
			if (n == 1)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << -1 << endl;
			}
			return 0;
		}

		int ret[50];

		for (int i = 0; i < n; i++)
		{
			int v = 9;
			while (v >= 0)
			{
				if (s >= v)
				{
					ret[i] = v;
					s -= v;
					break;
				}
				v--;
			}
		}

		if (s != 0)	cout << -1 << endl;
		else
		{
			for (int i = 0; i < n; i++)
			{
				cout << ret[i];
			}
			cout << endl;
		}
		return 0;
	}
};

int LargestNumberPossible_Test()
{
	int test;
	cin >> test;

	while (test--)
	{
		int n, s;
		cin >> n >> s;

		LargestNumberPossible::Run(n, s);
	}

	return 0;
}