#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>

using namespace std;

class element
{
public:
    string str;
    long long size;
    int has_num;

    long long calnum(string a)
    {   
        has_num = 0;
        long long alen = 0;
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] <='9' && a[i] >= '0')
            {
                alen *= 10;
                alen += a[i] - '0';
                has_num = 1;
            }
        }
        this->size = alen;
    }

    void init()
    {
        calnum(this->str);
    }


};


long long cmp(const void *p1,const void *p2)
{
    element *q1 = (element *) p1;
    element *q2 = (element *) p2;
    if(q1->size != q2->size)
    {return q1->size - q2->size;}
}

int main()
{
    element a[100];
    int n = 0;
    char c = getchar();
    while(c!='\n')
    {
        a[n].str+=c;
        c = getchar();
        if(c == ' ' )
        {
            n++;
            c = getchar();
        }
        a[n].init();
    }
    n++;
    a[n].init();
    // for(int i = 0; i < n; i++)
    // {cout << a[i] << " ";}
    sort(a,a+n,cmp);

    for(int i = 0; i < n; i++)
    {cout << a[i].str << " ";}

    return 0;

}