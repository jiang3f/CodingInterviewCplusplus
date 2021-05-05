//
//  https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits-1587115621/1

/*
*
Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 109
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace SwapAllOddAndEvenBits
{
	class Solution
	{
	public:
		//Function to swap odd and even bits.
		unsigned int swapBits(unsigned int n)
		{
			// Your code here
			unsigned int ret = 0;
			int offset = 0;
			while (n != 0)
			{
				unsigned int mask = n & 1;

				n = n >> 1;

				mask = (mask << 1) + (n & 1);

				n = n >> 1;
				
				ret = (mask << offset) + ret;
				offset += 2;
			}

			return ret;
		}
	};
};

int SwapAllOddAndEvenBits_Test()
{
	/*
	int t;
	cin >> t;//testcases
	while (t--)
	{
		unsigned int n;
		cin >> n;//input n

		SwapAllOddAndEvenBits::Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	*/

	SwapAllOddAndEvenBits::Solution ob;
	//calling swapBits() method
	cout << ob.swapBits(23) << endl;
	return 0;
}
