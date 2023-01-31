#include<iostream>

using namespace std;

int pri[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149};
int DEX[1000];

void carry(int * dig)
{
    for(int i = 999; i > 0; i--)
    {
        dig[i - 1] += dig[i] / 10;
        dig[i] %= 10;
    }
}

void mult(int * dig, int count)
{
    for(int i = 999; i >= 0; i--)
    {
        dig[i] *= pri[count];
    }
    carry(dig);
}

void add(int * dig, int num)
{
    int count = 999;
    while(num)
    {
        dig[count--] += num % 10;
        num /= 10;
    }
    
    carry(dig);
}

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int count = 0;
    int dig[1000];
    int temp = 0;
    for(int i = 0; i < len; i++)
    {
        
        switch (s[i])
        {
        case ',':
            dig[count++] = temp;
            temp = 0;
            break;
        
        default:
            temp *= 10;
            temp += s[i] - '0';
            break;
        }
    }
    
    dig[count] = temp;//别忘了末尾，还有不用++

    for(int i = 0; i <= count; i++)
    {
        mult(DEX, count - i);
        add(DEX,dig[i]);
    }

    count = 0;
    while(!DEX[count] && count != 999)//别忘了0
        count++;
    while(count < 1000)
    {
        
        if(count == 999)
            cout << DEX[count++];
        else
            cout << DEX[count++];
    }

}