/*
* https://see.stanford.edu/materials/icspacs106b/H19-RecBacktrackExamples.pdf
* 
Classic exhaustive subset patternAnother of the classic exhaustive recursion problems is listing all the
subsets of a given set.  Therecursive approach is basically the same as the n-choose-k problem we looked
at in lecture.  Ateach step, we isolate an element from the remainder and then recursively list those
sets thatinclude that element, and recur again to build those sets that don't contain that element.  In
eachcase, the set of remaining elements is one smaller and thus represents a slightly easier,
smallerversion of the same problem. Those recursive calls will eventually lead to the simplest case,
thatof listing the subsets of an empty set. Here is the pseudocode description:

–If there are no more elements remaining,print current subsetelse 
{        
Consider the next element of those remaining       
Try adding it to the current subset, and use recursion to build subsets from here       
Try not adding it to current subset, and use recursion to build subsets from here
}

*/

#include "stdafx.h"
#include <iostream>

using namespace std;
namespace AllSubsetsOfGivenSet
{
    void RecSubsets(string soFar, string rest)
    {
        if (rest.empty())
        {
            cout << soFar << endl;
        }
        else
        {
            RecSubsets(soFar + rest[0], rest.substr(1));
            RecSubsets(soFar, rest.substr(1));
        }
    }
};

int AllSubsetsOfGivenSet_Test ()
{
    string s = "rest";

    AllSubsetsOfGivenSet::RecSubsets("", s);

    return 0;
}
