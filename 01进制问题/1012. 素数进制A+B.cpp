#include<iostream>
#include<string.h>
#include<stack>
#include<deque>

using namespace std;

int base[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main()
{
    int total;
    cin >> total;
    getchar();
    for(int i = 0 ; i < total; i++)
    {
        
        cout << "case #" << i<<":"<<endl;

        stack<long long> fir;
        stack<long long> sec;

        int flen = 0;
        char c;
        while((c = getchar()) != ' ')
        {
            if(c == ',')
            {continue;}
            
            int temp = 0;
            while(c != ',' && c != ' ')
            {
                temp *= 10;
                temp += (c - '0');
                c = getchar();
                if(c == ' ')
                {goto FLAG1;}//经典死循环，goto，多重循环的神
            }
            FLAG1:
            fir.push(temp);

            if(c == ' ')
            {goto FLAG2;}
        }


        FLAG2:
        int slen = 0;
        while((c = getchar()) != '\n')
        {
            if(c == ',')
            {continue;}
            
            int temp = 0;
            while(c != ',' && c != '\n')
            {
                temp *= 10;
                temp += (c - '0');
                c = getchar();
                if(c == '\n')
                {goto FLAG3;}
            }
            FLAG3:
            sec.push(temp);

            if(c == '\n')
            {goto FLAG4;}
        }
       
        
        FLAG4:

        //把他们加起来
        deque<long long>sum;
        int min_size = (fir.size() > sec.size() ? sec.size() : fir.size());
        int max_size = (fir.size() < sec.size() ? sec.size() : fir.size());
        while(!fir.empty() && !sec.empty())
        {
            sum.push_front(fir.top() + sec.top());
            fir.pop();
            sec.pop();
        }
        while(!fir.empty())
        {
            sum.push_front(fir.top());
            fir.pop();
        }

        while(!sec.empty())
        {
            sum.push_front(sec.top());
            sec.pop();
        }

        //在front一直加，所以从back拿小的位数再放回front
        int len = sum.size();
        int carry = 0;
        for(int i = 0; i < len; i++)
        {
            
            int temp = sum.back();
            temp += carry;
            carry = 0;//注意你的carry每一次都要变成0
            if(temp >= base[i])//别忘记等于！！！
            {
                carry = temp / base[i];
                temp %= base[i];
            }
            sum.pop_back();
            sum.push_front(temp);

        }
        if(carry)
        {
            sum.push_front(carry);
        }

        deque<long long> :: iterator it = sum.begin();
        for(; it != sum.end() - 1; it++)
        {
            cout << *it << ",";
        }
        cout << *it << endl;
    }
    
}