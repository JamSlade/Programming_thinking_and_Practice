#include<iostream>
#include<stack>
using namespace std;

void trans(long long a)
{
    long nbase[10];
    long base = 1;
    for(int i = 1; i <= 9; i++)
    {
        base *= i;
        nbase[i] = base;  
    }

    int flag = 0;
    for(int i = 9; i > 0; i--)
    {
        int temp = a / nbase[i];//对应的几！进制下可以出现数字几
        if(temp != 0)//注意到前面可能有0
        {
            cout << temp;
            flag = 1;//保证后面的0可以输出
            a = a - temp * nbase[i];//注意n！进制要如何减少 
        }                           //以前可以直接除以来减少，但是这里的n!进制每次除都不同，所以最方便还是直接减
        else
        {
            if(flag)
            {
                cout << temp;
            }
        }
        

    }
    cout << endl;
}

int main()
{
    int total;
    cin >> total;

    for(int i = 0 ; i < total; i++)
    {
        long long a;
        cin >> a;
        cout << "case #" << i<<":"<<endl;
        trans(a);
    }
    
}