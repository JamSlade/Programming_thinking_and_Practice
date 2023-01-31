#include<iostream>
#include<deque>
using namespace std;

void POW(int b, int p)
{
    deque<int>D;
    D.push_back(b);

    if(p == 0)
    {
        cout << "1";
        return;
    }
    if(p == 1)
    {
        cout << b ;
        return;
    }//

    for(int i = 1; i < p; i++)
    {
        
        for(deque<int>::reverse_iterator it = D.rbegin(); it != D.rend(); it++)
        {
            *it *= b;
            
        }
        for(deque<int>::reverse_iterator it = D.rbegin(); it != D.rend(); it++)
        {
            int carry = 0;
            if(*it >= 10)
            {
                carry = *it / 10;
                *it %= 10;
            }
            if(carry)
            {
                if(it + 1 != D.rend())
                {
                    *(it + 1) += carry;
                }
                else
                {
                    D.push_front(carry);
                    break;
                }
            }
        }
    }
    for(deque<int>::iterator it = D.begin(); it != D.end(); it++)
    {
        cout << *it;
    }

}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int base,power;
        cin >> base >> power;
        cout << "case #" << i << ":"<<endl;
        POW(base,power);
        cout << endl;  
    }

    return 0;
}

