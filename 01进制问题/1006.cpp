#include<iostream>

using namespace std;

int dif(long long a,long long b)
{
    int c = 0;
    long long XOR = a^b;
    while(XOR)
    {
        XOR = XOR & (XOR - 1);
        c++;
    }

    return c;
}

int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        long long a,b;
        cin >> a >> b;
        cout << dif(a,b)<<endl;
    }
}