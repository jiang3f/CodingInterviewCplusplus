//
// 
//
#include "stdafx.h"
#include <iostream>
#include <queue>
#include <map>
#include <list>

using namespace std;

namespace NumberOfRectangles
{
    struct dot
    {
        int x;
        int y;

        dot(int a, int b)
        {
            x = a;
            y = b;
        }
    };


    class Solution
    {

    private:
        int total;

        int IsRectangle(vector<int> dots, int arr[])
        {
            dot* a[4];
            for (int i = 0; i < 4; i++)
            {
                a[i] = new dot(arr[dots[i] * 2], arr[dots[i] * 2 + 1]);
            }

            if (a[0]->x == a[1]->x)
            {
                if (a[2]->x == a[3]->x)
                {
                    if ((a[0]->y == a[2]->y) && (a[1]->y == a[3]->y))   return true;
                    if ((a[0]->y == a[3]->y) && (a[1]->y == a[2]->y))   return true;
                }
            }
            else if (a[0]->x == a[2]->x)
            {
                if (a[1]->x == a[3]->x)
                {
                    if ((a[0]->y == a[1]->y) && (a[2]->y == a[3]->y))   return true;
                    if ((a[0]->y == a[3]->y) && (a[2]->y == a[1]->y))   return true;
                }
            }
            else if (a[0]->x == a[3]->x)
            {
                if (a[1]->x == a[2]->x)
                {
                    if ((a[0]->y == a[1]->y) && (a[3]->y == a[2]->y))   return true;
                    if ((a[0]->y == a[2]->y) && (a[3]->y == a[1]->y))   return true;
                }
            }
            return false;

        }
        
        int IsRectangle(vector<int> dots)
        {
            if (dots.size() != 8)   return false;

            if (dots[0] == dots[2])
            {
                if (dots[4] = dots[6])
                {
                    if ((dots[1] == dots[5]) && (dots[3] == dots[7]))
                        return true;

                    if ((dots[1] == dots[7]) && (dots[3] == dots[5]))
                        return true;
                }
            }
            else if (dots[0] == dots[4])
            {
                if (dots[2] = dots[6])
                {
                    if ((dots[1] == dots[3]) && (dots[5] == dots[7]))
                        return true;

                    if ((dots[1] == dots[7]) && (dots[5] == dots[3]))
                        return true;
                }

            }
            else if (dots[0] == dots[6])
            {
                if (dots[2] = dots[4])
                {
                    if ((dots[1] == dots[3]) && (dots[7] == dots[5]))
                        return true;

                    if ((dots[1] == dots[5]) && (dots[7] == dots[3]))
                        return true;

                }
            }

            return false;
        }

        void PrintRectangle(vector<int> dots, int arr[])
        {
            for (int i = 0; i < 4; i++)
            {
                cout << "[" << arr[dots[i]*2] << "," << arr[dots[i]*2+1] << "] ";
            }

            cout << endl;
        }

        void PrintRectangle(vector<int> dots)
        {
            for (int i = 0; i < 4; i++)
            {
                cout << "[" << dots[i * 2] << "," << dots[i * 2 + 1] << "] ";
            }

            cout << endl;
        }

        int NumberOfRectangleFromDot(int id, int n, int arr[])
        {
            int ret = 0;
            bool *isVisit = new bool [n];
            //for (int i = 0; i < n; i++)  isVisit[i] = false;
            
            queue<vector<int>> q;
            vector<int> dots;
            dots.push_back(id);
            q.push(dots);

            while (!q.empty())
            {
                vector<int> dots = q.front();
                q.pop();

                for (int i = 0;i < n;i ++)
                {
                    isVisit[i] = false;
                }

                int max = INT_MIN;

                for (int i = 0; i < dots.size(); i++)
                {
                    isVisit[dots[i]] = true;
                    if (dots[i] > max)   max = dots[i];
                }

                if (dots.size() == 4)
                {
                    if (IsRectangle(dots, arr) == true)
                    {
                        ret++;
                        PrintRectangle(dots, arr);
                    }

                }
                else
                {

                    for (int i = max; i < n; i++)
                    {
                        if (isVisit[i] == false)
                        {
                            vector<int> newDots(dots);

                            newDots.push_back(i);

                            q.push(newDots);
                        }
                    }
                }
            }
            return ret;
        }

    public:
        int Run(int n, int arr[])
        {
            this->total = 0;

            int ret = 0;
            for (int i = 0; i < n; i++)
            {

                ret += NumberOfRectangleFromDot(i, n, arr);

            }
            return ret;
        }
    };

};

int NumberOfRectangles_Test ()
{
    int arr[] =
    {
        1, 1,
        1, 3,
        4, 1,
        4, 3,
        4, 8,
        7, 1,
        7, 3,
        7, 8
    };

    NumberOfRectangles::Solution ob;
    cout << ob.Run(8, arr) << "\n";

    /*
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int* arr = new int[2 * N];
        for (int i = 0; i < 2 * N; i++)
            cin >> arr[i];

        NumberOfRectangles::Solution ob;
        cout << ob.Run(N, arr) << "\n";
    }
    */
    return 0;
}
