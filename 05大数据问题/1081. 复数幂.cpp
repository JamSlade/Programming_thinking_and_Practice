#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;

const int MAXN = 3000;

class big
{
public:
    int dig[MAXN];
    int sign;
    int LEN;
    
//public:
    

    big();
    big(string s);
    big(const char *c);
    big(long long a);

    big &operator=(const big& b);
    big operator+(big b);
    big operator*(big b);
    big operator+=(big b);

    bool operator==(int a);
    

    void out();
    void carry();
    void test();


    bool com(long long a);

};//

void big::test()
{
    cout << sign << " " << LEN << endl;
    out();cout << endl;

}
void big::out()
{
    int l = MAXN - 1;
    while(dig[l] == 0 && l > 0)//注意0的情况
        l--;
    cout << ((sign == 1) ? "" : "-");
    for(;l >= 0; l--)
        cout << dig[l];
    //cout <<endl;
}
void big::carry()
{
    bool flag = 0;

    for(int i = 0; i < this->LEN; i++)
    {
        if(this->dig[i] >= 10)
        {
            this->dig[i + 1] += this->dig[i] / 10;
            this->dig[i] %= 10;
            if(i == LEN - 1)
                LEN++; 
        }
        else if(this->dig[i] < 0)
        {
            while(this->dig[i] < 0)
            {
                this->dig[i + 1]--;
                this->dig[i] += 10;
            }
            flag = 1;
        }
    }
    if(flag)
    {
        while(dig[LEN - 1] == 0 && LEN - 1 >= 0)
            LEN--;
        if(LEN == 0)
            LEN = 1;
    }
    

}//

big::big()
{
    LEN = 1;
    sign = 1;
    memset(dig,0,sizeof(dig));
}
big::big(string s)
{
    memset(dig,0,sizeof(dig));
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
            dig[LEN++] = s[i] - '0';
            break;
        }
    }
    if(sign != -1)sign = 1;
}
big::big(long long a)
{
    memset(dig,0,sizeof(dig));
    LEN = 0;
    sign = ((a >= 0) ? 1 : -1);

    if(a < 0)
        a = -a;

    while(a)
    {
        dig[LEN++] = a % 10;
        a /= 10;
    }
    if(sign != -1)sign = 1;
}
big::big(const char *c)
{
    memset(dig,0,sizeof(dig));
    LEN = 0;
    int len = strlen(c);
    for(int i = len - 1; i >= 0; i--)
    {
        switch(c[i])
        {
            case '+':
            sign = 1;break;
            case '-':
            sign = -1;break;
            default:
            dig[LEN++] = c[i] - '0';
        }
    }
    if(sign != -1)sign = 1;
}

big& big::operator=(const big & b)
{
    this->sign = b.sign;
    this->LEN = b.LEN;
    for(int i = 0; i < LEN;i++) 
    {
        this->dig[i] = b.dig[i];
    }
    return *this;
}
big big::operator+(big b)
{
    
    if(this->sign * b.sign == -1)
    {
        if(b.LEN > this->LEN)
        {
            for(int i = 0; i < b.LEN; i++)
                b.dig[i] -= this->dig[i];
            b.carry();
            return b;
        }
        else if(b.LEN < this->LEN)
        {
            for(int i = 0; i < this->LEN; i++)
                this->dig[i] -= b.dig[i];
            this->carry();
            return *this;
        }
        else
        {
            bool flag = true;
            for(int i = b.LEN - 1; i >= 0; i--)
            {
                if(this->dig[i] > b.dig[i])
                {flag = true;break;}
                else if(this->dig[i] < b.dig[i])
                {flag = false;break;}
            }

            if(flag)
            {
                for(int i = 0; i < this->LEN; i++)
                    this->dig[i] -= b.dig[i];
                this->carry();
                return *this;
            }
            else
            {
                for(int i = 0; i < b.LEN; i++)
                    b.dig[i] -= this->dig[i];
                b.carry();
                return b;
            }
        }
    }
    else
    {   
        int mlen = ((this->LEN > b.LEN) ? this->LEN : b.LEN);
        for(int i = 0; i < mlen; i++)
            this->dig[i] += b.dig[i];
        this->carry();
    }
    return *this;
}
big big::operator*(big b)
{
    big B;
    B.sign = this->sign * b.sign;
    for(int i = 0; i < b.LEN; i++)
    {
        for(int j = 0; j < this->LEN; j++)
        {
            B.dig[i + j] += this->dig[j] * b.dig[i];
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
    while(dig[dlen - 1] == 0 && dlen - 1 >= 0)
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
        if(a % 10 != dig[i])
            return false;
        a/=10;
        temp++;
    }   
    return true;
}



void out(big R, big I)
{
    if(R==0)
    {
        if(I==0)
            cout << "0";
        else if(I==1)
            cout << "i";
        else if(I==-1)
            cout << "-i";
        else
        {
            I.out();
            cout << 'i';
        }
    }
    else
    {
        R.out();
        if(I==0){}
        else if(I==1)
            cout << "+i";
        else if(I==-1)
            cout << "-i";
        else
        {
            cout << ((I.sign == 1) ? "+" : "");
            I.out();
            cout << 'i';
        }
    }
    
    
}


int main()
{
    string s;
    cin >> s;
    int power;
    cin >> power;

    int len = s.length();
    string a;
    string b;
    string temp;
    //有i 无i i只有一个
    //无实数
    for(int i = 0; i < len; i++)
    {
        switch(s[i])
        {
            case('i'):
            b = temp;b+='i';break;
            case('+'):
            a = temp;
            temp = "";break;
            case('-'):
            a = temp;
            temp = "";temp+=s[i];break;
            default:
            temp += s[i];
        }
    }
    if(b == "-i")
        b ="-1";
    else if(b == "i")
        b ="1";
    else if(b == "")
        b ="0";
    if(a == "")
        a = "0";

    big A(a); big B(b);
    big C(a); big D(b);

    if(power == 0)
        cout << "1";
    else if(power == 1)   
        out(A,B);
    else
    {
        
        for(int i = 1; i < power; i++)
        {
            big t(-1);
            big ta = A;
            big tb = B;
            A = ta*C + tb*D*t;
            B = tb*C + ta*D;
        }
        out(A,B);
    }

}