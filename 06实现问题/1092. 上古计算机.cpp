#include<iostream>

using namespace std;
string opera[] = {"IN","MOV","ADD","SUB","MUL","DIV","OUT"};

int main()
{
    
    long long ABCD[10];
    for(int i = 0; i < 10; i++)
        ABCD[i] = 0;
    string s;
    while(getline(cin,s))
    {
        int len = s.length();
        int space = s.find(' ');
        string name = s.substr(0,space);
        int o;
        for(int i = 0; i < 7; i++)
        {
            if(name == opera[i])
                o = i;
        }
        int loc;
        int loc2;
        int flag = 0;
        switch (o)
        {
        case 0:
            
            loc = s[space + 1] - 'A';
            space = s.find(',');
            ABCD[loc] = 0;
            
            while(space < len-1)
            {
                if(s[space+1] == '-')
                {
                    flag = 1;
                    space++;continue;
                }
                ABCD[loc] *= 10;
                ABCD[loc] += s[++space] - '0';
            }
            if(flag)
                ABCD[loc]*=-1;
            //cout << ABCD[loc];
            break;
        case 1:
            
            loc = s[space + 1] - 'A';
            space = s.find(',');
            
            loc2 = s[space + 1] - 'A';
            ABCD[loc] = ABCD[loc2];
            break;
        case 2:
            
            loc = s[space + 1] - 'A';
            space = s.find(',');
            
            loc2 = s[space + 1] - 'A';
            ABCD[loc] += ABCD[loc2];
            break;
        case 3:
            
            loc = s[space + 1] - 'A';
            space = s.find(',');
            
            loc2 = s[space + 1] - 'A';
            ABCD[loc] -= ABCD[loc2];
            break;
        case 4:
            
            loc = s[space + 1] - 'A';
            space = s.find(',');
            
            loc2 = s[space + 1] - 'A';
            ABCD[loc] *= ABCD[loc2];
            break;
        case 5:
            
            loc = s[space + 1] - 'A';
            space = s.find(',');
            
            loc2 = s[space + 1] - 'A';
            ABCD[loc] /= ABCD[loc2];
            break;
        case 6:
            
            loc = s[space + 1] - 'A';
            cout << ABCD[loc]<<endl;
            break;
        default:
            break;
        }
    }
}