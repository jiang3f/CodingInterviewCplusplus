//
// https://practice.geeksforgeeks.org/problems/number-of-unique-paths/1/?problemType=full&difficulty[]=0&difficulty[]=1&page=1&query=problemTypefulldifficulty[]0difficulty[]1page1
//
#include "stdafx.h"
#include <iostream>

using namespace std;

namespace NumberOfUniquePaths
{

	unsigned long NumberOfPathSub(unsigned long x, unsigned long y, unsigned long width, unsigned long height)
	{
		unsigned long ret = 0;

		if (x == (width - 1) && y == (height - 1))
		{
			return 1;
		}

		if (x < width - 1)
		{
			// move right
			ret += NumberOfPathSub(x + 1, y, width, height);
		}
		if (y < height - 1)
		{
			// move down
			ret += NumberOfPathSub(x, y + 1, width, height);
		}

		return ret;

	}
	unsigned long Run(unsigned long width, unsigned long height)
	{
		unsigned long ret = NumberOfPathSub(0, 0, width, height);
	
		return ret;
	}
};

int NumberOfUniquePaths_Test ()
{
	int test;
	cin >> test;
	while (test--)
	{
		unsigned long width, height;
		cin >> width >> height;

		unsigned long ret = NumberOfUniquePaths::Run(width, height);

		cout << ret << endl;
	}

	return 0;
}
