#include<iostream>
#include<stack>
using namespace std;

string HEXI = "0123456789ABCDEF";

struct DATA
{
    string all;
    char location;
    
    int judge;//异或运算
    int check;//储存数据的
    bool put;

    int hour,min,sec;

    string longititude;
    double lon;
    char EW;
    stack<char> comma;

    void init()
    {
        
        location = 0;
        judge = 'G';
        check = 0;
        put = false;

        hour = 0;
        min = 0;
        sec = 0;
        
        // EW = '\0';
        // lon = 0;
        // longititude = "";

        while(!comma.empty())
            comma.pop();
    }//

    void test()
    {
        cout << "all "  << all << endl;
        cout << "location "  << location << endl << endl;

        cout << "hour "  << hour << endl;
        cout << "min "  << min << endl;
        cout << "sec "  << sec << endl<<endl;

        // cout << "longititude "  << longititude << endl;
        // cout << "lon "  << lon << endl;
        // cout << "EW "  << EW << endl;

        cout << "check "  << check << endl;
        cout << "judge "  << judge << endl;
        cout << "put "  << put << endl;
    }

    void out()
    {
        
        if(put)
            printf("%02d:%02d:%02d",hour,min,sec);
    }

    void handleDATA()
    {
        bool XOR = true;
        int len = all.length();

        for(int i = 2; i < len; i++)
        {
            if(all[i] == '*')
                XOR = false;

            if(XOR)
                judge ^= all[i];
        }



        for(int i = 2; i < len; i++)
        {
            
            
            if(all[i] == ',')//对应的i还是逗号
                comma.push(',');


            if(comma.size() == 1)//处理时间
            {//此时对应的a[i]是','
                hour += all[i + 1] -'0';
                hour *= 10;
                hour += all[i + 2] - '0';

                min += all[i + 3] -'0';
                min *= 10;
                min += all[i + 4] - '0';

                sec += all[i + 5] -'0';
                sec *= 10;
                sec += all[i + 6] - '0';
                i++;//别忘记XOR运算
                
                while(comma.size() == 1)
                {
                    if(all[i] != ',')
                        i++;
                    else
                        comma.push(',');
                }//不用减了，因为前面有+的步骤

                hour += 8;
                if(hour >= 24)
                    hour -= 24;
            }

            if(comma.size() == 2)//处理定位
            {
                location = all[i + 1];
                i++;
            }

            // if(comma.size() == 5)
            // {
            //     i++;
            //     while(comma.size() == 5)
            //     {
            //         if(all[i] == ',')
            //         {
            //             comma.push(',');
            //             break;
            //         }
            //         longititude += all[i];
            //         i++;
            //     }
            //     for(int i = 0; i < 3; i++)
            //     {
            //         lon *= 10;
            //         lon += longititude[i] - '0';
            //     }
            //     lon += (longititude[3] - '0') / (double)10;
                
            // }
            

            // if(comma.size() == 6)
            // {
            //     EW = all[i + 1];
            //     i++;
            // }

            if(all[i] == '*')
            {
                i++;
                while(i < len)
                {
                    check *= 16;
                    check += HEXI.find(all[i]);
                    i++;
                }
            }

            if(location == 'A' && check == judge)
            {put = true;}

            

        }
    }


    void transDATA()
    {

    }

};

int main()
{
    string t;
    DATA D;
    int hour;
    int sec;
    int min;
    while (cin >> t)
    {
        if(t != "END")
        {
            D.all = t;
            D.init();
            D.handleDATA();
            if(D.put)
            {
                hour = D.hour;
                min = D.min;
                sec = D.sec;
            }
        }
        
        if(t == "END")
        {
            
            printf("%02d:%02d:%02d",hour,min,sec);
            break;
        }
        
        

    }


    return 0;
}
    