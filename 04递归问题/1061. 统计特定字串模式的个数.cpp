#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

ll IT(int n , int m)
{
    ll *arr = new ll[n + 1];
    memset(arr,0,8*n+8);
    for(int i = 1; i < n + 1; i++)
    {
        if(i < m)
        {arr[i] = 0;}
        else if(i == m)
        {arr[i] = 1;}
        else if(i > m)
        {
            arr[i] = arr[i - 1] * 2 + pow(2,i - m - 1) - arr[i - m - 1];
        }
    }
    ll temp = arr[n];
    delete[] arr;
    return temp;
}

ll RE(int n, int m)
{
    if(n < m) return 0;
    if(n == m) return 1;

    return 2 * RE(n - 1,m) + pow(2, n-m-1) - RE(n - m - 1,m);
}

int main()
{
    ll n, m;
    while(cin >> n >> m)
    {
        if(n == -1 && m == -1)
            break;

        
        cout << IT(n,m) << endl;
        //cout << RE(n,m) << endl;
    }    
}