#include<iostream>
#include<string.h>
using namespace std;



void trans2(int len,int last)
{
    for(int i = 0; i < last * 3 + 1;i++)
    {
        cout << ( (len & (1 << last * 3)) ? 1 : 0);
        len <<= 1;
    }
}

void func(char * a)
{
    cout << "0001";
    int len = strlen(a);
    int num[10];
    trans2(len,3);

    int times = len / 3;
    int last;

    if(times * 3 < len)
    {
        last = len - times * 3;
        times++;
    }
    else
        last = 3;


    for(int i = 0; i < times; i++)
    {   
        int eachT = 0;
        for(int j = 0; j < 3; j++)
        {   
            if(a[3 * i + j] == '\0') break;
            eachT *= 10;
            eachT += (a[3 * i + j] - '0');
        }
        // cout << endl<<eachT << "  eachT" << endl;
        (i != times - 1) ? trans2(eachT,3) : trans2(eachT,last);
    }
    

}


int main()
{
    char a[2000] = {0};
    cin >> a;
    
    func(a);
}