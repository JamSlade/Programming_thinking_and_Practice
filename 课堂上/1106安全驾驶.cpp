#include<iostream>
#include<stdlib.h>
#include<limits>
using namespace std;
//注意初始化问题
class car
{
public:
    long advance;
    long remain;
    long speed;
    double to_time;

};

int main()
{
    long distance;
    car C[1010];
    int number;
    double speed;
    

    cin >> distance;
    cin >> number;
    for(int i = 0; i < number; i++)
    {
        cin >> C[i].advance;
        cin >> C[i].speed;

    }

    for(int i = 0; i < number; i++)
    {
        C[i].to_time = (double)(distance - C[i].advance) / (double)(C[i].speed);

    }

    double times = 0;
    for(int i = 0; i < number; i++)
    {
        if(times < C[i].to_time)
        {times = C[i].to_time;}
    }
    speed = distance / times;
    printf("%.6f",speed);
    return 0;
}