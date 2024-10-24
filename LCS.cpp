// return longest common subsequence between two strings

#include<bits/stdc++.h>
using namespace std;


// brute force
int lcs(string s, string t)
{
    // base case
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }

    // recursive calls

    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else
    {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));
        int c = lcs(s.substr(1), t.substr(1));

        return max(a, max(b, c));
    }
}



// memoization
int lcs_helper(string s, string t, vector<vector<int>>& dp)
{
    int m = s.length();
    int n = t.length();
    
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    if (s[0] == t[0])
    {
        int ans = 1 + lcs_helper(s.substr(1), t.substr(1), dp);
        dp[m][n] = ans;
        return ans;
    }
    else
    {
        int a = lcs_helper(s.substr(1), t, dp);
        int b = lcs_helper(s, t.substr(1), dp);
        int c = lcs_helper(s.substr(1), t.substr(1), dp);

        int ans =  max(a, max(b, c));
        dp[m][n] = ans;
        return ans;
    }
}

int lcs2(string s, string t)
{
    vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
    return lcs_helper(s, t, dp);
}


// DP

int lcs3(string s, string t)
{
    int m = s.length();
    int n = t.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1));


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
            if (s[i-1]==t[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                int a = dp[i-1][j];
                int b = dp[i][j-1];
                int c = dp[i-1][j-1];

                dp[i][j] = max(a, max(b, c));
            }
            
        }
        
    }
    
    return dp[m][n];
}

string printLCS(string s, string t)
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
            if (s[i-1] == t[j-1])
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

    // .print lcs
    string ans="";

    int i=m,j=n;

    while (i>0 && j>0)
    {
        if (s[i-1] == t[j-1])
        {
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j-1] > dp[i-1][j])
            {
                i--;
            } 
            else
            {
                j--;
            }
               
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main()
{
    cout<<printLCS("xyz", "zxay")<<endl;
}