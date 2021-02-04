//
//https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// 

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <list>
#include <strstream>

using namespace std;
namespace MatrixChainMultiplication_permutation
{
    /*
    * The matrix chain multiplication problem isn't permutation problem
    * 
    * The solution is wrong
    */
    int MultipleMatrix( stack<int>& myStack )
    {
        if (myStack.size() < 3)
        {
            while (myStack.size() != 0)
            {
                myStack.pop();
            }
            return 0;
        }

        int dimensions[3];
       
        for (int i = 0; i < 3; i++)
        {
            dimensions[i] = myStack.top();
            myStack.pop();
        }

        myStack.push(dimensions[0]);
        myStack.push(dimensions[2]);

        return dimensions[0] * dimensions[1] * dimensions[2];
    }

    void GetTotalOps(stack<int> myStack)
    {
        while (myStack.size() != 0)
        {
            int v = myStack.top();
            myStack.pop();
            cout << v << " ";
        }

        int sum = 0;
        while (myStack.size() > 0)
        {
            sum += MultipleMatrix(myStack);
        }

        cout << "sum:" << sum << endl;
    }

    void Sub(int arr[], int n, stack<int> myStack)
    {
        if (n == 2)
        {
            stack<int> s1(myStack);
            s1.push(arr[0]);
            s1.push(arr[1]);
            GetTotalOps(s1);
         
            stack<int> s2(myStack);
            s2.push(arr[1]);
            s2.push(arr[0]);
            GetTotalOps(s2);
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                int v = arr[i];
                arr[i] = arr[0];
                arr[0] = v;
                
                stack<int> newStack(myStack);
                newStack.push(arr[0]);

                Sub(&arr[1], n - 1, newStack);
                arr[0] = arr[i];
                arr[i] = v;
                
            }

        }
    }

    int Run(int *arr, int n)
    {
        if (n == 0) return 0;
        else if (n == 1)    return 0;

        stack<int> myStack;

        cout << endl;

        Sub (arr, n, myStack);

        return 0;
    }

};

namespace MatrixChainMultiplication
{
    void AllMatrixMultiplicationCompbination(string s, int openCount, int closeCount, int operationCount, int *arr, int n)
    {
        if (openCount == operationCount && closeCount == operationCount)
        {
            cout << s << endl;
            return;
        }

        if (openCount < operationCount)
        {
            if (n > 2)
            {
                string s1 = s + "(";
                strstream ss;
                ss << arr[0] << " " << ends;
                s1 += ss.str();
                AllMatrixMultiplicationCompbination(s1, openCount + 1, closeCount, operationCount, &arr[1], n - 1);

                if (n > 3)  // three elements to form a matrix multiplication
                {
                    if (openCount < operationCount - 1)
                    {
                        string s2 = s + "(";
                        AllMatrixMultiplicationCompbination(s2, openCount + 1, closeCount, operationCount, arr, n);
                    }
                    else
                    {
                        // the last open parenthesis must be followed by a matrix
                        return;
                    }
                }
                else
                {
                    // N/A
                    return;
                }
            }
            else
            {
                return;
            }
        }

        if (closeCount < operationCount)
        {
            strstream ss;
            if (closeCount == 0)
            {
                ss << arr[0] << " " << arr[1] << " " << ends;
            }
            else if (n > 0)
            {
                ss << arr[0] << " " << ends;
            }
            else
            {
                ss << ends;
            }
            string s1 = s + ss.str();
            s1 += ")";
            AllMatrixMultiplicationCompbination(s1, openCount, closeCount + 1, operationCount, (n>0)?&arr[1]:arr, (closeCount==0)?(n-2):(n-1));
        }
    }

    int Run(int* arr, int n)
    {
        string s;
        AllMatrixMultiplicationCompbination(s, 0, 0, n-2, arr, n);
        return 0;
    }
};


namespace MatrixChainMultiplication_Native
{
    // Matrix Ai has dimension p[i-1] x p[i] 
    // for i = 1..n 
    int MatrixChainOrder(int p[], int i, int j)
    {
        if (i == j)
            return 0;
        int k;
        int min = INT_MAX;
        int count;

        // place parenthesis at different places 
        // between first and last matrix, recursively 
        // calculate count of multiplications for 
        // each parenthesis placement and return the 
        // minimum count 
        for (k = i; k < j; k++)
        {
            count = MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];

            if (count < min)
                min = count;
        }

        // Return minimum count 
        return min;
    }

    int Run(int arr[], int n)
    {
        return MatrixChainOrder(arr, 1, n - 1);
    }
};


namespace MatrixChainMultiplication_DP_Memoization
{
    int dp[100][100];

    int MatrixChainMemoised(int arr[], int i, int j)
    {
        if (i == j)
        {
            dp[i][j] = 0;
            cout << "dp[" << i << "][" << j << "]=" << dp[i][j] << endl;
            return dp[i][j];
        }

        if (dp[i][j] != -1)
        {
            cout << "dp[" << i << "][" << j << "]=" << dp[i][j] << endl;
            return dp[i][j];
        }

        dp[i][j] = INT_MAX;

        for (int k = i; k < j; k++)
        {
            dp[i][j] = min(dp[i][j], MatrixChainMemoised(arr, i, k) + MatrixChainMemoised(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
        }

        cout << "dp[" << i << "][" << j << "]=" << dp[i][j] << endl;
        return dp[i][j];
    }

    int Run(int arr[], int n)
    {
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                dp[i][j] = -1;
            }
        }

        return MatrixChainMemoised(arr, 1, n - 1);
    }
};

namespace MatrixChainMultiplication_DP_Tabulation
{
    int Run(int arr[], int n)
    {

        /* For simplicity of the program, one
        extra row and one extra column are
        allocated in m[][]. 0th row and 0th
        column of m[][] are not used */
        int** m;
        m = new int* [n];
        for (int i = 0; i < n; i++)
        {
            m[i] = new int[n];
        }

        int i, j, k, L, q;

        /* m[i, j] = Minimum number of scalar
        multiplications needed to compute the
        matrix A[i]A[i+1]...A[j] = A[i..j] where
        dimension of A[i] is p[i-1] x p[i] */

        // cost is zero when multiplying 
        // one matrix. 
        for (i = 1; i < n; i++)
            m[i][i] = 0;

        // L is chain length. 
        for (L = 2; L < n; L++)
        {
            for (i = 1; i < n - L + 1; i++)
            {
                j = i + L - 1;
                m[i][j] = INT_MAX;
                for (k = i; k <= j - 1; k++)
                {
                    // q = cost/scalar multiplications 
                    q = m[i][k] + m[k + 1][j]
                        + arr[i - 1] * arr[k] * arr[j];
                    if (q < m[i][j])
                        m[i][j] = q;
                }
            }
        }

        return m[1][n - 1];
    }

};

// Driven Program 
int MatrixChainMultiplication_Test ()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)   cin >> arr[i];

        cout << MatrixChainMultiplication_DP_Tabulation::Run(arr, n) << "\n";

    }
    return 0;
}