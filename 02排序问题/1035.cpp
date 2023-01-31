    #include<iostream>
    #include<algorithm>
    #include<climits>
    #define ll long long
    using namespace std;

    struct cylinder
    {
        ll h;
        ll r;
        ll surface;
        ll floor;
        ll lateral;

        void init()
        {
            floor = r * r;
            lateral = 2 * r * h;
            surface = floor + lateral;//可视化应该只有一个底面和侧面
        }

    };

    //  本来只需要前m个数据，如果 m-n 的数据不进行交换
    //  我们直接找出来前m个数据中最大的半径的圆柱体作为底面即可

    //  但是如果我们要从 m-n 数据之间找数据替换，有什么条件呢？
    //  从 m-n数据之间找数据只能放底层吧，放其他地方会导致侧面积缩小
    //  所以放 m-n 到底层 表面积产生了什么变化？
    //  首先最底层的底面积少了，齐次，最小的侧面积减少了;

    bool cmp(cylinder a, cylinder b)
    {
        return(a.lateral > b.lateral);
    }

    int main()
    {
        int n,m;
        cin >> n >> m;
        cylinder * C = new cylinder[n];
        for(int i = 0; i < n ;i++)
        {
            cin >> C[i].r >> C[i].h;
            C[i].init();
            
        }

        
        sort(C,C+n,cmp);

        ll all = 0;
        for(int i = 0; i < n; i++)
        {
            ll each_max = 0;
            int qual = 0;

            each_max += C[i].surface;
            for(int j = 0; j < n; j++)
            {
                if(j == i)
                {
                    continue;//
                }
                
                
                if(qual == m - 1)
                {
                    break;
                }//这个if和下一个if不要换。。仔细想想为啥
                if(C[i].r >= C[j].r)
                {
                    qual ++;
                    each_max += C[j].lateral;
                }
            }

            if(qual == m - 1 && each_max > all)
            {
                all = each_max;
            }
        }

        cout << all;

        return 0;
    }