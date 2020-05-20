//
// https://practice.geeksforgeeks.org/problems/reverse-bits/0
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace ReverseBits
{
	unsigned int Run(unsigned int n)
	{
		unsigned int sum = 0;

		for (int i = 0; i < 32; i++)
		{
			if (n & (1 << i))
			{
				sum += 1 << (31 - i);
			}
		}
		return sum;
	}
};

namespace ReverseBits_UseMerge
{

	unsigned int Merge(unsigned int cur, unsigned int n, int shift)
	{
		unsigned int ret = (cur << shift) + n;
		return ret;
	}

	unsigned int ReverseBits(unsigned int num, int shift)
	{
		unsigned int cur = (num >> shift) & 1;

		if (shift == 31)
		{
			return cur;
		}
		unsigned int right = ReverseBits(num, shift + 1);
		unsigned int ret = Merge(cur, right, 32 - shift - 1);
		return ret;
	}

	unsigned int Run (int n) 
	{
		return ReverseBits(n, 0);
	}


};

namespace ReverseBits_WithoutBitwise
{
	unsigned int Run (unsigned int n) 
	{
		unsigned int r;
		int i = 0;
		unsigned int result = 0;
		while (i<32) {
			r = n % 2;
			n = n / 2;
			result = (result * 2 + r);
			++i;
		}

		return result;
	}
}

int ReverseBits_Test()
{
	int t;
	cin >> t;

	while (t--)
	{
		unsigned int n;

		cin >> n;

		unsigned int sum = ReverseBits::Run(n);
		cout << sum << endl;

		sum = ReverseBits_UseMerge::Run(n);
		cout << sum << endl;

		sum = ReverseBits_WithoutBitwise::Run(n);
		cout << sum << endl;
	}

	return 0;
}
