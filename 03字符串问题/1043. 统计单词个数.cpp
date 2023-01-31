#include<iostream>

using namespace std;

string no_statistic[] = 
{
    "the","The","tHe","thE","THe","tHE","ThE","THE",
    "a","A",
    "an","An","AN","aN",
    "of","Of","OF","oF",
    "For","for","fOr","foR","FOr","FoR","fOR","FOR",
    "and","And","aNd","anD","ANd","AnD","ANd","AND"
};
//

int main()
{
    int t;
    cin >> t;
    getchar();
    for(int i = 0; i < t; i++)
    {
        string a;
        getline(cin, a);//
        int count = 0;
        int alen = a.length();
        for(int j = 0; j < alen; j++)
        {
            string b = "";
            while(a[j] != ' '  && j < alen)
            {
                b += a[j++];
            }

            int flag = 1;
            for(int k = 0; k < 33; k++)
            {
                
                if(b == no_statistic[k])
                {
                    flag = 0;
                    break;
                }
                
            }
            if(flag)
            {
                count++;
            }
        }

        cout << "case #" << i << ":"<<endl;
        cout << count << endl;
    }
}