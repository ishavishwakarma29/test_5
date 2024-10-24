#include<bits/stdc++.h>
using namespace std;

// brute force

int knapsack(int *weight, int *values, int n, int maxWeight)
{
    // base case
    if (n==0 || maxWeight==0)
    {
        return 0;
    }
    

    if (weight[0] > maxWeight)
    {
        return knapsack(weight+1, values+1, n-1, maxWeight);
    }
    


    int x = knapsack(weight+1, values+1, n-1, maxWeight-weight[0]) + values[0];
    int y = knapsack(weight+1, values+1, n-1, maxWeight);

    return max(x, y);
}


// memoization

int knapsack_2_help(int *weight, int *values, int n, int maxWeight, vector<vector<int>>& dp)
{
    // base case
    if (n == 0 || maxWeight == 0)
    {
        return 0;
    }

    if (dp[n][maxWeight] != -1)
    {
        return dp[n][maxWeight];
    }
    else
    {
        if (weight[0] > maxWeight)
        {
            dp[n][maxWeight] = knapsack(weight + 1, values + 1, n - 1, maxWeight);
            return dp[n][maxWeight];
        }

        int x = knapsack(weight + 1, values + 1, n - 1, maxWeight - weight[0]) + values[0];
        int y = knapsack(weight + 1, values + 1, n - 1, maxWeight);
        dp[n][maxWeight] = max(x, y);
        return max(x, y);
    }
}

int knapsack2(int *weight, int *values, int n, int maxWeight)
{
    vector<vector<int>> dp(n+1, vector<int>(maxWeight, -1));
    return solve(weight, values, n, maxWeight, dp);
}

    // DP

int Knapsack3(int *weight, int *values, int n, int maxWeight)
{
    vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, -1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= maxWeight; i++)
    {
       dp[0][i] = 0;
    }
    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
        {
            if (weight[i-1] <= j)
            {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }   
        }   
    }
    

    return dp[n][maxWeight];

}

    int main()
{
    
}