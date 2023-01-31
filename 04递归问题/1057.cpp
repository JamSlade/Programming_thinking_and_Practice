
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
string a[2000];
int i,t=1;
double f1(double a,char b,double c)//运算函数
{
    switch(b)
    {
        
        case'+':return a+c;
        
        case'-':return c-a;//调换减法和除法前后两数的位置
        case'*':return a*c;
        case'/':return c/a;
    }
}

double f2()
{
    int i=t;//t相当于一个指针
    if(a[i][0]>='0'&&a[i][0]<='9')//如果i的位置是一个数值
    {
        t++;//指针指向下一位
        return atof(a[i].c_str());//转换成浮点数
    }
    t++;//如果是运算符，指针指向下一位
    return f1(f2(),a[i][0],f2());//函数的参数是从右至左传递的
}

int main()
{
    string b;
    while(cin>>b)
        a[++i]=b;
    printf("%lf",f2());
    return 0;
}