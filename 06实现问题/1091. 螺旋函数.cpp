#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    ll a;
    cin >> a;
    ll b = 0 ;
    while(b*b < a)//b? <= a < (b+1)?
        b++;//

    ll c = a - b * b;

    pair<ll,ll> p;
    if(b % 2)
    {
        p.first = b / 2;
        p.second = b / 2 + 1;
        if(c > b)
        {
            p.first -= b;
            p.second -= c - b;
        }
        else
        {
            p.first -= c;
        }
    }
    else
    {
        p.first = -b / 2;
        p.second = -b / 2;
        if(c > b)
        {
            p.first += b;
            p.second += c - b;
        }
        else
        {
            p.first += c;
        }
    }
    cout << '(' << p.first << ',' << p.second <<')';

}