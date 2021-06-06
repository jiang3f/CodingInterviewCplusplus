/*
* https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

/*
* Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
namespace KthLargestElementInAnArray
{
    class Solution {
    public:
        vector<int> Merge(vector<int> v1, vector<int> v2)
        {
            vector<int> ret;

            vector<int>::iterator it1 = v1.begin();
            vector<int>::iterator it2 = v2.begin();

            while (it1 != v1.end() && it2 != v2.end())
            {
                if (*it1 < *it2)
                {
                    ret.push_back(*it1);
                    it1++;
                }
                else
                {
                    ret.push_back(*it2);
                    it2++;
                }
            }

            while (it1 != v1.end())
            {
                ret.push_back(*it1);
                it1++;
            }

            while (it2 != v2.end())
            {
                ret.push_back(*it2);
                it2++;
            }

            /*cout << "after:" << endl;
            for(int v: ret)
            {
                cout << v << " ";
            }
            cout << endl;
            */
            return ret;
        }

        void Sort(vector<int>& arr)
        {
            /*cout << "before:" << endl;
            for(int v: arr)
            {
                cout << v << " ";
            }
            cout << endl;
            */

            if (arr.size() <= 1)  return;

            int mid = arr.size() / 2;

            //cout << "mid " << mid << endl;

            vector<int> left(arr.begin(), arr.begin() + mid);
            vector<int> right(arr.begin() + mid, arr.end());

            /*cout << "left:" << endl;
            for(int v: left)
            {
                cout << v << " ";
            }
            cout << endl;

            cout << "right:" << endl;
            for(int v: right)
            {
                cout << v << " ";
            }
            cout << endl;
            */
            Sort(left);
            Sort(right);

            arr = Merge(left, right);

        }

        int findKthLargest(vector<int>& nums, int k) {
            if (nums.size() == 0)   return 0;
            Sort(nums);
            return nums[nums.size() - k];
        }
    };
};

int KthLargestElementInAnArray_Test()
{
    KthLargestElementInAnArray::Solution ob;

    vector<int> nums{ 3,2,1,5,6,4 };
    int k = 2;
    ob.findKthLargest(nums, k);

    return 0;
}
