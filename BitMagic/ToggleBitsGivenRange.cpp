//
// https://practice.geeksforgeeks.org/problems/toggle-bits-given-range0952/1

/*
* Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 105
1 <= L<=R <= Number of Bits in N
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace ToggleBitsGivenRange
{
    class Solution {
    public:
        int toggleBits(int N, int L, int R) 
        {
            // code here
            int mask = 0;

            for (int i = L; i <= R; i++)
            {
                mask |= 1 << (i-1);
            }

            return N ^ mask;
        }
    };

};

int ToggleBitsGivenRange_Test()
{
    int t;
    cin >> t;
    while (t--) {
        int N, L, R;

        cin >> N >> L >> R;

        ToggleBitsGivenRange::Solution ob;
        cout << ob.toggleBits(N, L, R) << endl;
    }
    return 0;
}

