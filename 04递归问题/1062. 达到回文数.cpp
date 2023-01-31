#include<iostream>
using namespace std;

void ADD(string & s)
{
    string s1 = s;
    int len = s.length();
    short * SUM = new short[len];
    for(int i = 0, j = len - 1; i < len; i++, j--)
    {
        SUM[i] = s[i] -'0' + s1[j] - '0';
    }
    int carry = 0;
    for(int i = len - 1; i >= 0; i--)
    {
        SUM[i] += carry;
        if(SUM[i] >= 10)
        {
            SUM[i] -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }
    s = "";
    if(carry)
    {
        s += '1';
    }
    for(int i = 0; i < len; i++)
    {
        s += '0' + SUM[i];
    }

    delete[] SUM;
    //cout << s << endl;

}

int main()
{
    string str;
    int n ;
    cin >> n;
    while(n)
    {
        int temp = n % 10;
        str.insert(0,1,temp + '0');
        n /= 10;
    }
    //cout << str;

    int times = 0;
    FLAG:
    int len = str.length();
    for(int i = 1; i <= len / 2; i++)
    {
        if(str[i-1] != str[len - i])
        {
            times++;
            ADD(str);
            goto FLAG;
        }
    }
    cout << times <<" " << str<< endl;

    return 0;
}