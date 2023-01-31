#include<iostream>
#include<cmath>
#define db double
using namespace std;

struct polar
{
    db x;
    db y;
    db angle;
    db chord;

    db hypoteuse(db x, db y)
    {
        db temp = pow(x,2) + pow(y,2);
        temp = sqrt(temp);
        return temp;
    }

    db Pangle(db x ,db y)
    {
        if(x == 0 && y > 0)
        {return acos(0);}
        else if(x == 0 && y < 0)
        {return 3 * acos(0);}

        db k = (db)y / (db)x;
        
        if(x > 0 && y >= 0)
        {return atan(k);}
        else if(x > 0 && y < 0)
        {return 4 *acos(0) + atan(k);}
        else if(x < 0 && y > 0)
        {return 2 * acos(0) + atan(k);}
        else
        {return  2 * acos(0) + atan(k);}

    }

    void init()
    {
        chord = hypoteuse(x,y);
        angle = Pangle(x,y);
    }
};

int cmp(const void *q1, const void *q2)
{
    polar * p1 = (polar *)q1;
    polar * p2 = (polar *)q2;

    if(p1->angle == p2->angle)
    {
        if(p1->chord > p2->chord)
        {return -1;}
        else
        {return 1;}
    }
    if(p1->angle > p2->angle)
    {return 1;}
    else
    return -1;
}

void print(polar *a,int len)
{
    for(int i = 0; i < len; i++)
        printf("(%.4lf,%.4lf)",a[i].chord,a[i].angle);
}



int main()
{
    int total;
    cin >> total;
    
    for(int i = 0; i < total; i++)
    {
        int allp;
        cin >> allp;
        polar * point = new polar[allp];

        for(int j = 0; j < allp; j++)
        {
            cin >> point[j].x >> point[j].y;
            point[j].init();
        }
        cout << "case #"<<i<<":" << endl;
        // for(int i = 0; i < allp; i++)
        // {
        //     printf("(%.4lf,%.4lf)\n",point[i].chord,point[i].angle);
        // }
        
        
        qsort(point,allp,sizeof(polar),cmp);
        for(int i = 0; i < allp; i++)
        {
            printf("(%.4lf,%.4lf)\n",point[i].chord,point[i].angle);
        }
        delete point;
    }
    
}
