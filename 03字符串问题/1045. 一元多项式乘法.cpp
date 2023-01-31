#include<iostream>
#define ll long long
using namespace std;

void calco(char * c, ll * co)
{
    while(*c)
    {
        ll sig = 1, coefficient = 0, power = 0; 
        if(*c == '-')
        {c++; sig = -1;}
        else if(*c == '+')
        {c++;}//处理完符号之后可能会出现的情况
        //数字 // 要判定是系数还是幂还是常数
        while(*c >= '0' && *c <= '9')
        {
            coefficient *= 10;
            coefficient += (*c) - '0';
            c++;
        }
        //搞定好符号之后的数字后有几种情况
        //有x -》系数
        //没x 常数，可以直接返回了
        //当然如果没有数字就认为c是1；

        if(*c == '\0')//认为是常数数字
        {
            co[0] = coefficient * sig;
            return;
        }
        else if(*c == 'x')
        {
            if(!coefficient)
            {coefficient = 1;}
            c++;
            if(*c == '^')//顺便把系数解决掉
            {
                c++;
                while(*c >= '0' && *c <= '9')
                {
                    power *= 10;
                    power += (*c) - '0';
                    c++;
                }
            }
            else
                power = 1;

            co[power] = coefficient * sig;
        }

    }
}

void multiply(char * c1, char * c2, ll * arr)
{
    ll co1[1000] = {0};
    ll co2[1000] = {0};
    calco(c1,co1);
    calco(c2,co2);


    for(ll i = 0; i < 500; i++)
    {
        for(ll j = 0; j < 500; j++)
        {
            arr[i + j] += co1[i] * co2[j]; 
        }
    }
}

int main()
{
    char s1[1000] = {0}, s2[1000] = {0};
    while((scanf("%s %s",s1,s2)) == 2)
    {
        ll coefficient[1000] = {0};
        ll out[1000] = {0};
        multiply(s1,s2,coefficient);
        ll sig = 0;
        for(ll i = 0; i < 1000; i++)
        {
            if(coefficient[i])
                out[sig++] = coefficient[i];
        }

        for(ll i = sig - 1; i >= 0; i--)//从后往前，别忘记++变--
            cout << out[i] << " ";
        cout << endl;

    }
}