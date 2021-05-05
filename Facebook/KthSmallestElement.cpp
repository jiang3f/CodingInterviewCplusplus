/*
* https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
* https://www.geeksforgeeks.org/facebook-nyc-onsite-interview-experience/
*/

/*
* 
Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element 
in the given array. It is given that all array elements are distinct.
*/

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

// My solution is wrong

namespace KthSmallestElement
{
    struct compare
    {
        bool operator() (int l, int r)
        {
            return l >  r;
        }
    };

    int kthSmallest(int arr[], int l, int r, int k)
    {

        priority_queue<int, vector<int>, compare> q;
        
        int ret;

        for (int i = l; i <= r; i++)
        {
            q.push(arr[i]);
        }

        for (int i = 0; i < k; i++)
        {
            ret = q.top();
            cout << ret << " ";
            q.pop();
        }

        cout << endl;
        return ret;
    }

};

int KthSmallestElement_Test()
{
    /*
    int test_case;
    scanf("%d", &test_case);
    while (test_case--)
    {
        int number_of_elements;
        scanf("%d", &number_of_elements);
        int *a = new int [number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            scanf("%d", &a[i]);

        int k;
        scanf("%d", &k);
        printf("%d", KthSmallestElement::kthSmallest(a, 0, number_of_elements - 1, k));
        printf("\n");
    }
    */
    int a[] = { 7, 10, 4, 20, 15 };
    int number_of_elements = 5;
    int k = 4;

    printf("%d", KthSmallestElement::kthSmallest(a, 0, number_of_elements - 1, k));
    printf("\n");
    return 0;

}
