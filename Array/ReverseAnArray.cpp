//
// https://practice.geeksforgeeks.org/problems/reverse-an-array/1/?problemType=full&difficulty[]=0&difficulty[]=1&page=1&query=problemTypefulldifficulty[]0difficulty[]1page1
//
#include "stdafx.h"
#include <iostream>

using namespace std;

namespace ReverseAnArray
{
	void Run(int arr[], int n)
	{
		if (n == 0)	return;

		if (n == 1)
		{
			cout << arr[0] << endl;
			return;
		}

		int a = 0;
		int b = n - 1;

		while (a < b)
		{
			int tmp = arr[a];
			arr[a] = arr[b];
			arr[b] = tmp;

			a++;
			b--;
		}

		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int ReverseAnArray_Test ()
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
		
		ReverseAnArray::Run(arr, n);

	}

	return 0;
}
