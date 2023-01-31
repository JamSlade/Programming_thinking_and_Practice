#include<iostream>
#define ll long long
using namespace std;

int cmp(const void *q1, const void *q2)
{
    ll * p1 = (ll *)q1;
    ll * p2 = (ll *)q2;

    if(*p1 > *p2)
    {return 1;}
    else
    {return -1;}
}

int main()
{
    int total;
    cin >> total;
    ll * point = new ll[total];
    for(int i = 0; i < total; i++)
    {
        cin >> point[i];
    }
    
    

    qsort(point,total,sizeof(ll),cmp);
    
    ll min_ = 0;
    for(int i = 0; i < total / 2; i++)
    {
        min_ += (point[2*i + 1] - point[2 * i]);
    }
    cout << min_;

    return 0;  
}