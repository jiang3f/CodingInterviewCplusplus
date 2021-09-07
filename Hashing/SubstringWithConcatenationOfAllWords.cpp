/*
* https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
*/

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

namespace SubstringWithConcatenationOfAllWords
{
    class Solution {
 
    public:
        bool IsConcatenation(string s, vector<string>& words, int n, int len)
        {
            map<string, int> hash;
            for (int j = 0; j < n; j++)
            {
                if (hash.find(words[j]) == hash.end())
                {
                    hash[words[j]] = 1;
                }
                else
                {
                    hash[words[j]] ++;
                }
            }

            for (int i = 0; i < s.length(); i += len)
            {
                string subStr = s.substr(i, len);

                //cout << subStr << endl;

                map<string, int>::iterator it = hash.find(subStr);

                if (it == hash.end())
                {
                    return false;
                }
                else if (it->second == 0)
                {
                    return false;
                }
                else
                {
                    it->second --;
                }
            }
            return true;
        }

        vector<int> findSubstring(string s, vector<string>& words) {

            int n = words.size();
            int wordLen = words[0].length();

            int subStringLen = n * wordLen;

            vector<int> ret;
            int len = s.length();


            for (int i = 0; i <= len - subStringLen; i++)
            {
                string subS = s.substr(i, subStringLen);


                if (IsConcatenation(subS, words, n, wordLen))
                {
                    ret.push_back(i);
                }
            }

            return ret;
        }
    };
};

int SubstringWithConcatenationOfAllWords_Test()
{

    string s = "wordgoodgoodgoodbestword";
    vector<string> words = { "word", "good", "best", "word"};

    SubstringWithConcatenationOfAllWords::Solution ob;

    vector<int> ret = ob.findSubstring(s, words);

    return 0;

}