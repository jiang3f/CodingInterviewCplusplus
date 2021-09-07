/*
* https://leetcode.com/contest/weekly-contest-246/problems/count-sub-islands/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace CountSubIslands
{
    class Solution {

    public:
        void MergeIslands(vector<vector<int>>& islands, int oldVal, int newVal)
        {
            for (int i = 0; i < islands.size(); i++)
            {
                for (int j = 0; j < islands[i].size(); j++)
                {
                    if (islands[i][j] == oldVal)    islands[i][j] = newVal;
                }
            }
        }

        void MergeIslands(vector<set<pair<int,int>>>& islands, int s1, int s2)
        {
            for (set<pair<int, int>>::iterator it = islands[s1].begin(); it != islands[s1].end(); it++)
            {
                islands[s2].insert(*it);
            }

            islands[s1].clear();
        }

        vector<set<pair<int,int>>> FindAllIslands(vector<vector<int>>& grid, vector<vector<int>>& islands)
        {
            vector<set<pair<int, int>>> ret;
            
            set<pair<int, int>> set0;
            ret.push_back (set0);

            int islandNo = 1;

            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == 1)
                    {
                        // check left
                        int leftCellIslandNo = 0;
                        int topCellIslandNo = 0;
                        
                        if (i > 0)
                        {
                            topCellIslandNo = islands[i - 1][j];
                        }

                        if (j > 0)
                        {
                            leftCellIslandNo = islands[i][j - 1];
                        }

                        if (leftCellIslandNo == 0 && topCellIslandNo == 0)
                        {
                            islands[i][j] = islandNo;
                            set<pair<int, int>> newIsland;
                            newIsland.insert(make_pair(i, j));
                            ret.push_back(newIsland);
                            islandNo++;
                        }
                        else if (leftCellIslandNo == 0)
                        {
                            islands[i][j] = topCellIslandNo;
                            ret[topCellIslandNo].insert(make_pair(i, j));
                        }
                        else if (topCellIslandNo == 0)
                        {
                            islands[i][j] = leftCellIslandNo;
                            ret[leftCellIslandNo].insert(make_pair(i, j));
                        }
                        else if (topCellIslandNo == leftCellIslandNo)
                        {
                            islands[i][j] = leftCellIslandNo;
                            ret[leftCellIslandNo].insert(make_pair(i, j));
                        }
                        else  // merge islands
                        {
                            MergeIslands(islands, topCellIslandNo, leftCellIslandNo);
                            MergeIslands(ret, topCellIslandNo, leftCellIslandNo);
                            islands[i][j] = leftCellIslandNo;
                            ret[leftCellIslandNo].insert(make_pair(i, j));
                        }
                    }
                }
            }

            return ret;
        }

        int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
        {
            int width = grid1.size();
            int height = grid1[0].size();

            vector<vector<int>> island1(width), island2(width);

            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < grid1[i].size(); j++)
                {
                    island1[i].push_back(0);
                    island2[i].push_back(0);
                }
            }
            vector<set<pair<int, int>>> sets1 = FindAllIslands(grid1, island1);
            vector<set<pair<int, int>>> sets2 = FindAllIslands(grid2, island2);

            int total = 0;

            for (int i = 1; i < sets2.size(); i++)
            {
                if (sets2[i].size() == 0)   continue;

                set<pair<int, int>>::iterator it = sets2[i].begin();
                
                if (island1[it->first][it->second] == 0) continue;

                int setNo = island1[it->first][it->second];

                if (std::includes(sets1[setNo].begin(), sets1[setNo].end(), sets2[i].begin(), sets2[i].end()))
                {
                    total ++;
                }
            }

            return total;
        }
    };
};

int CountSubIslands_Test()
{
    vector<vector<int>> grid1 = { {1,1,1,1,0,0},{1,1,0,1,0,0},{1,0,0,1,1,1},{1,1,1,0,0,1},{1,1,1,1,1,0},{1,0,1,0,1,0},{0,1,1,1,0,1},{1,0,0,0,1,1},{1,0,0,0,1,0},{1,1,1,1,1,0} };
    vector<vector<int>> grid2 = { {1,1,1,1,0,1},{0,0,1,0,1,0},{1,1,1,1,1,1},{0,1,1,1,1,1},{1,1,1,0,1,0},{0,1,1,1,1,1},{1,1,0,1,1,1},{1,0,0,1,0,1},{1,1,1,1,1,1},{1,0,0,1,0,0} };
    CountSubIslands::Solution ob;

    cout << ob.countSubIslands(grid1, grid2);

    return 0;
}