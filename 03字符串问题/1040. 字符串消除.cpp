#include<iostream>

using namespace std;

string duplicate(string& a)
{
    int len = a.length();
    string b;
    if(a[0] != a[1])
    {
        b += a[0];
    }

    for(int i = 1; i < len - 1; i++)
    {
        if(a[i] == a[i + 1])
        {
            continue;
        }
        else
        {
            if(a[i] == a[i - 1])
            {
                continue;
            }
            else
            {
                b += a[i];
            }
        }
    }

    if(a[len - 2] != a[len - 1])
    {
        b += a[len - 1];
    }
    len = b.length();
    int jud = 0;
    for(int i = 0; i < len - 1; i++)
    {
        if(b[i] == b[i + 1])
        {
            jud = 1;
            break;
        }
    }

    if(jud)
    {return duplicate(b);}
    else{return b;}
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string a;
        cin >> a;

        int len = a.length();
        int removal = 0;
        for(int j = 0; j < len; j++)
        {
            string a1 = a;
            a1.insert(j,"A");
            string b1 = duplicate(a1);
            int disa = a1.length() - b1.length();
            if(disa > removal)
            {
                removal = disa;
            }

            string a2 = a;
            a2.insert(j,"B");
            string b2 = duplicate(a2);
            disa = a2.length() - b2.length();
            if(disa > removal)
            {
                removal = disa;
            }

            string a3 = a;
            a3.insert(j,"C");
            string b3 = duplicate(a3);
            disa = a3.length() - b3.length();
            if(disa > removal)
            {
                removal = disa;
            }


        }

        cout << "case #"<<i << ":"<<endl;
        cout << removal << endl;
    }
    return 0;
}