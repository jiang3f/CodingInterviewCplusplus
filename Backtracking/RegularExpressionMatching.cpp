/*
* https://leetcode.com/problems/regular-expression-matching/
*/

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

namespace RegularExpressionMatching
{
    class Solution {
    protected:
        bool isZeroElement(string p)
        {
            if (p.size() < 2)   return false;

            if (p.at(0) != '*' && p.at(1) == '*')   return true;

            else return false;
        }

        bool isMatch_sub(string s, string p, char ch)
        {
            if (s.size() == 0 && p.size() == 0) return true;

            if (s.size() == 0 && p.size() != 0)
            {
                // a = "a", s = ".*"
                //if (p.size() == 1 && ch != '\0' && p.at(0) == '*')    return true;
                int i = 0;

                for (i = 0; i < p.size(); i+=2)
                {
                    if (isZeroElement(p.substr(i)) == false) break;
                }

                if (i == p.size())  return true;
                else if (p.at(0) == '*')
                {
                    return isMatch_sub(s, p.substr(1), '\0'); 
                }
                else return false;
            }

            if (s.size() != 0 && p.size() == 0) return false;

            bool ret = false;

            if (p.at(0) == '.')
            {
                ret = isMatch_sub(s.substr(1), p.substr(1), '.');
            }
            else if (p.at(0) == '*')
            {
                if (ch == s.at(0) || ch == '.')
                {
                    // 2 + elment ch
                    ret = isMatch_sub(s.substr(1), p, ch);

                    if (ret == false)
                    {
                        // 2 element ch
                        ret = isMatch_sub(s.substr(1), p.substr(1), '\0');
                    }

                    if (ret == false)
                    {
                        // 1 element ch
                        ret = isMatch_sub(s, p.substr(1), '\0');
                    }
                }
                else
                {
                    // 1 element ch
                    ret = isMatch_sub(s, p.substr(1), '\0');
                }
            }
            else
            {
                if (s.at(0) == p.at(0))
                {
                    ret =  isMatch_sub(s.substr(1), p.substr(1), p.at(0));

                    /*if (ret == false)
                    {
                        // no more '*'
                        if (p.size() > 2 && p.at(1) == '*')
                        {
                            ret = isMatch_sub(s.substr(1), p.substr(2), '\0');
                        }
                    }*/
                }
            }

            if (ret == false)
            {
                // zero element ch
                if (isZeroElement(p) == true)
                {
                    ret = isMatch_sub(s, p.substr(2), ch);
                }
            }

            return ret;
        }

    public:
        bool isMatch(string s, string p) {

            //if (s.size() == 0 && p.size() == 0)  return true;

            //if (s.size() == 0 && p.size() != 0) return false;

            //if (s.size() == 0)  return false;

            return isMatch_sub(s, p, '\0');
        }
    };
};

int RegularExpressionMatching_Test()
{
    string s = "ab";
    string p = ".*c";

    RegularExpressionMatching::Solution ob;

    bool ret = ob.isMatch(s, p);
    if (ret)    cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}
