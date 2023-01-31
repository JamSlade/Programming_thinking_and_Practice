#include<iostream>

using namespace std;

void compress(string & a)
{
    int each[500] = {0};
    char c[500] = {0};
    int len = a.length();
    c[0] = a[0];
    each[0]++;

    int location = 0;
    for(int i = 1; i < len; i++)
    {
        if(a[i] == c[location])
        {
            while(i < len && a[i] == c[location])
            {
                if(each[location] == 255)
                {
                    location++;
                    c[location] = a[i];
                }
                each[location]++;
                i++;

            }
            i--;
        }
        else
        {
            location++;
            c[location] = a[i];
            each[location]++;
        }
        
    }
    location++;//別忘了最後加上一個哦
    for(int i = 0; i < location; i++)
    {
        cout << each[i] << c[i] ;
    }
    cout << endl;

}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string a;
        cin >> a;

        cout << "case #" << i << ":"<<endl;
        compress(a);
    }

    return 0;
}