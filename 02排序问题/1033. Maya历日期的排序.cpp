#include<iostream>
#include<algorithm>

using namespace std;
string month[] = 
{
    "pop","no","zip", "zotz", "tzec", "xul",
    "yoxkin", "mol", "chen", "yax", "zac", 
    "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"
};

struct date
{
    int y;
    string m;
    int d;
    int m_num;
    
    void init()
    {
        for(int i = 0; i < 19; i++)
        {
            if(this->m == month[i])
                this->m_num = i;
        }
    }
};

bool cmp(date a, date b)
{
    if(a.y == b.y)
    {
        if(a.m_num == b.m_num)
        {return (a.d < b.d);}
        return(a.m_num < b.m_num);
    }
    return (a.y < b.y);
}

int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        int alld;
        cin >> alld;
        date * D = new date[alld];

        for(int j = 0; j < alld; j++)
        {
            cin >> D[j].d;
            getchar();
            cin >> D[j].m;
            cin >> D[j].y;
            D[j].init();
        }

        sort(D,D+alld,cmp);
        cout << "case #" << i << ":" << endl;
        for(int j = 0; j < alld; j++)
        {
            cout << D[j].d << ". "<<D[j].m << " " << D[j].y << endl;
        }
    }
    return 0;
}