#include<iostream>
#include<algorithm>
using namespace std;
class file
{
public:
    int year;
    int mon;
    int day;
    int hour;
    int min;
    long long size;
    string name;
    
};

bool Ncmp(const file A ,const file B)
{
    return (A.name < B.name);
};
bool Scmp(const file A ,const file B)
{
    if(A.size != B.size)
    {return (A.size < B.size);}
    else 
        return A.name < B.name;
    
};
bool Tcmp(const file A ,const file B)
{
    if(A.year < B.year)
    {return true;}
    else if(A.year > B.year)
    {return false;}
    else
    {
        if(A.mon < B.mon)
        {return true;}
        else if(A.mon > B.mon)
        {return false;}
        else
        {
            if(A.day < B.day)
            {return true;}
            else if(A.day > B.day)
            {return false;}
            else
            {
                if(A.hour < B.hour)
                {return true;}
                else if(A.hour > B.hour)
                {return false;}
                else
                {
                    if(A.min < B.min)
                    {return true;}
                    else if(A.min > B.min)
                    {return false;}
                    else
                    {
                        return(A.name < B.name);
                    }
                }
            }
        }
    }

};


void func(int total)
{
    file* F = new file[total];
    for(int i = 0; i < total; i++)
    {
        char c;
        cin >> F[i].year >> c >> F[i].mon >> c >> F[i].day >> F[i].hour >> c >> F[i].min >> F[i].size >> F[i].name;
    }

    string list,opera;//输入的操作有空格。。。
    
    cin>>list >> opera;

    if(opera == "/NAME")
    {
        sort(F,F+total,Ncmp);
    }
    else if (opera == "/SIZE")//
    {
        sort(F,F+total,Scmp);
    }
    else if (opera == "/TIME")
    {
        sort(F,F+total,Tcmp);
    }
    
    for(int i = 0; i < total; i++)
    {
        printf("%04d-%02d-%02d %02d:%02d%17lld ",F[i].year,F[i].mon,F[i].day,F[i].hour,F[i].min,F[i].size);\
        cout << F[i].name << endl;
    }
    cout << endl;

}

int main()
{
    int total = 1;
    
    
    while(total)
    {   
        cin >> total;
        func(total);
    }
        
    return 0;
    
    
}