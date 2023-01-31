#include<iostream>

using namespace std;
string hexi = "0123456789abcdef";

int main()
{
    string a;
    cin >> a;
    int len = a.length();
    long trans = 0;
    int has_hex = 0;
    long arr[10000] = {0};
    for(int i = 0; i < len; i++)
    {
        if(a[i] == '0' && a[i + 1] == 'x')
        {
            i += 2;
            int flag = 0;
            while(hexi.find(a[i]) != hexi.npos)
            {
                arr[has_hex] *= 16;
                arr[has_hex] += hexi.find(a[i]);
                flag = 1;
                i++;
                //停止有两种情况，一个是遇见了其他字符，第二个是遇见了0x//
                if(a[i] == 0 && a[i + 1] == 'x')
                    break;
            }
            if(flag)
                has_hex++;

        }
        else
        {
            continue;
        }

    }

    for(int i = 0; i < has_hex; i++)
    {
        cout << arr[i] << " ";
    }
    if(!has_hex)
    {
        cout << "-1";
    }
}