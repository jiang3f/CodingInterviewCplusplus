//
// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1

/*
*
Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
0 <= N <= 1018
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace PowerOf2
{

    class Solution {
    public:
        // Function to check if given number n is a power of two.
        bool isPowerofTwo(long long n) 
        {
            // Your code here    
            if (n == 0) return false;

            return ((n & (n - 1)) == 0);
        }
    };

};

int PowerOf2_Test()
{
    /*
    int t;
    cin >> t;//testcases

    for (int i = 0; i < t; i++)
    {
        long long n; //input a number n
        cin >> n;

        PowerOf2::Solution ob;
        if (ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
    */

    PowerOf2::Solution ob;
    if (ob.isPowerofTwo(1099511627776)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

