//
// https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1

/*
Expected Time Complexity: O(max(log m, log n)).
Expected Auxiliary Space: O(1).

Constraints:
1 <= M <= 109
1 <= N <= 109

*/

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace RightmostDifferentBit
{
    class Solution {
    public:
        /*  Function to find the first position with different bits
        *   This function returns the position with different bit
        */
        int posOfRightMostDiffBit(int m, int n)
        {

            // Your code here
            n = m ^ n;

            int bits = 16;
            int firstSet = 0;

            while (bits > 0)
            {
                unsigned int rightHalf = n & ((1 << bits) - 1);

                if (rightHalf != 0)
                {
                    n = rightHalf;
                }
                else
                {
                    n = n >> bits;
                    firstSet += bits;
                }

                bits = bits / 2;
            }

            return firstSet + 1;
        }
    };
};

int RightmostDifferentBit_Test()
{

    int t;
 
    cin >> t; //input number of testcases
    
    while (t--)
    {
        int m, n;
        cin >> m >> n; //input m and n
        RightmostDifferentBit::Solution ob;
        cout << ob.posOfRightMostDiffBit(m, n) << endl;
    }
    
    return 0;
}
