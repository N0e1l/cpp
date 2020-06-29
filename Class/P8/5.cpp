#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
int n;
int dp[400];  //ÍêÈ«±³°ü
int DP(){
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=17;i++){
        for(int j=i*i;j<=n;j++){
            dp[j]+=dp[j-i*i];
        }
    }
    return dp[n];
}
int main()
{
    while(cin>>n&&n){
        cout<<DP()<<endl;
    }
    return 0;
}