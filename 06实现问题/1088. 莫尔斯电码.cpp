#include<iostream>
#include<bits/stdc++.h>

using namespace std;
map<string,char> m;

void init()
{
    m[".-"]='A';    m["-..."]='B';  m["-.-."]='C';  m["----."]='9';
    m["-.."]='D';   m["."]='E';     m["..-."]='F';  m["--."]='G';
    m["...."]='H';  m[".."]='I';    m[".---"]='J';  m["-.-"]='K';
    m[".-.."]='L';  m["--"]='M';    m["-."]='N';    m["---"]='O';
    m[".--."]='P';  m["--.-"]='Q';  m[".-."]='R';   m["..."]='S';
    m["-"]='T';     m["..-"]='U';   m["...-"]='V';  m[".--"]='W';
    m["-..-"]='X';  m["-.--"]='Y';  m["--.."]='Z';  m["-----"]='0';
    m[".----"]='1'; m["..---"]='2'; m["...--"]='3'; m["....-"]='4';
    m["....."]='5'; m["-...."]='6'; m["--..."]='7'; m["---.."]='8';
    m["/////"]='.'; m["///"]=' ';
    
}

int main()
{
    int t;
    cin >> t;getchar();
    init();
    for(int i = 0; i < t; i++)
    {
        string s;
        string search = "";
        getline(cin,s);
        int len = s.length();
        cout << "case #" << i << ":"<<endl;
        for(int j = 0; j < len; j++)
        {
            if(s[j] != '/')
            {
                search += s[j];
            }
            else
            {
                for(auto x : m)
                    if(search == x.first)
                        cout << x.second;
                
                //cout << search << endl << endl;
                search = "";
                while(s[j] == '/' && j < len)
                    search += s[j++];
                for(auto x : m)
                    if(search == x.first)
                        cout << x.second;
                
                //cout << search << endl << endl;
                search = "";j--;
            }
        }
        for(auto x : m)
            if(search == x.first)
                cout << x.second;
        
        
        cout << endl;
    }

    return 0;
}

