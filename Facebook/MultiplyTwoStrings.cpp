/*
* https://www.geeksforgeeks.org/facebook-interview-set-1/?ref=rp
* https://practice.geeksforgeeks.org/problems/multiply-two-strings/1
*/

/*
* Given two numbers as stings s1 and s2. Calculate their Product.
* 1 <= length of s1 and s2 <= 103
* 


Expected Time Complexity : O(n1* n2)
Expected Auxiliary Space : O(n1 + n2); where n1and n2 are sizes of strings s1and s2 respectively.
*/
#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>

using namespace std;


namespace MultiplyTwoStrings
{

    class Solution 
    {
    public:
        /*You are required to complete below function */
        string multiplyStrings(string s1, string s2) 
        {
            //Your code here

            return "";
        }

    };

};

int MultiplyTwoStrings_Test()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;
        cin >> a >> b;
        MultiplyTwoStrings::Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;
    }

    return 0;
}

