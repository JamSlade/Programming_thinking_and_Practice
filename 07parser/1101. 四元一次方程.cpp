#include<iostream>

using namespace std;

int dp[1010];
int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << "case #" << i << ":"<<endl;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4; i < 1010; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] ;
        }
        cout <<dp[n] << endl;
    }

    return 0;
}

