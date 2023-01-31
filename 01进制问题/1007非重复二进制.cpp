#include<iostream>

using namespace std;

int max_len_dif(long long a)
{
    int fir = a % 2,sec;
    int count = 1;
    int temp = 1;
    while(a)
    {   
        
        a >>= 1;
        sec = a % 2;
        if(sec != fir)
        {temp++;}
        else
        {
            if(temp > count)
                {count = temp;}
            temp = 1;
        }
        
        fir = sec;
    }

    if(temp > count){count = --temp;}
    return count;
}


int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        long long a;
        cin >> a;
        cout << "case #" << i << ":"<<endl;
        cout << max_len_dif(a) << endl; 
    }

    return 0;
}