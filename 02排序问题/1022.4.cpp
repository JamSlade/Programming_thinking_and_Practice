#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct mail//直接开100000的char数组太大了，用指针
{
    char *name;
    char *realm;
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

char all[10000000];

int main()
{
    cout << "????";
    int total;
    cin >> total;
    getchar();
    cout << "????";
    mail * M = new mail[total];
    
    int len = 0;
    M[0].name = all;
    
    for(int i = 0 ; i < total; i++)
    {
        char c = getchar();
        while(c != EOF && c != '\n')
        {
            if(c == EOF || c == '\n')
            {
                all[len++] = 0;
                M[i + 1].name = (all + len);
                continue;
            }
            if(c == '@')
            {
                all[len++] = 0;
                M[i].realm = all + len;
                continue;
            }
            all[len++] = c;
            c = getchar();
        }
        cout << "i " << i <<endl;
        cout << "name  " <<M[i].name<<endl;
        cout << "REALM  " <<M[i].realm << endl;//


    }


    return 0;
}