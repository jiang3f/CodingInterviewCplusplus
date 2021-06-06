/*
* https://leetcode.com/problems/n-queens-ii/
*/

/*
*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/
#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
namespace NQueensII
{
    class Graph
    {
        int n;
        list<int>* edges;

    public:
        Graph(int n)
        {
            edges = new list<int>[n];
        };

        void AddEdge(int start, int end)
        {
            edges[start].push_back(end);
        }

        void DFS(int s)
        {
            cout << s << ",";

            if (edges[s].size() == 0)   cout << endl;

            list<int>::iterator it = edges[s].begin();
            while (it != edges[s].end())
            {
                DFS(*it);
            }
        }

    };
    class Solution 
    {
    private:
        set<vector<int>> result;

    protected:
        void MoveTo(int& row, int& col, int t)
        {
            if (t == 0)
            {
                row --;
                col --;
            }
            else if (t == 1)
            {
                row --;
                col ++;
            }
            else if (t == 2)
            {
                row++;
                col--;
            }
            else
            {
                row++;
                col++;
            }
        }
        void UpdateVisit(bool* visit, int a, int n)
        {
            int row = a / n;
            int col = a % n;

            for (int i = row * n; i < (row+1) * n  ; i++)     visit[i] = true;

            for (int i = col; i < n * n; i += n)    visit[i] = true;

            for (int i = 0; i < 4; i++)
            {
                int row1 = row;
                int col1 = col;
                while (row1 >= 0 && row1 < n && col1 >= 0 && col1 < n)
                {
                    visit[row1 * n + col1] = true;
                    MoveTo(row1, col1, i);
                }
            }

            cout << "Updated visit for [" << a << "]:" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << visit[i * n + j] << ",";
                }
                cout << endl;
            }
        }

        void Queen_sub(int a, bool* visit, vector<int> v, int n)
        {
            v.push_back(a);
            UpdateVisit(visit, a, n);

            bool isNul = true;

            for (int i = 0; i < n * n; i++)
            {
                if (visit[i] == false)
                {
                    vector<int> v1;
                    vector<int>::iterator it = v.begin();
                    while (it != v.end())
                    {
                        v1.push_back(*it);
                        it++;
                    }

                    bool* visit1 = new bool[n * n];
                    for (int j = 0; j < n * n; j++)  visit1[j] = visit[j];

                    Queen_sub(i, visit1, v1, n);

                    isNul = false;
                }
            }

            if (isNul == true)
            {
                if (v.size() == n)
                {
                    sort(v.begin(), v.end());
                    result.insert(v);
                }
            }

        }
    public:
        int totalNQueens(int n) 
        {
            int cells = n * n;

            bool* visit = new bool[cells];

            for (int i = 0; i < cells; i++)
            {

                for (int j = 0; j < cells; j++)   visit[j] = false;
               
                vector<int> v;
                Queen_sub(i, visit, v, n);
            }

            cout << ">>>>>>>>>>>>>>>>Result:" << endl;
            set<vector<int>>::iterator it = this->result.begin();
            while (it != result.end())
            {
                vector<int> v = *it;
                vector<int>::iterator it1 = v.begin();
                while (it1 != v.end())
                {
                    cout << *it1 << ",";
                    it1++;
                }
                cout << endl;
                it++;
            }
            return result.size();
        }
    };
};

int NQueensII_Test()
{
    int n = 7;

    NQueensII::Solution ob;

    cout << ob.totalNQueens(n) << endl;

    return 0;
}
