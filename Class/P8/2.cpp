#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int dp[100010];
int n;
int DP(){
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=3;i++){
        for(int j=i;j<=n;j++){
            dp[j]+=dp[j-i];
        }
    }
    return dp[n];
}
int main()
{
    while(cin>>n){printf("%d\n",DP());}
    return 0;
}