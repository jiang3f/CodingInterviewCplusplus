//
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes/0/
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>


#define MAX_NUM 99999
typedef long long ll;

using namespace std;

namespace MinimumCostOfRopes
{
	//
	//    this solution is wrong.
	//	  for 2,4,6,7,9 the correct anwser should be 62. This solution will return 65
	//    
	//

	ll MinimumCost_debug(ll cost, ll connectRope, ll arr[], bool visit[], ll n, list<ll>& costs)
	{
		ll count = 0;

		for (ll i = 0; i < n; i++)
		{
			if (visit[i] == false)
			{
				visit[i] = true;
				ll newCost = (connectRope == 0) ? cost : cost + connectRope + arr[i];
				MinimumCost_debug (newCost, connectRope + arr[i], arr, visit, n, costs);
				count++;
				visit[i] = false;
			}
		}

		if (count == 0)
		{
			costs.push_back(cost);
			return 0;
		}

	}

	ll MinimumCost(ll cost, ll connectRope, ll arr[], bool visit[], ll n, ll& minCost)
	{
		ll count = 0;

		for (ll i = 0; i < n; i++)
		{
			if (visit[i] == false)
			{
				visit[i] = true;
				ll newCost = (connectRope == 0) ? cost : cost + connectRope + arr[i];
				MinimumCost(newCost, connectRope + arr[i], arr, visit, n, minCost);
				count++;
				visit[i] = false;
			}
		}

		if (count == 0)
		{
			if (minCost > cost)
			{
				minCost = cost;
				return 0;
			}
		}

	}

	ll Run(ll arr[], ll n)
	{
		if (n == 1)
		{
			return arr[0];
		}
		
		if (n == 2)
		{
			return arr[0] + arr[1];
		}
		
		list<ll> costs;
		bool *visit = new bool[n];
		for (ll i = 0; i < n; i++)	visit[i] = false;
		ll minCost = MAX_NUM;

#if 1
		MinimumCost_debug(0, 0, arr, visit, n, costs);

		for (list<ll>::iterator it = costs.begin(); it != costs.end(); it++)
		{
			cout << *it << " ";
		}

		cout << endl;
#else
		MinimumCost(0, 0, arr, visit, n, minCost);
#endif;
		return minCost;

	}
};

// https ://ide.geeksforgeeks.org/8f1P7wAxi9
namespace MinimumCostOfRopes_PQ
{
	ll Run (ll arr[], ll n)
	{
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (ll i = 0; i < n; i++)
			pq.push(arr[i]);

		ll ans = 0;
		while (pq.size() >= 2) {
			ll r1 = pq.top();
			pq.pop();
			ll r2 = pq.top();
			pq.pop();

			ans += r1 + r2;
			pq.push(r1 + r2);
		}

		return ans;
	}
};

int MinimumCostOfRopes_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		ll n;
		cin >> n;

		ll * arr = new ll[n];

		for (ll i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		ll ret = MinimumCostOfRopes_PQ::Run(arr, n);

		cout << ret << endl;

	}
	return 0;
}

