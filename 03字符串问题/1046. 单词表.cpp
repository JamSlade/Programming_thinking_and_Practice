#include<iostream>
#include<set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    getchar();
    for(int i = 0; i < t; i++)
    {
        string a;
        set<string>s;
        char c;
        c = getchar();
        while(c != '\n')
        {   
            int flag = 0;
            while(c != ' ' && c != '.' && c != '?' && c != '!' && c != ',' && c != '\n')
            {
                a += c;
                c = getchar();
                flag = 1;
            }
            
            if(flag)
                s.insert(a);
            a = "";

            if(c != '\n')
            {
                c = getchar();
            }
        }
        cout << "case #" << i << ":" << endl;
        for(set<string>::iterator it = s.begin(); it != s.end(); it++)//
            cout << *it <<" ";
        cout << endl;
    }
    
}