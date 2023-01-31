#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int n=31,m=63;
ll dp[n],dpa[n],dpb[n],dpk[n];
ll p2[m];
int main()
{
    int tt;
    int i,a,b,k;
    int p,q,r;
    scanf("%d",&tt);
    p2[0]=1;
    for (i=1;i<m;i++) p2[i]=p2[i-1]<<1;
    while (tt--)
    {
        scanf("%d%d%d",&a,&b,&k);
        for (i=1;i<n;i++)
        {
            r=(k&p2[i-1])>0;
            switch (r)
            {
            case 0: // k=0;
                dpk[i]=3*dpk[i-1]; break; //
            case 1: // k=1;
                dpk[i]=dpk[i-1]+3*p2[2*i-2]; break; // ?
            }
        }
        for (i=1;i<n;i++)
        {
            p=(a&p2[i-1])>0; r=(k&p2[i-1])>0;
            switch (p*2+r)
            {
            case 0: // a=0; k=0;
                dpa[i]=2*dpa[i-1]; break; //
            case 1: // a=0; k=1;
                dpa[i]=(a&p2[i-1]-1)*p2[i]; break; //
            case 2: // a=1; k=0;
                dpa[i]=dpa[i-1]+2*dpk[i-1]; break; //
            case 3: // a=1; k=1;
                dpa[i]=dpa[i-1]+(a&p2[i-1]-1)*p2[i-1]+p2[2*i-1]; break;
            }
        }
        for (i=1;i<n;i++)
        {
            q=(b&p2[i-1])>0; r=(k&p2[i-1])>0;
            switch (q*2+r)
            {
            case 0: // b=0; k=0;
                dpb[i]=2*dpb[i-1]; break;
            case 1: // b=0; k=1;
                dpb[i]=(b&p2[i-1]-1)*p2[i]; break;
            case 2: // b=1; k=0;
                dpb[i]=dpb[i-1]+2*dpk[i-1]; break;
            case 3: // b=1; k=1;
                dpb[i]=dpb[i-1]+(b&p2[i-1]-1)*p2[i-1]+p2[2*i-1]; break;
            }
        }
        for (i=1;i<n;i++)
        {
            p=(a&p2[i-1])>0; q=(b&p2[i-1])>0; r=(k&p2[i-1])>0;
            switch (p*4+q*2+r)
            {
            case 0: // a=0; b=0; k=0;
                dp[i]=dp[i-1]; break; //
            case 1: // a=0; b=0; k=1;
                dp[i]=(a&p2[i]-1)*(b&p2[i]-1); break; //
            case 2: // a=0; b=1; k=0;
                dp[i]=dp[i-1]+dpa[i-1]; break; //
            case 3: // a=0; b=1; k=1;
                dp[i]=(a&p2[i]-1)*(b&p2[i]-1); break; //
            case 4: // a=1; b=0; k=0;
                dp[i]=dp[i-1]+dpb[i-1]; break; //
            case 5: // a=1; b=0; k=1;
                dp[i]=(a&p2[i]-1)*(b&p2[i]-1); break; //
            case 6: // a=1; b=1; k=0;
                dp[i]=dpa[i-1]+dpb[i-1]+dpk[i-1]; break; //
            case 7: // a=1; b=1; k=1;
                dp[i]=p2[2*i-2]+p2[i-1]*((a&p2[i-1]-1)+(b&p2[i-1]-1))+dp[i-1]; break; //
            }
        }
        printf("%lld\n",dp[n-1]);
    }
    return 0;
}
