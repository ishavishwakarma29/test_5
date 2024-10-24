// given m*n matrix find the minimum cost to reach from (0, 0) to (m-1, n-1)
// cost of moving through a cell is equal to value of that matrix
// moves allowed = right down diagonal;

#include<bits/stdc++.h>
using namespace std;

// brute force

int solve(int** input, int m, int n, int i, int j, int** dp)
{
    // base case
    if (i==m-1 && j==n-1)
    {
        return input[i][j];
    }
    
    if (i >= m || j>= n)
    {
        return INT32_MAX;
    }
    
    int x = solve(input, m, n, i, j+1);
    int y = solve(input, m, n, i+1, j+1);
    int z = solve(input, m, n, i+1, j);

    int ans = min(x, min(y, z))+input[i][j];
    return ans;
}

int minCost(int** arr, int m, int n)
{
    return solve(arr, m, n, 0, 0);
}

// memoization

int solve2(int **input, int m, int n, int i, int j, int** dp)
{
    // base case
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }

    if (i >= m || j >= n)
    {
        return INT32_MAX;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    

    int x = solve2(input, m, n, i, j + 1, dp);
    int y = solve2(input, m, n, i + 1, j + 1, dp);
    int z = solve2(input, m, n, i + 1, j, dp);

    int ans = min(x, min(y, z)) + input[i][j];
    dp[i][j] = ans;
    return ans;
}

int minCost2(int **arr, int m, int n)
{
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
        
    }
    
    return solve2(arr, m, n, 0, 0, dp);
}

// DP

int mincost3(int** arr, int m, int n)
{
    int dp[m][n];
    dp[m-1][n-1] = arr[m-1][n-1];
    

    for (int j = n-2; j>=0; j--)
    {
        dp[m-1][j] = dp[m-1][j+1] + arr[m-1][j];
    }

    for (int j = m - 2; j >= 0; j--)
    {
        dp[j][n-1] = dp[j+1][n-1] + arr[j][n-1];
    }

    for (int i = m-2; i >= 0; i--)
    {
       for (int j = n-2; j>=0; j--)
       {
            dp[i][j] = min(dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j]));
       }
       
    }
    
    return dp[0][0];
}