#include<iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int z = 0; z < t; z++)
    {
        int line_len;
        cin >> line_len;
        getchar();//有换行符且用getline要记得getchar
        string all;
        getline(cin,all);
        int all_len = all.length();

        cout << "case #" << z << ":"<<endl;

        
        int i = 0;//遍历all的变量

        while(i < all_len)
        {
            
            for(; all[i] == ' '; i++);//处理开头的空格
            int line_loc = i;//每一行的开头
            int word_alen = 0;//记录一行的单词字母数
            int word_anum = 0;//记录单词数,对应的也是最 少空格数+1
            
            for(; word_alen + word_anum <= line_len && i < all_len ;) /*i越界问题。。。*/
            {
                int j = 0, k = i;
                while(all[k] != ' ' && k < all_len) /*l越界问题。。。*/
                {
                    j++;k++;//j记录下一个单词长度
                }
                if(j + word_alen + word_anum <= line_len)
                {
                    word_alen += j;
                    word_anum++;
                    //满足就放进去这一行
                    for(i = k; all[i] == ' '; i++);//继续下一个单词
                }
                else
                    break;
            }
            int empty = line_len - word_alen;//空格数量
            word_anum--;




            while(line_loc < i)
            {
                while(all[line_loc] != ' ' && line_loc < i)
                    cout << all[line_loc++];
                while(all[line_loc] ==' '&& line_loc < i)/*越界问题。。。*/
                    line_loc++;

                if(i == all_len && word_anum)
                    cout << ' ' ;//最后一行输出单个空格
                else
                {
                    int j = 0;//否则让一行的空格尽可能均分在右边
                    for(;word_anum && j < empty / word_anum; j++)
                    {
                        //首先你得输出，然后均分在右边用empty/word数量来操作
                        cout << " " ;
                    }
                    empty -= j;//对应也要减少
                }
                word_anum--;
            }
            cout << endl;


        }
        
    }

    return 0;
}

