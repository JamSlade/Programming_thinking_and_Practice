#include<iostream>
#include<cstring>
using namespace std;
const int N = 2e4;
typedef long long ll;

string alpha = "0123456789ABCDEF";
pair<int,int> complex[16] = 
{
    {0,0},{1,0},{-1,1},{0,1},
    {0,-2},{1,-2},{-1,-1},{0,-1},
    {2,2},{3,2},{1,3},{2,3},
    {2,0},{3,0},{1,1},{2,1}
};

#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

const int MAXN = 1000;

class big
{
public:
    int arr[MAXN];
    int sign;
    int LEN;
    
//public:
    

    big();
    big(string s);
    //big(const char *c);
    big(long long a);

    big &operator=(const big& b);
    big operator+(big &b);
    big operator*(big &b);
    big operator+=(big b);

    bool operator==(int a);
    

    void out();
    void carry();
    void test();


    bool com(ll a);

    bool bigger(const big & b)const
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
    bool ABSbig(const big & b)const
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
    bool small(const big & b)const
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
    bool ABSsmall(const big & b)const
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


};//

void big::test()
{
    cout << sign << " " << LEN << endl;
    out();cout << endl;

}
void big::out()
{
    int l = MAXN - 1;
    while(arr[l] == 0 && l > 0)//注意0的情况
        l--;
    cout << ((sign == 1) ? "" : "-");
    for(;l >= 0; l--)
        cout << arr[l];
    //cout <<endl;
}
void big::carry()
{
    bool flag = 0;

    for(int i = 0; i < this->LEN; i++)
    {
        if(this->arr[i] >= 10)
        {
            this->arr[i + 1] += this->arr[i] / 10;
            this->arr[i] %= 10;
            if(i == LEN - 1)
                LEN++; 
        }
        else if(this->arr[i] < 0)
        {
            while(this->arr[i] < 0)
            {
                this->arr[i + 1]--;
                this->arr[i] += 10;
            }
            flag = 1;
        }
    }
    if(flag)
    {
        while(arr[LEN - 1] == 0 && LEN - 1 >= 0)
            LEN--;
        if(LEN == 0)
            LEN = 1;
    }
    

}//

big::big()
{
    LEN = 1;
    sign = 1;
    memset(arr,0,sizeof(arr));
}
big::big(string s)
{
    memset(arr,0,sizeof(arr));
    LEN = 0;
    int len = s.length();
    for(int i = len - 1; i >= 0; i--)
    {
        switch(s[i])
        {
            case '+':
            sign = 1;break;
            case '-':
            sign = -1;break;
            default:
            arr[LEN++] = s[i] - '0';
            break;
        }
    }
    if(sign != -1)sign = 1;
}
big::big(long long a)
{
    memset(arr,0,sizeof(arr));
    LEN = 0;
    sign = ((a >= 0) ? 1 : -1);

    if(a < 0)
        a = -a;

    while(a)
    {
        arr[LEN++] = a % 10;
        a /= 10;
    }
    if(sign != -1)sign = 1;
}
// big::big(const char *c)
// {
//     memset(arr,0,sizeof(arr));
//     LEN = 0;
//     int len = strlen(c);
//     for(int i = len - 1; i >= 0; i--)
//     {
//         switch(c[i])
//         {
//             case '+':
//             sign = 1;break;
//             case '-':
//             sign = -1;break;
//             default:
//             arr[LEN++] = c[i] - '0';
//         }
//     }
//     if(sign != -1)sign = 1;
// }

big& big::operator=(const big & b)
{
    this->sign = b.sign;
    this->LEN = b.LEN;
    for(int i = 0; i < LEN;i++) 
    {
        this->arr[i] = b.arr[i];
    }
    return *this;
}
big big::operator+(big& b)
{
    
    if(this->sign * b.sign == -1)
    {
        if(b.LEN > this->LEN)
        {
            for(int i = 0; i < b.LEN; i++)
                b.arr[i] -= this->arr[i];
            b.carry();
            return b;
        }
        else if(b.LEN < this->LEN)
        {
            for(int i = 0; i < this->LEN; i++)
                this->arr[i] -= b.arr[i];
            this->carry();
            return *this;
        }
        else
        {
            bool flag = true;
            for(int i = b.LEN - 1; i >= 0; i--)
            {
                if(this->arr[i] > b.arr[i])
                {flag = true;break;}
                else if(this->arr[i] < b.arr[i])
                {flag = false;break;}
            }

            if(flag)
            {
                for(int i = 0; i < this->LEN; i++)
                    this->arr[i] -= b.arr[i];
                this->carry();
                return *this;
            }
            else
            {
                for(int i = 0; i < b.LEN; i++)
                    b.arr[i] -= this->arr[i];
                b.carry();
                return b;
            }
        }
    }
    else
    {   
        int mlen = ((this->LEN > b.LEN) ? this->LEN : b.LEN);
        for(int i = 0; i < mlen; i++)
            this->arr[i] += b.arr[i];
        this->carry();
    }
    return *this;
}
big big::operator*(big &b)
{
    big B;
    B.sign = this->sign * b.sign;
    for(int i = 0; i < b.LEN; i++)
    {
        for(int j = 0; j < this->LEN; j++)
        {
            B.arr[i + j] += this->arr[j] * b.arr[i];
            B.LEN = i + j + 1;//注意长度
            B.carry();
        }
    }
    return B;
}

bool big::operator==(int a)
{
    if(a * sign < 0)
        return false;
    if(a < 0)
        a = -a;


    int alen = 0;
    int dlen = MAXN;
    while(arr[dlen - 1] == 0 && dlen - 1 >= 0)
        dlen--;
    if(dlen == 0)
        dlen++;
    int temp = a;
    if(temp == 0)
        alen = 1;
    while(temp)
    {
        alen++;
        temp/=10;
    }

    if(dlen != alen)
        return false;

    temp = 0;
    for(int i = 0; i < alen; i++)
    {
        if(a % 10 != arr[i])
            return false;
        a/=10;
        temp++;
    }   
    return true;
}
////
void out(big R)
{
    big zero(0);
    if(!R.small(zero) && !R.bigger(zero))
    {
        // if(!I.small(0) && !I.bigger(0))
        //     cout << "0";
        // else if(!I.small(1) && !I.bigger(1))
        //     cout << "i";
        // else if(!I.small(-1) && !I.bigger(-1))
        //     cout << "-i";
        // else
        // {
        //     I.out();
        //     cout << 'i';
        // }
    }
    else
    {
        R.out();
        
    }
    
    
}
void iout(big I)
{
    big zero(0);
    big one(1);
    big neg(-1);
    if(!I.small(zero) && !I.bigger(zero)){}
        else if(!I.small(one) && !I.bigger(one))
            cout << "+i";
        else if(!I.small(neg) && !I.bigger(neg))
            cout << "-i";
        else
        {
            cout << ((I.sign == 1) ? "+" : "");
            I.out();
            cout << 'i';
        }
}


int main()
{
    string s;
    cin >> s;
    int len = s.length();

    big R(complex[alpha.find(s[2])].first);
    big I(complex[alpha.find(s[2])].second);

    for(int i = 3; i < len; i++)
    {
        big four(-4);
        R = R * four;
        I = I * four;
        big _1(complex[alpha.find(s[i])].first);
        R = R + _1;
        big _2(complex[alpha.find(s[i])].second);
        I = I + _2;
    }
    out(R);//
    iout(I);
}