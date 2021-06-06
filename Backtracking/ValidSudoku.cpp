/*
* https://see.stanford.edu/materials/icspacs106b/H19-RecBacktrackExamples.pdf
*  https://leetcode.com/problems/valid-sudoku/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>


using namespace std;
namespace ValidSudoku
{
    class Solution {
    public:
        bool NoUnassignedCell(vector<vector<char>>& board, int& row, int& col)
        {
            for (row = 0; row < board.size(); row ++)
            {
                for (col = 0; col < board[row].size(); col ++)
                {
                    if (board[row][col] == '.')
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        bool NoRowConflicts(vector<vector<char>>& board, int row, int col, char v)
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[row][i] == v)   return false;
            }
            return true;
        }
        bool NoColConflicts(vector<vector<char>>& board, int row, int col, char v)
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i][col] == v)   return false;
            }
            return true;
        }

        bool NoBlockConflicts(vector<vector<char>>& board, int row, int col, char v)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i+row][j+col] == v)   return false;
                }
            }
            return true;
        }

        void PrintBoard(vector<vector<char>>& board)
        {
            for (int row = 0; row < board.size(); row++)
            {
                for (int col = 0; col < board[row].size(); col++)
                {
                    cout << board[row][col] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
         
        bool NoConflicts(vector<vector<char>>& board, int row, int col, char v)
        {
            PrintBoard(board);
            return NoBlockConflicts(board, (row / 3) * 3, (col / 3) * 3, v) && NoColConflicts(board, row, col, v) && NoRowConflicts(board, row, col, v);
        }

        bool isValidSudoku(vector<vector<char>>& board)
        {

            char digits[] = { '0', '1','2', '3','4', '5','6', '7','8', '9' };

            int row, col;

            if (NoUnassignedCell(board, row, col) == true)
            {
                return true;
            }

            for (int i = 1; i < 10; i++)
            {
                if (NoConflicts(board, row, col, digits[i]))
                {
                    board[row][col] = digits[i];

                    bool ret = isValidSudoku(board);

                    if (ret == true)    return true;

                    board[row][col] = '.';
                }
            }

            return false;
        }
    };
};

int ValidSudoku_Test()
{
    ValidSudoku::Solution ob;

    vector<vector<char>> board =
        {
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

    bool ret = ob.isValidSudoku(board);

    if (ret)    cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}