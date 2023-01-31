#include<iostream>

using namespace std;

int times(int ALLf, int floor, int minute, int end)
{
    if(minute == 0 && floor == end)
    {return 1;}
    else if(minute == 0 && floor != end)
    {return 0;}

    if(floor == 1)
    {return times(ALLf,floor + 1, minute - 1,end);}
    if(floor == ALLf)
    {return times(ALLf,floor - 1, minute - 1,end);}

    return times(ALLf,floor - 1, minute - 1,end) + times(ALLf,floor + 1, minute - 1,end);
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {

        long long n,p,m,t;
        cin >> n >> p >> m >> t;
        cout << times(n,p,m,t) << endl;

    }

    return 0;
}

