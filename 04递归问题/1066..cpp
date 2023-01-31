#include<iostream>
#define ll long long
using namespace std;

ll POW(ll base, ll power)
{
    ll temp = 1;
    while(power--)
    {
        temp *= base;
    }
    return temp;
}

ll distan(string s)
{
    int len = s.length();
    int times = 0;
    for(int i = 0; i < len - 1; i++)
    {
        times += s[i] -'0';
    }
    return (times % 9) ? (9 - times % 9) : 0;
    //判断这个数字抹去个位数后离下一个9的倍数还有多少个数

}

ll solve(string s)
{
    int len  = s.length();
    ll num = 0;
    for(int i = 0; i < len - 1; i++)
    {
        if(s[i] == '9')
        {
            for(int j = i; j < len; j++)
                s[j] = '8';
        }
        num += (s[i] - '0') * POW(9LL, len - i - 2) * 8LL;
        //比如 1023，每个整千就会有0~8 九个整百数需要处理累加
        //每个整百又可以分0~8九个整10来处理，每个整十均有8个满足条件的数
    }

    ll remain = min(s[len - 1], '8') - '0';
    num += remain;//个位数单独处理
    num ++;//别忘了0

    if(distan(s) <= remain)
        num--;

    return num;

    
}

int main()
{
    string a,b;
    cin >> a >> b;
    ll way = solve(b) - solve(a);
    cout << ++way << endl;
    //别忘了a是闭区间
    return 0;
}