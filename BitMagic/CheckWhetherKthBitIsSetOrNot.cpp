//
// https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
/*
Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 109
0 <= K <= floor(log2(N) + 1)
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace CheckWhetherKthBitIsSetOrNot
{
	class Solution
	{
	public:
		// Function to check if Kth bit is set or not.
		bool checkKthBit(int n, int k)
		{
			// Your code here
			// It can be a one liner logic!! Think of it!!

			return n & (1 << k);
		}
	};

};

int CheckWhetherKthBitIsSetOrNot_Test ()
{
	int t;
	cin >> t;//taking testcases
	while (t--)
	{
		long long n;
		cin >> n;//input n
		int k;
		cin >> k;//bit number k
		CheckWhetherKthBitIsSetOrNot::Solution obj;
		if (obj.checkKthBit(n, k))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;

}
