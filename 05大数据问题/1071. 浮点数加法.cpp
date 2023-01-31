#include<iostream>

using namespace std;

int inte[500] = {0};
int sma[500] = {0};

int i_len = 0;
int s_len = 0;

void EXA(int*in, int* sm, int exa)
{
    i_len--;//注意数组的界
    for(int i = s_len - 1; i > 0; i--)
    {
        if(sm[i] >= 10)
        {
            sm[i - 1] += sm[i] / 10;
            sm[i] %= 10;
        }
    }
    if(sm[0] >= 10)
    {
        in[499] += sm[0] / 10;
        sm[0] %= 10;
    }
    for(int j = 499; j > 499 - i_len + 1; j--)
    {
        if(in[j] >= 10)
        {
            in[j - 1] += in[j] / 10;
            in[j] %= 10; 
        }
    }
    if(in[499 - i_len] >= 10)
    {
        in[499 - i_len - 1] += in[499 - i_len] / 10;
        in[499 - i_len] %= 10;
        i_len++;
    }
    //cout << i_len << endl;

/*
    for(int i = 0; i < s_len; i++)
        cout << sma[i] <<" ";
    cout << endl;*/

    // for(int j = i_len; j >= 0; j--)
    //     cout << in[499 - j] <<" ";

    // cout << endl;

    if(sm[exa] >= 5)
        sm[exa - 1]++;
    for(int i = s_len - 1; i > 0; i--)
    {
        if(sm[i] >= 10)
        {
            sm[i - 1] += sm[i] / 10;
            sm[i] %= 10;
        }
    }
    if(sm[0] >= 10)
    {
        in[499] += sm[0] / 10;
        sm[0] %= 10;
    }
    for(int j = 499; j > 499 - i_len; j--)
    {
        if(in[j] >= 10)
        {
            in[j - 1] += in[j] / 10;
            in[j] %= 10; 
        }
    }
    if(in[499 - i_len] >= 10)
    {
        in[499 - i_len - 1] += in[499 - i_len] / 10;
        in[499 - i_len] %= 10;
        i_len ++;
    }

    //cout << i_len << endl;
    for(int j = i_len; j >= 0; j--)
        cout << in[499 - j];
    cout << ".";
    for(int i = 0; i < exa; i++)
        cout << sma[i];
    
    
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

/*
    for(int i = 0; i < s_len; i++)
        cout << sma[i] <<" ";
    cout << endl;*/
    
}

void i_tra(string s, int * arr)
{
    while(s[0] == '0')
        s.erase(0,1);//开头为0是真的离谱

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
    int exact;
    cin >> a >> b >> exact;

    i_tra(a,inte);
    i_tra(b,inte);
    s_tra(a,sma);
    s_tra(b,sma);
    EXA(inte,sma,exact);
}