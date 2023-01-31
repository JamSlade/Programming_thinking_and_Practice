#include<iostream>
using namespace std;

string Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void put(int out, int location ,string str)//out是需要转换的内容的末尾，location代表字符串转换的位置
{
    string all;
    for(int i = location ; i < out; i++)//3out是str的前3n内容
    {
        for(int j = 0; j < 8; j++)
        {
            
            if(!str[i])
            {
                all.insert(i * 8,1,'0');
            }
            else
            {
                all.insert(i * 8,1,str[i] % 2 + '0');
                str[i] /= 2;
            }
            
        }
        //cout << all << endl;
    }

    int alen = all.length();
    int * B_asc = new int[out];
    for(int i = 0; i < out; i++)
    {B_asc[i] = 0;}

    int loc = 0;
    for(int i = 0; i < alen;)
    {
        for(int j = 0; j < 6 && i < alen; j++, i++)
        {
            B_asc[loc] *= 2;
            B_asc[loc] += (all[i] - '0');
            
        }
        
        cout << Base64[B_asc[loc]];
        loc++;
    }
}

void put(int out, int location ,string str,int a)//out是需要转换的内容的末尾，location代表字符串转换的位置
{
    
    string all;
    
    for(int i = 0 ; i < out - location; i++)//3out是str的前3n内容
    {
        
        for(int j = 0; j < 8; j++)
        {
            
            if(!str[i])
            {
                all.insert(i * 8,1,'0');
            }
            else
            {
                all.insert(i * 8,1,str[location + i] % 2 + '0');
                str[i + location] /= 2;//注意位置变化。。。
            }
            
        }
    }
    

    
    while(all.length() < 24)
    {all+='0';}
    int alen = all.length();

    int * B_asc = new int[out - location + 1];
    //最后的情况比较特殊，有1个字符要输出两个转换好的+2个=
    //2个字符就是3个转好的+1个=

    for(int i = 0; i < out - location + 1; i++)
    {B_asc[i] = 0;}

    int loc = 0;
    for(int i = 0; i < (out - location + 1) * 6;)
    {
        for(int j = 0; j < 6 && i < alen; j++, i++)
        {
            B_asc[loc] *= 2;
            B_asc[loc] += (all[i] - '0');
        }

        cout << Base64[B_asc[loc]];
        loc++;
        //cout << out - location + 1 << " loc  i"<< i << endl;
    }//
    for(int i = 0; i < 3 - out % 3; i++)
    {cout << "=";}
}


void trans(string str)
{
    int len = str.length();
    int out = len / 3;

    int flag = 0;
    if(len % 3)
        flag = 1;

    
    put(out * 3,0,str);
//
    if(flag)
    {
        put(len, out * 3, str, 1);
    }

    // string all;
    // for(int i = 0; i < out * 3; i++)//3out是str的前3n内容
    // {
    //     for(int j = 0; j < 8; j++)
    //     {
            
    //         if(!str[i])
    //         {
    //             all.insert(i * 8,1,'0');
    //             //就很离谱
    //         }
    //         else
    //         {
    //             all.insert(i * 8,1,str[i] % 2 + '0');
    //             str[i] /= 2;
    //         }
            
    //     }
    //     cout << all << endl;
    // }

    // int alen = all.length();
    // int * B_asc = new int[out - location];
    // int loc = 0;
    // for(int i = 0; i < alen;)
    // {
    //     for(int j = 0; j < 6 && i < alen; j++, i++)
    //     {
    //         B_asc[loc] *= 2;
    //         B_asc[loc] += (all[i] - '0');
    //     }

    //     cout << Base64[B_asc[loc]];
    //     loc++;
    // }
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {

        cout << "case #" << i << ":"<<endl;
        string str;
        cin >> str;

        trans(str);
        cout<<endl;
    }//

    return 0;
}