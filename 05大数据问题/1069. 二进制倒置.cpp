#include<iostream>
#include<deque>
using namespace std;

void trans_bin(string ten, string & bin)
{
    int len = ten.length();
    int * pc = new int[len];
    for(int i = 0; i < len;i++)
    {
        pc[i] = ten[i] - '0';
    }
    
    if(ten == "0")
    {bin = "0"; return;}

    while(1)
    {
        
        int flag = 1;
        for(int i = 0; i < len; i++)
        {
            if(pc[i])
            {    
                flag = 0;
                break;
            }    
        }
        if(flag)
        {break;}

        if(pc[len - 1] % 2)
            bin.insert(0,1,'1');
        else
            bin.insert(0,1,'0');
        
        for(int i = 0; i < len - 1; i++)
        {
            if(pc[i] % 2)
            {
                pc[i + 1] += 10;
            }
            pc[i] /= 2;
        }
        pc[len - 1] /= 2;

    }
    delete[] pc;
}

void rev(string & a, string & b)
{
    int len = a.length();
    for(int i = 1; i <= len ;i++)
    {
        b += a[len - i];
    }
    while(b[0] == '0' && b.length() != 1)
    {b.erase(0,1);}
    return;
}


void trans_ten(string & s, string& d)
{
    int len = s.length();
    d.insert(0,1,s[0]);

    for(int i = 1; i < len; i++)
    {
        int dlen = d.length();
        int * arr = new int[dlen];
        for(int j = 0; j < dlen; j++)
        {
            arr[j] = d[j] - '0';
        }
        d = "";

        // for(int j = 0; j < dlen; j++)
        // {cout << arr[j];}
        // cout << endl;

        int carry = 0;
        for(int j = dlen - 1; j > 0 ;j--)
        {
            arr[j] *= 2;
            
            if(carry)
                arr[j] += 1;
            //应该在*2之后再加carry
            if(arr[j] >= 10)
            {
                carry = 1;
                arr[j] -= 10;
            }
            else
                carry = 0;
        }
        arr[0] *= 2;
        if(carry)
        {arr[0] += 1;}
        if(arr[0] >= 10)
        {
            arr[0] -= 10;
            carry = 1;
        }
        else
            carry = 0;

        arr[dlen - 1] += s[i] -'0';

        // for(int j = 0; j < dlen; j++)
        // {cout << arr[j];}
        // cout << "?" << endl;//


        for(int j = dlen - 1; j >= 0; j--)
            d.insert(0,1,arr[j] + '0');

        if(carry)
            d.insert(0,1,'1');

        
        
        //delete[] arr;
    }
    cout << d << endl;

}


int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {

        cout << "case #" << i << ":"<<endl;
        string bin;
        string re_bin;
        string ten;
        string re_ten;
        cin >> ten;

        trans_bin(ten,bin);//
        rev(bin,re_bin);
        //cout << "bin " << bin << endl << "re_bin " << re_bin << endl; 
        trans_ten(re_bin,re_ten);


    }//

    return 0;
}

