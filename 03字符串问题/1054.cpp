#include<iostream>
#include<set>
using namespace std;
//
set<string> S[26];
int main()
{
    int n;
    string a;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(a[0] >= 'a' && a[0] <='z')
            S[a[0] - 'a'].insert(a);
        if(a[0] >= 'A' && a[0] <='Z')
            S[a[0] - 'A'].insert(a);
    }

    cin >> a;
    int len = a.length();
    for(int i = 0; i < len; i++)
    {   
        string max;
        int max_len = 0;
        
        for(set<string>::iterator it = ((a[i]>= 'a' && a[i] <='z') ? S[a[i] - 'a'].begin() : S[a[i] - 'A'].begin());
         it != ((a[i]>= 'a' && a[i] <='z') ? S[a[i] - 'a'].end() : S[a[i] - 'A'].end()); it++)
        {
            int flag = 1;//判定字典有没有这个元素
            int d_len = it->length();
            for(int j = 0; j < d_len && i + j < len; j++)
            {
                if(it->at(j) != a[i + j] || i + d_len > len)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                if(d_len > max_len)
                {
                    max = *it;
                    max_len = d_len;
                }
            }
        }
        //找出来最大的分词之后要输出并让i移到新的位置；
        if(max_len >= 1)
        {
            cout << max << " ";
            i += max_len - 1;
        }
        else
        {
            cout << a[i] << " ";
        }

    }
    cout << endl;

}