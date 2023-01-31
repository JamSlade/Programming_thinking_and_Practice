#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct mail//直接开100000的char数组太大了，用指针
{
    char name[1000000];
    char realm[1000000];
};
//
int qcmp(const void * q1, const void *q2)
{
    mail * p1 = (mail *) q1;
    mail * p2 = (mail *) q2;
    int judge = strcmp(p1->realm,p2->realm);
    if(judge == 0)
    {
        return strcmp(p2->name,p1->name);
    }
    return judge;
}

bool scmp(mail p1, mail p2)
{
    int judge = strcmp(p1.realm,p2.realm);
    if(judge == 0)
    {
        int j = strcmp(p2.name,p1.name);
        if (j < 0)
            return false;
        else
        return true;
    }
    if(judge > 0)
        return false;
    else
        return false;
}



int main()
{
    int total;
    cin >> total;
    getchar();
    mail * M = new mail[total];
    for(int i = 0; i < total; i++)
    {
        char c = getchar();
        int back = 0;
        int n_len = 0;
        int r_len = 0;
        while(c != '\n' && c != EOF)
        {
            if(c == '\n' || c == EOF)
            {
                M[i].realm[r_len] == 0;
                continue;
            }
            if(c == '@')
            {
                c = getchar();
                back = 1;
                M[i].name[n_len] == 0;
                continue;

            }
            if(!back)
            {
                M[i].name[n_len++] = c;
            }
            else
            {
                M[i].realm[r_len++] = c;
            }
            c = getchar();
        }
        cout << "i " << i <<endl;
        cout << "name  " <<M[i].name<<endl;
        cout << "REALM  " <<M[i].realm << endl;//
        
    }
    cout << endl;
    for(int i = 0; i < total; i++)
    {
        cout << M[i].name << "@" << M[i].realm << endl;
    }
    cout << endl;
    qsort(M,total,sizeof(mail),qcmp);
    for(int i = 0; i < total; i++)
    {
        cout << M[i].name << "@" << M[i].realm << endl;
    }

    return 0;
}