#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
//#include <algorithm>

using namespace std;

class PermutationOfString
{

public:

	void PermutationOfStringSub(map<char, int> arr, string &s)
	{
		map<char, int>::iterator it;
		int sum = 0;

		for (it = arr.begin(); it != arr.end(); it++)
		{
			if ((*it).second != 0)
			{
				map<char, int>arr1 = arr;
				arr1[(*it).first] --;
				string s1 = s + (*it).first;
				PermutationOfStringSub(arr1, s1);
			}
			sum += (*it).second;
		}

		if (sum == 0)
		{
			cout << s << endl;
		}
	}

	void Run(const char * s, int len)
	{
		map<char, int>arr;
		for (int i = 0; i < len; i++)
		{
			map<char, int>::iterator it = arr.find(*s);
			if (it == arr.end())
			{
				arr.insert(pair<char, int>(*s, 1));
			}
			else
			{
				arr[*s] += 1;
			}

			s++;
		}

		//	sort(arr.begin(), arr.end());

		string output = "";
		PermutationOfStringSub(arr, output);

	}
};

// Driver Code 
int PermutationOfString_Test()
{
	long test;
	cin >> test;
	while (test--) {

		string s;
		cin >> s;
		PermutationOfString test;
		test.Run(s.c_str(), (int)s.length());
	}
	return 0;
}


