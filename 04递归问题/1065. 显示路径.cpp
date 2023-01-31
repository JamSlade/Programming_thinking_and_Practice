#include<iostream>
#define ll long long
using namespace std;

int times = 0;
string STR;
void direction(ll x, ll y)
{
    

    if(x % 2 != 0)
    {
        ll E = x - 1;
        ll W = x + 1;
        //搞清楚怎么走是向东走。
        E /= 2;
        W /= 2;
        y /= 2;
        if(y == 0 && E == 0)
        {
            times++;
            STR += 'E';
            return;//
        }
        if(y == 0 && W == 0)
        {
            times++;
            STR += 'W';
            return;
        }

        if((E + y) % 2 != 0)
        { 
            times++;
            STR +=  'E';
            direction(E,y);
        }
        else if((W + y) % 2 != 0)
        {
            times++;
            STR += 'W';
            direction(W,y);
        }
        
    }
    else if (y % 2 != 0)
    {
        
        ll N = y - 1;
        ll S = y + 1;
        //同上
        S /= 2;
        N /= 2;
        x /= 2;
        if(x == 0 && N == 0)
        {
            times++;
            STR += 'N';
            return;
        }
        if(x == 0 && S == 0)
        {
            times++;
            STR += 'S';
            return;
        }

        if((x + S) % 2 != 0)
        {
            times++;
            STR += 'S' ;
            direction(x,S);
        }
        else if((x + N) % 2 != 0)
        {
            times++;
            STR += 'N';
            direction(x,N);
        }
    }

}

int main()
{
    ll x,y;
    cin >> x >> y;
    if(x == 0 && y == 0)
    {
        cout << "0"<<endl;
    }
    else if((x + y) % 2 == 0)
    {
        cout << "-1" << endl;
        return 0;
    }
    
    else
    {
        direction(x,y);
        cout << times << endl << STR;
    }

    return 0;
}