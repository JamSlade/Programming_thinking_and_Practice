#include<iostream>
#include<stack>
using namespace std;

string alpha = "0123456789ABCDEF";
void transI(stack<char>&bin)
{
    int len = bin.size();
    long long i = 0;
    long long r = 0;
    long long complex[16][2] = 
    {
        {0,0},{1,0},{-1,1},{0,1},
        {0,-2},{1,-2},{-1,-1},{0,-1},
        {2,2},{3,2},{1,3},{2,3},
        {2,0},{3,0},{1,1},{2,1}
    };

    for(int j = 0; j < len; j++)
    {
        char temp = bin.top();
        int temp_int = alpha.find(temp);
        long long ti = complex[temp_int][1];
        long long tr = complex[temp_int][0];

        for(int k = 0; k < j;k++)
        {
            ti *= -4;
            tr *= -4;
        }

        i += ti;
        r += tr;
        //cout << bin.top() << endl;
        //cout << "ti " << ti <<" tr "<<tr <<" r " << r << " i " << i <<endl<<endl;
        bin.pop();
    }


    int puti = 0;
    int putr = 0;
    int positive = 0;
    int one = 0;
    if(i)
    {
        puti = 1;
        if(i == 1 || i == -1){one = 1;}
        if(i > 0){positive = 1;}
    }
    if(r){putr = 1;}
    

    if(putr)
    {cout << r;}
    if(positive && putr)
    {cout << '+';}
    
    if(puti && !one)
    {cout<< i << "i" ;}
    else if(puti && one)
    {
        cout << ((i > 0)?"i":"-i");
        
    }
}

int main()
{
    string hexadecimal;
    cin >> hexadecimal;

    if(hexadecimal == "0x0")
    {
        cout << "0";
        return 0;
    }
    int len = hexadecimal.length();
    
    stack<char>bin;
    for(int i = 2; i < len; i++)
    {
        bin.push(hexadecimal[i]);
    }
    
    //cout << endl<<bin.size()<<endl;
    transI(bin);

    return 0;
}