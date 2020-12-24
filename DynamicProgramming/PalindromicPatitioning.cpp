//
// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace PalindromicPatitioning
{
    class Solution {
    public:
        int palindromicPartition(string str)
        {
            // code here

            return 0;
        }
    };
};

// Driven Program 
int PalindromicPatitioning_Test ()
{
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        PalindromicPatitioning::Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}