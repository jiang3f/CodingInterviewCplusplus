//
// https://practice.geeksforgeeks.org/problems/min-coin5549/1/?category[]=Greedy&difficulty[]=1&page=1&query=category[]Greedydifficulty[]1page1
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

namespace MinCoin
{

	map<pair<vector<int>, int>, int> myMap;

	//
	// Time Limit Exceeded
	// 
	int Run (vector<int>nums, int amount)
	{
		map<pair<vector<int>, int>, int>::iterator it = myMap.find(make_pair(nums, amount));

		if (it != myMap.end())
		{
			return it->second;
		}

		int ret = -1;

		if (amount < 0)	ret = -1;

		else if (nums.size() == 0)	ret = -1;

		else if (nums.size() == 1)
		{
			if ((amount % nums[0]) != 0)
			{
				ret = -1;
			}
			else
			{
				ret = amount / nums[0];
			}
		}
		else
		{
			ret = INT_MAX;

			for (int i = amount / nums[0]; i >= 0; i--)
			{
				vector<int> newNums(nums.begin() + 1, nums.end());

				int ret1 = Run(newNums, amount - nums[0] * i);

				if (ret1 != -1)
				{
					if (ret > ret1 + i)
					{
						ret = ret1+ i;
					}
				}
			}

			ret = (ret == INT_MAX) ? -1 : ret;
		}

		myMap.insert(make_pair(make_pair(nums, amount), ret));

		return ret;
	}
};

namespace MinCoins_WithoutDP
{
	int Run (vector <int> nums, int amount )
	{
		int coins = 0;
		int cent = 0;
		int finalCount = amount;

		for (int i = nums.size() - 1; i >= 0; i--)
		{
			cent = amount;

			for (int j = i; j <= nums.size() - 1; j++)
			{
				coins += cent / nums[j];
				cent = cent % nums[j];
				if (cent == 0) break;
			}

			if (coins < finalCount)
			{
				finalCount = coins;
			}
			coins = 0;
		}

		return finalCount;
	}
};

namespace MinCoin_WithDP
{
	int Run(vector<int>nums, int amount)
	{
		int* minCoins = new int[amount + 1];

		for (int i = 1; i <= amount; i++)
		{
			minCoins[i] = 99999;

			for (int j = 0; j < nums.size(); j++)
			{

				if (i >= nums[j])
				{

					int n = minCoins[i - minCoins[j]] + 1;

					if (n < minCoins[i])
						minCoins[i] = n;
				}
			}
		}

		return minCoins[amount];
	}
};

int MinCoin_Test ()
{
	int tc;
	cin >> tc;
	while (tc--) 
	{
		int n, amount;
		cin >> n >> amount;
	
		vector<int>nums(n);

		for (int i = 0; i < n; i++)
			cin >> nums[i];
				
		sort(nums.begin(), nums.end(), std::greater<int>());

		int ans = MinCoin_WithDP::Run (nums, amount);
		cout << ans << "\n";
	}
	return 0;
}

