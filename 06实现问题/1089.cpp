#include <stdio.h>
#include <string.h>
const int N = 111;
int dx[N] = {0},dy[N] = {0};
char order[N];
//***********************************************
int walk(int ab,int dxy,int dis_xy)//对于一次循环里的每一个状态，计算ab能否到达这一状态，第几次循环到达
{
    if(dis_xy > 0 && ab >= dxy && (ab - dxy) % dis_xy == 0)
        return (ab - dxy) / dis_xy;//等于0代表第一次循环就到达
    else if(dis_xy < 0 && ab <= dxy && (ab - dxy) % dis_xy == 0)
        return (ab - dxy) / dis_xy;//等于0代表第一次循环就到达
    else if(dis_xy == 0 && ab == dxy)
        return -2;//-2表示每次都可到达
    else
        return -1;//-1表示无法到达
}

/**********************************************/
int main(void)
{
    scanf("%s",order);
    int len=strlen(order);
    dx[0] = 0;
    dy[0] = 0;
    for(int i = 1; i <= len; i++)   //dx，dy的数量比order数加1
    {                               //遍历一次循环里能到达的状态
        dx[i] = dx[i-1];
        dy[i] = dy[i-1];
        switch(order[i-1])
        {
        case 'U':
            dy[i]++;
            break;
        case 'D':
            dy[i]--;
            break;
        case 'L':
            dx[i]--;
            break;
        case 'R':
            dx[i]++;
            break;
        }
    }
    int dis_x = dx[len];
    int dis_y = dy[len];
    //初始化完成


    int __;
    scanf("%d",&__);
    for(int _ = 0,a,b; _<__; _++) //OJ里单纯用来记问题数的量可以用下划线
    {                             //公司里不行，不然会被打 :)
        scanf("%d %d",&a,&b);
        //输入问题

        int ans = 0;
        for(int i = 0;i <= len; i++)
        {
            ans = 0;
            int can_reach_a = walk(a,dx[i],dis_x);
            int can_reach_b = walk(b,dy[i],dis_y);
            if(can_reach_a == -1 || can_reach_b == -1)//-1表示无法到达
                ans = 0;
            else if(can_reach_a == -2 || can_reach_b == -2)//-2表示每次都可到达
                ans = 1;
            else if(can_reach_a == can_reach_b)//表示在相同次循环到达
                ans = 1;
            else
                ans = 0;//表示在不同次循环到达
            if(ans)
                break;
        }
        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}