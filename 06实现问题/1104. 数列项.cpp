#include<iostream>
using namespace std;
long long DP[1000];

int main()
{
    int n,k;
    cin >> k >> n;
    DP[0] = 0;
    DP[1] = 1;
    for(int i = 2; i < n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(i - j < 0)
                continue;
            else
                DP[i] += DP[i - j];
        }
    }
    cout << DP[n - 1];//
}