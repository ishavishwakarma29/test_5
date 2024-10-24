// problem - find num of possible binary trees with height h


#include<bits/stdc++.h>
using namespace std;


const int mod = 1000000009;
// brute force

long long int cnt(int h)
{
    if (h<=1)
    {
        return 1;
    }
    
        long long int a = cnt(h-1);
        long long int b = cnt(h-2);

        return ((((a%mod)*(a%mod))%mod)%mod + (2*((b%mod)*(a%mod))%mod)%mod);
}


// memoization
// balanced BTs
long long int cnt2_help(int h, int* arr)
{
        if (h <= 1)
        {
        return 1;
        }

        if (arr[h] != -1)
        {
            return arr[h];
        }
        

        long long int a = cnt(h - 1);
        long long int b = cnt(h - 2);

        long long int ans = ((((a % mod) * (a % mod)) % mod) % mod + (2 * ((b % mod) * (a % mod)) % mod) % mod);

        arr[h] = ans;

        return ans;
}

int cnt2(int n)
{
        int *arr = new int[n + 1];

        for (int i = 0; i <= n; i++)
        {
        arr[i] = -1;
        }

        return cnt2_help(n, arr);
}

// dp

long long int cnt3(int h)
{
        if (h <= 1)
        {
            return 1;
        }
        long long int *arr = new long long int[h + 1];
        arr[0] = 1;
        arr[1] = 1;
        for (int i = 2; i <= h; i++)
        {
            arr[i] = ((((arr[i-1]% mod) * (arr[i-1]% mod)) % mod) % mod + (2 * ((arr[i-2] % mod) * (arr[i-1] % mod)) % mod) % mod);
        }

        return arr[h];
        
}

int main()
{
        int n;
        cin >> n;

        cout << cnt(n) << endl;
        cout << cnt2(n) << endl;
        cout << cnt3(n) << endl;
}