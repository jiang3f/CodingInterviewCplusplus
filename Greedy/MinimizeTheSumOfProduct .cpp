//
// https://practice.geeksforgeeks.org/problems/minimize-the-heights/0/
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <functional>


using namespace std;
namespace MinimizeTheSumOfProduct
{
	long Run(long arrA[], long arrB[], long n)
	{
		long sum = 0;

		sort(arrA, arrA + n);

		sort(arrB, arrB + n, greater<long>());

		for (long i = 0; i < n; i++)
		{
			sum += arrA[i] * arrB[i];
		}

		return sum;
	}

};

int MinimizeTheSumOfProduct_Test()
{
	long test;
	cin >> test;
	while (test--)
	{
		long n;
		cin >> n;

		long* arrA = new long[n];

		for (long i = 0; i < n; i++)
		{
			cin >> arrA[i];
		}

		long* arrB = new long[n];

		for (long i = 0; i < n; i++)
		{
			cin >> arrB[i];
		}

		long ret = MinimizeTheSumOfProduct::Run(arrA, arrB, n);

		cout << ret << endl;

	}
	return 0;
}

