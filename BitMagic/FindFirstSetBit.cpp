//
// https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1

/*
Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
0 <= N <= 108

*/

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace FindFirstSetBit
{
    //
    // Time Limit Exceeded
    // 
    class Solution_1 {
    public:
        /*  function to find position of first set
        bit in the given number
         * n: given input for which we want to get
              the position of first set bit
         */

        unsigned int getFirstSetBit(int n) 
        {
            // Your code here
            unsigned int ret = 0;

            for (;;)
            {
                if (n & 0x1)    break;
                n = n >> 1;
                ret++;
            }
                
            return ret + 1;
        }
    };

    class Solution {
    public:
        /*  function to find position of first set
        bit in the given number
         * n: given input for which we want to get
              the position of first set bit
         */

        unsigned int getFirstSetBit(int n)
        {
            // Your code here

            if (n == 0) return 0;

            int bits = 16;
            int firstSet = 0;

            while(bits > 0)
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

            return firstSet+1;
        }
    };

};

int FindFirstSetBit_Test ()
{
    /*
    int t;
    cin >> t; // testcases
    while (t--)
    {
        int n;
        cin >> n; //input n
        FindFirstSetBit::Solution ob;

        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
    */

    FindFirstSetBit::Solution ob;

    printf("%u\n", ob.getFirstSetBit(74496)); // function to get answer

    return 0;
}

