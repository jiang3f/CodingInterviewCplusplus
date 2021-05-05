//
// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1

/*
*
Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= A, B <= 10 6
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace Bitifference
{
	class Solution_1 {
	public:
		// Function to find number of bits needed to be flipped to convert A to B
		int countBitsFlip(int a, int b)
		{

			// Your logic here
			int ab_xor = a ^ b;
			int count = 0;
			while (ab_xor != 0)
			{
				if (ab_xor & 1)	count++;
				ab_xor = ab_xor >> 1;
			}
			return count;
		}
	};

	class Solution {
	public:
		// Function to find number of bits needed to be flipped to convert A to B
		int countBitsFlip(int a, int b)
		{

			// Your logic here
			int diff = 0;
			while (a > 0 || b > 0)
			{
				if ((a % 2) != (b % 2)) diff++;
				a /= 2;
				b /= 2;
			}
			return diff;
		}
	};
};

int Bitifference_Test()
{
	int t;
	cin >> t;// input the testcases
	while (t--) //while testcases exist
	{
		int a, b;
		cin >> a >> b; //input a and b

		Bitifference::Solution ob;
		cout << ob.countBitsFlip(a, b) << endl;
	}
	return 0;

}
