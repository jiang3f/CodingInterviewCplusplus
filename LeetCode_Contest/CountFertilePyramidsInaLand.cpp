/*
* https://leetcode.com/contest/biweekly-contest-66/problems/count-fertile-pyramids-in-a-land/
*/

/*
*


A farmer has a rectangular grid of land with m rows and n columns that can be divided into unit cells. Each cell is either fertile (represented by a 1) or barren (represented by a 0). All cells outside the grid are considered barren.

A pyramidal plot of land can be defined as a set of cells with the following criteria:

    The number of cells in the set has to be greater than 1 and all cells must be fertile.
    The apex of a pyramid is the topmost cell of the pyramid. The height of a pyramid is the number of rows it covers. Let (r, c) be the apex of the pyramid, and its height be h. Then, the plot comprises of cells (i, j) where r <= i <= r + h - 1 and c - (i - r) <= j <= c + (i - r).

An inverse pyramidal plot of land can be defined as a set of cells with similar criteria:

    The number of cells in the set has to be greater than 1 and all cells must be fertile.
    The apex of an inverse pyramid is the bottommost cell of the inverse pyramid. The height of an inverse pyramid is the number of rows it covers. Let (r, c) be the apex of the pyramid, and its height be h. Then, the plot comprises of cells (i, j) where r - h + 1 <= i <= r and c - (r - i) <= j <= c + (r - i).

Some examples of valid and invalid pyramidal (and inverse pyramidal) plots are shown below. Black cells indicate fertile cells.

Given a 0-indexed m x n binary matrix grid representing the farmland, return the total number of pyramidal and inverse pyramidal plots that can be found in grid.



Example 1:


Input: grid = [[0,1,1,0],[1,1,1,1]]
Output: 2
Explanation:
The 2 possible pyramidal plots are shown in blue and red respectively.
There are no inverse pyramidal plots in this grid.
Hence total number of pyramidal and inverse pyramidal plots is 2 + 0 = 2.

Example 2:


Input: grid = [[1,1,1],[1,1,1]]
Output: 2
Explanation:
The pyramidal plot is shown in blue, and the inverse pyramidal plot is shown in red.
Hence the total number of plots is 1 + 1 = 2.

Example 3:

Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 0
Explanation:
There are no pyramidal or inverse pyramidal plots in the grid.

Example 4:


Input: grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
Output: 13
Explanation:
There are 7 pyramidal plots, 3 of which are shown in the 2nd and 3rd figures.
There are 6 inverse pyramidal plots, 2 of which are shown in the last figure.
The total number of plots is 7 + 6 = 13.



Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 1000
    1 <= m * n <= 105
    grid[i][j] is either 0 or 1.


*
*/

#include "stdafx.h"
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

namespace CountFertilePyramidsInaLand
{
    class Solution {
    private:
        string makekey(int x, int y, int h, bool inverse)
        {
            stringstream os;
            os << x << "," << y << "," << h;
            if (inverse) os << ",i";
            return os.str();
        }

        map<string, int> pps;

    private:
        bool Ispyramidalplot(int x, int y, int h, vector<vector<int>>& grid)
        {
            string key = makekey(x, y, h, false);

            map<string, int>::iterator lt = pps.find(key);
            if (lt != pps.end())
            {
                return (lt->second == 1) ? true : false;
            }

            bool ret = true;

            int height = grid.size();
            int width = grid[0].size();

            if (h < 2)  ret = false;

            else if ((y + h) > height)   ret = false;

            else if ((x + 1 - h) < 0) ret = false;

            else if ((x + h) > width) ret = false;

            else
            {
                if (h == 2)
                {
                    for (int i = -1; i <= 1; i++)
                    {
                        if (grid[1 + y][x + i] == 0)
                        {
                            ret = false;
                            break;
                        }
                    }
                }
                else
                {
                    if (Ispyramidalplot(x, y, h - 1, grid) == false)
                    {
                        ret = false;
                    }
                    else
                    {
                        for (int i = (1 - h); i <= (h - 1); i++)
                        {
                            if (grid[y + h - 1][x+i] == 0)
                            {
                                ret = false;
                                break;
                            }
                        }
                    }
                }
            }

            pps[key] = (ret == true) ? 1 : 0;
            return ret;
        }

        bool Isinversepyramidalplot(int x, int y, int h, vector<vector<int>>& grid)
        {
            string key = makekey(x, y, h, true);

            map<string, int>::iterator lt = pps.find(key);
            if (lt != pps.end())
            {
                return (lt->second == 1) ? true : false;
            }

            bool ret = true;

            int height = grid.size();
            int width = grid[0].size();


            //cout << "checking (" << x << ", " << y << "), h = " << h << "." << endl;

            if (h < 2)  ret = false;

            else if (y < 2 - 1)   ret = false;

            else if ((x + 1 - h) < 0) ret = false;

            else if ((x + h) > width) ret = false;

            else
            {
                if (h == 2)
                {
                    for (int i = -1; i <= 1; i++)
                    {
                        if (grid[y - 1][x + i] == 0)
                        {
                            ret = false;
                            break;
                        }
                    }
                }
                else
                {
                    if (Isinversepyramidalplot(x, y, h - 1, grid) == false)
                    {
                        ret = false;
                    }
                    else
                    {
                        for (int i = (1 - h); i <= (h - 1); i++)
                        {
                            if (grid[y - h + 1][i+x] == 0)
                            {
                                ret = false;
                                break;
                            }
                        }
                    }
                }
            }

            pps[key] = (ret == true) ? 1 : 0;
            return ret;

        }

