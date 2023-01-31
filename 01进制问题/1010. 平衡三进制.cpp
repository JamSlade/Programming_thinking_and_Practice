#include<iostream>
#include<string>
using namespace std;

//×ÖÄ¸±íÓ³Éä

void Ternary(string a)
{
    
    int len = a.length();
    int num = 0;
    int Alp [130];
    Alp['0'] = 0;
    Alp['1'] = 1;
    Alp['-'] = -1;
    for(int i = 0; i < len; i++)
    {
        num *= 3;
        num += Alp[ a[i] ];
    }
    cout << num << endl;
}

int main()
{
    int total;
    cin >> total;

    for(int i = 0 ; i < total; i++)
    {
        string a;
        cin >> a;
        cout << "case #" << i<<":"<<endl;
        Ternary(a);
    }
    
}