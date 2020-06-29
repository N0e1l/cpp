#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int date[200010];
int dp[200010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>date[i];
    dp[1]=date[1];
    int Ans=dp[1];
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1]+date[i],date[i]);
        Ans=max(Ans,dp[i]);
    }
    cout<<Ans;
    return 0;
}