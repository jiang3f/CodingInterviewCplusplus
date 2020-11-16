//
// https://practice.geeksforgeeks.org/problems/water-connection-problem/0/?category[]=Greedy&difficulty[]=1&page=1&query=category[]Greedydifficulty[]1page11page1
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

namespace WaterConnectionProblem
{
	#define TOTAL_SIZE 500

	int indeg[TOTAL_SIZE];
	int outdeg[TOTAL_SIZE];
	pair<int, int> adj[TOTAL_SIZE];
	int ans;

	int dfs(int n)
	{
		if (outdeg[n] == 0)	return n;

		ans = min(ans, adj[n].second);
		return dfs(adj[n].first);
	}

	void Run(int h, int p)
	{

		vector<pair<pair<int, int>, int>> pr;

		for (int i = 1; i < h; i++)
		{
			if (indeg[i] == 0)
			{
				ans = INT_MAX;
				int x = dfs(i);
				if (x != i)
					pr.push_back(make_pair(make_pair(i, x), ans));
			}
		}
		cout << pr.size() << endl;
		for (auto it : pr)
			cout << it.first.first << " " << it.first.second << " " << it.second << endl;

	}
};

int WaterConnectionProblem_Test ()
{
	int test;
	cin >> test;
	while (test--)
	{
		int h, p, a, b, c;

		cin >> h >> p;

		for (int i = 0; i <= h; i++)
		{
			WaterConnectionProblem::indeg[i] = 0;
			WaterConnectionProblem::outdeg[i] = 0;
		}

		for (int i = 0; i < p; i++)
		{
			cin >> a >> b >> c;
			WaterConnectionProblem::indeg[a] ++;
			WaterConnectionProblem::outdeg[b] --;
			WaterConnectionProblem::adj[a] = make_pair(b, c);
		}

		WaterConnectionProblem::Run(h, p);

	}

	return 0;
}