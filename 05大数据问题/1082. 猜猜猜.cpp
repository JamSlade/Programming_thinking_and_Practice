#include<iostream>

using namespace std;

const int MOD = 1e9+7;
typedef long long ll;

ll func(string a)
{
    int len = a.length();
    if(len == 1)    return 1;
    if(len == 2)    return ((a[0] == a[1]) ? 1 : 4);

    ll r = 1;
    if(a[0] != a[1])    r = 2;
    for(int i = 1; i < len - 1; i++)
    {
        ll c = 1;
        if(a[i] != a[i - 1])    c++;
        if(a[i] != a[i + 1] && a[i - 1] != a[i + 1])    c++;
        r = (r * c) % MOD;
    }
    if(a[len - 1] != a[len - 2]) r = (r * 2) % MOD;
    return r;

}


int main()
{
    string s;
    cin >> s;
    cout << func(s) << endl;
}