#include<iostream>
#include<algorithm>

using namespace std;

struct alpha
{
    double fre;
    char letter;
    int ord;
};

alpha A[52];
//加0在char数组的末尾
//相同频率不只是大小写，不同字母如果也有相同频率要看字母表order
bool cmp(alpha a,alpha b)
{
    if(a.fre == b.fre)
    {
        return(a.ord < b.ord);
    }
    return(a.fre > b.fre);
}

bool scmp(char a, char b)
{
    int aloc, bloc;
    for(int i = 0; i < 52; i++)
    {
        if(a == A[i].letter)
        aloc = i;
        if(b == A[i].letter)
        bloc = i;
    }
    return (aloc < bloc);
}

int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        for(int j = 0; j < 52; j+=2)
        {
            double temp;
            cin >> temp;
            A[j].fre = A[j + 1].fre = temp;
            A[j].letter = j / 2 + 'a';
            A[j].ord = j;
            A[j + 1].ord = j + 1;
            A[j + 1].letter =  j / 2 + 'A';

        }
        sort(A,A + 52, cmp);

        // cout << endl;
        // for(int j = 0; j < 52; j++)
        // {
        //     cout << A[j].letter << " " << A[j].fre << endl;
        // }
        // cout << endl;
        getchar();
        char str[200] = {0};
        int len = 0;
        char c = getchar();
        while(c != '\n')
        {
            str[len++] = c;
            c = getchar();
        }

        //str[len] = 0;//用char数组一定要记得结尾加0
        sort(str,str + len, scmp);
        cout << "case #" << i << ":" << endl;
        cout << str << endl;
    }


    return 0;
}