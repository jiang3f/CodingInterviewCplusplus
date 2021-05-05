//
// https://www.geeksforgeeks.org/snake-ladder-problem-2/
/*
*
*/
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

namespace SnakeAndLadder
{
#define TotalCells 30
    struct QueueEntry
    {
        int vertex;
        int dist;
    };

    class Solution 
    {
    private:

        int minThrowSub(int move[])
        {
            queue<QueueEntry> q;
            bool isVisit[TotalCells + 1];
            for (int i = 0; i <= TotalCells; i++)
            {
                isVisit[i] = false;
            }

            QueueEntry s = { 1, 0 };

            q.push(s);
            isVisit[1] = true;

            QueueEntry s1;

            while (q.empty() != true)
            {
                s1 = q.front();

                int v = s1.vertex;

                // No need to complete the traversal since we have reached the destination cell
                if (v == TotalCells)    break;


                q.pop();

                for (int i = v + 1; i <= (v + 6) && (v <= TotalCells); i++)
                {
                    if (isVisit[i] == false)
                    {
                        QueueEntry newEntry;
                        newEntry.dist = s1.dist + 1;
                        isVisit[i] = true;

                        if (move[i] != -1)
                        {
                            newEntry.vertex = move[i];
                        }
                        else
                        {
                            newEntry.vertex = i;
                        }

                        q.push(newEntry);
                    }

                }
            }

            return s1.dist;
        }

    public:
        int minThrow(int N, int arr[]) 
        {
            // code here
            int ret = 0;
            
            int move [TotalCells+1];

            for (int i = 0; i <= TotalCells; i++)
            {
                move[i] = -1;
            }

            for (int i = 0; i < N; i++)
            {
                move[arr[i * 2]] = arr[i * 2 + 1];
            }

            ret = minThrowSub (move);

            return ret;
        }
    };
};

int SnakeAndLadder_Test()
{
    /*
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int * arr = new int [2 * N];
        for (int i = 0; i < 2 * N; i++)
            cin >> arr[i];

        SnakeAndLadder::Solution ob;
        cout << ob.minThrow(N, arr) << "\n";
    }
    */

    int N = 8;
    int arr[] = { 3, 22, 5, 8, 11, 26, 20, 29, 17, 4, 19, 7, 27, 1, 21, 9 };

    SnakeAndLadder::Solution ob;
    cout << ob.minThrow(N, arr) << "\n";

    return 0;

}

