#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct mail//直接开100000的char数组太大了，用指针
{
    string name;
    string realm; 
};
//
int qcmp(const void * q1, const void *q2)
{
    mail * p1 = (mail *) q1;
    mail * p2 = (mail *) q2;
    const char * n1 = p1->name.c_str();
    const char * n2 = p2->name.c_str();
    const char * r1 = p1->realm.c_str();
    const char * r2 = p2->realm.c_str();
    int judge = strcmp(r1,r2);
    if(judge == 0)
    {
        return strcmp(n2,n1);
    }
    return judge;
}

bool scmp(mail p1, mail p2)
{
    const char * n1 = p1.name.c_str();
    const char * n2 = p2.name.c_str();
    const char * r1 = p1.realm.c_str();
    const char * r2 = p2.realm.c_str();

    cout << "n1 " << n1 << endl;
    cout << "n2 " << n2 << endl<<endl;;
    int judge = strcmp(r1,r2);
    if(judge == 0)
    {
        int j = strcmp(n2,n1);
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
    mail * M = new mail[total + 1];
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
                
                continue;
            }
            if(c == '@')
            {
                c = getchar();
                back = 1;
                
                continue;

            }
            if(!back)
            {
                M[i].name += c;
            }
            else
            {
                M[i].realm += c;
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
    sort(M,M+total,scmp);
    for(int i = 0; i < total; i++)
    {
        cout << M[i].name << "@" << M[i].realm << endl;
    }

    return 0;
}