#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

int main()
{
    ll x;
    ll y;
    std::cin >> x >> y;
    ll a = abs(x) + abs(y);
    if(!a)
    {
        cout << "0" << endl;
    }
    else if(! (a % 2))
    {
        cout << "-1" << endl;
    }
    else
    {
        for(int i = 0; i < 64; i++)
        {
            if(a >= pow(2,i) && a <= pow(2,i+1))
                cout << i + 1 << endl;
        }
    }
}