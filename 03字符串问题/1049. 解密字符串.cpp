#include<iostream>
#include<cstring>

using namespace std;

int alpha[130];
string number[10] = 
{   "ZERO","ONE","TWO",
    "THREE","FOUR",
    "FIVE","SIX",
    "SEVEN","EIGHT","NINE"
};
//0 Z
//1 除去其他数字 O
//2 W
//3 把0和4除掉就是R
//4 U
//5 除去4剩F
//6 X
//7 V 除去 5
//8 G
//9 与1差异是I

void trans(string str)
{
    memset(alpha,0,520);
    int NUM[10] = {0};

    int len = str.length();
    for(int i = 0; i < len; i++)
    {
        alpha[str[i]]++;
    }

    while(alpha['Z'])//0
    {
        alpha['Z']--;
        alpha['E']--;
        alpha['R']--;
        alpha['O']--;
        NUM[0]++;

    }
    while(alpha['W'])//2
    {
        alpha['T']--;
        alpha['W']--;
        alpha['O']--;
        NUM[2]++;
    }
    while(alpha['U'])//4
    {
        alpha['F']--;
        alpha['O']--;
        alpha['U']--;
        alpha['R']--;
        NUM[4]++;
    }
    while(alpha['F'])//5
    {
        alpha['F']--;
        alpha['I']--;
        alpha['V']--;
        alpha['E']--;
        NUM[5]++;
    }
    while(alpha['X'])//6
    {
        alpha['S']--;
        alpha['I']--;
        alpha['X']--;
        NUM[6]++;
    }
    while(alpha['V'])//7
    {
        alpha['S']--;
        alpha['E']--;
        alpha['V']--;
        alpha['E']--;
        alpha['N']--;
        NUM[7]++;
    }
    while(alpha['G'])//8
    {
        alpha['E']--;
        alpha['I']--;
        alpha['G']--;
        alpha['H']--;
        alpha['T']--;
        NUM[8]++;
    }
    while(alpha['I'])//9
    {
        alpha['N']--;
        alpha['I']--;
        alpha['N']--;
        alpha['E']--;
        NUM[9]++;
    }
    while(alpha['O'])//服了，1到10都能漏
    {
        alpha['O']--;
        alpha['N']--;
        alpha['E']--;
        NUM[1]++;
    }
    while(alpha['R'])//1
    {
        alpha['T']--;
        alpha['H']--;
        alpha['E']-=2;
        alpha['R']--;
        
        NUM[3]++;
    }

    for(int i = 0; i < 10 ; i++)
    {
        while(NUM[i])
        {
            NUM[i]--;
            cout << i ;
        }
    }
    
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        cout << "case #" << i << ":"<<endl;
        trans(str);
        cout << endl;
    }

    return 0;
}