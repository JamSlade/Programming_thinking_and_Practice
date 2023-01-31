#include<iostream>

int arr[10000];
//
int main()
{
    std::string s;
    std::cin >> s;
    int len = s.length();
    for(int i = len - 1,j = 0; i >= 0 ;j++, i--)
    {
        arr[j] = s[i] - '0'; 
    }
    arr[0]++;
    if(arr[0]>=10)
    {
        int loc = 0;
        while(arr[loc] >= 10 && loc < len)
        {
            arr[loc]-=10; arr[loc+1]++; loc++;
            if(loc == len)
                len++;
        }
    }
    while(1)
    {
        FLAG:
        int temp = 0;
        for(int i = 0; i < len; i++)
        {
            temp += arr[i];
            if(arr[i] == 9)
            {
                arr[i + 1]++;
                for(int j = i; j >= 0; j--)
                    arr[j] = 0;
                
                if(i == len - 1)
                    len++;
                while(arr[i] >= 10)
                {
                    arr[i + 1] ++;
                    arr[i]-=10;
                    i++;
                    if(i == len - 1)
                        len++;
                }
                goto FLAG;
            }
        }

        if(temp % 9 == 0)
        {
            arr[0]++;
        }
        else
        {
            for(int i = len - 1; i >= 0; i--)
            std::cout << arr[i] ;
            break;
        }
    }

}