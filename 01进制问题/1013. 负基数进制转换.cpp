#include<iostream>
#include<stack>
using namespace std;

string alpha = "0123456789ABCDEFGHIJKLMN";

int main()
{
    int num;
    int base;
    stack<int> store;
    cin >> num;
    cin >> base;
    if(!num)
    {
        cout<<0;
        return 0;
    }
    while(num)
    {
        int temp = num % base;
        num /= base;
        if(temp < 0)
        {
            temp -= base;
            num++;
        }   
        store.push(temp);
    }

    while(!store.empty())
    {
        int temp = store.top();
        store.pop();
        cout << alpha[temp];
    }
    cout<<endl;

}

