//
// https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1
// https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/
//

/*
Expected Time Complexity: O(N * N * N * N)
Expected Auxiliary Space: O(N * N * N * N)

Constraints:
1<=N<=16
here, N = length of S.
S only contains digits(i.e. 0-9)

*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

namespace GenerateIPAddresses
{
    string GetIpSub(char* p, int len)
    {
        string ret;
        char tmp = p[len];
        p[len] = 0x0;

        if (atoi(p) < 255)  ret = string(p);
        
        p[len] = tmp;
        return ret;
    }

    vector<string> genIp(string& s) 
    {
        // Your code here
        vector<string> ret;

        if (s.empty())  return ret;

        char* p = (char *)s.c_str();

        for (int i = 0; i < 3; i++)
        {
            if (s.length() < i + 1)    continue;

            string s1 = GetIpSub(p, i + 1);
            if (s1.length() == 0)   continue;
            s1 = s1 + ".";

            for (int j = 0; j < 3; j++)
            {
                if (s.length() < i + j + 2)    continue;

                string s2 = GetIpSub(p + i + 1, j + 1);
                if (s2.length() == 0)   continue;
                s2 = s1 + s2 + ".";

                for (int m = 0; m < 3; m++)
                {
                    if (s.length() < i + j + m + 3)    continue;

                    string s3 = GetIpSub(p + i + j + 2, m + 1);
                    if (s3.length() == 0)   continue;
                    s3 = s2 + s3 + ".";

                    string s4 = GetIpSub(p + i + j + m + 3, s.length() - (i + j + m + 3));
                    if (s4.length() == 0)   continue;
                    s4 = s3 + s4 ;

                    ret.push_back(s4);
                }
            }
        }
                
        return ret;
    }

};

// This code is contributed by Harshit

namespace GenerateIPAddresses_Example
{
	// Function checks whether IP digits
	// are valid or not.
	int is_valid(string ip)
	{
		// Splitting by "."
		vector<string> ips;
		string ex = "";
		for (int i = 0; i < ip.size(); i++) {
			if (ip[i] == '.') {
				ips.push_back(ex);
				ex = "";
			}
			else {
				ex = ex + ip[i];
			}
		}
		ips.push_back(ex);

		// Checking for the corner cases
		// cout << ip << endl;
		for (int i = 0; i < ips.size(); i++) {
			// cout << ips[i] <<endl;
			if (ips[i].length() > 3
				|| stoi(ips[i]) < 0
				|| stoi(ips[i]) > 255)
				return 0;

			if (ips[i].length() > 1
				&& stoi(ips[i]) == 0)
				return 0;

			if (ips[i].length() > 1
				&& stoi(ips[i]) != 0
				&& ips[i][0] == '0')
				return 0;
		}
		return 1;
	}

	// Function converts string to IP address
	vector<string> genIp(string& ip)
	{
		int l = ip.length();

		// Check for string size
		if (l > 12 || l < 4) {
			cout << "Not Valid IP Address";
		}

		string check = ip;
		vector<string> ans;

		// Generating different combinations.
		for (int i = 1; i < l - 2; i++) {
			for (int j = i + 1; j < l - 1; j++) {
				for (int k = j + 1; k < l; k++) {
					check = check.substr(0, k) + "."
						+ check.substr(k, l - k + 2);
					check
						= check.substr(0, j) + "."
						+ check.substr(j, l - j + 3);
					check
						= check.substr(0, i) + "."
						+ check.substr(i, l - i + 4);

					// cout<< check <<endl;
					// Check for the validity of combination
					if (is_valid(check)) {
						ans.push_back(check);
						//std::cout << check << '\n';
					}
					check = ip;
				}
			}
		}

		return ans;
	}


};

int GenerateIPAddresses_Test ()
{
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        vector<string> str = GenerateIPAddresses_Example::genIp(s);
        sort(str.begin(), str.end());
        for (auto& u : str) {
            cout << u << "\n";
        }
    }

    return 0;
}// } Driver Code Ends
