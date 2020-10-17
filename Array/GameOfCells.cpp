//
// https://practice.geeksforgeeks.org/problems/game-of-cells/0/?problemType=full&difficulty[]=0&difficulty[]=1&page=1&query=problemTypefulldifficulty[]0difficulty[]1page1
//
#include "stdafx.h"
#include <iostream>

using namespace std;

namespace GameOfCells
{
	void Run(unsigned long n)
	{
		/*int*** arr = new int** [n];

		for (int i = 0; i < n; i++)
		{
			arr[i] = new int* [n];

			for (int j = 0; j < n; j++)
				arr[i][j] = new int[n];
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					arr[i][j][k] = 0;

		*/
		if ((n % 2) == 0)
		{
			cout << "Mike" << endl;
		}

		else
		{
			cout << "Harvey" << endl;
		}

	}
};

int GameOfCells_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		unsigned long n;
		cin >> n;

		GameOfCells::Run(n);

	}

	return 0;
}
