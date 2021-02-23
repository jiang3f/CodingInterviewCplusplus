//
// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
/*
*
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 107
1 <= K <= N
0 <=  arr[i] <=  107
*/
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace MaximumOfAllSubarraysOfSizeK
{
	int GetMax(int arr[], int start, int len)
	{
		int max = INT_MIN;

		//cout << "[";

		for (int i = 0; i < len; i++)
		{
			if (max < arr[start + i])
			{
				max = arr[start + i];
			}
			//cout << arr[start + i] << ",";
		}

		//cout << "]:" << max << endl;
		return max;
	}

	vector <int> max_of_subarrays(int* arr, int n, int k) 
	{
		// your code here
		vector <int> ret;

		for (int i = 0; i < n - k + 1; i++)
		{
			int max = GetMax(arr, i, k);
			ret.push_back(max);
		}
		return ret;
	}

};

namespace MaximumOfAllSubarraysOfSizeK_2
{
	int GetMaxinQueue(queue<int>& q, int& pos)
	{
		int len = q.size();
		int max = INT_MIN;

		for (int i = 0; i < len; i++)
		{
			int v = q.front();
			q.pop();
			if (v > max)
			{
				max = v;
				pos = i;
			}
			q.push(v);
		}
		return max;
	}

	vector <int> max_of_subarrays(int* arr, int n, int k)
	{
		// your code here
		vector <int> ret;
		queue<int> q;
		for (int i = 0; i < k; i++)
		{
			q.push(arr[i]);
		}

		int maxPos = 0;
		int preMax = GetMaxinQueue(q, maxPos);
		ret.push_back(preMax);

		for (int i = k; i < n; i++)
		{
			q.pop();
			q.push(arr[i]);
			if (arr[i] >= preMax)
			{
				maxPos = k - 1;
				preMax = arr[i];
				ret.push_back(arr[i]);
				
			}
			else if (maxPos != 0)
			{
				maxPos--;
				ret.push_back(preMax);
			}
			else
			{
				preMax = GetMaxinQueue(q, maxPos);
				ret.push_back(preMax);
			}
			
		}
		return ret;
	}
};

int MaximumOfAllSubarraysOfSizeK_Test () 
{

	int t;
	cin >> t;

	while (t--) {

		int n, k;
		cin >> n >> k;

		int *arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		vector <int> res = MaximumOfAllSubarraysOfSizeK_2::max_of_subarrays(arr, n, k);
		for (int i = 0; i < res.size(); i++)
			cout << res[i] << " ";
		cout << endl;

	}

	return 0;
}  // } Driver Code Ends