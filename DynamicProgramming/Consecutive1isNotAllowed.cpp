//
// https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0/
//
#include "stdafx.h"
#include <iostream>
#include <math.h>     
#include <map>

using namespace std;

namespace Consecutive1isNotAllowed
{
	int f(int left, int n)
	{
		if (n == 1)
		{
			return (left == 0) ? 2 : 1;
		}

		else
		{
			if (left == 1)	return f(0, n - 1);
			else
			{
				int ret = f(0, n - 1);
				ret += f(1, n - 1);
				return ret;
			}
		}
	}

	int Run(int n)
	{
		
		int ret = f (0, n);

		return ret;
	}

};

namespace Consecutive1isNotAllowed_formula
{
	unsigned long long Run(int n)
	{

		// (1/2 sqrt(5)) * [((1+sqrt(5))/2) power n)*(3+sqrt(5)) - (((1-sqrt(5))/2) power n) * (3-sqrt(5))]
		double root5plus1 = sqrt(5) + 1.0f;
		double root5sub1 = 1.0f - sqrt(5);
		double root5plus3 = sqrt(5) + 3;
		double root5sub3 = 3 - sqrt(5);

		double v = pow(root5plus1 / 2, n);
		v = v * root5plus3;
		v = v - pow((root5sub1 / 2), n) * root5sub3;
		v = v / (2.0f * sqrt(5));


		return (unsigned long long)v;

	}
};

namespace Consecutive1isNotAllowed_recursion
{

	class Series
	{
	private:
		map<int, unsigned long long> _myMap;

	public:

		unsigned long long Run(int n)
		{
			if (n == 0)	return 1;

			if (n == 1) return 2;

			unsigned long long v1, v2;

			map<int, unsigned long long>::iterator it = _myMap.find(n - 1);
			if (it != _myMap.end())
			{
				v1 = it->second;
			}
			else
			{
				v1 = Run(n - 1);
				_myMap.insert(make_pair(n-1, v1));
			}

			it = _myMap.find(n - 2);
			if (it != _myMap.end())
			{
				v2 = it->second;
			}
			else
			{
				v2 = Run(n - 2);
				_myMap.insert(make_pair(n-2, v2));
			}

			return (v1 + v2) % 1000000007;
		}
	};
};

int Consecutive1isNotAllowed_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;

		//int ret = Consecutive1isNotAllowed::Run(n);

		Consecutive1isNotAllowed_recursion::Series s;

		unsigned long long ret = s.Run(n);

		//ret = ret % 1000000007;

		cout << ret << endl;

	}
	return 0;
}

