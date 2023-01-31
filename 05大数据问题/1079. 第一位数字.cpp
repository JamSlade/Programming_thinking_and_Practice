#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a;
    while(cin >> a)
    {
        if(!a)
            return 0;
        
        double f = a*log10(a);
        f -= (int)f;
        int b = pow(10,f);
        cout << b << endl;
    }
}