#include<iostream>

#define ll long long
using namespace std;

struct STA
{
    long long coea = 0;
    long long coeb = 0;
    ll da = 0;
    ll db = 0;

    ll upa = 0;
    ll upb = 0;
    
};
//
int main()
{
    int a;
    int n;
    int m;
    int x;
    cin >> a >> n >> m >> x;
    STA * sta = new STA[n];
    sta[0].coea = 1;
    sta[1].coea = 1;
    sta[0].upa = 1;
    sta[1].upb = 1;
    for(int i = 2; i < n; i++)
    {
        sta[i].upa = sta[i - 1].upa + sta[i - 2].upa;
        sta[i].upb = sta[i - 1].upb + sta[i - 2].upb;

        sta[i].da = sta[i - 2].upa;
        sta[i].db = sta[i - 2].upb;

        sta[i].coea = sta[i].da + sta[i - 1].coea;
        sta[i].coeb = sta[i].db + sta[i - 1].coeb;

        //cout <<"coea  " <<sta[i].coea <<"  coeb  "<<sta[i].coeb << endl;

    }
    //a一开始上车 m一开始下车
    //n车站 x车站
    ll b = (m - a * sta[n - 2].coea) / sta[n - 2].coeb;
    cout << "b " << b << " a " << a << endl;

    ll people = sta[x - 1].coeb * b + sta[x - 1].coea * a;
    cout << people << endl;


    return 0;
}