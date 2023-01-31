#include<iostream>
#include<vector>
using namespace std;

struct Polynomial
{
    int x[9];

    Polynomial(int * v)
    {
        for(int i = 0; i < 9; i++)
            x[i] = v[8 - i];
    }
    void print()
    {

        bool first = true;
        int loc = -1;
        for(int i = 8; i >= 0; i--)
            if(x[i] != 0)
            {
                loc = i;
                first = false;
                break;
            }
        if(loc > 1)
        switch(jud(x[loc]))
            {
                case 0:
                    break;
                case 1:
                    cout << "x^" << loc;
                    break;
                case -1:
                    cout << "-x^" << loc;
                    break;

                default:
                    cout << x[loc] << "x^" << loc;
                    break;
            }
        else if(loc == 1)
         switch(jud(x[loc]))
            {
                case 0:
                    break;
                case 1:
                    cout << "x" ;
                    break;
                case -1:
                    cout << "-x";
                    break;

                default:
                    cout  << x[loc] << "x";
                    break;
            }
        else if(loc == 0)
        switch(jud(x[loc]))
            {
                case 0:
                    break;
                case 1:
                    cout << "1" ;
                    break;
                case -1:
                    cout << "-1";
                    break;

                default:
                    cout  << x[loc];
                    break;
            }

        

        for(int i = loc - 1; i > 1;i--)
        {
            switch(jud(x[i]))
            {
                case 0:
                    break;
                case 1:
                    cout << "+x^" << i;
                    break;
                case -1:
                    cout << "-x^" << i;
                    break;

                case 2:
                    cout << '+' << x[i] << "x^" << i;
                    break;
                case -2:
                    cout << x[i] << "x^" << i;
            }
        }

        if(loc > 1)
        switch(jud(x[1]))
        {
            case 0:
                    break;
                case 1:
                    cout << "+x";
                    break;
                case -1:
                    cout << "-x";
                    break;

                case 2:
                    cout << '+' << x[1] << "x";
                    break;
                case -2:
                    cout << x[1] << "x" ;
        }
        if(loc > 0)
        switch(jud(x[0]))
        {
            case 0:
                    break;
                case 1:
                    cout << "+1";
                    break;
                case -1:
                    cout << "-1";
                    break;

                case 2:
                    cout << '+' << x[0];
                    break;
                case -2:
                    cout << x[0];
        }
        
        
        if(first)
            cout << "0";

       
    }

    int jud(int a)
    {
        switch (a)
        {
        case 1:
            return 1;
        case -1:
            return -1;
        case 0:
            return 0;
        default:
            return ((a > 0) ? 2 : -2);
        }
    }
    
};

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {

        cout << "case #" << i << ":"<<endl;
        int v[9];
        for(int i = 0; i < 9; i++)
            cin >> v[i];
        Polynomial P(v);
        P.print();
        cout << endl;
    }

    return 0;
}

