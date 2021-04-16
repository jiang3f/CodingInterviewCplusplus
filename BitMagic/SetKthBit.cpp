//
// https://practice.geeksforgeeks.org/problems/set-kth-bit3724/1

/*
* 
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 109
0 <= K < X, where X is the number of bits in the binary representation of N.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace SetKthBit
{
    class Solution
    {
    public:
        int setKthBit(int N, int K)
        {
            // Write Your Code here
            return N | (1 << K);

        }

    };

};

int SetKthBit_Test()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;

        SetKthBit::Solution ob;
        int ans = ob.setKthBit(N, K);
        cout << ans << endl;
    }
    return 0;
}
