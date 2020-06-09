//
// https://practice.geeksforgeeks.org/problems/page-faults-in-lru/0/
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <map>

using namespace std;

namespace PageFaultsinLRU
{
	class LRUCache
	{
		// store keys of cache 
		list<int> dq;

		// store references of key in cache 
		map<int, list<int>::iterator> ma;
		int csize; // maximum capacity of cache 

	public:
		LRUCache(int);
		bool refer(int);
		void display();

	};

	// Declare the size 
	LRUCache::LRUCache(int n)
	{
		csize = n;
	}

	// Refers key x with in the LRU cache 
	// return true if page fault
	bool LRUCache::refer(int x)
	{
		bool ret = false;

		// not present in cache 
		if (ma.find(x) == ma.end()) {
			// cache is full 
			if (dq.size() == csize) {
				// delete least recently used element 
				int last = dq.back();

				// Pops the last elmeent 
				dq.pop_back();

				// Erase the last 
				ma.erase(last);
			}

			ret = true;
		}

		// present in cache 
		else
			dq.erase(ma[x]);

		// update reference 
		dq.push_front(x);
		ma[x] = dq.begin();

		//display();
		return ret;
	}

	// Function to display contents of cache 
	void LRUCache::display()
	{

		// Iterate in the deque and print 
		// all the elements in it 
		for (auto it = dq.begin(); it != dq.end();
			it++)
			cout << (*it) << " ";

		cout << endl;
	}


	int Run(int arr[], int n, int capacity)
	{
		LRUCache cache(capacity);
		int ret = 0;

		for (int i = 0; i < n; i++)
		{
			if(cache.refer(arr[i]) == true)	ret ++;
		}

		return ret;
	}
};

int PageFaultsinLRU_Test()
{
	int test;
	cin >> test;

	while (test--)
	{
		int n;
		cin >> n;

		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		int capacity;
		cin >> capacity;

		int ret = PageFaultsinLRU::Run(arr, n, capacity);

		cout << ret << endl;
	}

	return 0;
}