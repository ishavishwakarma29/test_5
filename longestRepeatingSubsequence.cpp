#include<bits/stdc++.h>
using namespace std;

int lrs(string s, string t)
{
    int m = s.length();
    int n = t.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1] && i!=j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int a = dp[i - 1][j];
                int b = dp[i][j - 1];
                int c = dp[i - 1][j - 1];

                dp[i][j] = max(a, max(b, c));
            }
        }
    }

    return dp[m][n];
}

int main()
{
    return 0;
}