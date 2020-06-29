#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int dp[1010],w[1010],v[1010];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)cin>>v[i];
        for(int i=1;i<=n;i++)cin>>w[i];
        for(int i=1;i<=n;i++){
            for(int j=m;j>=w[i];j--){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}