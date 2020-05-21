//
// https://practice.geeksforgeeks.org/problems/find-optimum-operation/0
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace MinimumOperations
{
	int Run(int n)
	{
		int operations = 0;

		while (n != 0)
		{
			if (n % 2)	operations++;
			n = n / 2;
			if (n != 0)	operations++;
		}
		return operations;
	}
};

int MinimumOperations_Test()
{
	int test;
	cin >> test;

	while (test--)
	{
		int n;
		cin >> n;
		int op = MinimumOperations::Run(n);
		cout << op << endl;
	}

	return 0;
}
