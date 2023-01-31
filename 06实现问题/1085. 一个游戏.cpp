#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10000][2];
    memset(arr,0,sizeof(arr));
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        set<pair<int,int>> s;
        int l;
        int max = 0;
        cin >> l;
        for(int j = 0; j < l; j++)
        {
            int n,m;
            cin >> n >> m;
            if(n > max)
                max = n;
            if(m > max)
                max = m;
            if(m == n)
                continue;
            pair<int,int> p = {n,m};
            s.insert(p);
        }

        
        for(auto x : s)
        {
            arr[x.first][0]++;
            arr[x.second][1]++;
        }
        int Q = 1;
        for(int j = 0; j <= max; j++)
        {
            if((arr[j][0] >= 1 && arr[j][1] >= 1) || arr[j][0] >= 2)
                Q = 0;
        }
        if(Q)
            cout << "Lucky dxw!" << endl;
        else
            cout << "Poor dxw!"<<endl;

        
        memset(arr,0,sizeof(arr));
    }

    return 0;
}//