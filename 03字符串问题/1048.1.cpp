#include<iostream>
#include<cstring>
using namespace std;


string Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void trans(string s, int len)
{
    string bin;
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < 8; j++)
        {   
            //cout << "bin " << bin << " s[i] " << (int)s[i] <<" ?? " << s[i] <<" i " << i << endl;
            if(!s[i])
            {
                bin.insert(i * 8,1,'0');
            }
            else
            {
                int temp = s[i] % 2;
                bin.insert(i * 8, 1, '0' + temp);
                s[i] /= 2;
            }
            cout << "bin " << bin << " s[i] " << (int)s[i] << endl;
        }
    }

    int * c = new int[10000];
    memset(c,0,40000);
    int loc = 0;
    int times = 0;
    int blen = bin.length();

    int flag = 0;
    if(blen % 6)
    {
        flag = 1;
        while(blen < 6 * (len + 1))
        {
            bin += '0';
            blen++;
        }
    }
    
    for(int i = 0; i < blen; i++)
    {
        c[loc] *= 2;
        c[loc] += (bin[i] - '0');
        times++;
        if(times == 6)
        {
            times = 0;
            loc++;
        }
    }
    
    for(int i = 0; i < loc; i++)
        {cout << Base64[c[i]];}
    if(flag)
    {
        for(int i = 0; i < 3 - len ;i++)
        {
            cout << "=";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        int len = str.length();
        int group = len / 3;//看有多少组

        int flag = 0;
        if(len % 3)
            flag = len % 3;

        
        cout << "case #" << i << ":"<<endl;

        //put(group * 3,0,str);先把前面的内容搞定好
        trans(str,group * 3);

        if(flag)
        {   
            string s1;
            for(int j = flag; j > 0; j--)
            {
                s1 += str[len - j];//别把j写成flag。。。
            }
            trans(s1,s1.length());
            //put(len, out * 3, str, 1);
        }


        
        cout << endl;
    }

    return 0;
}