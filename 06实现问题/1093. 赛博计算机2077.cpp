#include<iostream>

using namespace std;
string opera[] = {"IN","OUT","MOV","XCHG","ADD","SUB","MUL","DIV","MOD","AND","OR","XOR"};

int main()
{
    long long ABCD[30];
    for(int i = 0; i < 30; i++)
        ABCD[i] = 0;
    string s;
    while(getline(cin,s))
    {
        int len = s.length();
        int space = s.find(' ');
        string name = s.substr(0,space);
        int o;
        for(int i = 0; i < 12; i++)
        {
            if(name == opera[i])
                o = i;
        }

        int loc;
        int loc2;
        int loc3;
        int flag = 0;
        long long temp = 0;
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
            break;


            case 1:
                loc = s[space + 1] - 'A';
                cout << ABCD[loc]<<endl;
            break;

            case 2:
                loc = s[space + 1] - 'A';
                space = s.find(',');
                
                loc2 = s[space + 1] - 'A';
                ABCD[loc] = ABCD[loc2];
            break;

            case 3:
                loc = s[space + 1] - 'A';
                space = s.find(',');
                
                loc2 = s[space + 1] - 'A';
                temp = ABCD[loc];
                ABCD[loc] = ABCD[loc2];
                ABCD[loc2] = temp;
            break;

            case 4:
                loc = s[space + 1] - 'A';
                space = s.find(',');
                loc2 = s[space + 1] - 'A';
                space = s.find(',',space + 1);
                if(space == s.npos)
                {
                    ABCD[loc] += ABCD[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    ABCD[loc] = ABCD[loc2] + ABCD[loc3];
                }
            break;

            case 5:
                loc = s[space + 1] - 'A';
                space = s.find(',');
                loc2 = s[space + 1] - 'A';
                space = s.find(',',space + 1);
                if(space == s.npos)
                {
                    ABCD[loc] -= ABCD[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    ABCD[loc] = ABCD[loc2] - ABCD[loc3];
                }
            break;

            case 6:
                loc = s[space + 1] - 'A';
                space = s.find(',');
                loc2 = s[space + 1] - 'A';
                space = s.find(',',space + 1);
                if(space == s.npos)
                {
                    ABCD[loc] *= ABCD[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    ABCD[loc] = ABCD[loc2] * ABCD[loc3];
                }
            break;

            case 7:
                loc = s[space + 1] - 'A';
                space = s.find(',');
                loc2 = s[space + 1] - 'A';
                space = s.find(',',space + 1);
                if(space == s.npos)
                {
                    ABCD[loc] /= ABCD[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    ABCD[loc] = ABCD[loc2] / ABCD[loc3];
                }
            break;

            case 8:
                loc = s[space + 1] - 'A';
                space = s.find(',');
                loc2 = s[space + 1] - 'A';
                space = s.find(',',space + 1);
                if(space == s.npos)
                {
                    ABCD[loc] %= ABCD[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    ABCD[loc] = ABCD[loc2] % ABCD[loc3];
                }
            break;

            case 9:
                loc = s[space + 1] - 'A';
                space = s.find(',');
                loc2 = s[space + 1] - 'A';
                space = s.find(',',space + 1);
                if(space == s.npos)
                {
                    ABCD[loc] &= ABCD[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    ABCD[loc] = ABCD[loc2] & ABCD[loc3];
                }
            break;

            case 10:
                loc = s[space + 1] - 'A';
                space = s.find(',');
                loc2 = s[space + 1] - 'A';
                space = s.find(',',space + 1);
                if(space == s.npos)
                {
                    ABCD[loc] |= ABCD[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    ABCD[loc] = ABCD[loc2] | ABCD[loc3];
                }
            break;

            case 11:
                loc = s[space + 1] - 'A';
                space = s.find(',');
                loc2 = s[space + 1] - 'A';
                space = s.find(',',space + 1);
                if(space == s.npos)
                {
                    ABCD[loc] ^= ABCD[loc2];
                }
                else
                {
                    loc3 = s[space + 1] - 'A';
                    ABCD[loc] = ABCD[loc2] ^ ABCD[loc3];
                }

            break;

        }
    }
}