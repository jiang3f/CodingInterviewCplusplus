//
// https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0
// 

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;

namespace RomanNumbertoInteger
{
	int Run( string s)
	{
		map<string, int> myMap;
		myMap.insert(make_pair("I", 1));
		myMap.insert(make_pair("V", 5));
		myMap.insert(make_pair("X", 10));
		myMap.insert(make_pair("L", 50));
		myMap.insert(make_pair("C", 100));
		myMap.insert(make_pair("D", 500));
		myMap.insert(make_pair("M", 1000));
		myMap.insert(make_pair("IV", 4));
		myMap.insert(make_pair("IX", 9));
		myMap.insert(make_pair("XL", 40));
		myMap.insert(make_pair("XC", 90));
		myMap.insert(make_pair("CD", 400));
		myMap.insert(make_pair("CM", 900));


		char *p = (char *)s.c_str();
		
		int sum = 0;

		int i = 0;

		while (i < s.length())
		{
			string str1 = string(1, p[i]);
			
			if (i < s.length() - 1)
			{
				str1.push_back(p[i + 1]);
			}
			map<string, int>::iterator it = myMap.find(str1);
			if (it != myMap.end())
			{
				sum += it->second;
				i++;
			}
			else
			{
				str1.pop_back();
				it = myMap.find(str1);
				if (it != myMap.end())
				{
					sum += it->second;
				}
			}			
			i++;
		}

		return sum;
	}
};

namespace RomanNumbertoInteger_solution1
{
	int Run (string s)
	{
		map<char, int>m;
		int ans = 0;
		m['I'] = 1;
		m['V'] = 5;
		m['X'] = 10;
		m['L'] = 50;
		m['C'] = 100;
		m['D'] = 500;
		m['M'] = 1000;
		for (int i = 0; i<s.length(); i++) {
			if (m[s[i]] < m[s[i + 1]] && i<s.length() - 1) {
				ans -= m[s[i]];
			}
			else {
				ans += m[s[i]];
			}
		}

		return ans;
	}
}

//
// Symbol 	I 	V 	X 	L 	C 		D 		M
// Value 	1 	5 	10 	50 	100 	500 	1000

int RomanNumbertoInteger_Test()
{
	long test;
	cin >> test;
	while (test--) {

		string s;

		cin >> s;

		int ret = RomanNumbertoInteger::Run(s);
		cout << ret << endl;

		cout << "Solution from someone" << endl;

		ret = RomanNumbertoInteger_solution1::Run(s);
		cout << ret << endl;
	}

	return 0;
}
