#include<bits/stdc++.h>
using namespace std;

// no. of ways
// coin change
int solve(int *coin, int sum, int n)
{
    int dp[n+1][sum+1];

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i-1] <= j)
            {
                dp[i][j] = dp[i][j-coin[i-1]]+dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }   
    }
    
    return dp[n][sum];
}


// minimum number of coins

int solve2(int *coin, int sum, int n)
{
    int dp[n+1][sum+1];

    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = INT32_MAX-1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = min(1+dp[i][j - coin[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    return 0;
}