#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct point
{
    int x;
    int y;
};

int func(int x, int px, int dx)
{
    if(dx == 0 && x == px)
        return -2;//每一次循环都能到达
    else if(dx > 0 && x >= px && (x - px) % dx == 0 )
        return (x - px) / dx; 
    else if(dx < 0 && x <= px && (x - px) % dx == 0 )
        return (x - px) / dx;
    else 
        return -1; 
}

int main()
{
    point p[200];
    p[0].x = p[0].y = 0;
    string s;
    cin >> s;
    int len = s.length();

    for(int i = 0; i < len; i++)
    {
        p[i + 1].x = p[i].x;
        p[i + 1].y = p[i].y;
        switch (s[i])
        {
        case 'U':
            p[i+1].y += 1;
            break;
        case 'D':
            p[i+1].y -= 1;
            break;
        case 'L':
            p[i+1].x -= 1;
            break;
        case 'R':
            p[i+1].x += 1;
            break;
        }
    }    

    int dx = p[len].x, dy = p[len].y;

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int x,y;
        cin >> x >> y;
        int r_x = 0, r_y = 0, r_p = 0;
        for(int j = 0; j <= len ; j++)
        {
            r_x = func(x, p[j].x, dx);
            r_y = func(y, p[j].y, dy);
            if(r_x == -1 || r_y == -1)
                r_p = 0;
            else if(r_x == -2 || r_y == -2)
                r_p = 1;
            else if(r_x == r_y && r_x != -1)
                r_p = 1;
            else r_p = 0;

            if(r_p)
                break;
        }
        if(r_p)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
    return 0;
}