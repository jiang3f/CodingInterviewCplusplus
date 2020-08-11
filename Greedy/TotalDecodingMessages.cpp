//
// https://practice.geeksforgeeks.org/problems/total-decoding-messages/0/
//
#include "stdafx.h"
#include <iostream>

using namespace std;

namespace TotalDecodingMessages
{

	int NumWays(char* s, int n)
	{
		if (*s == '0')
		{
			return 0;
		}

		if (n == 1)	return 1;
		
		else if (n == 2)
		{
			int v = atoi(s);
			if (v > 26)
			{
				return NumWays(s+1, n-1);
			}
			
			else if (v == 10 || v == 20) return 1;
			
			else return 2;
		}
		else
		{
			char c = s[2];
			s[2] = 0;
			int v = atoi(s);
			s[2] = c;
			if (v > 26)
			{
				return NumWays(s + 1, n - 1);
			}
			else
			{
				int n1 = NumWays(s + 1, n - 1);

				//if (n1 == 0)
				//{
				//	return 0;
				//}

				int n2 = NumWays(s + 2, n - 2);
				
				//if (n2 == 0)
				//{
				//	return 0;
				//}

				return n1 + n2;
			}
		}
	}

	int Run(char * s, int n)
	{
		if (n == 0)	return 1;

		return NumWays(s, n);

	}

};

int TotalDecodingMessages_Test()
{
	//  1<=N<=40
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		char s[41];
		cin >> s;
		int ret = TotalDecodingMessages::Run(s, n);
		cout << ret << endl;
	}
	return 0;
}

