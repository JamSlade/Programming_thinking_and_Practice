#include<iostream>
#include<cstring>
using namespace std;

int a[1000][1000];
int S[1000][1000];
int main()
{
    int Qus,k,r,c,n;
    cin >> Qus;
    for(int z = 0;z < Qus; z++)
    {
        memset(a,0,sizeof(a));
        memset(S,0,sizeof(S));

        cin >> r >> c >> n >> k;
        for(int i = 0;i < n; i++)
        {   
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
        }

        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++) 
                S[i][j] = S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1] + a[i][j];
            
        // for(int j = 1; j <= c; j++)
        //  {
        //      for(int i = 1;i <= r; i++)
        //     {
        //         cout << a[i][j] <<" ";
        //     }
        //     cout << endl;
        //  }
        //  cout << endl << endl;
        //  for(int j = 1; j <= c; j++)
        //  {
        //      for(int i = 1;i <= r; i++)
        //     {
        //         cout << S[i][j] <<" ";
        //     }
        //     cout << endl;
        //  }cout << endl << endl;
            
        long long ans = 0;

        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                for(int x = i; x <= r; x++)
                    for(int y = j; y <= c; y++)
                        if(S[x][y] - S[i - 1][y] - S[x][j - 1] + S[i - 1][j - 1] >= k)
                            ans++;
            
                
                    
            
        
        cout << "case #" << z << ":" << endl;
        cout << ans << endl;

        
    }
}