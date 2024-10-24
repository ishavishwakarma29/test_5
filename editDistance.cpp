// given two strings s and t
// make them equal
// operations allowed
// 1. update a character
// 2. remove a character
// 3. insert a charater
// return min no. of operations required to make them equal

// brute force

int editDistance(string s, string t)
{
    if (s.length()==0)
    {
        return t.length();
    }
    if (t.length()==0)
    {
       return s.length();
    }

    if (s[0]==t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }
    else
    {
        int x = 1 + editDistance(s , t.substr(1));
        int y = 1 + editDistance(s.substr(1), t);
        int z = 1 + editDistance(s.substr(1), t.substr(1));

        return min(x, y, z);
    }   
}




// memoization

int editDistanceHelp(string s, string t, vector<vector<int>>& dp)
{
    int m = s.length();
    int n = t.length();
    if (s.length() == 0)
    {
        return t.length();
    }
    if (t.length() == 0)
    {
        return s.length();
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    if (s[0] == t[0])
    {
        int ans = editDistance(s.substr(1), t.substr(1));
        dp[m][n] = ans;

        return ans;
    }
    else
    {
        int x = 1 + editDistance(s, t.substr(1));
        int y = 1 + editDistance(s.substr(1), t);
        int z = 1 + editDistance(s.substr(1), t.substr(1));

        int ans = min(x, min(y, z));
        dp[m][n] = ans;
        return ans;
    }
}

int editDistance2(string s, string t)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));
    return editDistanceHelp(s, t, dp);
}


// DP

int editDistance3(string s, string t)
{
    if (s.length()==0)
    {
        return t.length();
    }
    if (t.length() == 0)
    {
        return s.length();
    }

    int m = s.length();
    int n = t.length();

    vector<vector<int>> dp(m + 1, vector<int>(n+1));

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = i;
    }
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m-i] == t[n-j])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                int x = 1 + dp[i-1][j];
                int y = 1 + dp[i][j-1];
                int z = 1 + dp[i-1][j-1];

                dp[i][j] = min(x, min(y, z));
            }
            
        }
        
    }
    
    return dp[m][n];
}



#include<bits/stdc++.h>
using namespace std;

int main()
{
    
}