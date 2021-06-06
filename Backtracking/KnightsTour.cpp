/*
* https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
*/

/*
*   Given a N*N board with the Knight placed on the first block of an empty board. Moving according to the rules 
    of chess knight must visit each square exactly once. Print the order of each the cell in which they are visited.
*/ 
#include "stdafx.h"
#include <iostream>

using namespace std;
namespace KnightsTour
{
    void PrintSol(int* sol[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool IsSafe(int row, int col, int* sol[], int n)
    {
        return (row >= 0 && row < n&& col >= 0 && col < n && (sol[row][col] == -1));
    }

    bool solveKT_utility(int row, int col, int* sol[], int move, int n)
    {

        sol[row][col] = move;

        //int row_move[] = { 1, 1,  2, 2 ,-2, -2, -1, -1 };
        //int col_move[] = { -2, 2, -1, 1 ,-1,  1, -2,  2 };
        int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        for (int i = 0; i < 8; i++)
        {
            int nextRow = row + xMove[i];
            int nextCol = col + yMove[i];

            if (IsSafe(nextRow, nextCol, sol, n) == true)
            {
                sol[nextRow][nextCol] = move;
                bool ret = solveKT_utility(nextRow, nextCol, sol, move + 1, n);
                if (ret == true)
                {
                    return true;
                }
                else
                {
                    sol[nextRow][nextCol] = -1;
                }
            }
        }

        return false;
    }

    void solveKT(int n)
    {
        int** sol = new int* [n];
        for (int i = 0; i < n; i++)
        {
            sol[i] = new int[n];

            for (int j = 0; j < n; j++)
            {
                sol[i][j] = -1;
            }
        }

        sol[0][0] = 0;

        bool ret = solveKT_utility(0, 0, sol, 1, n);

        if (ret == true)
        {
            PrintSol(sol, n);
        }
        else
        {
            cout << "No solution." << endl;
        }
    }
};

int KnightsTour_Test()
{
    int n = 8;
    
    KnightsTour::solveKT(n);

    return 0;
}