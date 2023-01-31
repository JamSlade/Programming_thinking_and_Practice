#include<iostream>
#include<cstring>

using namespace std;

int alpha[130];

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int loc = 0;
    int l = 1;
    int k = 0;
    for(int i = 0; i < len; i++)
    {
        memset(alpha, 0, sizeof(alpha));
        k = 0;
        for(int j = i; j < len && k < 70; j++,k++)
        {
            
            if(alpha[s[j]] > 0)
            {
                if(k > l)
                {
                    l = k;
                    loc = i;
                }
                break;
            }
            alpha[s[j]]++;
        }
        if(k > l)
        {
            l = k;
            loc = i;
        }
    }
    for(int i = loc, j = 0; j < l; j++)
    {
        cout << s[i + j];
    }
}