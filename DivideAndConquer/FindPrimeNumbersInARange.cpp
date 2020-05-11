
//
// Find Prime numbers in a range 
// https://practice.geeksforgeeks.org/problems/find-prime-numbers-in-a-range/0/
//

#include "stdafx.h"
#include <iostream>
using namespace std;


namespace FindPrimeNumbersInARange
{
	struct Node
	{
		unsigned long v;
		Node *next;
		Node(unsigned long _v)
		{
			v = _v;
			next = nullptr;
		}
	};

	Node *Merge(unsigned long n, Node *s)
	{
		bool flag = false;
		Node *ret = s;

		while (s != NULL)
		{
			if (n % (s->v) == 0)	flag = true;
			s = s->next;
		}

		if (flag == false)
		{
			Node *out = new Node(n);
			out->next = ret;
			ret = out;
		}
		return ret;
	}

	Node * FindPirmeNumber(unsigned long highest)
	{
		if (highest == 2)
		{
			Node *out = new Node(2);
			return out;
		}
		Node * primes = FindPirmeNumber(highest - 1);

		Node *ret = Merge(highest, primes);

		return ret;
	}

	void PrintNode(Node *ret, unsigned long lowest)
	{
		Node * out = NULL;
		while (ret != NULL)
		{
			if (ret->v >= lowest)
			{
				Node *ret1 = new Node(ret->v);
				ret1->next = out;
				out = ret1;
			}
			ret = ret->next;
		}
		while (out->next != NULL)
		{
			cout << out->v << " ";
			out = out->next;
		}
		cout << out->v << " " << endl;

	}

	int Run(unsigned long lowest, unsigned long highest)
	{
		Node *ret = FindPrimeNumbersInARange::FindPirmeNumber(highest);

		FindPrimeNumbersInARange::PrintNode(ret, lowest);

		return 0;
	}
};


namespace FindPrimeNumbersInARange_Solution1
{

	//
	//https ://www.geeksforgeeks.org/sieve-of-eratosthenes/
	//

	void FindPirmeNumber(unsigned long highest)
	{
		bool * mark = new bool[highest + 1];
		for (unsigned long i = 0; i < highest + 1; i++)	mark[i] = true;

		for (unsigned long i = 2; i * i <= highest; i++)
		{
			if (mark[i] == true)
			{
				for (unsigned long j = i * i; j <= highest; j += i)
				{
					mark[j] = false;
				}
			}
		}

		for (unsigned long i = 2; i <= highest; i++)
		{
			if (mark[i] == true)	cout << i << " ";
		}
	}


};
int FindPrimeNumbersInARange_Test()
{
	long test;
	cin >> test;
	while (test--) {

		unsigned long num[2];
		for (int i = 0; i < 2; i++)			cin >> num[i];
		
		FindPrimeNumbersInARange::Run(num[0], num[1]);

		cout << "solution 1" << endl;

		FindPrimeNumbersInARange_Solution1::FindPirmeNumber(num[1]);

	}
	return 0;

}