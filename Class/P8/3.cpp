#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int One[2010];
int Two[2010];
int dp[2010];  //转移公式:dp[1]=One[1]; (当i>=2时) dp[i]=min(dp[i-1]+One[i],dp[i-2]+Two[i-1])
int main()
{
    int T,k;
    cin>>T;
    while(T--){
        cin>>k;
        for(int i=1;i<=k;i++) cin>>One[i];
        for(int i=1;i<k;i++)cin>>Two[i];
        dp[1]=One[1];
        for(int i=2;i<=k;i++) dp[i]=min(dp[i-1]+One[i],dp[i-2]+Two[i-1]);
        int h,Min,sec;
        h=8+dp[k]/3600;
        Min=dp[k]%3600/60;
        sec=dp[k]%60;
        if(h<12)printf("%02d:%02d:%02d am\n",h,Min, sec);
		else printf("%02d:%02d:%02d pm\n", h, Min, sec);
    }
    return 0;
}
