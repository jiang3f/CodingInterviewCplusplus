//
// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0/
//

#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;

namespace SubarrayWithGivenSum_Mine
{
	/*
	Your program took more time than expected.Time Limit Exceeded
	Expected Time Limit < 1.792sec
	Hint : Please optimize your code and submit again.
	*/
	int Run(int arr[], int n, int sum)
	{
		int begin, end;
		map<int, int> myMapEven;
		map<int, int> myMapOdd;
		bool exit = false;

		begin = end = -1;
		for (int i = 0; i < n && exit == false; i++)
		{
			if (arr[i] > sum)
			{
				myMapEven.clear();
				myMapOdd.clear();
			}
			else if (arr[i] == sum)
			{
				begin = i;
				end = i;
				exit = true;
				break;
			}
			else
			{
				if (i % 2 == 0)
				{
					map<int, int>::iterator it;
					for (it = myMapEven.begin(); it != myMapEven.end(); it++)
					{
						if (it->second + arr[i] == sum)
						{
							begin = it->first;
							end = i;
							exit = true;
							break;
						}
						else if (it->second + arr[i] < sum)
						{
							myMapOdd[it->first] = it->second + arr[i];
						}
					}
					myMapEven.clear();
					myMapOdd.insert(make_pair(i, arr[i]));

				}
				else
				{
					map<int, int>::iterator it;
					for (it = myMapOdd.begin(); it != myMapOdd.end(); it++)
					{
						if (it->second + arr[i] == sum)
						{
							begin = it->first;
							end = i;
							exit = true;
							break;
						}
						else if (it->second + arr[i] < sum)
						{
							myMapEven[it->first] = it->second + arr[i];
						}
					}
					myMapOdd.clear();
					myMapEven.insert(make_pair(i, arr[i]));

				}
			}

		}

		if (begin == -1)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << begin+1 << " " << end+1 << endl;
		}

		return 0;
	}
}

namespace SubarrayWithGivenSum
{
	int Run(int arr[], int n, int sum)
	{
		int sas = 0;
		int c = 0;

		for (int i = 0; i < n; i++)
		{
			if (sas + arr[i] <= sum)
			{
				sas += arr[i];
			}
			else
			{
				sas += arr[i];
				while (sas > sum)
				{
					sas -= arr[c++];
				}
			}
			if (sas == sum)
			{
				cout << c+1 << " " << i+1 << endl;
				return 0;
			}
		}
		cout << -1 << endl;
		return 0;
	}
};


int SubarrayWithGivenSum_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		int sum;
		cin >> sum;

		int * arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		SubarrayWithGivenSum::Run(arr, n, sum);
	}

	return 0;
}


