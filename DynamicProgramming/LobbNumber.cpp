//
// https://www.geeksforgeeks.org/lobb-number/
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace LobbNumber
{
    int Run(int n, int m)
    {
        int ret = 0;

        return ret;
    }
};


// Driven Program 
int LobbNumber_Test ()
{
    int T;
    //taking testcases
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        cout << LobbNumber::Run (n, m) << endl;
    };

    return 0;

}