//
// https://www.geeksforgeeks.org/find-maximum-subset-xor-given-set/
// https://practice.geeksforgeeks.org/problems/maximum-subset-xor/1

/*
Expected Time Complexity : O(N*Log(max(arr[i])))
Expected Auxiliary Space : O(1)
 
Contraints :
1 <= N <= 105
1 <= arr[i] <= 106 
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace MaximumSubsetXOR
{
    class Solution
    {
    public:
        int maxSubsetXOR(int arr[], int N)
        {
            //Your code here

            int max = arr[0];
            vector<int> q;
            q.push_back(arr[0]);

            for (int i = 1; i < N; i++)
            {
                int sz = q.size();

                for (int j = 0; j < sz; j++)
                {
                    int v = arr[i] ^ q[j];
                    q.push_back(v);

                    if (v > max)    max = v;
                }

                q.push_back(arr[i]);
                if (arr[i] > max)   max = arr[i];
            }
            
            return max;

        }
    };
};

namespace MaximumSubsetXOR_Example
{
#define INT_BITS    32

    int maxSubarrayXOR(int arr[], int N)
    {
        // Initialize index of 
        // chosen elements 
        int index = 0;

        // Traverse through all 
        // bits of integer  
        // starting from the most 
        // significant bit (MSB) 
        
        for (int i = INT_BITS - 1; i >= 0; i--)
        {
            
            // Initialize index of 
            // maximum element and 
            // the maximum element 
            
            int maxInd = index;
            int maxEle = INT_MIN;

            for (int j = index; j < N; j++)
            {
                if ((arr[j] & (i << i)) != 0 && (arr[j] > maxEle))
                {
                    maxEle = arr[j];
                    maxInd = j;
                }

                // If there was no  
                // element with i'th 
                // bit set, move to 
                // smaller i 
                if (maxEle == INT_MIN)
                    continue;

                // Put maximum element 
                 // with i'th bit set  
                 // at index 'index' 
                swap(arr[index], arr[maxInd]);

                // Update maxInd and  
                // increment index 
                maxInd = index;

                // Do XOR of set[maxIndex] 
                // with all numbers having 
                // i'th bit as set. 
                for (int j = 0; j < N; j++)
                {
                    // XOR set[maxInd] those 
                    // numbers which have the 
                    // i'th bit set 
                    if (j != maxInd && (arr[j] & (1 << i)) != 0)
                    {
                        arr[j] = arr[j] ^ arr[maxInd];
                    }
                }

                // Increment index of 
                // chosen elements 
                index++;
            }
        }

        // Final result is  
        // XOR of all elements 
        
        int res = 0;
        for (int i = 0; i < N; i++)
        {
            res ^= arr[i];
        }
        
        return res;
    }
};

int MaximumSubsetXOR_Test ()
{
    /*
    int t, n, a[100004], k;
    scanf("%d", &t);
    while (t--)
    {
        //cin>>n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        MaximumSubsetXOR::Solution obj;
        printf("%d\n", obj.maxSubarrayXOR(a, n));
        // cout<<bin(a,0,n-1,k)<<endl;
    }
    */
    int a[] = { 1,2,3,4,5,6,22,33,44,22,111 };
    int n = 11;
    MaximumSubsetXOR::Solution obj;
    printf("%d\n", obj.maxSubsetXOR(a, n));

    return 0;
}  // } Driver Code Ends

