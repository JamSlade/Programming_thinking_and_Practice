#include<iostream>

using namespace std;

int R[130];
int main()
{   
    R['I'] = 1, R['V'] = 5, R['X'] = 10, R['L'] = 50, R['C'] = 100, R['D'] = 500, R['M'] = 1000;
    long long flag = 1;
    long long sum = 0;
    string s;
    cin >> s;
    int len = s.length();
    //利用栈的特性来判定正负
    long long* each = new long long[len];
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case '(':
            flag *= 1000;
            break;
        case ')':
            flag /= 1000;
            break;
        
        default:
            each[count++] = flag * R[s[i]];
            break;
        }
    }
    for(int i = 0; i < count; i++)
    {
        if(i == count - 1)
            sum += each[i];
        
        else
            sum += ((each[i] < each[i + 1]) ? -each[i] : each[i]);
    }
    cout << sum;
}