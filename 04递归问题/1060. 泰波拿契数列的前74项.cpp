#include<iostream>

using namespace std;

long long RE(int num)
{
    if(num == 0) return 0;
    if(num == 1) return 1;
    if(num == 2) return 1;
    cout << num << endl;//
    return RE(num - 1)+RE(num - 2)+RE(num - 3);
}

long long IT(int num)
{
    long long *arr = new long long[num + 1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3; i <= num; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[num];
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        cout << "case #" << i << ":"<<endl;
        cout <<IT(num) <<endl;
    }

    return 0;
}

