#include<bits/stdc++.h>
using namespace std;

bool subsetSum3(int *arr, int sum, int n)
{
    bool dp[n + 1][sum + 1];

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
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int ans = INT32_MIN;
    for (int i = 0; i <= n; i++)
    {
       for (int j = 0; j <= sum/2; j++)
       {
            if (dp[i][j])
            {
                ans = min(ans, sum-2*j);
            }
            
       }  
    }
    return ans;
}

int main()
{
    return 0;
}