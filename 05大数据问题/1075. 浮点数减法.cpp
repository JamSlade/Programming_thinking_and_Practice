#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

struct BIG
{
    string s;
    int in[500];
    int i_l;
    int sm[500];
    int s_l;
    int point;

    void loc()
    {
        point = s.find('.');
        if(point == 0)//没有整数
           point = 1;
        if(point == s.npos)//没有小数
            point = s.length();
    }

    void init()
    {
        memset(in,0,sizeof(in));
        memset(sm,0,sizeof(sm));


        for(int i = 0; i < point; i++)
        {
            if(s[0] == '.')
            {
                break;
            }
            in[i] = s[point - i - 1] - '0';
        }
        this->i_l = point;


        int len = s.length();
        for(int i = point + 1,j = 0; i < len; i++,j++)
        {
            sm[j] = s[i] - '0';
        }
        this->s_l = len - point - 1;


        // for(int i = point - 1; i >=0; i--)
        // {cout << in[i];}
        // cout << ".";
        // for(int i = 0; i < len - point - 1; i++)//p的位置是往前挪了一位，所以要-1
        // cout << sm[i];
        // cout << endl;//
    }
};


void sub(BIG&a, BIG&b, deque<char>&D, int i_len, int s_len, int exa)
{
    for(int i = 0; i < s_len; i++)
            a.sm[i] -= b.sm[i];
        
        for(int i = 0; i < i_len; i++)
            a.in[i] -= b.in[i];

        for(int i = s_len - 1; i > 0 ; i--)
            while(a.sm[i] < 0)
            {
                a.sm[i] += 10;
                a.sm[i - 1] --;
            }
        if(a.sm[0] < 0)
        {
            a.sm[0]+=10;
            a.in[0]--;
        }

        for(int i = 0; i < i_len; i++)
            while(a.in[i] < 0)
            {
                a.in[i] += 10;
                a.in[i + 1]--;
            }

        //四舍五入
        if(a.sm[exa] >= 5)
            {a.sm[exa - 1]++;}
        for(int i = exa - 1; i > 0; i--)
        {
            if(a.sm[i] >= 10)
            {
                a.sm[i] -= 10;
                a.sm[i - 1]++;
            }
        }
        if(a.sm[0] >= 10)
        {
            a.sm[0]-=10;
            a.in[0]++;
        }
        for(int i = 0; i < i_len - 1; i++)
            if(a.in[i] >= 10)
            {
                a.in[i] -= 10;
                a.in[i + 1]++;
            }
        
        if(a.in[i_len - 1] >= 10)
        {   
            a.in[i_len - 1] -= 10;
            a.in[i_len]++;
            i_len++;
        }
        
        // cout << i_len << endl;
        // cout << a.in[0 ] << " a.in " << endl;
        for(int i = i_len - 1; i >= 0; i--)
            D.push_back(a.in[i] + '0');
        D.push_back('.');
        for(int i = 0; i < exa; i++)
            D.push_back(a.sm[i] + '0');
        
        while(D.front() == '0')
            D.pop_front();
        if(D.front() == '.')
            D.push_front('0');

    return;
}



deque<char> MINUS(BIG& a, BIG& b, int exa)
{
    deque<char> D;
    int i_len = (a.i_l > b.i_l) ? a.i_l : b.i_l;
    int s_len = (a.s_l > b.s_l) ? a.s_l : b.s_l;

    int A = 0;
    int B = 0;
    for(int i = i_len - 1; i >= 0; i--)
    {
        if(a.in[i] > b.in[i])
        {
            A = 1;
            break;
        }//
        if(a.in[i] < b.in[i])
        {
            B = 1;
            break;
        }
    }
    if(!A && !B)
    {
        for(int i = 0; i < s_len; i++)
        {
            if(a.sm[i] < b.sm[i])
            {
                B = 1;
                break;
            }
            if(a.sm[i] > b.sm[i])
            {
                A = 1;
                break;
            }
        }
    }


    //cout << A << endl << B << endl;


    if(!A && !B)
    {
        D.push_front('0');
        D.push_back('.');
        for(int i = 0; i < exa; i++)
        D.push_back('0');
    }
    if(A)
    {
        sub(a,b,D,i_len,s_len,exa);
    }
    if(B)
    {
        sub(b,a,D,i_len,s_len,exa);
        D.push_front('-');
    }
    
    return D;
}

int main()
{
    int sm[500];
    int sm1[500];
    int in[500];
    int in1[500];

    int exa;
    BIG a;
    BIG b;
    while(cin >> a.s >> b.s >> exa)
    {
        a.loc(),b.loc();
        a.init(),b.init();
        deque<char> D = MINUS(a,b,exa);   
        for(auto it = D.begin(); it != D.end(); it++)
            cout << *it;
        cout << endl;
    }
    return 0;
}