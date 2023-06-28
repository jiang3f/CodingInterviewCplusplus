/*
* https://leetcode.com/contest/weekly-contest-274/problems/maximum-employees-to-be-invited-to-a-meeting/
*
A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.


Input: favorite = [2,2,1,2]
Output: 3
Explanation:
The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
The maximum number of employees that can be invited to the meeting is 3. 

Constraints:

n == favorite.length
2 <= n <= 105
0 <= favorite[i] <= n - 1
favorite[i] != i

*/

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

namespace MaxEmployeestoBeInvitedtoMeeting
{
    class Solution {

    public:
        int maximumInvitations(vector<int>& A) 
        {
            int N = A.size();

            vector<int> m(N, -1); // m[i] is the depth of node i. -1 means unvisited
            vector<vector<int>> r(N); // The reverse graph
            
            for (int i = 0; i < N; ++i)
            {
                r[A[i]].push_back(i);
            }

            // handle case 1
            function<int(int)> dfs = [&](int u) 
            {
                if (m[u] != -1) 
                    return m[u];

                int ans = 0;
                for (int v : r[u])
                {
                    if (v == A[u])  continue;

                    ans = max(ans, dfs(v));
                }
                
                return m[u] = 1 + ans;
            };

            int ans = 0, free = 0;
            for (int i = 0; i < N; ++i) 
            {
                if (m[i] != -1) continue; // skip visited nodes
            
                if (A[A[i]] == i) 
                {
                    m[i] = m[A[i]] = 0;
                    
                    int a = 0, b = 0; // find the length of the longest arms starting from `i` and `A[i]`
                    
                    a = dfs(i);

                    for (int v : r[i]) 
                    {
                        if (v == A[i]) 
                            continue;
                        
                        a = max(a, dfs(v));
                    }

                    for (int v : r[A[i]]) {
                        if (v == i) continue;
                        b = max(b, dfs(v));
                    }
                    free += a + b + 2; // this free component is of length `a+b+2`
                }
            }
            // handle case 2
            function<tuple<int, int, bool>(int)> dfs2 = [&](int u)->tuple<int, int, bool> {
                if (m[u] != -1) return { u, m[u], false }; // We visited this node the second time, so this node must be the entry point to the cycle
                m[u] = 0;
                auto [entryPoint, depth, cycleVisited] = dfs2(A[u]);
                if (cycleVisited) { // After the cycle being traversed, any other node in the backtracking process are outside of the cycle and should be ignored (by keeping m[u] as 0).
                    return { entryPoint, depth, true };
                }
                m[u] = 1 + depth; // If we haven't met the entry point again, this is a node within the cycle, so we increment the depth.
                return { entryPoint, m[u], u == entryPoint }; // When we visit the entry point again, we know what we've done traversing the cycle.
            };
            for (int i = 0; i < N; ++i) {
                if (m[i] != -1) continue;
                auto [entryPoint, depth, cycleVisited] = dfs2(i);
                if (cycleVisited) ans = max(ans, depth);
            }
            return max(ans, free);
        }
    };
};

int MaxEmployeestoBeInvitedtoMeeting_Test()
{
    return 0;
}
