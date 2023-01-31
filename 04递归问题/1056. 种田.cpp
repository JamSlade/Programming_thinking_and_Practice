#include<iostream>

#define ll long long
using namespace std;


ll re_func(ll x, ll y)
{
    ll min = (x > y) ? y : x;
    ll max = (x < y) ? y : x;
    if(min == 0)
        return 0;
    ll num = max / min;
    max -= min * num;
    num *= 4 * min;

    return num + re_func(max, min);
}

ll it_func(ll x, ll y)
{
    ll min = (x > y) ? y : x;
    ll max = (x < y) ? y : x;
    ll all = 0;
    while(max % min)
    {
        ll num = max / min;
        all += min * 4 * num;
        ll temp = min;
        min = max % min;
        max = temp;
    }

    all += max * 4;

    return all;
    

}

int main()
{
    ll x;
    ll y;
    cin >> x >> y;
    ll peri = 0;
    peri = it_func(x,y);
    cout << peri << endl;

}