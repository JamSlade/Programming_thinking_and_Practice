#include<iostream>

using namespace std;

int main()
{

    string a;
    cin >> a;
    int len = a.length();
    int enclosure = 1;
    int count = 1;
    for(int i = 0; i < len - 1; i++)
    {
        if(a[i] != a[i + 1])
        {
            count++;
        }
        else
        {
            if(count > enclosure)
            {
                enclosure = count;
            }
            count = 1;
        }

    }
    if(count > enclosure)
    {
        enclosure = count;
    }
    cout << enclosure << endl;

    return 0;
}