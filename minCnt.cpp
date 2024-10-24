// problem statement = 
// find minimum number of numbers whose sum of squares is equal to n.


// BRUTE FORCE

#include<bits/stdc++.h>

using namespace std;

// brute force

int cnt(int n)
{
    if (n<=1)
    {
        return n;
    }
    int ans = INT32_MAX;
    for (int i = 1; i <= sqrt(n); i++)
    {
        int a = cnt(n-(i*i))+1;
        ans = min(ans, a);
    }
    
    return ans;
    
}

// memoization

int cnt2_help(int n, int* arr)
{
    if (n<=1)
    {
        return n;
    }
    
    if (arr[n] != -1)
    {
       return arr[n];
    }

    int ans = INT32_MAX;
    for (int i = 1; i <= sqrt(n); i++)
    {
       int a = cnt(n - (i * i)) + 1;
       ans = min(ans, a);
    }

    arr[n] = ans;

    return ans;
}

int cnt2(int n)
{
    int * arr = new int[n+1];

    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    
    return cnt2_help(n, arr);
}


// dp

int cnt3(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int* arr = new int[n+1];

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int ans = INT32_MAX;
        for (int j = 1; j <= sqrt(i); j++)
        {
            int a = arr[i - (j * j)] + 1;
            ans = min(ans, a);
        }

        arr[i] = ans;
    }
    
    return arr[n];
}

int main()
{
    int n;
    cin>>n;

    cout<<cnt(n)<<endl;
    cout << cnt2(n) << endl;
    cout << cnt3(n) << endl;
}