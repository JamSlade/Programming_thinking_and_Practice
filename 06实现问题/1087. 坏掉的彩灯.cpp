#include<iostream>
#include<cstring>
using namespace std;


void func(string & s)
{
    int light[130];
    memset(light, 0 , sizeof(light));

    int len = s.length();
    int i,j,k,l;
    i = j = k = l = 0;

    while(i < len && s[i] != 'R')
        i++;
    while(j < len && s[j] != 'B')
        j++;
    while(k < len && s[k] != 'Y')
        k++;
    while(l < len && s[l] != 'G')
        l++;


    if(i == len)
    {
        j%=4;k%=4;l%=4;
        i = 6 - j - k - l;
    }
    if(j == len)
    {
        i%=4;k%=4;l%=4;
        j = 6 - i - k - l;
    }
    if(k == len)
    {
        j%=4;i%=4;l%=4;
        k = 6 - j - i - l;
    }
    if(l == len)
    {
        j%=4;k%=4;i%=4;
        l = 6 - j - k - i;
    }
    
    i%=4;j%=4;k%=4;l%=4;
    //cout << i<<'R' << j <<'B'<< k<<'y' << l<<"g" <<endl;

    for(;i < len || j < len || k < len || l < len; i+=4, j+=4, k+=4, l+=4)
    {
        if(s[i] != 'R' && i < len)
            light['R']++;
        if(s[j] != 'B' && j < len)
            light['B']++;
        if(s[k] != 'Y' && k < len)
            light['Y']++;
        if(s[l] != 'G' && l < len)
            light['G']++;
    }
    cout << light['R'] << " " << light['B'] << " " << light['Y'] << ' ' << light['G'] << endl;

}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {

        cout << "case #" << i << ":"<<endl;
        string s;
        cin >> s;
        func(s);
    }

    return 0;
}

