//
// https://practice.geeksforgeeks.org/problems/anagram/0/
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace Anagram
{

	bool Run_mine(string left, string right)
	{
		if (left.length() == 0 && right.length() == 0)	return true;
		
		if (left.length() == 0 || right.length() == 0)	return false;

		char * p1 = new char[left.length()];
		strcpy(p1, left.c_str());

		char *p2 = new char[right.length()];
		strcpy(p2, right.c_str());

		sort(p1, p1 + sizeof(p1));
		sort(p2, p2 + sizeof(p2));

		return (strcmp(p1, p2)==0) ? true : false;
	}

	bool Run(string s1, string s2)
	{
		if (s1.size() == s2.size())
		{
			int c[26] = { 0 };
			for (int i = 0; i < s1.size(); i++)
				c[s1[i] - 'a']++;
			for (int i = 0; i < s2.size(); i++)
				c[s2[i] - 'a']--;
			if (count(c, c + 26, 0) == 26)
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

//
// 2
// geeksforgeeks forgeeksgeeks
// allergy allergic
//

int Anagram_Test()
{
	long test;
	cin >> test;
	while (test--) {
		string s[2];

		for (int i = 0; i < 2; i++)
		{
			cin >> s[i];
		}

		if (true == Anagram::Run (s[0], s[1]))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}