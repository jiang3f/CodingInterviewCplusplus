/*
* https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

/*
*
Given a string s, find the length of the longest substring without repeating characters.
*/
#include "stdafx.h"
#include <iostream>

using namespace std;
namespace LongestSubstringWithoutRepeatingCharacters
{
    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if (s.length() == 0)    return 0;


            int max = 0;
            int start = 0;
            int i = 0;
            for (i = 0; i < s.length(); i++)
            {
                size_t found = s.substr(start, i - start).find(s.at(i));

                if (found != std::string::npos)
                {
                    if (max < (i - start))
                    {
                        max = i - start;
                    }
                    start = start + found + 1;

                    //cout << "character '" << s.at(i) << "' repeated at " << start + found << ". len reset to " << i - start + 1 << endl;

                }
            }

            if (max < (i - start))
            {
                max = i - start;
            }

            return max;
        }
    };
};

int LongestSubstringWithoutRepeatingCharacters_Test()
{
    //string s = "pwwkew";
    string s = "dvdf";

    LongestSubstringWithoutRepeatingCharacters::Solution ob;
    cout << ob.lengthOfLongestSubstring(s) << endl;
    return 0;
}
