#include<iostream>

using namespace std;

void compress(unsigned long long a)
{   
    int binb[64] = {0};
    int flag = 0;
    int before = 0;
    
    
    
    //转换并储存数据
    for(int i = 0; i < 64; i++)
    {
        if( a & (1LL << 63) )
        {
            flag = 1;
            binb[i] = 1;
        }

        a <<= 1;

        if(flag)
            before++;
    }
    

    flag = 0;//初始化来第二波
    int count = 0;
    int bina[64] = {0};
    int after = 0;
    int place = 63;
    //从后往前

    for(int i = 0; i < before; )
    {   
        count = 0;//你注意一下你用了while(count--)  会变成-1的。
        if(binb[63 - i] == 0)
        {
            bina[place--] = 0;
            i++;
            after++;
            continue;
        }//0的情况
        else
        {
            while(binb[63 - i])
            {
                count++;
                i++;
            }
            
            // cout << " cout "<<count << endl;
            if(count <= 2)//1的情况分类讨论
            {
                while(count)
                {
                    bina[place--] = 1;
                    after++;
                    count--;
                }
                
            }
            else
            {
                //count从10进制变成2进制
                while(count)
                {
                    bina[place--] = (count % 2) ? 1 : 0;
                    count >>= 1;
                    after++;
                }
            }
            //cout << " cout "<<count << " i "<<i<<endl;
            // for(int i = 0; i < 64; i++)
            // {
            //     cout << bina[i];
            // }
            // cout<<endl;
        }
        
        
    }
    //和count同理
    unsigned long long num = 0;//储存也要ULL，别忘了。。。
    for(int i = 0;i < 64; i++)
    {
        num *= 2;
        num += bina[i];
    }

    
    cout << num <<","<<before<<","<<after;

}

int main()
{
    unsigned long long a;
    cin >> a;
    compress(a);
}

