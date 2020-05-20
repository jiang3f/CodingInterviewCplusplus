//
// https://practice.geeksforgeeks.org/problems/word-boggle/0
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>

using namespace std;

namespace WordBoggle
{
	bool Safe(int y, int x, char * word, char board[][7], int places[][7], int width, int height)
	{
		if (*word == 0x0)	return true;

		places[y][x] = 1;

		int top = (y > 0) ? (y - 1) : 0;
		int bottom = (y < height - 1) ? (y + 1) : height-1;
		int left = (x > 0) ? x - 1 : 0;
		int right = (x < width - 1) ? x + 1 : width - 1;

		for (int i = top; i <= bottom; i++)
		{
			for (int j = left; j <= right; j++)
			{
				if (i != y || j != x)
				{
					if (board[i][j] == word[0] && places[i][j] == 0)
					{
						if (Safe(i, j, &word[1], board, places, width, height) == true)
						{
							return true;
						}
					}
				}
			}
		}

		return false;
	}

	int Run( string dict[], int n, char board[][7], int width, int height)
	{
		set<string> mywords;

		int places[7][7];

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				for (int i = 0; i < n;i ++)
				{
					if (dict[i].at(0) == board[y][x] && mywords.find(dict[i]) == mywords.end())
					{

						for (int i = 0; i < 7; i++)
						{
							for (int j = 0; j < 7; j++)
							{
								places[i][j] = 0;
							}
						}
						string s = dict[i];
						char *p = (char *)s.c_str();

						if (Safe(y, x, &p[1], board, places, width, height) == true)
						{
							mywords.insert(dict[i]);

							break;
						}
					}
				}
			}
		}

		if (mywords.size() == 0)	cout << -1 << endl;
		else
		{			
			set<string>::iterator it;
			for(it = mywords.begin();it != mywords.end(); it ++)
			{
				cout << *it << " ";
			}
			cout << endl;
		}

		return 0;
	}
}

/*
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E
*/
int WordBoggle_Test()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;

		string dict[10];
		int i;
		for(i = 0;i < x;i ++)
		{
			cin >> dict[i];
		}

		int n;
		cin >> n;

		int m;
		cin  >> m;

		char board[7][7];

		for (i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> board[i][j];
			}
		}

		WordBoggle::Run(dict, x, board, m, n);

	}
	return 0;
}
