/*
* https://see.stanford.edu/materials/icspacs106b/H19-RecBacktrackExamples.pdf
* 
Classic exhaustive permutation patternFirst, a procedural recursion example, this one that forms all
possible re-arrangements of theletters in a string. It is an example of an exhaustive procedural
algorithm. The pseudocodestrategy is as follows:

If you have no more characters left to rearrange, print current permutationfor 
    (every possible choice among the characters left to rearrange) {    
        Make a choice and add that character to the permutation so far    
        Use recursion to rearrange the remaining letters
    }

In this exhaustive traversal, we try every possible combination. There are n! ways to rearrangethe
characters in a string of length n and this prints all of them.This is an important example and worth
spending the time to fully understand. The permutationpattern is at the heart of many recursive
algorithms— finding anagrams, solving sudoku puzzles,optimally matching classes to classrooms, or
scheduling for best efficiency can all be done usingan adaptation of the general permutation code.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;
namespace AllPossibleReArrangementsOfThelettersInAString
{
    void RecPermutate(string soFar, string rest)
    {
        if (rest.empty())
        {
            cout << soFar << endl;
        }
        else
        {
            for (int i = 0; i < rest.length(); i++)
            {
                string remaining = rest.substr(0, i) + rest.substr(i + 1);

                RecPermutate(soFar + rest[i], remaining);
            }
        }
    }

}

int AllPossibleReArrangementsOfThelettersInAString_Test()
{
    string s = "rest";

    AllPossibleReArrangementsOfThelettersInAString::RecPermutate("", s);

    return 0;
}