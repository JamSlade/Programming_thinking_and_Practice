#include<iostream>
#include<algorithm>
#include<climits>
#define ll long long
using namespace std;

bool cmp(ll a,ll b)
{
    return(a > b);
}

int main()
{
    int n,m;
    cin >> n >> m;
    ll* arr = new ll[n];
    for(int i = 0;i < n ;i++)
    {
        ll temp;
        cin >> temp;
        arr[i] = temp;
    }

    sort(arr, arr + n, cmp);

    ll*brr = new ll[n - 1];
    
    for(int i = 0; i < n - 1; i++)
    {
        brr[i] = arr[i] - arr[i + 1]; 
    }
    ll S = 0;
    for(int i = 0; i < m - 1;i++)
    {
        S += brr[i] *(m - i - 1); 
    }
    ll min = S;

    for(int i = 0; i < n - m; i++)
    {
        S -= brr[i] * (m - 1);
        S += (arr[i + 1] - arr[i + m]);
        if(S < min)
        min = S;
    }

    cout << min << endl;

}