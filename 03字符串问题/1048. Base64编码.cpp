#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

string Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void trans(string a)
{
    
    int len = a.length();
    int out = len / 3;

    int flag = 0;
    if(len % 3)
        flag = 1;
    
    string *D = new string [out];//¼ÇÂ¼baseÂë
    D[0] = "1";
    D[1] = "2";
    
    //cout << D[0] <<endl << D[2] <<endl << D[1] << endl;
    int D_loc = 0;
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if( D[D_loc].length() == 6)
            {
                D_loc++;
                cout << "???"<<endl;
            }
            
            int temp = a[i] % 2;
            D[D_loc] += temp + '0';
            a[i] /= 2;
            
cout << j;
        }
    }

    int* B_asc = new int[out];
    memset(B_asc,0,out * 4);

    for(int i = 0; i < out; i++)
    {
        for(int j = 0; j < 6; i++)
        {
            B_asc[i] << 1;
            B_asc[i] += D[i][j] - '0';
        }
        cout << Base64[B_asc[i]];
    }


    // if(flag)
    // {
    //     int surplus = len % 3;
    //     string *Q = new string [surplus + 1];
    //     int Q_loc = 0;
    //     for(int i = len - surplus; i < len; i++)
    //     {
    //         for(int j = 0; j < 8; j++)
    //         {
    //             if( Q[Q_loc].size() == 6)
    //             {
    //                 Q_loc++;
    //             }
    //             int temp = a[i] % 2;
    //             Q[Q_loc].push_back(temp);
    //             a[i] >> 1;
    //         }
    //     }
        
    // }

    
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {

        cout << "case #" << i << ":"<<endl;
        string a;
        cin >> a;
        trans(a);
    }

    return 0;
}