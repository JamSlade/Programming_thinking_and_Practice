#include<iostream>
#include<string.h>
using namespace std;

int yes[100][10000];
int data[100];

int main()
{
    int t;
    cin >> t;
    int sum = 0;
    for(int i = 0; i < t; i++)
    {
        int temp;
        cin >> temp;
        data[i] = temp;
        sum += temp;
    }

    memset(yes, 0 ,sizeof(yes));
    yes[0][5000] = 1;

    for(int i = 1; i <= t; i++)
    {
        for(int j = 0; j < 10000; j++)
        {
            if(yes[i - 1][j])
            {
                yes[i][j]++;
                yes[i][j + data[i - 1]]++;
                yes[i][j - data[i - 1]]++;
            }
        }
    }
    for(int i = 5001; i <= 5000 + sum; i++)
        cout << ((yes[t][i]) ? '1' : '0');//

}