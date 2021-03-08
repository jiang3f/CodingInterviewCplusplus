//
// https://practice.geeksforgeeks.org/problems/geek-collects-the-balls/0/?category[]=Greedy&difficulty[]=1&page=1&query=category[]Greedydifficulty[]1page1
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>

using namespace std;

namespace GeekCollectsTheBalls
{
    class Solution {
    private:
        int maxBallsSub(int curPos, int curLen, int p[], int otherPos, int otherLen, int other[])
        {
            if (curPos == curLen)   return 0;

            if (curPos == 3)
            {
                curPos = curPos;
            }

            int changePos = -1;

            while (otherPos < otherLen)
            {
                if (other[otherPos] > p[curPos])   break;
                else if (other[otherPos] == p[curPos])
                {
                    changePos = otherPos;
                    break;
                }
                otherPos++;
            }

            int ret1 = INT_MIN;
            int ret2 = INT_MIN;

            if (changePos != -1)
            {
                ret1 = maxBallsSub(changePos + 1, otherLen, other, curPos, curLen, p);
            }
            ret2 = maxBallsSub(curPos + 1, curLen, p, otherPos, otherLen, other);

            int ret = ret1;

            if (ret2 > ret)    ret = ret2;

           // cout << "p[" << curPos << "]=" << p[curPos] << ", max ret=" << ret << endl;
            
            return ret + p[curPos];
        }

    public:
        int maxBalls(int N, int M, int a[], int b[]) {
            // code here

            int ret = maxBallsSub(0, N, a, 0, M, b);

            int ret1 = maxBallsSub(0, M, b, 0, N, a);
            
            if (ret > ret1) return ret;
            else return ret1;
        }
    };
};

int GeekCollectsTheBalls_Test ()
{
    /*
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        int* a = new int[N];
        int* b = new int[M];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];

        GeekCollectsTheBalls::Solution ob;
        cout << ob.maxBalls(N, M, a, b) << "\n";
    }
 */

    int a[5] = { 1, 4, 5, 6, 8 };
    int b[5] = { 2, 3, 4, 6, 9 };

    GeekCollectsTheBalls::Solution ob;
    cout << ob.maxBalls(5, 5, a, b) << "\n";

	return 0;
}