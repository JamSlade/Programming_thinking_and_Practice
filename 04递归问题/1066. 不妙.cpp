#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

ll a[20];
ll dp[20][20];

int dfs(int location, bool Fdigit, bool upper)
{
    if(location == -1)
        return 1;
    //当遍历完所有的数位之后location会到-1位
    //对应的就是第一位的前一位（遍历完了）
    //表示枚举完毕

    if(!Fdigit && !upper && dp[location] != -1)
        return dp[location][state];
    /*
    Fdigit代表首位数字是否是0
    upper代表这个数字是否是这个数位的上界

    比如说234
    可以把Fdigit分成3块讨论，2，1，0。
    包括100~199和 001~099 和 200~234这部分

    ①显然如果首位是1——（100~199）的部分  也就是说：首位不是0，
    ②并且不是限制位     比如首位是2，那你得考虑下一位是不是3
    ③并且前面的递归已经记录好000~099这部分的数据，
    
    那就可以直接放在100到199这部分了


    */

    int up = upper ? a[location] : 9;
    ll count = 0;
    for(int i = 0; i < up; i++)
    {
        if(i == 9)//含有9直接无视
            continue;
        count += dfs(location - 1,Fdigit && i == 0, upper && i == a[location]);
    }

    if(!Fdigit && !upper)
        dp[location] = count;
    
    return count;
}

int main()
{
    ll count = 0;
    ll a,b;
    cin >> a >> b;

    for(ll i = a; i <= b; i++)
    {
        if(i % 9 == 0)
        {continue;}
        ll temp = i;
        while(temp)
        {
            ll t = temp % 10;
            if(t == 9)
            {goto FLAG;}
            temp /= 10;
        }

        count++;
        FLAG:;
    }
    cout << count << endl;
    return 0;
}