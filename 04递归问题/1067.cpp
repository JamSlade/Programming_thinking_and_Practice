#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

int A[32],B[32],K[32];
ll dp[32][2][2][2];

ll dfs(int loc, int aup, int bup , int kup)
{
    if(loc == -1)
        return !(aup || bup || kup);
        //三者有一个是1，说明有一个数取到了上限
    if(dp[loc][aup][bup][kup] != -1)
        return dp[loc][aup][bup][kup];
        //初始化好了就直接返回，不然就会重复计算子递归
    
    int amax = aup ? A[loc] : 1;
    int bmax = bup ? B[loc] : 1;
    //不是上限的话就取最大值,这里的最大值是1

    ll way = 0;

    for(int i = 0; i <= amax; i++)
    {
        for(int j = 0; j <= bmax; j++)
        {
            if(kup && (i & j) > K[loc])
                continue;//大于k位也不考虑
            bool taup = ((aup && i) == amax);
            bool tbup = ((bup && j) == bmax);
            //判断接下来的递归是否还有上极限限制
            bool tkup = (kup && (i & j) == K[loc]);
            //判断是否和K对应的位相等

            way += dfs(loc - 1, taup, tbup, tkup);
        }
    }
    dp[loc][aup][bup][kup] = way;
    return way;
}

void solve()//初始化
{
    int a,b,k;
    cin >> a >> b >> k;
    for(int i = 0; i < 32; i++)
    {
        A[i] = a & 1; a >>= 1;
        B[i] = b & 1; b >>= 1;
        K[i] = k & 1; k >>= 1;
    }
    memset(dp,-1,sizeof(dp));
    cout << (ll)dfs(31,1,1,1) << endl;
    //默认开始的时候都是1，判定是否是上限
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}