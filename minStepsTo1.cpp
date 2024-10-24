// problem statement-:
// you are given a integer n and you have to reduce it to 1. The following operations are allowed-
// 1. decrement by 1, n-1
// 2. divide by 2, n/2 (if n%2==0)
// 3. divide by 3, n/3  (if n%3==0)


#include<iostream>
using namespace std;


// BRUTE FORCE

int cnt(int n)
{
    // base case
    if (n<=1)
    {
        return 0;
    }

    int x = cnt(n-1);
    int y = INT32_MAX;
    int z = INT32_MAX;

    if (n%2==0)
    {
        y = cnt(n/2);
    }
    if (n%3==0)
    {
        z = cnt(n/3);
    }
   
    int ans = min(x, min(y, z)) + 1;
    return ans;
}


// MEMOIZATION APPROACH


// T(n) = O(n)
int cnt2_help(int n, int* ans)
{
    // base case
    if (n<=1)
    {
        return 0;
    }

    //check if output already exists

    if (ans[n] != -1)
    {
        return ans[n];
    }


    // calculate output
    
    int x = cnt2_help(n-1, ans);
    int y = INT32_MAX;
    int z = INT32_MAX;

    if (n%2==0)
    {
        y = cnt2_help(n/2, ans);
    }

    if (n%3==0)
    {
        z = cnt2_help(n/3, ans);
    }
    
    int output = 1+min(x, min(y,z));

    // save output for future use

    ans[n] = output;

    return output;
}

int cnt_2(int n)
{
    int * ans = new int[n+1];

    for (int i = 0; i <=n; i++)
    {
        ans[i] = -1;
    }
    
    return cnt2_help(n, ans);
}


// DP approach

// T(n) = O(n)

int cnt3(int n)
{
    int arr[n+1];

    // arr[0] = 0;
    arr[1] = 0;

    for (int i = 2; i<=n; i++)
    {
        int x = arr[i-1];
        int y = INT32_MAX;
        int z = INT32_MAX;

        if (i%2==0)
        {
           y = arr[i/2];
        }
        
        if (i%3==0)
        {
            z = arr[i/3];
        }
        
        arr[i] = 1+min(x, min(y, z));
    }
    
    return arr[n];
}




int main()
{
    cout<<cnt(5)<<endl;
    cout<<cnt3(5)<<endl;
    cout<<endl;
    cout << cnt(7) << endl;
    cout << cnt3(7) << endl;
    cout << endl;
    cout << cnt(10) << endl;
    cout << cnt3(10) << endl;
    cout << endl;
    cout << cnt(12) << endl;
    cout << cnt3(12) << endl;
    cout << endl;
    cout << cnt(4) << endl;
    cout << cnt3(4) << endl;
}