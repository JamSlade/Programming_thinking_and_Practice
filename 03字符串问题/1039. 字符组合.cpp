#include<iostream>

using namespace std;

void print(string b)
{
    
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
            if(alpha['a' + i]){b += 'a' + i;}
        }

        cout << "case #" <<i << ":" <<endl;
        print(b);
    }

    return 0;
}