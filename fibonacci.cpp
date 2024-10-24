// DP APPROACH CONCEPT 
// for n = 6;
// fib(6) = fib(5) + fib(4);
// fib(5) = fib(4) + fib(3);
// fib(4) = fib(3) + fib(2);
// fib(3) = fib(2) + fib(1);
// fib(2) = fib(1) + 1;
// fib(1) = 1;
// values are repeating therefore we can save values ans reuse it




#include<iostream>
using namespace std;

// classical fibonacci

// brute force
// T(n) = O(2^n)

int fibo(int n)
{
    if (n<=1)
    {
       return 1;
    }

    int a = fibo(n-1);
    int b = fibo(n-2);

    return a+b;
    
}

// MEMOIZATION APPROACH

// ITS A RECURSIVE APPROACH
// memoization - top down approach in which we save previous answer
// T(n) = O(n)

int fibo2_help(int n, int* ans)
{
    if (n<=1)
    {
        return 1;
    }
    
    // check if output already exists
    if (ans[n] != -1)
    {
        return ans[n];
    }
    
    int a = fibo2_help(n-1, ans);
    int b = fibo2_help(n-2, ans);

    // save output for future use

    ans[n] = a+b;

    return ans[n];
}


int fibo_2(int n)
{
    int *ans = new int[n+1];

    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    

    return fibo_help(n, ans);
}

//  DP APPROACH

// dynamic programming approach is a bottom-up approach
// it saves previous answer
// its a iterative approach
// T(n) = O(n)

int fibo_3(int n)
{
    int* ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i <=n; i++)
    {
        ans[i] = ans[i-1] + ans[i-2];
    }
    
    return ans[n];
}