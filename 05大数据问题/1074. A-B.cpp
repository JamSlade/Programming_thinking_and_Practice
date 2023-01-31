#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int main()
{
    string a,b;
    while(cin >> a >> b)
    {
        while(a[0] == '0')
            a.erase(0,1);
        while(b[0] == '0')
            b.erase(0,1);

        deque<int>a1,b1;
        int alen = a.length(), blen = b.length();

        for(int i = 0; i < alen; i++)
            a1.push_back(a[i] - '0');
        for(int i = 0; i < blen; i++)
            b1.push_back(b[i] - '0');

        while(a1.size() < b1.size())
            a1.push_front(0);
        while(a1.size() > b1.size())
            b1.push_front(0);


        int same = 1;
        int A = 0, B = 0;
        for(auto ita = a1.begin(), itb = b1.begin(); ita != a1.end() && itb != b1.end(); ita++, itb++)
        {
            if((*ita) != (*itb))
            {
                same = 0;
                if((*ita) > (*itb))
                    A = 1;
                else
                    B = 1;
                break;
            }
        }

        if(same)
            cout <<"0";
        else if(A)
        {
            for(auto ita = a1.rbegin(), itb = b1.rbegin(); ita != a1.rend() && itb != b1.rend(); ita++, itb++)
            {
                *ita -= *itb;
                if(*ita < 0)
                {
                    *ita += 10;
                    *(ita + 1) -= 1;
                }
            }
            while(*a1.begin() == 0)
                a1.pop_front();
            for(auto x : a1)
                cout << x;
            
        }
        else if(B)
        {
            for(auto ita = a1.rbegin(), itb = b1.rbegin(); ita != a1.rend() && itb != b1.rend(); ita++, itb++)
            {
                *itb -= *ita;
                if(*itb < 0)
                {
                    *itb += 10;
                    *(itb + 1) -= 1;
                }
            }
            while(*b1.begin() == 0)
                b1.pop_front();
            cout << "-";
            for(auto x : b1)
                cout << x;
        }
        
        cout << endl;
    }
}