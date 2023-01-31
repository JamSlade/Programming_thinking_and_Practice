#include<iostream>

using namespace std;

void func()
{
    bool b[3][3];
    int times[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            b[j][i] = true;
            times[j][i] = 0;
        }
    
    }
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 2; j++)
    //         cout << b[j][i] << " ";
    //     cout << b[2][i] << endl;
    // }
    // cout << endl;

    int a;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            cin >> a;
            if(j > 0)  times[i][j - 1] += a;
            if(j < 2)  times[i][j + 1] += a;
            if(i > 0)  times[i - 1][j] += a;
            if(i < 2)  times[i + 1][j] += a ;
            times[i][j] += a;
        }
    

    for(int i = 0; i < 3 ;i++)
    for(int j = 0; j < 3; j++)
    {
        if(times[i][j] % 2 == 1)
            b[i][j] = false;
    }
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 2; j++)
    //         cout << times[i][j] << " ";
    //     cout << times[i][2] << endl;
    // }
    // cout << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
            cout << b[i][j] << " ";
        cout << b[i][2] << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {

        cout << "case #" << i << ":"<<endl;
        func();
    }

    return 0;
}

