#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct ele
{
    char str[1000];
    long long num;
    int has_num;

    void assign()
    {
        int len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                this->has_num = 1;
                
                num *= 10;
                num += str[i] - '0';
            }
        }
        //printf("%s %d %d\n",this->str,this->num,this->has_num);
    }

    ele()
    {
        this->num = 0;
        this->has_num = 0;
    }    
};


int cmp(const void *q1, const void * q2)
{
    ele * p1 = (ele *) q1;
    ele * p2 = (ele *) q2;
    if(p1->has_num != p2->has_num)
    {return p1->has_num - p2->has_num;}
    else
    {
        if(p1->num != p2->num)
        {return p1->num - p2->num;}
        else
        {return strcmp(p1->str,p2->str);}
    }
}


int main()
{
    ele a[1000];
    int n = 0;
    char c = getchar();
    int len = 0;
    while(c!='\n')
    {
        a[n].str[len++]=c;
        c = getchar();
        if(c == ' ' )
        {
            c = getchar();
            len = 0;
            a[n++].assign();
            
        }
    }
    
    a[n++].assign();//你需要注意空格是比数据少一个的
    
    // for(int i = 0; i < n; i++)
    // {cout << a[i] << " ";}
    qsort(a,n,sizeof(ele),cmp);

    for(int i = 0; i < n; i++)
    {cout << a[i].str << " ";}

    return 0;

}