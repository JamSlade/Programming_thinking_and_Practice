#include<iostream>

using namespace std;

long long it_func(long long a)
{
    long long arr[100];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i = 4; i < 100; i++)
    {
        arr[i] =  arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
    }
    return arr[a];
}

long long re_func(long long a)
{
    if(a == 0)
    {
        return 1;
    }
    if(a == 1)
    {
        return 1;
    }
    if(a == 2)
    {
        return 2;
    }
    if(a == 3)
    {
        return 4;
    }
    return (re_func(a - 1) + re_func(a - 2) + re_func(a - 3) + re_func(a - 4));
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {

        cout << "case #" << i << ":"<<endl;
        long long a;
        cin >> a;
        cout << it_func(a) << endl;
    }

    return 0;
}