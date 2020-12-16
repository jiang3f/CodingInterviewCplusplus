//
// https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace BellNumbers
{
    long long Run(long long n)
    {
        return 0;
    }
};

// Driven Program 
int BellNumbers_Test()
{
    int T;
    //taking testcases
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << BellNumbers::Run(n) << endl;
    };

    return 0;

}