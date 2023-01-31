#include<iostream>
#include<cstdlib>
using namespace std;

struct team
{
    int point;
    long long number;
    long long win;
    long long lose;
    team()
    {
        point = 0;
        win = 0;
        lose = 0;
    }

};

int cmp(const void *q1, const void *q2)
{
    team *t1 = (team*) q1;
    team *t2 = (team*) q2;
    if(t1->point == t2->point)
    {
        if(t1->win == t2->win)
        {
            if(t1->lose == t2->lose)
            {
                return(t1->number - t2->number);
            }
            return(t1->lose - t2->lose);//
        }
        return(t2->win - t1->win);
    }
    return(t2->point - t1->point);
}

int main()
{
    int n,m;
    cin >> n >> m;
    while(n != 0 || m != 0)
    {
        team T[11];
        for(int i = 1; i <= 10; i++)
        {
            T[i].number = i;
        }
        

        // for(int i = 1; i <= n; i++)
        // {
        //     cout << T[i].number<<" !!!";
        // }
        // cout << endl;
        
        
        for(int i = 0; i < m; i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            if(c == 0)
            {
                T[a].point++;
                T[b].point++;
                
            }
            if(c == 1)
            {
                T[a].point += 3;
                T[b].point --;
                T[b].lose++;
                T[a].win++;
            }
            if(c == -1)
            {
                T[a].point--;
                T[b].point +=3;
                T[b].win++;
                T[a].lose ++;
            }
        }

        qsort(T + 1, n, sizeof(team), cmp);

        for(int i = 1; i <= n; i++)
        {
            cout << T[i].number<<" ";
        }
        cout << endl;


        cin >> n >> m;
    }

    
    return 0;

}