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
#include <vector>

using namespace std;

namespace RotateBits
{
    class Solution
    {
    public:
        vector <int> rotate(int n, int d)
        {
            //code here.

            vector<int> ret;
            d %= 16;
            int mode;
            int bits;
            for (int i = 0; i < 2; i++)
            {
                if (i == 0) bits = 16 - d;
                else bits = d;

                mode = 1 << bits;

                int a = n / mode;
                int b = n % mode;

                ret.push_back(a  + (b << (16 - bits)));
            }

            return ret;
        }
    };

};

int RotateBits_Test()
{
    /*
    int t; cin >> t;
    while (t--)
    {

        int n, d; cin >> n >> d;
        RotateBits::Solution ob;
        vector <int> res = ob.rotate(n, d);
        cout << res[0] << endl << res[1] << endl;
    }
    */

    RotateBits::Solution ob;
    vector <int> res = ob.rotate(28, 2);
    cout << res[0] << endl << res[1] << endl;

    return 0;
}
