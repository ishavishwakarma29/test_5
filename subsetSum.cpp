#include<bits/stdc++.h>
using namespace std;


// brute force
bool subsetSum(int* arr, int sum, int n, int curr, int i)
{
    if (curr == sum)
    {
       return true;
    }
    
    if (i==n)
    {
        return false;
    }
    
    if (curr+arr[i] <= sum)
    {
        return subsetSum(arr, sum, n, curr + arr[i], i + 1) || (arr, sum, n, curr, i + 1);
    }

    return (arr, sum, n, curr, i + 1);
}


// memoisation
bool subsetSum2help(int* arr, int sum, int n, int** dp, int curr, int i)
{
    if (curr == sum)
    {
        return true;
    }

    if (i == n)
    {
        return false;
    }


    if (dp[i][curr] != -1)
    {
        return dp[i][curr];
    }
    

    if (curr+arr[i]<=sum)
    {
        return dp[i][curr] = subsetSum(arr, sum, n, curr + arr[i], i + 1) || (arr, sum, n, curr, i + 1);
    }

    return dp[i][curr] = (arr, sum, n, curr, i + 1);
}


bool subsetSum2(int* arr, int sum, int n)
{
    int dp[n+1][sum+1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    
    return subsetSum2(arr, sum, n, dp, 0, 0);
}

// DP
bool subsetSum3(int *arr, int sum, int n)
{
    bool dp[n+1][sum+1];

    dp[0][0] = true;

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    for (int j = 1; j <= n; j++)
    {
        dp[j][0] = true;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }  
            else
            {
                dp[i][j] = dp[i-1][j];
            }
               
        }    
    }
    
    return dp[n][sum];
}

int main()
{
    
    return 0;
}