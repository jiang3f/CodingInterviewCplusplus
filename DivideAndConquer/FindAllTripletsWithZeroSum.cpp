//
// https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

namespace FindAllTripletsWithZeroSum
{
	struct Triple
	{
		int a;
		int b;
		int c;

		Triple(int _a, int _b, int _c)
		{
			a = _a;
			b = _b;
			c = _c;
		}
	};

	struct Node
	{
		int data;
		Node *next;

		Node(int v)
		{
			data = v;
			next = NULL;
		}
	};

	list <Triple> Merge(int t1, list<pair<int, int>> t2t3)
	{
		list<Triple> ret;

		list<pair<int, int>>::iterator it;

		for (it = t2t3.begin(); it != t2t3.end(); it++)
		{
			if ((t1 + it->first + it->second) == 0)
			{
				struct Triple * newT = new Triple(t1, it->first, it->second);

				ret.push_back(*newT);
			}
		}

		return ret;

	}
	list<Triple> FindZeroSum(struct Node *root, list<pair<int, int>> &t2t3)
	{
		list<Triple> ret;

		if (root->next->next == nullptr)
		{
			t2t3.push_back(make_pair( root->data, root->next->data));

			return ret;
		}

		int t1 = root->data;

		list<Triple> result = FindZeroSum (root->next, t2t3);

		while (root != nullptr)
		{
			t2t3.push_back(make_pair(t1, root->data));
			root = root->next;
		}

		list<Triple> result1 = Merge(t1, t2t3);

		list<Triple>::iterator it;

		for (it = result1.begin(); it != result1.end(); it++)
		{
			result.push_back(*it);
		}

		return result;
	};

	void PrintTriple(list<Triple> myTriple)
	{
		list<Triple>::iterator it;

		for (it = myTriple.begin(); it != myTriple.end(); it++)
		{
			cout << it->a << " " << it->b << " " << it->c << endl;
		}
	}

	int Run(int arr[], int len)
	{
		struct Node *root = NULL;


		for (int i = 0; i < len; i++)
		{
			struct Node *newNode = new Node(arr[i]);

			newNode->next = root;

			root = newNode;
		}

		list<pair<int, int>> t2t3;

		list<struct Triple> result = FindZeroSum(root, t2t3);

		PrintTriple(result);

		return 0;
	}
};

namespace FindAllTripletsWithZeroSum_solution1
{

	bool findTriplets(int arr[], int n);

	bool findSub(int *p, int n, int v)
	{
		for (int i = 0; i < n; i++)
		{
			if ((p[i] + v) == 0)	return true;
		}
		return false;

	}

	bool findTriplets(int arr[], int num)
	{
		int *p = new int[num];
		int np = 0;

		int *n = new int[num];
		int nn = 0;
		int nZero = 0;
		for (int i = 0; i < num; i++)
		{
			if (arr[i] < 0)	n[nn++] = arr[i];
			else
			{
				p[np++] = arr[i];
				if (arr[i] == 0) nZero++;
			}
		}
		if (nZero > 2)   return true;

		bool flag = false;

		for (int i = 0; i < np; i++)
		{
			for (int j = i + 1; j < np; j++)
			{
				if (findSub(n, nn, p[i] + p[j]) == true)
				{
					flag = true;
				}
			}
		}

		for (int i = 0; i < nn; i++)
		{
			for (int j = i + 1; j < nn; j++)
			{
				if (findSub(p, np, n[i] + n[j]) == true)
				{
					flag = true;
				}
			}
		}
		delete p;
		delete n;
		return flag ? true : false;
	}

	// Driver program to test above functions
	int Run () {
		int T;
		cin >> T;

		while (T--) {
			int n, i;
			cin >> n;
			int *price = new int[n];
			for (i = 0; i < n; i++) cin >> price[i];
			// function call
			bool ret = findTriplets(price, n);
			if (ret)	printf("true\n");
			else
			{
				printf("false\n");
			}
			delete price;
		}
		return 0;
	}

}


namespace FindAllTripletsWithZeroSum_Simple
{
	// Time Complexity : O(n3).
	//	Auxiliary Space : O(1).
	
	// Prints all triplets in arr[] with 0 sum 
	void findTriplets(int arr[], int n)
	{
		bool found = true;
		for (int i = 0; i<n - 2; i++)
		{
			for (int j = i + 1; j<n - 1; j++)
			{
				for (int k = j + 1; k<n; k++)
				{
					if (arr[i] + arr[j] + arr[k] == 0)
					{
						cout << arr[i] << " "
							<< arr[j] << " "
							<< arr[k] << endl;
						found = true;
					}
				}
			}
		}

		// If no triplet with 0 sum found in array 
		if (found == false)
			cout << " not exist " << endl;

	}
}

namespace FindAllTripletsWithZeroSum_Hashing
{
	// Complexity Analysis:

	// Time Complexity : O(n2).
	// Auxiliary Space : O(n).


	// function to print triplets with 0 sum 
	void findTriplets(int arr[], int n)
	{
		bool found = false;

		for (int i = 0; i<n - 1; i++)
		{
			// Find all pairs with sum equals to 
			// "-arr[i]" 
			set<int> s;
			for (int j = i + 1; j<n; j++)
			{
				int x = -(arr[i] + arr[j]);
				if (s.find(x) != s.end())
				{
					printf("%d %d %d\n", x, arr[i], arr[j]);
					found = true;
				}
				else
					s.insert(arr[j]);
			}
		}

		if (found == false)
			cout << " No Triplet Found" << endl;
	}

};

namespace FindAllTripletsWithZeroSum_Sorting
{
	// 
	// Time Complexity : O(n2).
	//	only two nested loops is required, so the time complexity is O(n2).
	//	Auxiliary Space : O(1), no extra space is required, so the time complexity is constant.

	// function to print triplets with 0 sum 
	void findTriplets(int arr[], int n)
	{
		bool found = false;

		// sort array elements 
		sort(arr, arr + n);

		for (int i = 0; i<n - 1; i++)
		{
			// initialize left and right 
			int l = i + 1;
			int r = n - 1;
			int x = arr[i];
			while (l < r)
			{
				if (x + arr[l] + arr[r] == 0)
				{
					// print elements if it's sum is zero 
					printf("%d %d %d\n", x, arr[l], arr[r]);
					l++;
					r--;
					found = true;
				}

				// If sum of three elements is less 
				// than zero then increment in left 
				else if (x + arr[l] + arr[r] < 0)
					l++;

				// if sum is greater than zero than 
				// decrement in right side 
				else
					r--;
			}
		}

		if (found == false)
			cout << " No Triplet Found" << endl;
	}
};

//
// 1
// 5
// 0 -1 2 -3 1
int FindAllTripletsWithZeroSum_Test()
{
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int *arr = new int[n];

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		FindAllTripletsWithZeroSum::Run(arr, n);

		cout << "solution 1" << endl;

		bool ret = FindAllTripletsWithZeroSum_solution1::findTriplets(arr, n);
		if (ret)	printf("true\n");
		else
		{
			printf("false\n");
		}

		cout << "simple solution O(N3)" << endl;

		FindAllTripletsWithZeroSum_Simple::findTriplets(arr, n);

		cout << "Hashing solution" << endl;

		FindAllTripletsWithZeroSum_Hashing::findTriplets(arr, n);

		cout << "sorting solution" << endl;

		FindAllTripletsWithZeroSum_Sorting::findTriplets(arr, n);

		delete arr;


	}
	
	//Run();

	return 0;

}