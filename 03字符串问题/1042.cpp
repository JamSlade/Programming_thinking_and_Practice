#include<iostream>
#include<algorithm>
#include<deque>
#include<cstring>
using namespace std;

//本题实际上是把字符串进行去重之后比较看是否相等，然后拿字符串长度来进行比较
//取得最小值应该是拿中间长度的数据来比大小
string duplicate(string a)
{
    int len = a.length();
    deque<char> b;
    b.push_back(a[0]);

    for(int i = 1; i < len; i++)
    {
        if(a[i] == b.back())
        {
            continue;
        }
        else
        {
           b.push_back(a[i]);
        }
    }

    string c;
    for(deque<char>::iterator it = b.begin(); it != b.end(); it++)
    {
        c += *it;
    }
    return c;
}

//用长数组记录整个数据
//接下来把各个部分转换成str然后去重
bool cmp(int a, int b)
{
    return (a < b);
}

int change_min(int *arrl,int t)
{
    int mid = t / 2;
    int mid1 = mid;
    if(!(t % 2))
    {
        mid1--;
    }

    long long times = 0;
    for(int i = 0; i < mid; i++)
    {
        times += arrl[mid] - arrl[i];
    }
    for(int i = mid + 1; i < t; i++)
    {
        times += arrl[i] - arrl[mid];
    }

    long long times1 = 0;
    for(int i = 0; i < mid1; i++)
    {
        times1 += arrl[mid1] - arrl[i];
    }
    for(int i = mid1 + 1; i < t; i++)
    {
        times1 += arrl[i] - arrl[mid1];
    }
    return (times > times1) ? times : times1;
}


int main()
{
    int t;
    cin >> t;
    string *str = new string[t];
    string *str1 = new string[t];

    for(int i = 0; i < t; i++)
    {
        cin >> str[i];
        str1[i] = duplicate(str[i]);
    }

    for(int i = 0; i < t - 1; i++)
    {
        if (str1[i] != str1[i + 1])
        {
            cout << "-1" << endl;
            return 0;
        }
    }


    
    int len = str1[0].length();
    int * arrl = new int[t];
    int * location = new int[t];//记录位置

    memset(arrl, 0 ,4 * t);
    memset(location, 0 ,4 * t);
    long long T = 0;


    for(int i = 0; i < len; i++)//从最简的数据开始分割
    {
        for(int j = 0; j < t; j++)//每个输入进来的字符串都要统计
        {
            int len = str[j].length();
            for(;location[j] < len; location[j]++)//每个字符串的每个数字
            {
                if(str[j][location[j]] == str1[0][i])
                {arrl[j]++;}
                else
                {break;}//
            }
        }

        //统计好单个字符在各个字符串出现情况后后，开始找中位数并计算
        sort(arrl , arrl + t, cmp);


        T += change_min(arrl,t);
        
        
        //重新初始化等下一个循环
        memset(arrl, 0 ,4 * t);
    }
    

    cout << T << endl;


    return 0;
}