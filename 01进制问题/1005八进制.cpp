#include<iostream>
#include<string.h>
using namespace  std;


// void trans(int q)
// {

//     string Octal;
//     char decimal[1000];
//     /*
//     ①   八进制转换十进制时
//         从后往前，每次取出每一位的数（8）
//         将其与上一次除法运算得到的商相加
//         再除以8
//     */
//     cin >> Octal;
//     int num;//记录十位数
//     int len = Octal.length() - 1;
//     int Dlen = 0;//记录十进制数的位数

//     for(; len != 1; len--)
//     {
//         num = Octal[len] - '0';
//         int digit = 0;//记录mod之后的数
//         int j = 0;//从前往后
//         do
//         {
//             int temp;
//             if(j < Dlen)
//             {
//                 temp = num * 10 + decimal[j] - '0';
//             }
//             else
//             {
//                 temp = num * 10;
//                 //后面没有存放的数据了，只能继续往后借0
//             }
//             digit = temp % 8;
//             decimal[j++] = temp / 8 +'0';//别忘了j是要往后一位的，然后你是字符别忘记加0
//             num = digit;
//         }
//         while(digit || j < Dlen);
//         Dlen = j;//更新十进制的位数
//     }
    
//     cout << "case #" << q << ":" << endl <<"0.";
//     for(int i = 0; i < Dlen; i++)
//     {
//         cout << decimal[i];
//     }
//     cout << endl;
// }
void add(char *a, char *b)
{
    int alen = strlen(a);
    int blen = strlen(b);
    char * OP = a;//a+b的大小赋值给a（OP）

    int len = (alen > blen) ? alen : blen;
    OP[len] = '\0';
    int ten_dig = 0;
    int c = 0;
    for(int i = len - 1; i > 1; i--)
    {
        //注意可能a b小数点后的数不一样，所以要借0
        int da = (i < alen) ? a[i] - '0' : 0;
        int db = (i < blen) ? b[i] - '0' : 0;
        
        int sum = da + db + c;
        c = sum / 10;
        OP[i] = sum % 10 + '0';//别忘记char；

    }
    OP[1] = '.';
    OP[0] =  a[0] + b[0] - '0' + c;
    
}


void trans01(int a)
{
    char oct[1000];
    scanf("%s",oct);
    cout << "case #" << a << ":"<<endl;
    char c[1000] = {'0'};
    c[1] = '.';
    
    int len = strlen(oct);
    for(int i = 2; i < len; i++)
    {
        char b[1000] = {'0'};
        b[1] = '.';
        for(int j = 2; j <= i; j++)
        {
            
        }
    }
}



int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        //trans(i);
        trans01(i);
    }
}