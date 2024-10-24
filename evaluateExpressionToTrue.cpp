#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

// brute force

int solve(string s, int i, int j, bool isTrue)
{
    if(i>j)
    {
        return false;
    }


    if (i == j)
    {
        if (isTrue==true)
        {
            return s[i]=='T';
        }
        else
        {
            return s[i]=='F';
        }
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }
    
    int ans = 0;
    for (int k = i+1; k <= j-1; k += 2)
    {
        int lt = solve(s, i, k-1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k+1, j, true);
        int rf = solve(s, k + 1, j, false);

        if (s[k]=='&')
        {
            if (isTrue==true)
            {
                ans += lt*rt;
            }
            else
            {
                ans += lf*rt + lf*rf + lt*rf;
            }
            
        }
        else if (s[k]=='|')
        {
            if (isTrue==true)
            {
                ans += lf*rt + lt*rf + lt*rt;
            }
            else
            {
                ans += lf*rf;
            }
            
        }
        else if (s[k]=='^')
        {
            if (isTrue==true)
            {
                ans += lf*rt + rt*lf;
            }
            else
            {
                ans += lt*rt + lf*rf;
            }    
        }
    }
    
    return mp[temp]=ans;
}

// memoisation

int solve2(string s, int i, int j, bool isTrue)
{
    if (i > j)
    {
        return false;
    }

    if (i == j)
    {
        if (isTrue == true)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt = solve(s, i, k - 1, true);
        int lf = solve(s, i, k - 1, false);
        int rt = solve(s, k + 1, j, true);
        int rf = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue == true)
            {
                ans += lt * rt;
            }
            else
            {
                ans += lf * rt + lf * rf + lt * rf;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue == true)
            {
                ans += lf * rt + lt * rf + lt * rt;
            }
            else
            {
                ans += lf * rf;
            }
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
            {
                ans += lf * rt + rt * lf;
            }
            else
            {
                ans += lt * rt + lf * rf;
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}