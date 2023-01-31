#include<iostream>
#include<cstring>

#define ll long long
#define MOD (ll)(1e9 + 7)
using namespace std;

ll dp[300][210];
int arr[1000];

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        memset(dp,0,sizeof(dp));
        memset(arr,0,sizeof(arr));
        dp[0][0] = 1;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            arr[i] = s[i] - '0';
        }

        for(int i = 0; i < len; i++)
        {
            for(int rem = 0; rem < 210; rem++)
            {
                ll temp = 0;
                for(int j = i + 1; j <= len; j++)
                {
                    temp *= 10;
                    temp += arr[j - 1];
                    temp %= 210;

                    dp[j][(rem + temp) % 210] += dp[i][rem];
                    dp[j][(rem - temp + 210) % 210] += dp[i][rem];

                    dp[j][(rem + temp) % 210] %= MOD;
                    dp[j][(rem - temp + 210) % 210] %= MOD;
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < 210; i++)
            if(!(i % 2) || !(i % 3) || !(i % 5) || !(i % 7))
            {
                ans += dp[len][i];
                ans %= MOD;
            }

        cout << ans * ((MOD + 1) / 2) % MOD << endl;
        //cout << ans  % MOD << endl;
        //Г§вд2
    }

    return 0;
}

