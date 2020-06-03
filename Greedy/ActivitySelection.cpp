//
// https://practice.geeksforgeeks.org/problems/activity-selection/0
//


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
namespace ActivitySelection
{
	bool sortByVal(const pair<int, int> &a, const pair<int, int> &b)
	{
		return (a.second < b.second);
	}

	int Run(vector<pair<int, int>> myVector)
	{
		sort(myVector.begin(), myVector.end(), sortByVal);

		vector<pair<int, int>>::iterator it = myVector.begin();

		int activityEnd = 0 ;

		int max = 0;

		for (it = myVector.begin(); it != myVector.end() ; it ++)
		{
			if (it->first >= activityEnd)
			{
				activityEnd = it->second;
				max++;
			}
		}
		return max;
	}
};

int ActivitySelection_Test()
{
	int test;
	cin >> test;

	while (test--)
	{
		int n;
		cin >> n;

		int *begin = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> begin[i];
		}

		int *end = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> end[i];
		}

		vector<pair<int, int>> myVector;

		for (int i = 0; i < n; i++)
		{
			myVector.push_back(make_pair(begin[i], end[i]));
		}


		int ret = ActivitySelection::Run(myVector);

		cout << ret << endl;
	}

	return 0;
}
