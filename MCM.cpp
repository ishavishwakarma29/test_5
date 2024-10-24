#include<bits/stdc++.h>
using namespace std;


// brute force
int solve(int arr[], int i, int j)
{
    if(i>=j)
    {
        return 0;
    }

    int ans = INT32_MAX;
    for (int k = i; k<=j-1; k++)
    {
        ans = min(ans, solve(arr, i, k)+solve(arr, k+1, j)+(arr[i-1]*arr[k]*arr[j]));
    }
    return ans;
}


// memoisation

int solve2help(int arr[], int i, int j, vector<vector<int>>& dp)
{
    if (i >= j)
    {
        return 0;
    }


    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    
    int ans = INT32_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        ans = min(ans, solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]));
    }

    return dp[i][j]=ans;
}

int solve2(int arr[], int i, int j)
{
    vector<vector<int>> dp(j-i+1, -1);
    solve2help(arr, i, j, dp);
}

int main()
{ 
    return 0;
}