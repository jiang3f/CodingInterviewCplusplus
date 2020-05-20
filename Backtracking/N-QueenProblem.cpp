//
// https://practice.geeksforgeeks.org/problems/n-queen-problem/0
//

#include "stdafx.h"
#include <iostream>
#include <memory.h>

using namespace std;

namespace NQueenProblem
{
	void PrintPlaces(int ** places, int n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << places[i][j] << " ";
			}
			cout << endl;
		}
	}

	int ** UpdatePlace(int x, int y, int ** places, int n)
	{
		int ** ret = new int*[n];

		for (int i = 0; i < n; i++)
		{
			ret[i] = new int[n];

			for (int j = 0; j < n; j++)
			{
				ret[i][j] = places[i][j];
			}
		}

		// horizantal 
		for (int i = x; i < n; i++)
		{
			ret[y][i] = 1;
		}

		// 
		int x1 = x + 1;
		int y1 = y - 1;
		while (y1 >= 0 && x1 < n)
		{
			ret[y1--][x1++] = 1;
		}

		x1 = x + 1;
		y1 = y + 1;
		while (y1 < n && x1 < n)
		{
			ret[y1++][x1++] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			ret[i][x] = 1;
		}

		//PrintPlaces(ret, n);

		return ret;
	}
	int FindQueenPlaceInColumn(int x, int n, int **places, int *myQueue)
	{
		if (x == n)
		{
			cout << "[";
			for (int i = 0; i < n; i++)
			{
				cout << myQueue[i] << " ";
			}
			cout << "] ";

			return 1;
		}

		int nPlace = 0;

		for (int i = 0; i < n; i++)
		{
			nPlace += places[i][x];
		}

		if (nPlace == n)
		{
			return 0;
		}

		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			if (places[i][x] == 0)
			{
				myQueue[x] = i+1;

				int ** newPlace = UpdatePlace(x, i, places, n);

				sum += FindQueenPlaceInColumn(x + 1, n, newPlace, myQueue);
			}
		}

		return sum;
	}
	

	int Run(int n)
	{
		int **places = new int *[n];
		for (int i = 0; i < n; i++)
		{
			places[i] = new int [n];
			memset(places[i], 0x0, n * sizeof(int));
		}

		int * myQueue = new int[n];

		int ret = FindQueenPlaceInColumn(0, n, places, myQueue);

		if (ret == 0)	cout << -1;

		cout << endl;

		return 0;
	}
};

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

namespace NQueenProblem_solution1
{
	bool isSafe(int row, int col, bool board[][10], int n) {
		for (int i = 0; i<col; i++) {
			if (board[row][i] == true)
				return false;
		}
		for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j] == true)
				return false;
		}
		for (int i = row, j = col; j >= 0 && i<n; i++, j--) {
			if (board[i][j] == true)
				return false;
		}
		return true;
	}
	void helper(int col, int n, vector<int>v, bool board[][10]) {
		if (col == n)
			return;
		for (int i = 0; i<n; i++) {
			if (isSafe(i, col, board, n) == true) {
				v.push_back(i + 1);
				board[i][col] = true;
				helper(col + 1, n, v, board);
				if (v.size() == n) {
					printf("[");
					for (auto x : v)
						printf("%d ", x);
					printf("] ");
				}
				board[i][col] = false;
				v.pop_back();
			}
		}
	}
	void nQueens (int n)
	{
		vector<int> v;
		bool board[10][10];
		for (int i = 0; i<10; i++)
			for (int j = 0; j<10; j++)
				board[i][j] = false;
		helper(0, n, v, board);
		printf("\n");
	}

	int Run ( int n)
	{
		if (n == 1)
			printf("[1 ]\n");
		else if (n == 2 || n == 3)
			printf("-1\n");
		else
			nQueens(n);

		return 0;
	}

};

int NQueenProblem_Test()
{
	long test;

	cin >> test;
	
	while (test--) {

		int n;

		cin >> n;

		//NQueenProblem::Run(n);

		NQueenProblem_solution1::Run(n);
	}
	return 0;
}