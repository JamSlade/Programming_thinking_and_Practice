#include<iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int m, n;
        cin >> m >> n;
        if(n > m - n)
            n = m - n;
        unsigned long long q = 1;
        for(int j = 1, k = m; j <= n; j++, k--)
        {
            q *= k;
            q /= j;
        }
        cout << "case #" << i << ":"<<endl;
        cout << q << endl;
    }

    return 0;
}

