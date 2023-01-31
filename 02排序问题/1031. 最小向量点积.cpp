#include<iostream>
#include<set>
#define ll long long
using namespace std;

int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        multiset<ll>a1;
        multiset<ll>a2;
        int all;
        cin >> all;
        for(int i = 0; i < all; i++)
        {
            ll temp;
            cin >> temp;
            a1.insert(temp);
        }
        for(int i = 0; i < all; i++)
        {
            ll temp;
            cin >> temp;
            a2.insert(temp);
        }
        multiset<ll>::iterator it1 = a1.begin();
        multiset<ll>::reverse_iterator it2 = a2.rbegin();
        ll out = 0;
        for(; it1 != a1.end(), it2 != a2.rend(); it1++, it2++)
        {
            out += (*it2) * (*it1);
        }
        cout << "case #" << i << ":" << endl;
        cout << out << endl;
    }

    return 0;
}