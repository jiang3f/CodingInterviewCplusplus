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

	bool Run(string left, string right)
	{
		char * p1 = new char[left.length()];
		strcpy(p1, left.c_str());

		char *p2 = new char[right.length()];
		strcpy(p2, right.c_str());

		sort(p1, p1 + sizeof(p1));
		sort(p2, p2 + sizeof(p2));

		return (strcmp(p1, p2)==0) ? true : false;
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