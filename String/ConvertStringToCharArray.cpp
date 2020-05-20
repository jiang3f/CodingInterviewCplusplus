//
// https://www.geeksforgeeks.org/convert-string-char-array-cpp/
//
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


namespace ConvertStringToCharArray
{
	char * Run(string s)
	{
		char *p = new char[s.length()];
		for (int i = 0; i < sizeof(p); i++)
		{
			p[i] = s[i];
		}
		
		return p;
	}

	void PrintArray(char *p, int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;

	}
};

int ConvertStringToCharArray_Test()
{
	long test;
	cin >> test;
	while (test--) {
		
		string s;
		
		cin >> s;
		
		char *p = ConvertStringToCharArray::Run(s);

		ConvertStringToCharArray::PrintArray(p, s.length());



	}

	return 0;
}
