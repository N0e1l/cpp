#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
int n;
int dp[1010];
int a[1010];
int main()
{
    while(cin>>n&&n!=0)
    {
        memset(dp,0,sizeof(dp));//≥ı ºªØ
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(a[i]>a[j])
                    dp[i]=max(dp[i],dp[j]+a[i]);
            }
            dp[i]=max(dp[i],a[i]);
        }
        sort(dp,dp+n);
        cout<<dp[n-1]<<endl;
    }
    return 0;
}
