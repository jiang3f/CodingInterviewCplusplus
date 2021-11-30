/*
* https://leetcode.com/problems/detect-squares/
* 
* You are given a stream of points on the X-Y plane. Design an algorithm that:

    Adds new points from the stream into a data structure. Duplicate points are allowed and should be treated as different points.
    Given a query point, counts the number of ways to choose three points from the data structure such that the three points and the query point form an axis-aligned square with positive area.

An axis-aligned square is a square whose edges are all the same length and are either parallel or perpendicular to the x-axis and y-axis.

Implement the DetectSquares class:

    DetectSquares() Initializes the object with an empty data structure.
    void add(int[] point) Adds a new point point = [x, y] to the data structure.
    int count(int[] point) Counts the number of ways to form axis-aligned squares with point point = [x, y] as described above.

 

Example 1:

Input
["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
Output
[null, null, null, null, 1, 0, null, 2]

Explanation
DetectSquares detectSquares = new DetectSquares();
detectSquares.add([3, 10]);
detectSquares.add([11, 2]);
detectSquares.add([3, 2]);
detectSquares.count([11, 10]); // return 1. You can choose:
                               //   - The first, second, and third points
detectSquares.count([14, 8]);  // return 0. The query point cannot form a square with any points in the data structure.
detectSquares.add([11, 2]);    // Adding duplicate points is allowed.
detectSquares.count([11, 10]); // return 2. You can choose:
                               //   - The first, second, and third points
                               //   - The first, third, and fourth points

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

namespace DetectSquares
{
    class Solution_map
    {
        map<pair<int, int>, int> m;
    public:
        Solution_map() {

        }

        void add(vector<int> point) 
        {
            m[{point[0], point[1]}]++;

        }

        int count(vector<int> point) 
        {
            int ret = 0;

            for (map<pair<int, int>, int>::iterator it = m.begin(); it != m.end(); it++)
            {
                pair<int, int>p = it->first;

                if (p.first != point[0] && p.second != point[1])
                {
                    if (abs(p.first - point[0]) == abs(p.second - point[1]))
                    {
                        int a = m[{p.first, p.second}];
                        int b = m[{p.first, point[1]}];
                        int c = m[{point[0], p.second}];

                        int cur = a * b * c;
                        ret += cur;

                    }
                }
            }
            return ret;
        }
    };
};

int DetectSquares_Test()
{
    DetectSquares::Solution_map ob;

    ob.add(vector<int>{3, 10});

    ob.add(vector<int>{11, 2});

    ob.add(vector<int>{3,2});
   
    cout << ob.count(vector<int>{11, 10}) << endl; // return 1. You can choose:
                                   //   - The first, second, and third points
    cout << ob.count(vector<int>{14, 8}) << endl;  // return 0. The query point cannot form a square with any points in the data structure.

    ob.add(vector<int>{11, 2});    // Adding duplicate points is allowed.

    cout << ob.count(vector<int>{11, 10}) << endl; // return 2. You can choose:
                                   //   - The first, second, and third points
                                   //   - The first, third, and fourth points

    return 0;
}
