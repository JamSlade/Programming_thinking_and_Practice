#include<iostream>

using namespace std;
char com[100];

void print(string & b, int len , int l ,int r)
{
    if(l == r)//如果左右相等了，说明到了字符串的'\0'处
        return;
    for(;l != r; l++)
    {
        com[len] = b[l];//先把一个数字放进去
        com[len + 1] = 0;//下一步放个0
        cout << com << endl;//输出
        print(b,len + 1, l + 1, r);//这部分是a加上下一部分“b”的输出
    }  
}

int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        string a;
        cin >> a;
        int alpha[130] = {0};
        string b;
        for(int i = 0; i < a.length(); i++)
        {
            alpha[a[i]]++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(alpha['A' + i]){b += 'A' + i;}
        }
        for(int i = 0; i < 26; i++)
        {
            if(alpha['a' + i]){b += 'a' + i;}
        }

        cout << "case #" <<i << ":" <<endl;
        int len = b.length();
        print(b,0,0,len);
    }

    return 0;
}