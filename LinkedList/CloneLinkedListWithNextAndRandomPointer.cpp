//
// https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <algorithm>

using namespace std;


namespace CloneLinkedListWithNextAndArbitPointer
{
	
	struct Node
	{
		int data;
		Node * next;
		Node * arbit;
	};

	class Graph
	{

	private:

		map<int, struct Node *> mymap;

	public:
		Graph()
		{
		}

		void AddEdge (struct Node *&list, int v, int arbit)
		{
			struct Node *elem = nullptr;
			map<int, struct Node*>::iterator it = mymap.find(v);
			if (it != mymap.end())
			{
				elem = it->second;
			}
			else
			{
				elem = new Node();
				elem->data = v;
				elem->next = nullptr;
			}

			it = mymap.find(arbit);
			if (it != mymap.end())
			{
				elem->arbit = it->second;
			}
			else
			{
				struct Node *randomElem = new struct Node();
				randomElem->data = arbit;
				randomElem->next = nullptr;
				randomElem->arbit = nullptr;

				mymap[arbit] = randomElem;

				elem->arbit = randomElem;
			}

			if (list == nullptr)
			{
				list = elem;
			}
			else
			{
				struct Node *cur = list;
				while (cur->next != nullptr)
				{
					cur = cur->next;
				}
				cur->next = elem;
			}

		}
		struct Node * Clone(struct Node *list)
		{
			mymap.clear();
			struct Node *newList = nullptr;

			struct Node *cur = list;
			while (cur != nullptr)
			{
				AddEdge(newList, cur->data, cur->arbit->data);
				cur = cur->next;
			}

			return newList;
		}

	};

	int Run()
	{

		Graph graph;
		struct Node *list = nullptr;

		graph.AddEdge(list, 1, 3);
		graph.AddEdge(list, 2, 1);
		graph.AddEdge(list, 3, 5);
		graph.AddEdge(list, 4, 3);
		graph.AddEdge(list, 5, 3);

		struct Node *newList = graph.Clone(list);


		return 0;
	}
};

int CloneLinkedListWithNextAndArbitPointer_Test()
{
	CloneLinkedListWithNextAndArbitPointer::Run();

	return 0;
}
