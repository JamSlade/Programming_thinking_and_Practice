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
        ll all = 0;

        
        sort(C,C+n,cmp);


        ll m_r_max = 0;//找出来前m个数最大的半径，作为底部
        ll m_la_min = LONG_LONG_MAX;
        for(int i = 0; i < m; i++)
        {
            if(m_r_max < C[i].r)
            {
                m_r_max = C[i].r;
            }
            if(m_la_min > C[i].lateral)
            {
                m_la_min = C[i].lateral;
            }
            
        }


        ll temp = 0;
        for(int i = m; i < n; i++)
        {
            if(C[i].surface > (m_la_min + m_r_max * m_r_max) && C[i].r >= m_r_max && C[i].surface > temp)
            {
                //你忘记了surface要大于temp。。。不然可能会偏小。。。服了
                temp = C[i].surface;
            }    
        }

        for(int i = 0; i < m; i++)
        {
            all += C[i].lateral;
        }

        if(temp)
        {
            all -= m_la_min ;
            all += temp;
        }
        else
        {
            all += (m_r_max * m_r_max);
        }
        cout << all << endl;

        return 0;
    }