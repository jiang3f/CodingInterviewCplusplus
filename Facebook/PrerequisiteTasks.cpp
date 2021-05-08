/*
* https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/?company[]=Facebook&company[]=Facebook&page=1&query=company[]Facebookpage1company[]Facebook
* 
*/

/*
*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 
you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

namespace PrerequisiteTasks
{
 /*   
 
    Wrong solution!!!

    /// <summary>
    /// Runtime Error:
    Runtime ErrorTime Limit Exceeded

        Your program took more time than expected.Time Limit Exceeded
        Expected Time Limit 1.12sec
        Hint : Please optimize your code and submit again.


    /// </summary>*/
    class Solution_wrong 
    {
    public:
        bool isPossible(int N, vector<pair<int, int> >& prerequisites)
        {
            // Code here
		// Code here

			if (N == 0) return true;

			bool* visit = new bool[N];


			map<int, vector<int>> tasks;

			for (int i = 0; i < prerequisites.size(); i++)
			{
				tasks[prerequisites[i].second].push_back(prerequisites[i].first);
			}

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)   visit[j] = false;

				queue<int> vertex;

				vertex.push(i);

				while (vertex.empty() == false)
				{
					int task = vertex.front();
					vertex.pop();

					visit[task] = true;

					vector<int>::iterator it = tasks[task].begin();
					while (it != tasks[task].end())
					{
						vertex.push(*it);
						it++;
					}
				}

				bool ret = true;
				for (int j = 0; j < N; j++)   ret &= visit[j];

				if (ret == true)    return true;
			}
			return false;
		}
    };


    class Solution {
    public:
        bool isCircle(int p, bool visit[], int N, map<int, vector<int>>& v)
        {
            if (visit[p] == true)   return true;

            visit[p] = true;

            vector<int>::iterator it = v[p].begin();

            while (it != v[p].end())
            {
                bool* vi = new bool[N];
                for (int j = 0; j < N; j++)   vi[j] = visit[j];

                bool ret = isCircle(*it, vi, N, v);

                if (ret == true)    return true;

                it++;
            }
            return false;
        }

        bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
            // Code here
            if (N == 0) return true;

            map<int, vector<int>> v;

            vector<pair<int, int>>::iterator it = prerequisites.begin();
            while (it != prerequisites.end())
            {
                v[it->first].push_back(it->second);
                it++;
            }

            bool* visit = new bool[N];
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)   visit[j] = false;

                bool ret = isCircle(i, visit, N, v);

                if (ret == true)    return false;
            }

            return true;

        }
    };
};

int PrerequisiteTasks_Test()
{
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        PrerequisiteTasks::Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;

}
