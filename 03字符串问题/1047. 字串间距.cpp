#include<iostream>

using namespace std;

int distance(const string &s1, const string &s2, const string &s)
{
    int dis;
    int slen = s.length();
    int s1len = s1.length();
    int s2len = s2.length();

    int s1back = 0;
    int s2front = 0;
    int flag1 = 0;
    for(int i = 0; i < slen; i++)
    {
        int flag = 0;
        for(int j = 0; j < s1len && i + j< slen; j++)
        {
            if(s1[j] != s[j + i])
            {break;}
            if(j == s1len - 1)
            {flag = 1;}
            if(flag)
            {
                s1back = i + j;
                flag1 = 1;
                goto FLAG;
            }
        }
    }

    FLAG://
    int flag2 = 0;
    for(int i = s1back + 1; i < slen; i++)
    {
        int flag = 0;
        for(int j = 0; j < s2len && i + j < slen; j++)
        {
            if(s2[j] != s[j + i])
            {break;}
            if(j == s2len - 1)
            {
                flag2 = 1;
                flag = 1;
            }
            if(flag)
            {s2front = i;}
        }


    }

    dis = s2front - s1back - 1;//¾àÀëÒª¶à¼õ1

    return ((flag2 && flag1) ? dis : 0);
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string s1, s2, s;
        cin >> s1 >> s2 >> s;
        cout << "case #" << i << ":"<<endl;
        int dis1 = distance(s1,s2,s);
        int dis2 = distance(s2,s1,s);
        cout << ((dis1 < dis2) ? dis2 : dis1) <<endl;
    }

    return 0;
}