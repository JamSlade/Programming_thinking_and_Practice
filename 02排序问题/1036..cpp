#include<iostream>
#include<algorithm>
#include<cmath>

#define ll long long
#define ull unsigned ll
using namespace std;

ull ABS(ll,ll);
struct point;
bool cmp(point,point);

struct point
{
    ll x;
    ll y;
    ull Manhattan;
    double coe;
    int power;

    void init()
    {
        Manhattan = ABS(x,0) + ABS(y,0);
    }
};

bool cmp(point a, point b)
{
    if(a.Manhattan == b.Manhattan)
    {
        if(a.x == b.x)
        {
            return(a.y < b.y);
        }
        return(a.x < b.x);
    }
    return(a.Manhattan > b.Manhattan);
}

ull ABS(ll a, ll b)
{
    ull u;
    ll min = (a > b) ? b : a;
    ll max = (a > b) ? a : b;
    u = max - min;
    return u;
}

int main()
{
    int total;
    cin >> total;
    point* P = new point[total];
    for(int i = 0;i < total; i++)
    {
        cin >> P[i].x >> P[i].y;
        P[i].init();
    }
    sort(P,P + total,cmp);

    // for(int i = 0; i < total; i++)
    // {
    //     cout << P[i].x << " x "<<P[i].y << " y " << P[i].Manhattan << endl;
    // }
    ull dx;
    ull dy;
    dx = ABS(P[0].x,P[1].x);
    dy = ABS(P[0].y,P[1].y);
    ull distance = dx + dy;
    cout << distance <<endl;

    point * PP = new point[total - 1];
    int step = 0;
    for(int i = 0; i < total - 1; i++)
    {
        dx =  ABS(P[i].x, P[i + 1].x) ;
        dy =  ABS(P[i].y, P[i + 1].y);
        if(dx % 2 != dy % 2)//判断加起来是不是奇数
        {
            for(int j = 1; j < 64; j++)
            {
                
                if( (dx < (1ULL << j)) && (dx >= (1ULL << (j - 1))) )
                {
                    PP[i].power = j;
                    PP[i].coe = dx / pow(2,j - 1);
                }
                if( (dy < (1ULL << j)) && (dy >= (1ULL << (j - 1))) )
                {
                    P[i].power = j;
                    P[i].coe = dy / pow(2,j - 1);
                }
            }
            ull max = ((P[i].power > PP[i].power) ? P[i].power : PP[i].power);
            ull min = ((P[i].power < PP[i].power) ? P[i].power : PP[i].power);
            step += max;
            //下面判断是否需要再加一
            //幂相同相加要加一
            //什么时候小幂会影响大幂？
            //小幂只小1，且系数/2加大幂系数＞2
            if(P[i].power == PP[i].power)//如果两者的幂相同，加起来的幂就多1
            {   
                step++;
            }
            else if(P[i].power - PP[i].power == 1)
            {
                PP[i].coe /= 2;
                if(PP[i].coe + P[i].coe >= 2)
                step++;
            }
            else if(P[i].power - PP[i].power == -1)
            {
                P[i].coe /= 2;
                if(PP[i].coe + P[i].coe >= 2)
                step++;
            }
            cout << step << endl;
        }
        else
        {
            break;
        }    
    }
    cout << step << endl;

    
    return 0;
}