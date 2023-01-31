#include<iostream>
using namespace std;
int func(int(*a)[11],int k, int r, int c, int n)
{

    int sum = 0;
    for(int a1 = 1; a1 <= r; a1++)
    {
        for(int a2 = 1; a2 <= c; a2++)
        {
            for(int b1 = 1; b1 <= r; b1++)
            {
                for(int b2 = 1; b2 <= c; b2++)
                {
                    //确定两点来确定矩形
                    int z = 0;
                    for(int c1 = a1; c1 <= b1; c1++)
                    {
                        for(int c2 = a2; c2 <= b2; c2++)
                        {
                            if(a[c1][c2])
                            {
                                z++;
                            }
                        }
                    }
                    if(z >= k) sum++;
                }
            }
        }
    }
    return sum;
}

int main()
{
    int Qus,k,r,c,n;
    cin >> Qus;
    for(int j = 0;j < Qus; j++)
    {
        int a[11][11] = {{0}};

        cin >> r >> c >> n >> k;
        for(int i = 0;i < n; i++)
        {   
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
        }
        
        cout << "case #" << j << ":" << endl;
        cout << func(a,k,r,c,n) << endl;

        
    }
    
    

    return 0;
}