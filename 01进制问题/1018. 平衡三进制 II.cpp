#include<iostream>
#include<deque>
using namespace std;

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

void trans(long long dec, long long denominator)
{   
    
    deque<char> inte;
    deque<char> small;
    int alpha[130];
    alpha['1'] = 1;
    alpha['0'] = 0;
    alpha['0'-1] = 2;

    //处理输入的数据
    long long remainder = dec % denominator;
    long long molecule;
    dec /= denominator;
    int point = 0;
    if(remainder)//顺便判断是否需要小数点
    {
        molecule = remainder;
        long long GCD = gcd(molecule,denominator);
        denominator /= GCD;
        molecule /= GCD;
        point = 1;
    }


    
    if(!dec){inte.push_back('0');}
    else
    {
        while(dec)
        {
            long long temp = dec % 3;
            inte.push_back(temp + '0');
            dec /= 3;
            //cout << temp;
            //7是21，但放入的是12
        }
        //cout << "   put dec " <<inte.size()<< endl;
    }
    

    int d_len = inte.size();
    int s_len = -1;//测量小数点长度，如果是1，其实就是0，也就是不需要小数点
    if(point)
    {
        while(denominator)
        {
            denominator /= 3;//3要除2次所以对应的数就是1了；
            s_len++;
        }
    }

    if(s_len > 0)//把小数放进去
    {
        for(int i = 0; i < s_len; i++)
        {
            int temp = molecule % 3 ;
            molecule /= 3;
            small.push_back(temp + '0');//放进尾巴出来也要从尾巴拿出来
            //比如 7 / 27  = 2/9 + 1/27
            //对应7mod 3 = 1，2 mod 3 = 2,那么就放120，但是对应的字是 .021
            //cout << temp;//
        }
        //cout <<" put  s_len" << endl;
    }
    
    //第二步
    int carry = 0;
    if(s_len > 0)
    {
        for(int i = 0; i < s_len; i++)
        {
            char temp = small.front() + 1 + carry;
            if(temp >= '3')
            {
                temp -= 3;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            small.push_back(temp);
            small.pop_front();
            
           // cout << temp ;
        }
        //cout << " trans one s" << endl;
    }
    
    for(int i = 0; i < d_len; i++)
    {//加应该从前往后而不是从后往前
        char temp = inte.front() + carry + 1;
        //cout <<"carry "<< carry <<" temp "<<temp<<" back "<<inte.back() << endl;;
        if(temp >= '3')
        {
            carry = 1;
            temp -= 3;
        }
        else
        {carry = 0;}
        inte.push_back(temp);
        inte.pop_front();
        //cout << temp ;
    }   
    
    if(carry)
    {
        inte.push_back('2');
        d_len++;
    }
        //cout << "  trans one d" << endl;
    //第三步/
    if(s_len > 0)
    {//减无所谓前后
        for(int i = 0; i < s_len; i++)
        {
            char temp = small.back() - 1;

            small.push_front(temp);
            small.pop_back();
            //cout << temp;
            
        }
        //cout << "trans two s" << endl;
    }
    for(int i = 0; i < d_len; i++)
    {
        char temp = inte.back() - 1;
        
        inte.push_front(temp);
        inte.pop_back();
        //cout << temp;
    }
    //cout << "trans two d" << endl;

    //输出
    for(int i = 0; i < d_len; i++)
    {
        cout << alpha[inte.back()];
        inte.pop_back();
    }
    if(s_len > 0)
    {
        cout << ".";
        for(int i = 0; i < s_len;i++)
        {
            cout<<alpha[small.back()];
            small.pop_back();
        }
    }


}

int main()
{
    long long dec;
    long long base;

    
    cin >> dec >> base;
    
    trans(dec,base);

    return 0;
}