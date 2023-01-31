#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

struct BIG
{
    int arr[(int)1e5];
    int arr_num;
    int power;
    int base[100];
    int exa;
    int len;

    BIG(ll a, int b, int c )
    {
        memset(arr,0,sizeof(arr));
        memset(base,0,sizeof(base));
        arr[0] = 1;
        arr_num = 1;
        power = b;
        exa = c;
        len = 0;

        while(a)
        {
            int temp = a % 10;
            base[len++] = temp;
            a /= 10;
        }
    }

    void POW()
    {
        if(!exa)
        {return ;}
       

        for(int i = 0; i < power; i++)
        {
            
            ll temp[10000];
            memset(temp,0,sizeof(temp));
            for(int j = 0; j < arr_num; j++)
            {
                for(int k = 0; k < len; k++)
                {
                    temp[j + k] += arr[j] * base[k];
                }
                
            }
            for(int k = 0; k < arr_num + len;k++)
                arr[k] = temp[k];
            carry();
        }

    }

    void carry()//进位
    {
        arr_num += len - 1;
        for(int i = 0; i < arr_num - 1; i++)
        {
            if(arr[i] >= 10)
            {
                arr[i+1] += arr[i] / 10;
                arr[i] %= 10;
            }
        }
        while(arr[arr_num - 1] >= 10)
        {
            arr[arr_num] += arr[arr_num - 1] / 10;
            arr[arr_num - 1] %= 10;
            arr_num++;
        }
        //test(1);
    }

    void OUT()
    {
        for(int i = exa - 1; i >= 0; i--)
            cout << arr[i];
    }

    void test(int q)//用于检验思路是否正确
    {
        cout << q << endl;
        cout << " base ";
        for(int i = len - 1; i >= 0; i--)
            cout << base[i];
        cout << endl << " arr ";

        for(int i = arr_num - 1; i >= 0; i--)
            cout << arr[i];
        cout << endl << "power " << power <<endl << " exa " << exa << endl << " len " << len << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        BIG num(a,b,c);
        num.POW();
        cout << "case #" << i << ":"<<endl;
        num.OUT();
        cout << endl;
    }

    return 0;
}

