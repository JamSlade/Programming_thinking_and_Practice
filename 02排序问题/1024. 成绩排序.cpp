#include<iostream>
#include<cstring>
using namespace std;

struct Stu
{
    char snum[100];
    long long num;

    long long score;
    Stu()
    {
        score = 0;
        num = 0;
        for(int i = 0;i < 100;i++)
        snum[i] = 0;
    }
    void ATOI()
    {
        for(int i = 0;i < strlen(snum) ;i++)
        {
            int temp = snum[i] - '0';
            num *= 10;
            num += temp;
        }
    }
};

int cmp(const void *q1, const void *q2)
{
    Stu * p1 = (Stu *)q1;
    Stu * p2 = (Stu *)q2;
    if(p1->score == p2->score)
    {
        if(p1->num > p2->num)//不要直接返回LL类型的相减，可能会溢出
        {return 1;}
        else
        {return -1;}
    }
    if(p2->score < p1->score)
        return -1;
    else if(p2->score > p1->score)
        return 1;
}

int main()
{
    
    int total;
    cin>>total;
    for(int i = 0; i < total; i++)
    {
        int n, m , g;
        cin >> n >> m >> g;
        long long Qscore[10];
        for(int i = 0; i < m; i++)
        {
            cin >> Qscore[i];
        }

        Stu * s = new Stu[n];

        for(int i = 0; i < n; i++)
        {
            cin >> s[i].snum;
            s[i].ATOI();

            int slove;
            cin >> slove;
            
            for(int j = 0; j < slove; j++)
            {
                int temp;
                cin >> temp;
                s[i].score += Qscore[temp - 1]; 
            }
            //cout << s[i].score <<" "<< s[i].snum <<" !! "<<s[i].num <<" ??????"<<endl;
        }

        qsort(s,n,sizeof(Stu),cmp);
        //cout << endl;
        //for(int i = 0; i < n; i++)
        //cout << s[i].score <<" "<< s[i].snum <<" !! "<<s[i].num <<" ??????"<<endl;
        cout << "case #" << i << ":" << endl;

        int flag = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i].score >= g)
            {
                flag++;
            }
        }
        cout << flag << endl;
        for(int i = 0; i < flag; i++)
        {cout << s[i].snum <<" " << s[i].score << endl;}


    }
    return 0;
}