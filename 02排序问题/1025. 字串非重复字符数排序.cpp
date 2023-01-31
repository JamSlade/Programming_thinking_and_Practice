#include<iostream>
#include<cstring>
using namespace std;

struct S
{
    char str[21];
    char alpha[26];
    int dif;

    S()
    {
        dif = 0;
        for(int i = 0;i < 26; i++)
        {
            if(i < 21)
            {str[i] = 0;}
            alpha[i] = 0;
        }
    }

    void statistic()
    {
        int len = strlen(str);
        for(int i = 0 ; i < len; i++)
        {
            if(alpha[str[i] - 'A'] == 0)
            {
                alpha[str[i] - 'A'] = 1;
                dif++;
            }
        }
    }
};

int cmp(const void *q1, const void *q2)
{
    S * p1 = (S *)q1;
    S * p2 = (S *)q2;

    if(p1->dif == p2->dif)
    {return strcmp(p1->str,p2->str);}
    return(p2->dif - p1->dif);
}


void func()
{
    int alls;
    cin >> alls;
    S * str = new S[alls];

    for(int i = 0 ; i < alls; i++)
    {
        cin >> str[i].str;
        str[i].statistic();
    }
    qsort(str,alls,sizeof(S),cmp);

    for(int i = 0; i < alls; i++)
    {
        cout << str[i].str << endl;
    }
}

int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {   
        cout << "case #" << i << ":" << endl;
        func();
    }
    return 0;
}