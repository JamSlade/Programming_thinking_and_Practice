#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main()
{
    int W,H;
    cin >> W >> H;
    int arr[200][200]; 
    int brr[200][200];
    memset(arr,0,sizeof(arr));
    memset(brr,0,sizeof(brr));
    
    for(int i = 1; i <= H; i++)
        for(int j = 1; j <= W; j++)
            cin >> arr[j][i];
    
    for(int y = 2; y < H; y++)
        for(int x = 2; x < W; x++)
        {
            vector<int> v;
            v.push_back(arr[x][y] <= arr[x - 1][y - 1]);
            v.push_back(arr[x][y] <= arr[x][y - 1]);
            v.push_back(arr[x][y] <= arr[x + 1][y - 1]);
            v.push_back(arr[x][y] <= arr[x + 1][y]);
            v.push_back(arr[x][y] <= arr[x + 1][y + 1]);
            v.push_back(arr[x][y] <= arr[x][y + 1]);
            v.push_back(arr[x][y] <= arr[x - 1][y + 1]);
            v.push_back(arr[x][y] <= arr[x - 1][y]);
            for(int i = 0; i < 8; i++)
                v.push_back(v[i]);
            
            int min = 300;
            for(int i = 0; i < 8; i++)
            {
                int temp = 0;
                for(int j = i, k = 0; k < 8; k++,j++)
                {
                    temp *= 2;
                    temp += v[j];
                }
                if(temp < min)
                    min = temp;
            }
            brr[x][y] = min;
        }
    for(int y = 2; y < H; y++)
    {
        for(int x = 2; x < W - 1; x++)
            cout << brr[x][y] << " ";
        cout << brr[W - 1][y] << endl;
    }
        
}