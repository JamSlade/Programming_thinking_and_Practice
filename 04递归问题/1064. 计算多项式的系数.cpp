#include<iostream>
#define ll long long

using namespace std;

ll arr[2000][2000];


int main()
{
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++)
    {
        ll a,b,k,n,m;
        cin >> a >> b >> k >> n >> m;

        a %= 10007;
        b %= 10007;
        
        arr[0][0] = 1;
        for(ll i = 1; i <= k; i++)
        {
            arr[i][0] = arr[i - 1][0] * a % 10007;
        }
        for(ll i = 1; i <= k; i++)
        {
            arr[0][i] = arr[0][i - 1] * b % 10007;
        }

        for(ll i = 1; i <= k; i++)
        {
            for(ll j = 1; j <= k; j++)
            {
                arr[i][j] = (a * arr[i - 1][j] + b * arr[i][j - 1]) % 10007;
                //斜着看就是杨辉三角了
            }
        }
        cout << "case #" << i << ":"<<endl;
        cout << arr[n][m] << endl;
    }

    return 0;
}
