//
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0/
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <tuple>    
#include <algorithm>

using namespace std;

namespace JobSequencingProblem
{
	struct Job
	{
		int index;
		int deadline;
		int profit;
	};

	bool SortByDeadline(const Job& a, const Job& b)
	{
		return (a.profit > b.profit);
	}

	int Run(int arr[], int n)
	{
		Job * job = new Job[n];
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			job[i].index = arr[j++];
			job[i].deadline = arr[j++];
			job[i].profit = arr[j++];
		}

		sort(job, job + n, SortByDeadline);

		int totalProfit = 0;
		
		bool flags[500];
		int unit = 0;
		for (int i = 0; i < 500; i++)	flags[i] = false;

		for (int i = 0; i < n; i++)
		{
			int days = job[i].deadline;

			for (j = days; j >= 1; j--)
			{
				if (flags[j] == false)
				{
					totalProfit += job[i].profit;
					flags[j] = true;
					unit++;
					break;
				}
			}
		}

		cout << unit << " " << totalProfit << endl;

		return 0;
	}
};

namespace JobSequencingProblem_Others
{

	bool comp(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
	{
		return (get<2>(a) > get<2>(b));
	}

	int Run (int input[], int n)
	{
		int x, y, z, i;

		vector<tuple<int, int, int>> v;

		long long int cnt = 0, pro = 0;
		
		bool arr[500];
		for (i = 0; i<500; i++)
			arr[i] = false;

		int j = 0;
		for (i = 0; i<n; i++)
		{
			x = input[j++];
			y = input[j++];
			z = input[j++];
			v.push_back(make_tuple(x, y, z));
		}

		sort(v.begin(), v.end(), comp);

		for (int i = 0; i < v.size(); i++)
		{
			int m = get<1>(v[i]);
			for (int j = m; j >= 1; j--)
			{
				if (arr[j] == false)
				{
					pro += get<2>(v[i]);
					cnt++;
					arr[j] = true;
					break;
				}
			}
		}
		cout << cnt << " " << pro << endl;

		return 0;
	}
}

int JobSequencingProblem_Test()
{
	int test;
	cin >> test;

	while (test--)
	{
		int n;
		cin >> n;

		int * arr = new int[3 * n];

		for (int i = 0; i < 3 * n; i++)
		{
			cin >> arr[i];
		}

		JobSequencingProblem::Run(arr, n);
	}
	return 0;
}

