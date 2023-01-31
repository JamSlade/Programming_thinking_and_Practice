#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> sig;
    int len = s.length();


    bool t = true;
    double data[4];
    double num = 0, unknown = 0;
    double temp = 0;
    char c;
    

    for(int i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case '+':case '-':
            if(sig.empty())
                num += temp;
            else
            {
                if(sig.top() == '+')
                    num += temp;
                else
                    num -= temp;
            }
            
            temp = 0;
            sig.push(s[i]);

            
            break;

        case '0':case '1':case '2':case '3':case '4':
        case '5':case '6':case '7':case '8':case '9':
            temp *= 10;
            temp += s[i] - '0'; 
            break;
        
        case '=':
            if(sig.empty())
                num += temp;
            else
            {
                if(sig.top() == '+')
                    num += temp;
                else
                    num -= temp;
            }
            sig.push('+');

            data[0] = num;
            data[1] = unknown;
            num = 0;unknown = 0;temp = 0;
            break;

        default:
            if(temp == 0)
                temp++;
            if(sig.empty())
            {
                unknown += temp;
            }
            else
            {
                if(sig.top() == '+')
                    unknown += temp;
                        
                else
                    unknown -= temp;
            }
            temp = 0;
            c = s[i];
            break;
            
        }
        //cout << i << endl;
    //cout << data[0]  <<endl << data[1]<<endl << num <<endl<< unknown << endl<<endl;
    }
    if(sig.top() == '+')
        num += temp;
            
    else
        num -= temp;
    //cout << data[0]  <<endl << data[1]<<endl << num <<endl<< unknown << endl<<endl;
    double a = ((data[0] - num) / (-(int)data[1] + (int)unknown));
    if(data[0] - num == 0)
        a = 0;
    printf("%c=%.3f",c,a);
}