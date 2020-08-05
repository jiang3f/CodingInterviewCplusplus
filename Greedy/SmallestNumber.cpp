//
// https://practice.geeksforgeeks.org/problems/smallest-number/0/
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;
namespace SmallestNumber
{
	int Run(int sum, int n)
	{
		int ret = 0;

		if (sum > n * 9 || sum == 0)	return -1;

		sum--;

		for (int i = 0; i < n; i++)
		{
			if (sum == 0)	break;
			int a = (sum > 9) ? 9 : sum;
			sum -= a;
			ret += a * pow(10, i);
		}
		
		ret += pow(10, n - 1);

		return ret;
	}

};

int SmallestNumber_Test ()
{
	int test;
	cin >> test;
	while (test--)
	{
		int sum, n;
		cin >> sum >> n;

		int ret = SmallestNumber::Run(sum, n);

		cout << ret << endl;

	}
	return 0;
}

