#include<iostream>
#include<algorithm>
using namespace std;

struct contain
{
    int data[51];
    short effe = 0;

    contain()
    {
        for(int i = 0; i < 51; i++)
        {
            data[i] = -1;
        }
    }
    void statistic()
    {
        for(int i = 0; i < 51; i++)
        {
            if(data[i] == -1)
            {break;}
            effe++;
        }
    }
};

void print(contain *a, int len)
{
    for(int j = 0; j < len; j++)
    {
        for(int i = 0; i < a[j].effe; i++)
        {
            cout << a[j].data[i] << " ";
        }
        cout << endl;
    }
    
}

bool cmp(contain a, contain b)
{
    for(int i = 0; i < a.effe && i < b.effe; i++)
    {
        return(a.data[i] > b.data[i]);
        
    }
    return(a.effe < b.effe);
}

int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        int allc;
        cin >> allc;
        contain * C = new contain[allc];

        for(int j = 0; j < allc; j++)
        {
            int temp;
            cin >> temp;
            int c_len = 0;
            while(temp != -1)
            {
                C[j].data[c_len++] = temp;
                cin >> temp;
            }
            C[j].effe = c_len;
        }


        sort(C,C+allc,cmp);
        //cout << "case #" << i << ":" << endl;
        print(C,allc);
        
    }

    return 0;
}