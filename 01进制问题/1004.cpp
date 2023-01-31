#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;


template<typename T>
void showMemory(T a)
{
    int c = sizeof(a);
    unsigned char * p = (unsigned char *) (&a);
    while(c--)
    {
        printf("%02x ",*p++);
    }
    cout << endl;
    return;
}

int main()
{
    char s[100];
    while(scanf("%s",s) != EOF)
    {
        if(strchr(s,'.') == 0)
        showMemory<int>(atoi(s));
        else
        showMemory<double>(atof(s));
    }
}