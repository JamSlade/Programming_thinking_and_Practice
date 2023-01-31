#include<iostream>
#include<string>
#include<string.h>

using namespace std;


int main()
{
    int totalQ;
    cin >> totalQ;
    for(int i = 0 ; i < totalQ; i++)
    {
        int alpha[260];
        memset(alpha,-1,260*sizeof(int));
        string to_sort;
        cin >> to_sort;
        int length = to_sort.length();
        int base = 0;
        
        for(int j = 0; j < length; j++)
        {   
            int temp = (int)to_sort[j];
            
            if(alpha[temp] == -1)
            {
                // cout << base << " base" <<endl;
                base++;
                // cout << base << " base" <<endl;
                // cout << endl;
                if(base == 1)//只有一个字符也默认是二进制
                {
                    alpha[temp] = 1;
                }
                else if(base == 2)//两个字符默认二进制
                {
                    alpha[temp] = 0;
                }
                else
                {
                    alpha[temp] = base - 1;
                }
                //cout << alpha[temp] << " "<< temp <<" " << (char)temp <<endl;
            }
        }
        
        //解决完进制的对应后开始转化数据
        long long Dnum = 0;
        if(base == 1) base = 2;
        // cout << base <<"base";

        for(int j = 0; j < length; j++)
        {   
            int temp = (int)to_sort[j];
            int each_char = alpha[temp];
            Dnum *= base;
            Dnum += each_char ;
            
        }
        cout << "case #" << i << ":" << endl;
        cout << Dnum << endl;
    }
    // system("pause");
    return 0;

}