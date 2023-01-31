#include<iostream>
#include<string.h>
using namespace std;

void gcd(int a,int b)
{
    int a1 = a;
    int b1 = b;
    while(a % b)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    a1 /= b;
    b1 /= b;
    cout << b1 << "/" << a1 <<endl;
}

void oneDensity(char* a)
{
    int len = strlen(a);
    int one = 0;
    for(int i = 0; i < len; i++)
    {
        char temp = a[i];
        while(temp)
        {
            temp = temp & (temp - 1);
            one++;
        }
    }
    int all = 8 * len;
    gcd(all,one);
}

int main()
{
    int total;
    cin >> total;
    getchar();
    for(int i = 0; i < total; i++)
    {
        char a[1000] ={"\0"};
        char c;
        int j =0;
        while((c = getchar()) != '\n')
        {a[j++] = c;}
        oneDensity(a);
    }

    return 0;
}