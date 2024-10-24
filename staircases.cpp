// Problem Statement : Staircase
// Problem Description : A child runs up a staircase with 'n' steps and can hop either 1 step,
// 2 steps or 3 steps at a time.
// Implement a method to count and return all possible ways in which the child can run - up to the stairs.

#include <iostream>
using namespace std;

// BRUTE FORCE

int cnt(int n)
{
    if (n==1)
    {
        return 1;
    }

    if (n==2)
    {
        return 2;
    }
    
    if (n==3)
    {
        return 4;
    }
    
    return cnt(n-1)+cnt(n-2)+cnt(n-3); 
}


// MEMOIZATION

int cnt2_help(int n, int* arr)
{
    if (n==1)
    {
        return 1;
    }

    if (n==2)
    {
        return 2;
    }
    
    if (n==3)
    {
        return 4;
    }
    

    if (arr[n] != -1)
    {
        return arr[n];
    }

    int ans = cnt(n - 1) + cnt(n - 2) + cnt(n - 3);

    arr[n] = ans;

    return ans;
}


int cnt2(int n)
{
    int* arr = new int[n+1];

    for (int i = 0; i <=n; i++)
    {
        arr[i] = -1;
    }
    
    return cnt2_help(n, arr);
}

// DP 

int cnt3(int n)
{
    int* arr = new int[n+1];
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n];
}


int main()
{
    int n;
    cin>>n;

    cout<<cnt(n)<<endl;
    cout<<cnt2(n)<<endl;
    cout<<cnt3(n)<<endl;
}