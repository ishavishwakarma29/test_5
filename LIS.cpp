#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pb push_back

int lis(vector<int> arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);

    int len = 1;

    for (int i = 1; i < n; i++)
    {
       for (int j = 0; j <i; j++)
       {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], 1+dp[j]);
                len = max(len, dp[i]);
            }    
       }  
    } 

    return len;
}


// using binary search
int longestIncreasingSubsequence(int arr[], int n, int k, int b)
{

    vector<int> temp;
    temp.push_back(arr[0]);

    int len = 1;

    for (int i = 1; i < n; i++)
    {
       if (arr[i] > temp.back())
       {
            // arr[i] > the last element of temp array

            temp.push_back(arr[i]);
            len++;
       }
       else
       {
            // replacement step
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
       }
    }

    return len;
}

int32_t main()
{
    return 0;
}