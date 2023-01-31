#include<iostream>
#include<math.h>
using namespace std;

int alpha[130];

long long gcd(long long a,long long b)
{
    long long max = (a > b) ? a : b;
    long long min = (a < b) ? a : b;
    while(max % min)
    {
        long long temp = max % min;
        max = min;
        min = temp;
    }
    return min;
}

void trans(string a)
{
    int len = a.length();
    int flag = 0;
    int power;
    int p_flag = 1;
    for(int i = 0; i < len; i++)
    {
        if(a[i] == '.')
        {
            power = i - 1;//哎，写题目注意点
            p_flag = 0;
        }
    }
    if(p_flag){power = len - 1;}//同上

    long long integer = 0;
    long long molecule = 0;
    long long denominator = 1;

    for(int i = 0; i < len; i++)
    {
        if(a[i] == '.')
        {
            flag = 1;
            power = a.length() - a.find('.');
            for(int j = 1; j < power; j++)//同上
            {
                denominator *= 3;
            }
            continue;
        }

        if(!flag)
        {
            long long temp = 1;
            for(int j = 0 ; j < power; j++)//一样
            {
                temp *= 3;
            }
            temp *= alpha[ a[i] ];
            integer += temp;
            power--;
            
            
        }
        else
        {
            
            molecule *= 3;
            molecule += alpha[ a[i] ];
            
        }
        
    }
    //测试是否有正数和分数
    int is_int = 0;
    
    if(integer){is_int = 1;}
    if(flag == 1)//处理小数公因数
    {
        
        int GCD = gcd(llabs(molecule),llabs(denominator));
        molecule /= GCD;
        denominator /= GCD;
        
    }
    //  处理正负问题
    if(integer > 0 && molecule > 0);
    else if(integer < 0 && molecule < 0)
    {molecule = -molecule;}
    else if(integer > 0 && molecule < 0)
    {
        integer--;
        molecule += denominator;
    }
    else if(integer < 0 && molecule > 0)
    {
        integer++;
        molecule = denominator - molecule;
    }


    //输出问题
    if(integer)
    {
        cout << integer <<" ";
    }
    if(flag)
    {
        cout << molecule <<" " << denominator;
    }

}

int main()
{
    alpha['2'] = -1;
    alpha['0'] = 0;
    alpha['1'] = 1;

    string a;
    cin >> a;
    if(a == "0")
    {cout << 0;
    return 0;}
    trans(a);
    return 0;
}