#include<iostream>
using namespace std;



int main()
{
    long long a[21];
    long long b[21];
    a[0] = 0;
    a[1] = 1;
    b[0] = 0;
    b[1] = 1;
    for(int i = 2; i < 21; i++)
    {
        a[i] = a[i - 1] + b[i - 1];
        b[i] = a[i] - b[i - 2];
    }
    
    int n;
    while((cin >> n)&& n != -1)
    {
        cout << a[n]+b[n]<<endl;
    }

    return 0;
}