//
// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1
//

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

namespace UglyNumbers
{
    void PrtArray(unsigned long long arr[], unsigned long long n)
    {
        for (unsigned long long i = 0; i < n; i++)
        {
            cout << "[" << i << "]\t" << arr[i] << endl;
        }
        cout << endl;

    }

    // https://www.geeksforgeeks.org/search-insert-and-delete-in-a-sorted-array/
    // Inserts a key in arr[] of given capacity. n is current 
    // size of arr[]. This function returns n+1 if insertion 
    // is successful, else n. 
    int insertSorted(unsigned long long arr[], int n, unsigned long long key, int capacity, int& i)
    {
        // Cannot insert more elements if n is already 
        // more than or equal to capcity 
        if (n >= capacity)
            return n;

        for (i = n - 1; (i >= 0 && arr[i] > key); i--)
            arr[i + 1] = arr[i];

        arr[i + 1] = key;

        return (n + 1);
    }


    int AddUgly(unsigned long long arr[], int capacity, int prime, int& len, map<unsigned long long, int>& dup, int targetPos )
    {
        int first = -1;

        unsigned long long last = arr[len - 1];
        int i = 0;
        while (arr[i] <= last)
        //for(int i = 0;i < len; i++)
        {
            unsigned long long key = (unsigned long long)arr[i] * (unsigned long long) prime;

            if (dup.find(key) == dup.end())
            {
                int pos = 0;

                len = insertSorted(arr, len, key, capacity, pos);

                dup.insert(make_pair(key, 1));

                if (first == -1)    first = pos+1;

                if ((pos + 1) > targetPos)  break;
            }
            i++;
        }

        return first;

    }

    unsigned long long Run(int n)
    {
        if (n == 0 || n == 1) return n;

        int primes[3] = { 2,3, 5 };

        map<unsigned long long, int> dup;
        int capacity = n * n + 10;

        unsigned long long* array = new unsigned long long[capacity];

        for (int i = 0; i < capacity; i++)    array[i] = 0;

        array[0] = 1;
        dup.insert(make_pair(1, 1));

        int len = 1;

        for (;;)
        {
            int ret = 0;
            for (int i = 0; i < 3; i++)
            {
                int first = AddUgly(array, capacity, primes[i], len, dup, n);
                if (first > n)  ret++;
            }

            if (ret == 3)   break;
        }

        return array[n-1];
    }
};

namespace UglyNumbers_Method1
{
    unsigned long long MaxDivide(unsigned long long n, int prime)
    {
        while (n % prime == 0)    n = n / prime;
        return n;
    }

    bool isUgly(unsigned long long n)
    {
        n = MaxDivide(n, 2);
        n = MaxDivide(n, 3);
        n = MaxDivide(n, 5);

        return (n == 1) ? true : false;
    }

    unsigned long long Run(int n)
    {
        if (n < 7)   return n;

        unsigned long long ans = 7;
        int i = 6;
        for (;;)
        {
            if (isUgly(ans))
            {
                i++;
                if (i == n) break;
            }
            ans++;
        }
        return ans;
    }
}

namespace UglyNumbers_Method2
{
    unsigned long long Run(int n)
    {
        unsigned long long* arr = new unsigned long long[n];

        arr[0] = 1;

        unsigned long long next_multiple_of_2 = 2;
        unsigned long long next_multiple_of_3 = 3;
        unsigned long long next_multiple_of_5 = 5;

        int i2, i3, i5;
        i2 = i3 = i5 = 0;

        unsigned long long nextUgly = 0;

        for (int i = 1; i < n; i++)
        {
            nextUgly = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));

            arr[i] = nextUgly;

            if (nextUgly == next_multiple_of_2)
            {
                i2++;
                next_multiple_of_2 = arr[i2] * 2;
            }
            if (nextUgly == next_multiple_of_3)
            {
                i3++;
                next_multiple_of_3 = arr[i3] * 3;
            }
            if (nextUgly == next_multiple_of_5)
            {
                i5++;
                next_multiple_of_5 = arr[i5] * 5;
            }

        }

        return arr[n - 1];
    }
       
};

//
// Expected Time Complexity: O(N)
// Expected Auxiliary Space : O(N)
//

int UglyNumbers_Test ()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unsigned long long ans = UglyNumbers_Method2::Run (n);
        cout << ans << "\n";
    }
    return 0;
}

/*
* 
---------------------
1
1000
51200000
---------------------
5
2000
8062156800
3000
278942752080
4000
4701849845760
5000
50837316566580
10000
288325195312500000
----------------------------
8
1
1
10
12
1000
51200000
2000
8062156800
3000
278942752080
4000
4701849845760
7000
2636718750000000
10000
288325195312500000

*/  