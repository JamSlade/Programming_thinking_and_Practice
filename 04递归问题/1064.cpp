#include<iostream>
using namespace std;
typedef long long ll;
const int mo=10007;
ll dp[1010][1010];
int ans;
int main() {
    int t;
    cin>>t;
    ans=0;
    while(t¨C){
        ll a,b,k,n,m;
        cin>>a>>b>>k>>n>>m;
        a=a%mo;
        b=b%mo;
            for(int i=0;i<=n;i++){
                for(int j=0;j<=m;j++){
                    if(i+j==0) dp[i][j]=1;
                    else if(i==0) dp[i][j]=bdp[i][j-1]%mo;
                    else if(j==0) dp[i][j]=adp[i-1][j]%mo;
                    else dp[i][j]=(adp[i-1][j]+bdp[i][j-1])%mo;
                }
            }
        cout<<¡±case #¡±<<ans++<<¡±:¡±<<endl;
        cout<<dp[n][m]<<endl;
    }
    return 0;
}