    public:
        int countPyramids(vector<vector<int>>& grid) {

            int ret = 0;

            int height = grid.size();

            int y = 0;
            for (auto& row : grid)
            {
                int x = 0;
                for (auto& col : row)
                {
                    if (grid[y][x] == 1)
                    {
                        for (int h = 2; h < height - y + 1; h++)
                        {

                            if (Ispyramidalplot(x, y, h, grid))
                            {
                                ret++;
                                cout << "(" << x << ", " << y << "), h = " << h << " is pyramidal plot." << endl;
                            }
                        }

                        for (int h = y + 1; h > 1; h--)
                        {
                            if (Isinversepyramidalplot(x, y, h, grid))
                            {
                                ret++;
                                cout << "(" << x << ", " << y << "), h = " << h << " is inverse pyramidal plot." << endl;
                            }
                        }
                    }
                    x++;
                }
                y++;
            }

            return ret;
        }
    };

    class Solution_Dp {
    private:
        void GetDp(int r, int c, vector<vector<int>>& grid, vector < vector<int>>& dp)
        {
            if (dp[r][c] != -1)  return;

            if (grid[r][c] == 1 && grid[r + 1][c] == 1)
            {
                GetDp(r + 1, c - 1, grid, dp);
                GetDp(r + 1, c + 1, grid, dp);

                dp[r][c] = min(dp[r + 1][c - 1], dp[r + 1][c + 1]) + 1;
            }
            else
            {
                dp[r][c] = grid[r][c];
            }
        }

        void GetIdp(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp)
        {
            if (dp[r][c] != -1)  return;

            if (grid[r][c] == 1 && grid[r - 1][c] == 1)
            {
                GetIdp(r - 1, c - 1, grid, dp);
                GetIdp(r - 1, c + 1, grid, dp);

                dp[r][c] = min(dp[r - 1][c - 1], dp[r - 1][c + 1]) + 1;
            }
            else
            {
                dp[r][c] = grid[r][c];
            }
        }

        void PrintDp(vector<vector<int>>& dp)
        {
            int height = dp.size();
            int width = dp[0].size();

            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    cout << dp[i][j] << ",";
                }

                cout << endl;
            }
        }

    public:
        int countPyramids(vector<vector<int>>& grid) {

            int height = grid.size();
            int width = grid[0].size();

            vector<vector<int>> dp(height, vector<int>(width, -1));

            for (int i = 0; i < height - 1; i++)
            {
                dp[i][0] = grid[i][0];
                dp[i][width - 1] = grid[i][width - 1];
            }
            for (int j = 0; j < width; j++)
            {
                dp[height - 1][j] = grid[height - 1][j];
            }

            for (int i = 0; i < height - 1; i++)
            {
                for (int j = 1; j < width - 1; j++)
                {
                    GetDp(i, j, grid, dp);
                }
            }
            
            cout << "print dp" << endl;
            PrintDp(dp);

            int ret = 0;

            for (int i = 0; i < height; i++)
            {
                for (int j = 1; j < width - 1; j++)
                {
                    if (dp[i][j] > 1)   ret += dp[i][j] - 1;
                }
            }

            for (int j = 0; j < width; j++)
            {
                dp[0][j] = grid[0][j];
            }

            for (int i = 1; i < height; i++)
            {
                for (int j = 1; j < width - 1; j++)
                {
                    dp[i][j] = -1;
                }
                dp[i][0] = grid[i][0];
                dp[i][width - 1] = grid[i][width - 1];
            }

            for (int i = height - 1; i > 0; i--)
            {
                for (int j = 1; j < width - 1; j++)
                {
                    GetIdp(i, j, grid, dp);
                }
            }

            cout << "print dp" << endl;
            PrintDp(dp);

            for (int i = 0;i < height;i ++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (dp[i][j] > 1)   ret += dp[i][j] - 1;
                }
            }

            return ret;
        }
    };

    //
    // https://leetcode.com/problems/count-fertile-pyramids-in-a-land/discuss/1598908/Simple-DP-Solution-with-Explanation-or-C%2B%2B-or-O(n-*-m)
    //
    class Solution_Dp1 {
    public:
        int count(vector<vector<int>> grid) {
            int i, j, n = grid.size(), m = grid[0].size(), ans = 0;
            for (i = 1; i < n; i++) {
                for (j = 1; j < m - 1; j++) {
                    if (grid[i][j] && grid[i - 1][j]) { // check if current cell can be a tip of pyramid or not.
                        grid[i][j] = min(grid[i - 1][j - 1], grid[i - 1][j + 1]) + 1; // if its a pyramid, find the height.
                        ans += grid[i][j] - 1;
                        // pyramid of size n contributes n - 1 times to the answer.
                    }
                }
            }

            return ans;
        }
        int countPyramids(vector<vector<int>>& grid) {
            int ans = count(grid); // this will count inverse pyramid.
            reverse(grid.begin(), grid.end());
            ans += count(grid); // this will count simple pyramid.
            return ans;
        }
    }; 
};

int CountFertilePyramidsInaLand_Test()
{
    vector<vector<int>> grid = { {1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {0, 1, 0, 0, 1} };

    CountFertilePyramidsInaLand::Solution_Dp ob;

    int ret = ob.countPyramids(grid);

    cout << ret << endl;

    return 0;
}