//
//  https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
/*
*
Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 109
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace RatInAMazeProblem
{
    class Solution {
    protected:
        bool findPathSub(int row, int col, vector<vector<int>> m, int n, string p, vector<string>& s)
        {
            if (m[row][col] == 0)   return false;

            if ((row == (n - 1)) && (col == (n - 1)))
            {
                //cout << p << endl;
                s.push_back(p);
                return true;
            }

            m[row][col] = 0;

            bool ret1 = false;
            bool ret2 = false;
            bool ret3 = false;
            bool ret4 = false;

            if (row < n - 1)  ret1 = findPathSub(row + 1, col, m, n, p + "D", s);
            if (col < n - 1)  ret2 = findPathSub(row, col + 1, m, n, p + "R", s);
            if (col > 0)    ret3 = findPathSub(row, col - 1, m, n, p + "L", s);
            if (row > 0)    ret4 = findPathSub(row - 1, col, m, n, p + "U", s);


            return ret1 | ret2 | ret3 | ret4;
        }

    public:
        vector<string> findPath(vector<vector<int>>& m, int n) {
            // Your code goes here
            vector<string> s;
            findPathSub(0, 0, m, n, "", s);
            sort(s.begin(), s.end());
            return s;
        }
    };

};

int RatInAMazeProblem_Test()
{
    /*
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        RatInAMazeProblem::Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    */

    int n = 5;
    vector<vector<int>> m =
    {
       {1, 1, 1, 1, 1},
       {1, 1, 1, 1, 1},
       {1, 1, 1, 1, 1},
       {1, 1, 1, 1, 1},
       {1, 1, 1, 1, 1}
    };

    RatInAMazeProblem::Solution obj;
    vector<string> result = obj.findPath(m, n);
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
    return 0;
}
