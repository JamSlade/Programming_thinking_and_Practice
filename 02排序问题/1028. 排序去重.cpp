#include<iostream>
#include<set>

using namespace std;

void positive(set<int>&s)
{
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
}


void negative(set<int>&s)
{
    for(set<int>::reverse_iterator it = s.rbegin(); it != s.rend(); it++)
    {
        cout << *it << " ";
    }
}

int main()
{
    char c;
    cin >> c;
    set<int> s;
    int a;
    while(cin >> a)
    {
        s.insert(a);
    }

    if(c == 'A')
        positive(s);
    else if(c == 'D')
        negative(s);
    
}