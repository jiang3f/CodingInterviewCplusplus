/*
* https://practice.geeksforgeeks.org/problems/maximum-occured-integer4602/1
* https://www.geeksforgeeks.org/maximum-occurred-integer-n-ranges/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace MaximumOccuredInteger
{
    class Solution
    {
	public:
		// L and R are input array
		 // maxx : maximum in R[]
		 // n: size of array
		 // arr[] : declared globally with size equal to maximum in L[] and R[]
		 //Function to find the maximum occurred integer in all ranges.
		int maxOccured(int L[], int R[], int n, int maxx) 
		{
			vector<int> arr(maxx+1);

			for (int i = 0; i < maxx+1; i++)	arr[i] = 0;

			for (int i = 0; i < n; i++)
			{
				int lowbound = L[i]-1;
				int upperbound = R[i]-1;

				arr[lowbound] += 1;
				arr[upperbound+1] -= 1;
			}

			int sum = INT_MIN;
			int range = 0;
			for (int i = 1; i < maxx+1; i++)
			{
				arr[i] = arr[i - 1] + arr[i];
				if (arr[i] > sum)
				{
					sum = arr[i];
					range = i;
				}
			}

			return range+1;
		}
    };
}

int MaximumOccuredInteger_Test()
{
/*	int t;

	//taking testcases
	cin >> t;

	while (t--) {
		int n;

		//taking size of array
		cin >> n;
		vector<int> L(n);
		vector<int> R(n);

		//adding elements to array L
		for (int i = 0; i < n; i++) {
			cin >> L[i];
		}

		int maxx = 0;

		//adding elements to array R
		for (int i = 0; i < n; i++) {

			cin >> R[i];
			if (R[i] > maxx) {
				maxx = R[i];
			}
		}
		MaximumOccuredInteger::Solution ob;

		//calling maxOccured() function
		cout << ob.maxOccured(L.data(), R.data(), n, maxx) << endl;
	}
*/

	int n = 5;
	vector<int> L = { 1, 5, 9, 13, 21 };
	vector<int> R = { 15, 8, 12, 20, 30 };
	int maxx = 30;

	MaximumOccuredInteger::Solution ob;
	cout << ob.maxOccured(L.data(), R.data(), n, maxx) << endl;

	return 0;
}
