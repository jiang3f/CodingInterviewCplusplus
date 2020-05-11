//
// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define MINIMUM -1000

namespace FindUnionAndIntersectionOfTwoTnsortedArrays
{
	int Run(int arr1[], int sz1, int arr2[], int sz2)
	{
		sort(arr1, arr1 + sz1);
		sort(arr2, arr2 + sz2);

		set<int> myUnion;
		set<int> myIntersection;

		int i = 0;
		int j = 0;

		while (i < sz1 && j < sz2)
		{
			if (arr1[i] < arr2[j])
			{
				myUnion.insert(arr1[i++]);
			}
			else if (arr1[i] > arr2[j])
			{
				myUnion.insert(arr2[j++]);
			}
			else
			{
				myUnion.insert(arr1[i]);
				myIntersection.insert(arr1[i]);
				i++;
				j++;
			}
		}

		while (i < sz1)
		{
			myUnion.insert(arr1[i++]);
		}

		while (j < sz2)
		{
			myUnion.insert(arr2[j++]);
		}

		cout << "Union: ";
		
		set<int>::iterator it;
		for (it = myUnion.begin(); it != myUnion.end(); it++)
			cout << " " << *it;

		cout << endl;

		cout << "Intersection: ";

		for (it = myIntersection.begin(); it != myIntersection.end(); it++)
			cout << " " << *it;

		cout << endl;
		return 0;
	}
};

namespace FindUnionAndIntersectionOfTwoTnsortedArrays_Sorting_and_Searching
{

	//
	// O((m+n)Logm, (m+n)Logn).
	//

	// A C++ program to print union and intersection 
	/// of two unsorted arrays 

	int binarySearch(int arr[], int l, int r, int x);

	// Prints union of arr1[0..m-1] and arr2[0..n-1] 
	void printUnion(int arr1[], int arr2[], int m, int n)
	{
		// Before finding union, make sure arr1[0..m-1] 
		// is smaller 
		if (m > n)
		{
			int *tempp = arr1;
			arr1 = arr2;
			arr2 = tempp;

			int temp = m;
			m = n;
			n = temp;
		}

		// Now arr1[] is smaller 

		// Sort the first array and print its elements (these two 
		// steps can be swapped as order in output is not important) 
		sort(arr1, arr1 + m);
		for (int i = 0; i<m; i++)
			cout << arr1[i] << " ";

		// Search every element of bigger array in smaller array 
		// and print the element if not found 
		for (int i = 0; i<n; i++)
			if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
				cout << arr2[i] << " ";
	}

	// Prints intersection of arr1[0..m-1] and arr2[0..n-1] 
	void printIntersection(int arr1[], int arr2[], int m, int n)
	{
		// Before finding intersection, make sure arr1[0..m-1] 
		// is smaller 
		if (m > n)
		{
			int *tempp = arr1;
			arr1 = arr2;
			arr2 = tempp;

			int temp = m;
			m = n;
			n = temp;
		}

		// Now arr1[] is smaller 

		// Sort smaller array arr1[0..m-1] 
		sort(arr1, arr1 + m);

		// Search every element of bigger array in smaller 
		// array and print the element if found 
		for (int i = 0; i<n; i++)
			if (binarySearch(arr1, 0, m - 1, arr2[i]) != -1)
				cout << arr2[i] << " ";
	}

	// A recursive binary search function. It returns 
	// location of x in given array arr[l..r] is present, 
	// otherwise -1 
	int binarySearch(int arr[], int l, int r, int x)
	{
		if (r >= l)
		{
			int mid = l + (r - l) / 2;

			// If the element is present at the middle itself 
			if (arr[mid] == x) return mid;

			// If element is smaller than mid, then it can only 
			// be presen in left subarray 
			if (arr[mid] > x)
				return binarySearch(arr, l, mid - 1, x);

			// Else the element can only be present in right subarray 
			return binarySearch(arr, mid + 1, r, x);
		}

		// We reach here when element is not present in array 
		return -1;
	}

	/* Driver program to test above function */
	int Run (int arr1[], int sz1, int arr2[], int sz2)
	{
		cout << "Union of two arrays is \n";
		printUnion(arr1, arr2, sz1, sz2);
		cout << "\nIntersection of two arrays is \n";
		printIntersection(arr1, arr2, sz1, sz2);
		return 0;
	}

}

namespace FindUnionAndIntersectionOfTwoTnsortedArrays_Hashing
{

	// Prints union of arr1[0..n1-1] and arr2[0..n2-1] 
	void printUnion(int arr1[], int arr2[], int n1, int n2)
	{
		set<int> hs;

		// Inhsert the elements of arr1[] to set hs 
		for (int i = 0; i < n1; i++)
			hs.insert(arr1[i]);

		// Insert the elements of arr2[] to set hs 
		for (int i = 0; i < n2; i++)
			hs.insert(arr2[i]);

		// Print the content of set hs 
		for (auto it = hs.begin(); it != hs.end(); it++)
			cout << *it << " ";
		cout << endl;
	}

	// Prints intersection of arr1[0..n1-1] and 
	// arr2[0..n2-1] 
	void printIntersection(int arr1[], int arr2[],
		int n1, int n2)
	{
		set<int> hs;

		// Insert the elements of arr1[] to set S 
		for (int i = 0; i < n1; i++)
			hs.insert(arr1[i]);

		for (int i = 0; i < n2; i++)

			// If element is present in set then 
			// push it to vector V 
			if (hs.find(arr2[i]) != hs.end())
				cout << arr2[i] << " ";
	}

	// Driver Program 
	int Run (int arr1[], int n1, int arr2[], int n2)
	{
		printUnion(arr1, arr2, n1, n2);
		printIntersection(arr1, arr2, n1, n2);

		return 0;
	}

};

int FindUnionAndIntersectionOfTwoTnsortedArrays_Test()
{
	int arr1[] = { 7, 1, 5, 2, 3, 6 };
	int	arr2[] = { 3, 8, 6, 20, 7 };

	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);

	FindUnionAndIntersectionOfTwoTnsortedArrays::Run(arr1, sz1, arr2, sz2);

	cout << "Sorting and Searching--" << endl;

	FindUnionAndIntersectionOfTwoTnsortedArrays_Sorting_and_Searching::Run(arr1, sz1, arr2, sz2);

	cout << "Use hashing--" << endl;

	FindUnionAndIntersectionOfTwoTnsortedArrays_Hashing::Run(arr1, sz1, arr2, sz2);

	return 0;
}

