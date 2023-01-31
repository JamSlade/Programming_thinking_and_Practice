#include<iostream>
#include<deque>

using namespace std;

int inte[500] = {0};
int sma[500] = {0};

int i_len = 0;
int s_len = 0;

void EXA(int* in, int* sm, int exa)
{
    cout << i_len << endl;//
    // cout << i_len << endl << endl;
    // cout << in[499-i_len+1] << endl << endl;
    for(int j = i_len - 1; j >= 0; j--)
        cout << in[499 - j] <<" ";
    cout << endl;
    cout << '.';
    for(int i = 0; i < s_len; i++)
        cout << sm[i] <<" ";
    cout << endl;

    
    for(int i = s_len - 1; i > 0; i--)
    {
        if(sm[i] >= 10)
        {
            int temp = sm[i] / 10;
            sm[i - 1] += temp;
            sm[i] %= 10;
        }
    }
    if(sma[0] >= 10)
    {
        int temp = sm[0] / 10;
        in[499] += temp;
        sm[0] %= 10;
    }
    //整
    for(int j = 499; j > 499 - i_len + 1; j-- )//注意数组的+1-1
    {
        if(in[j] >= 10)
        {
            int temp = in[j] / 10;
            in[j-1] += temp;
            in[j]%=10;
        }
    }    
    if(in[499 - i_len + 1] >= 10)
    {
        int temp = in[499 - i_len] / 10;
        in[499 - i_len - 1] += temp;
        in[499 - i_len]%=10;
        i_len ++;
    }
    
////

    for(int j = i_len - 1; j >= 0; j--)
        cout << in[499 - j] <<" ";
    cout << endl;
    cout << '.';
    for(int i = 0; i < s_len; i++)
        cout << sm[i] <<" ";
    cout << endl;
    cout << i_len << endl << endl;

////
    if(sm[exa] >= 5)
    {
        sma[exa - 1]++;
         for(int i = exa - 1; i > 0; i--)
        {
            if(sm[i] >= 10)
            {
                int temp = sm[i] / 10;
                sm[i - 1] += temp;
                sm[i] %= 10;
            }
        }
        if(sma[0] >= 10)
        {
            int temp = sm[0] / 10;
            in[499] += temp;
            sm[0] %= 10;
        }
        //整
        for(int j = 0; j < i_len; j++)
        {
            if(in[499 - j] >= 10)
            {
                int temp = in[499 - j] / 10;
                in[499 - j - 1] += temp;
                in[499 - j] %= 10;
            }
        }
        if(in[499 - i_len] >= 10)
        {
            int temp = in[499 - i_len] / 10;
            in[499 - i_len - 1] += temp;
            in[499 - i_len] %= 10;
            i_len++;
        }

    }
    //cout << i_len << endl;//
    cout << i_len << endl << endl;
    for(int j = i_len - 1; j >= 0; j--)
        cout << in[499 - j];
        cout << '.' ;
    for(int i = 0; i < exa; i++)
        cout << sm[i];

}

void s_tra(string s,int*arr)
{
    int point = s.find('.');
    if(point == s.npos)
        return;
    
    int len = s.length();
    for(int i = 0, j = point + 1; j < len; j++,i++)
        sma[i] += s[j] - '0';

    if(s_len < len - point - 1)
        s_len = len-point-1;

    // for(int i = 0; i < s_len; i++)
    //     cout << sma[i] <<" ";
    // cout << endl;
    
}

void i_tra(string s, int * arr)
{
    int point = s.find('.');
    if(point == s.npos)
        point = s.length();
    else if(point == 0)
        if(i_len < 1)
            i_len = 1;
    
    for(int i = 499, j = point - 1; i >= 0 && j >= 0; j--,i--)
        arr[i] += s[j] - '0';
    

    
    
    if(i_len < point )
        i_len = point;
    
    // for(int j = i_len; j >= 0; j--)
    //     cout << arr[499 - j] <<" ";

    // cout << endl;
}

int main()
{

    string a,b;
    int asnum,anum;
    int bsnum,bnum;
    int exact;
    cin >> a >> b >> exact;

    i_tra(a,inte);
    i_tra(b,inte);
    s_tra(a,sma);
    s_tra(b,sma);
    EXA(inte,sma,exact);
    
    //out(inte);
    //sout(sma,exact);
}