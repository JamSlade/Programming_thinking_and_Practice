#include<iostream>
#include<algorithm>
using namespace std;

struct NUM
{
    short initial;
    string all;
    long long num;

    NUM()
    {
        num = 0;
    }
    void init()
    {   
        int neg = 0;
        for(int i = 0; i < all.length(); i++)
        {
            if(all[i] == '-')
            {
                neg = 1;
                continue;
            }
            
            num *= 10;
            num += (all[i] - '0');
        }
        initial = ((neg) ? all[1] : all[0]) - '0';
        num = ((neg) ? -num : num);

    }
};

// int cmp(const void *q1, const void *q2)
// {
//     NUM * p1 = (NUM *)q1;
//     NUM * p2 = (NUM *)q2;

//     if(p1->initial == p2->initial)
//     {
//         if(p1->num > p2->num)
//         {return 1;}
//         else
//         {return -1;}
//     }
//     if(p1->initial > p2->initial)
//     {return -1;}
//     else
//     {return 1;}
// }

bool scmp(NUM p1,NUM p2)
{
    if(p1.initial == p2.initial)
    {
        return(p2.num > p1.num);
    }
    return (p1.initial > p2.initial);
}


int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        
        int alli;
        cin >> alli;
        NUM * N = new NUM[alli];
        for(int j = 0; j < alli; j++)
        {
            cin >> N[j].all;
            N[j].init();
        }

        sort(N,N+alli,scmp);
        cout << "case #" << i << ":" << endl;
        for(int j = 0; j < alli; j++)
        {
            cout << N[j].all << " ";
            //输出string的话只能输出第一个字符
        }
        cout << endl;
    }
}