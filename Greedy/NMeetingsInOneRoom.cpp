//
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace NMeetingsInOneRoom
{
	struct Meeting
	{
		int start;
		int end;
		int index;
	};

	bool sortByVal(const Meeting &a, const Meeting&b)
	{
		return (a.end < b.end);
	}

	int Run(int begin[], int end[], int n)
	{
		Meeting *arr = new Meeting[n];

		for (int i = 0; i < n; i++)
		{
			arr[i].start = begin[i];
			arr[i].end = end[i];
			arr[i].index = i;
		}
		
		sort(arr, arr + n, sortByVal);

		int activityEnd = 0;

		for (int i = 0;i < n;i ++)
		{
			if (arr[i].start >= activityEnd)
			{
				activityEnd = arr[i].end;

				cout << arr[i].index + 1 << " ";
			}
		}
		cout << endl;

		return 0;
	}
};

namespace NMeetingsInOneRoom_others
{
	// https://ideone.com/RVWlcJ

	struct Activity {
		int start, finish, index;
	};

	bool activityCompare(Activity s1, Activity s2)
	{
		return s1.finish < s2.finish;
	}

	int Run(int begin[], int end[], int n)
	{
		Activity *arr = new Activity[n];

		for (int i = 0; i < n; i++)
		{
			arr[i].start = begin[i];
			arr[i].finish = end[i];
			arr[i].index = i;
		}

		sort(arr, arr + n, activityCompare);

		int i = 0;
		cout << arr[i].index + 1 << " ";
		for (int j = 1; j < n; j++)
		{
			if (arr[j].start >= arr[i].finish)
			{
				cout << arr[j].index + 1 << " ";
				i = j;
			}
		}
		cout << endl;

		return 0;

	}

};

int NMeetingsInOneRoom_Test()
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

		NMeetingsInOneRoom::Run(begin, end, n);
	}
	return 0;
}