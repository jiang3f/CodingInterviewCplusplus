/*
* 
1. given List A and List B, the data of the list is string, write a function to compare if the combination of list A and list B are the same.
e.g.
List A "he"->"ll"->"o".
List B "hell"->"o"

*/

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

namespace CompairListContentCombination
{
    int CompareList(list<string>& a, list<string>& b)
    {
        if (a.empty() == true && b.empty() == true) return 1;
        else if (a.empty()) return false;
        else if (b.empty()) return false;

        else
        {
            list<string>::iterator it1 = a.begin();
            list<string>::iterator it2 = b.begin();
            string s1 = *it1;
            string s2 = *it2;

            while (it1 != a.end() && it2 != b.end())
            {
                if (s1 == s2)
                {
                    it1++;
                    if (it1 != a.end())                    s1 = *it1;
                    it2++;
                    if (it2 != b.end())                    s2 = *it2;
                }
                else if (s1.length() > s2.length())
                {
                    if (s1.compare(0, s2.length(), s2) != 0)
                    {
                        return 0;
                    }
                    else
                    {
                        s1 = s1.substr(s2.length());
                        it2++;
                        if (it2 != b.end())                        s2 = *it2;
                    }

                }
                else
                {
                    if (s2.compare(0, s1.length(), s1) != 0)
                    {
                        return 0;
                    }
                    else
                    {
                        s2 = s2.substr(s1.length());
                        it1++;
                        if (it1 != a.end())                        s1 = *it1;
                    }
                }
            }

            if (it1 == a.end() && it2 == b.end())   return true;
            else return false;
        }
    }
};

int CompairListContentCombination_Test()
{
    list<string> A, B;

    A.push_back("he");
    A.push_back("ll");
    A.push_back("o");

    B.push_back("hell");
    B.push_back("o");

    cout << CompairListContentCombination::CompareList (A, B) << endl;

    return 0;
}