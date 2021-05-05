/*
* https://www.geeksforgeeks.org/facebook-nyc-onsite-interview-experience/
*/

/*
* 
there’s some function that can “compress” strings like FACEBOOK -> F6K or 
FACEBOOK -> F2E2OK or INTERNATIONALIZATION -> I18N. The compression mechanism 
can delete arbitrarily many characters and replace them with the deleted 
character count. Write a function that takes a compressed string and a plaintext
string and determines if the compressed string is valid for the plaintext string.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace CompressStrings
{
    int CommonPrefix(string a, string b)
    {
        int i = 0;

        for (i = 0; i < a.length() && i < b.length(); i++)
        {
            if (a.at(i) != b.at(i))
            {
                break;
            }
        }

        return i;
    }

    string SkipChars (string s)
    {
        string ret = "";
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s.at(i) >= '0' && s.at(i) <= '9')
            {
                ret += s.at(i);
            }
        }
        return ret;
    }

    bool ValidCompressedString(string compress, string plaintext)
    {
        if (compress.length() == 0 && plaintext.length() == 0)  return true;

        else if (compress.length() == 0 || plaintext.length() == 0) return false;

        bool ret = false;

        if (compress.at(0) == plaintext.at(0))
        {
            int offset = CommonPrefix(compress, plaintext);
            if (offset < compress.length() && offset < plaintext.length())
            {
                ret = ValidCompressedString(compress.substr(offset), plaintext.substr(offset));
            }
        }

        if (ret == false)
        {
            if (compress.at(0) >= '0' && compress.at(0) <= '9')
            {
                string skipStr = SkipChars(compress);

                int offset = atoi(skipStr.c_str());
             
                if (offset < plaintext.length() && (skipStr.length() < compress.length()))
                {
                    ret = ValidCompressedString(compress.substr(skipStr.length()), plaintext.substr(offset));
                }
            }
        }
        return ret;
    }
};

int CompressStrings_Test()
{
    string a = "Facebook";
    string b = "F6k";

    bool ret = CompressStrings::ValidCompressedString(a, b);

    cout << "result: " << ret << endl;

    return 0;
}
