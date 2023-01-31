#include<iostream>

using namespace std;

int main()
{
    
    string a;
    char c = getchar();
    while(c != EOF)
    {
        if(c >= 'a' && c <= 'z')
        {
            c -= 'a';
            c += 'A';
        }
        if(a.empty())
        {
            a += c;
        }
        else
        {
            if(c >= a[0])
            {
                a.insert(0,1,c);
            }
            else
            {
                a += c;
            }
        }
        c = getchar();
    }
    cout << a <<endl;

    return 0;
}