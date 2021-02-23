//
// https://practice.geeksforgeeks.org/problems/special-keyboard3018/1
/*
*
Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)


Constraints:
1 < N < 75
*/
//

#include "stdafx.h"
#include <iostream>


using namespace std;

namespace SpecialKeyboard
{
    class Solution 
    {
    private:
        unsigned long long int optimalKeysSub(int n, int nClipboard, int nScreen)
        {
            if (n == 0) return nScreen;

            if (nScreen < 3)            // print A
            {
                return optimalKeysSub(n - 1, nClipboard, nScreen + 1);
            }
            else
            {
                if (n < 3)
                {
                    if (nClipboard > 0) // ctrl-v
                    {
                        return optimalKeysSub(n - 1, nClipboard, nScreen + nClipboard);
                    }
                    else  // print A
                    {
                        return optimalKeysSub(n - 1, nClipboard, nScreen + 1);
                    }
                }
                else  
                {
                    if (nClipboard > 0)
                    {
                        // Ctrll-A, Ctrl-C, ctl-V
                        unsigned long long int ret1 = optimalKeysSub(n - 3, nScreen, nScreen * 2);

                        // Ctrl-V
                        unsigned long long int ret2 = optimalKeysSub(n - 1, nClipboard, nScreen + nClipboard);

                        // print A
                        unsigned long long int ret3 = optimalKeysSub(n - 1, nClipboard, nScreen + 1);

                        ret1 = std::max(ret1, ret2);

                        return std::max(ret1, ret3);
                    }
                    else
                    {
                        unsigned long long int ret1 = optimalKeysSub(n - 3, nScreen, nScreen * 2);

                        unsigned long long int ret2 = optimalKeysSub(n - 1, nClipboard, nScreen + 1);

                        return std::max(ret1, ret2);
                    }
                }
            }
        }

    public:
        unsigned long long int optimalKeys(int N) 
        {
            // code here
            return optimalKeysSub(N, 0, 0);
        }
    };

};

int SpecialKeyboard_Test()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        SpecialKeyboard::Solution ob;
        cout << ob.optimalKeys(N) << "\n";
    }
    return 0;
}

