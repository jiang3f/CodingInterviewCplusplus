//
// https://practice.geeksforgeeks.org/problems/frequency-of-array-elements/0
//
#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

namespace FrequenciesOfLimitedRangeArrayElements
{
	void Run(int arr[], int n)
	{
		map<int, int> myMap;

		for (int i = 1; i <= n; i++)
		{
			myMap[i] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			myMap[arr[i]] = myMap[arr[i]] ++;
		}

		for (map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
		{
			cout << it->second << " ";
		}
		cout << endl;
	}
};

// https://ide.geeksforgeeks.org/sAVcvVB0D2
namespace FrequenciesOfLimitedRangeArrayElements_Others
{
	int Run (int arr[], int n)
	{
		int mod = n + 1;

		for (int i = 0; i < n; i++)
		{
			int id = arr[i] % mod - 1;
			arr[id] += mod;
		}

		for (int i = 0; i < n; i++)
		{
			int num = arr[i] / mod;
			cout << num << " ";
		}
		cout << endl;

		return 0;
	}
}
int FrequenciesOfLimitedRangeArrayElements_Test ()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;

		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		FrequenciesOfLimitedRangeArrayElements_Others::Run(arr, n);
	}

    return 0;
}
