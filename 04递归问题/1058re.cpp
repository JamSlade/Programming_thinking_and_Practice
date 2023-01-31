#include<iostream>

#define ll long long
using namespace std;

 int A[4] {1,0,1,0};
 int B[4] {0,0,0,1};



ll CALDb(int times)
{
    if(times == 1)
    {
        return B[0];
    }
    if(times == 2)
    {
        return B[0];
    }
    if(times == 3)
    {
        return B[0];
    }
    if(times == 4)
    {
        return B[3];
    }
    //cout << times << endl;
    return CALDb(times - 1) + CALDb(times - 2);
}

ll CALDa(int times)
{
    if(times == 1)
    {
        return A[0];
    }
    if(times == 2)
    {
        return A[1];
    }
    if(times == 3)
    {
        return A[2];
    }
    if(times == 4)
    {
        return A[3];
    }
    //cout << times << endl;
    return CALDa(times - 1) + CALDa(times - 2);
}

ll calcoea(int a)
{
    if(a == 1) return 1;
    if(a == 2) return 1;
    if(a == 3) return 2;
    if(a == 4) return 2;
    return CALDa(a) + calcoea(a - 1);
}
ll calcoeb(int b)
{
    if(b < 4) return 0;
    if(b == 4) return 1;
    return CALDb(b) + calcoeb(b - 1);
}

int main()
{
    int a;
    int n;
    int m;
    int x;
    cin >> a >> n >> m >> x;
    
    ll b = (m - a * calcoea(n - 1)) / calcoeb(n - 1);
    //cout << "b " << b << " a " << a << endl;//

    // for(int i = 3; i< 10; i++)
    // {
    //     cout << "b " << calcoeb(i) << " a " << calcoea(i) << endl;//
    // }
    ll people = calcoeb(x)* b + calcoea(x) * a;
    cout << people << endl;


    return 0;
}