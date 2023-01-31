#include<iostream>
#include<stack>

using namespace std;

string duplicate(string  a)
{
    stack<char> s;
    int len = a.length();
    cout << a << " a" <<  endl;
    for(int i = 0; i < len; i++)
    {
        int flag = 0;
        
        if(s.empty() || a[i] != s.top() )
        {
            s.push(a[i]);
            //cout << a[i] << " " << i << endl;
        }
        else// if(a[i] == s.top())
        {
            
            while( i < len && a[i] == s.top() )
            {
                i++;//
                flag = 1;
            }
            if(flag)
            {
                s.pop();
                i--;
            }
        }
        
        
        
    }
    string b;//
    
    while(!s.empty())
    {
        b += s.top();
        s.pop();
    }
    cout << b << " b" << endl;
    return b;
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
}