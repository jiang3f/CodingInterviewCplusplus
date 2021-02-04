//
//https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/
// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
// 

#include "stdafx.h"
#include <iostream>
#include <set>
#include <map>
#include <functional>

using namespace std;
namespace MobileNumericKeypad_recursive_map
{
    class Solution 
    {
    public:
        Solution()
        {
            set<int> key0{ 0, 8 };
            keyPad[0] = key0;

            set<int> key1{ 1, 2, 4 };
            keyPad[1] = key1;

            set<int> key2{ 2, 1, 3, 5 };
            keyPad[2] = key2;

            set<int> key3{ 3, 2, 6 };
            keyPad[3] = key3;

            set<int> key4{ 4, 1, 5, 7 };
            keyPad[4] = key4;

            set<int> key5{ 5, 2, 4, 6, 8 };
            keyPad[5] = key5;

            set<int> key6{ 6, 3, 5, 9 };
            keyPad[6] = key6;

            set<int> key7{ 7, 4, 8 };
            keyPad[7] = key7;

            set<int> key8{ 8, 5, 7, 9, 0 };
            keyPad[8] = key8;

            set<int> key9{ 9, 6, 8 };
            keyPad[9] = key9;
        }

        long long getCountSub(int key, int n)
        {
            if (n == maxPress)  return 1;

            long long total = 0;

            set<int>::iterator it;
            for (it = keyPad[key].begin(); it != keyPad[key].end(); it++)
            {
                total += getCountSub(*it, n + 1);
            }

            return total;
        }

        long long getCount(int N)
        {
            // Your code goes here
            maxPress = N;

            map<int, set<int>>::iterator keyIt;

            long long total = 0;

            for (keyIt = keyPad.begin(); keyIt != keyPad.end(); keyIt++)
            {
                total += getCountSub(keyIt->first, 1);
            }

            return total;
        }
    private:
        map<int, set<int>> keyPad;
        int maxPress;
    };

};

namespace MobileNumericKeypad_recursive_array
{
    class Solution
    {
    public:
        int GetCountSub(char keyPad[][3], int i, int j, int n)
        {
            if (keyPad == NULL || n < 1)    return 0;

            if (n == 1) return 1;

            // left, top, current, bottom, right
            int row[] = { -1, 0, 0, 0, 1 };
            int col[] = { 0, -1, 0, 1, 0 };

            int total = 0;

            for (int move = 0; move < 5; move++)
            {
                int move_i = i + row[move];
                int move_j = j + col[move];

                if (move_j < 0 || move_j >= 3 || move_i < 0 || move_i >= 4) continue;

                if (keyPad[move_i][move_j] != '*' && keyPad[move_i][move_j] != '#')
                {
                    total += GetCountSub(keyPad, move_i, move_j, n - 1);
                }
            }

            return total;
        }

        int GetCount(char keyPad[][3], int n)
        {
            if (keyPad == NULL || n < 1)    return 0;

            if (n == 1) return 10;

            int total = 0;
            for (int row = 0; row < 4; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    if (keyPad[row][col] == '*' || keyPad[row][col] == '#') continue;

                    total += GetCountSub(keyPad, row, col, n);
                }
            }

            return total;
        }

        int Run(int n)
        {
            char keyPad[4][3] = {
                {'1','2','3'},
                {'4','5','6'},
                {'7','8','9'},
                {'*','0','#'} };

            int ret = GetCount(keyPad, n);

            return ret;

        }
    };
};

namespace MobileNumericKeypad_dp
{
    class Solution
    {
    public:
        long GetCountSub (char keyPad[][3], long n)
        {
            if (keyPad == NULL || n < 1)    return 0;

            if (n == 1) return 10;

            // left, top, current, bottom, right
            long row[] = { -1, 0, 0, 0, 1 };
            long col[] = { 0, -1, 0, 1, 0 };

            long total = 0;
            
            // taking n+1 for simplicity - count[i][j] will store
            // number count starting with digit i and length j
            long** count;
            count = new long* [10];
            for (long i = 0; i < 10; i++)
            {
                count[i] = new long[n + 1];
            }
            
            // count numbers starting with digit i and of lengths 0 and 1
            for (long i = 0; i <= 9; i++)
            {
                count[i][0] = 0;
                count[i][1] = 1;
            }


            // Bottom up - Get number count of length 2, 3, 4, ..., n

            char buf[2];
            buf[0] = buf[1] = 0x0;

            for (long k = 2; k <= n; k++)
            {
                for (long x = 0; x < 4; x++)
                {
                    for (long y = 0; y < 3; y++)
                    {
                        if (keyPad[x][y] != '*' && keyPad[x][y] != '#')
                        {
                            buf[0] = keyPad[x][y];
                            long n = atoi(buf);
                            count[n][k] = 0;

                            for (long m = 0; m < 5; m++)
                            {
                                long move_x = x + col[m];
                                long move_y = y + row[m];

                                if (move_x < 0 || move_y < 0)   continue;
                                if (move_x > 3 || move_y > 2)   continue;
                                if (keyPad[move_x][move_y] != '*' && keyPad[move_x][move_y] != '#')
                                {
                                    buf[0] = keyPad[move_x][move_y];
                                    long button = atoi(buf);

                                    count[n][k] += count[button][k - 1];

                                    //cout << "count[" << button << "][" << k - 1 << "] = " << count[button][k - 1];
                                }
                            }
                            //cout << "count[" << n << "][" << k << "] = " << count[n][k] << endl;
                        }

                    }
                }
            }

            for (long i = 0; i < 10; i++)
            {
                total += count[i][n];
            }

            return total;
        }
        long getCount (long n)
        {
            char keyPad[4][3] = {
                {'1','2','3'},
                {'4','5','6'},
                {'7','8','9'},
                {'*','0','#'} };

            long ret = GetCountSub(keyPad, n);

            return ret;

        }
    };
};


// Driven Program 
int MobileNumericKeypad_Test()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        //MobileNumericKeypad_recursive_map::Solution ob;
        //cout << ob.getCount(n) << endl;

        //MobileNumericKeypad_recursive_array::Solution ob;
        //cout << ob.Run(n) << endl;

        MobileNumericKeypad_dp::Solution ob;
        cout << ob.getCount(n) << endl;
    }
    return 0;
}