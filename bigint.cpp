#include<iostream>
#include<cctype>
#include<cstring>

typedef long long ll;
const int N = 1000;
using namespace std;

struct bigint
{
    int arr[N];
    int sign;

    bigint()
    {
         memset(arr,0,sizeof(arr));
         sign = 0;
    }
    bigint(ll a)
    {
        memset(arr,0,sizeof(arr));
        if(a == 0)
            sign = 0;
        else if(a < 0)
        {
            sign = -1;
            a = -a;
        }
        else
            sign = 1;
        int len = 0;
        while(a)
        {
            arr[len++] = a % 10;
            a /= 10;
        }
    }
    bigint(string s)
    {
        memset(arr,0,sizeof(arr));
        int len = 0;
        int l = s.length();

        if(s[0] == '-')
            sign = -1;
        else if(s[0] == '0')
            sign = 0;
        else
            sign = 1;

        for(int i = l - 1; i >= 0; i--)
        {
            if(s[i] == '-')
                sign = -1;
            else
            {
                arr[len++] = s[i] - '0';
            }
        }
    }
    bigint(const bigint & b)
    {
        memset(arr,0,sizeof(arr));
        sign = b.sign;
        for(int i = 0; i < N ;i ++)
            arr[i] = b.arr[i];
    }

    bool big(const bigint & b)const
    {
        if(sign > b.sign)
            return true;
        else if(sign < b.sign)
            return false;
        else 
        {
            if(sign == 1)
            {
                for(int i = N - 1; i >= 0; i--)
                {
                    if(arr[i] > b.arr[i])
                        return true;
                    else if(arr[i] < b.arr[i])
                        return false;
                }
                
                return false;
            }
            else if (sign == -1)
            {
                for(int i = N - 1; i >= 0; i--)
                {
                    if(arr[i] < b.arr[i])
                        return true;
                    else if(arr[i] > b.arr[i])
                        return false;
                }
                return false;
            }
            
        }
    }
    bool ABSbig(const bigint & b)const
    {
        for(int i = N - 1; i >= 0; i--)
        {
            if(arr[i] > b.arr[i])
                return true;
            else if(arr[i] < b.arr[i])
                return false;
        }
        
        return false;
    }
    bool small(const bigint & b)const
    {
        if(sign > b.sign)
            return false;
        else if(sign < b.sign)
            return true;
        else 
        {
            if(sign == 1)
            {
                for(int i = N - 1; i >= 0; i--)
                {
                    if(arr[i] > b.arr[i])
                        return false;
                    else if(arr[i] < b.arr[i])
                        return true;
                }
                
                return false;
            }
            else if (sign == -1)
            {
                for(int i = N - 1; i >= 0; i--)
                {
                    if(arr[i] < b.arr[i])
                        return false;
                    else if(arr[i] > b.arr[i])
                        return true;
                }
                return false;
            }
            
        }
    }
    bool ABSsmall(const bigint & b)const
    {
        for(int i = N - 1; i >= 0; i--)
        {
            if(arr[i] > b.arr[i])
                return false;
            else if(arr[i] < b.arr[i])
                return true;
        }
        return false;
    }

    bigint operator+(const bigint & b)
    {
        bigint t(*this);
        if(sign * b.sign > 0)
        {
            for(int i = 0; i < N; i++)
                t.arr[i] += b.arr[i];
        }
        if(sign == 0)
            return b;
        if(b.sign == 0)
            return t;
        else if(ABSbig(b))
        {
            t.sign = sign;
            for(int i = 0; i < N; i++)
                t.arr[i] = arr[i]-b.arr[i];
        }
        else if(ABSsmall(b))
        {
            t.sign = -sign;
            for(int i = 0; i < N; i++)
                t.arr[i] = b.arr[i] - arr[i];
        }
        else
        {
            memset(t.arr,0,sizeof(t.arr));
        }
        t.carry();
        return t;
    }
    bigint operator*(const bigint & b)
    {
        bigint t(*this);
        memset(t.arr,0,sizeof(t.arr));
        t.sign = sign * b.sign;
        for(int i = 0; i < N - 1; i++)
            for(int j = 0; j + i < N - 1; j++)
            {
                t.arr[i+j] += arr[i] * b.arr[j];
                //t.carry();
            }

        t.carry();
        return t;
    }
    bigint& operator=(const bigint &b)
    {
        
        for(int i = 0; i < N; i++)
            arr[i] = b.arr[i];
        sign = b.sign;
        return *this;
    }

    void carry()
    {
        for(int i = 0; i < N; i++)
        {
            if(arr[i] < 0)
            {
                while(arr[i] < 0)
                {
                    arr[i + 1] -= 1;
                    arr[i] += 10;
                }
            }
            else if(arr[i] >= 10)
            {
                arr[i + 1] += arr[i] / 10;
                arr[i] %= 10;
            }
        }
    }
    void print()
    {
        cout << ((sign == -1)?"-":"");
        int l = N -1;
        while(arr[l] == 0 && l > 0)
            l--;
        
        while(l >= 0)
            cout << arr[l--]; 
    }
};


int main()
{
    bigint b("2");
    bigint a(-2);
    int i = 10;
    while(i--)
    {
        b = a*b;
        b.print();//cout<<endl;
    }
}