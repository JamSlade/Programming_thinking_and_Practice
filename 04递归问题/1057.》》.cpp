#include<iostream>
#include<deque>

using namespace std;

double trans(deque<string> & a) {
    string s = a.front();
	a.pop_front();
	switch(s[0]) {
		case '+':
			return trans(a) + trans(a); //递归调用，求出自身包含的波兰式
		case '-':
			return trans(a) - trans(a);
		case '*':
			return trans(a) * trans(a);
		case '/':
			return trans(a) / trans(a);
		default:
			return atof(s.c_str()); //将char转换成对应的浮点数
			break;
	}
}

int main()
{
    int t;
    cin >> t;
    getchar();
    char c = getchar();
    for(int i = 0; i < t; i++)
    {
        deque<string>s;
        string str;
        cout << "case #" << i << ":"<<endl;
        while(c != '\n' && c != EOF)
        {
            if(c == ' ')
            {
                c = getchar();
                s.push_back(str);
                str = "";
                continue;
            }
            str += c;
            c = getchar();
        }

        s.push_back(str);
        str = "";

        // while(!s.empty())
        // {
        //     cout << s.back() << endl;
        //     s.pop_back();
        // }
        printf("%.6lf\n",trans(s));
        c = getchar();
    }

    return 0;
}