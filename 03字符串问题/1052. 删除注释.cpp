#include<iostream>
#include<stack>

using namespace std;

int main()
{
    string str;
    char c;
    while((c = getchar()) != EOF)
    {
        str += c;
    }

    int len = str.length();
    string erase;
    int commentOne = 0;
    int commentMuch = 0;
    int CHAR = 0;
    int STR = 0;
    for(int i = 0; i < len;i++)
    {
        FLAG:
        if(str[i] == '/' && str[i + 1] == '/')//单行注释见到换行符就不理
        {
            while(str[i] != '\n')
                i++;
            //cout << "1" << endl;
        }

        if(str[i] == '/' && str[i+1] =='*')//多行注释结束之后要注意后面是否继续是单行注释
        {
            i+=2;
            while (!(str[i] == '*' && str[i + 1] == '/'))
            {
                i++;
            }
            i += 2;
            goto FLAG;
        }

        if(str[i] =='\'')//单引号中可能会出现双引号
        {
            for(int j = 0; j <= 3; j++)
            {
                erase += str[i + j];
            }
            i += 4;
            goto FLAG;
        }

        if(str[i] == '"')//双引号要遇到这一行的最后一个双引号，然后把中间所有内容都加起来
        {
            int j = i;
            int k = i;
            while(str[i] != '\n')
            {
                if(str[i] == '"')
                    k = i;
                i++;
            }
            k++;
            for(int q = j; q < k; q++)
            {
                erase += str[q];
            }
            i = k;
            //cout << "3" << endl;
            goto FLAG;
        }



        erase += str[i];

//
    }

    //cout << str << endl;
    cout << erase << endl;


    return 0;
}
//遇见//之后碰到换行后面继续输出；
//遇见/*之后碰到*/继续放//