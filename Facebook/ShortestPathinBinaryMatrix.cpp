/*
* https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/

/*
*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.



Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1



Constraints:

    n == grid.length
    n == grid[i].length
    1 <= n <= 100
    grid[i][j] is 0 or 1
*/

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <array>

using namespace std;

namespace ShortestPathinBinaryMatrix
{
    #define    DBG 1

    class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            auto PrintMatrix = [](vector<vector<int>>& g)
            {
                for (auto& l : g)
                {
                    for (auto& i : l)
                    {
                        cout << i << ",";
                    }
                    cout << endl;
                }
            };

            int h = grid.size();
            int w = grid[0].size();

            vector<int> dir = { -1, -1, 1, 1, -1, 0, 1, 0, -1 };

            queue<array<int, 3>> q;     //step,row,col

            q.push({ 1,0,0 });

            while (!q.empty())
            {
                auto& [steps, row, col] = q.front();

                q.pop();
#ifdef DBG            
                PrintMatrix(grid);
                cout << "row=" << row << ",col=" << col << ",grid[row][col]=" << grid[row][col] << ",steps=" << steps << endl;
#endif            
                if (grid[row][col] == 0)
                {
                    if (row == h - 1 && col == w - 1)   return steps;

                    grid[row][col] = steps;

                    for (int i = 0; i < 8; i++)
                    {
                        int r1 = row + dir[i];
                        int c1 = col + dir[i + 1];

                        if (min(r1, c1) >= 0 && r1 < h && c1 < w && grid[r1][c1] == 0)
                        {
                            q.push({ steps + 1,r1,c1 });
                        }
                    }
                }
            }

            return -1;
        }
    };
};

int ShortestPathinBinaryMatrix_Test ()
{
    ShortestPathinBinaryMatrix::Solution ob;

    vector<vector<int>> matrix = { 
        {0,0,1,1,0,0},
        {0,0,0,0,1,1},
        {1,0,1,1,0,0},
        {0,0,1,1,0,0},
        {0,0,0,0,0,0},
        {0,0,1,0,0,0} };
    int ret = ob.shortestPathBinaryMatrix(matrix);

    cout << "ret=" << ret << endl;

    return 0;
}
