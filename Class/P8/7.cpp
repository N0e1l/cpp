#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int n,hi,sly,fr,num[20];
int dp[20][105];
//!dp的思路和状态：
//!dp[i][j]:第i个月雇佣j个人说需要最低工资。
//! 很明显第i个月是否需要雇佣或者解雇人由第i-1月所雇佣的人数决定所以状态设计如上
//!dp[i][j]=min(dp[i-1][k]+解雇或者重新雇佣的钱)+本月工资
int main()
{
    while(cin>>n&&n){
        cin>>hi>>sly>>fr;
        int Max=0;
        for(int i=1;i<=n;i++){
            cin>>num[i];
            Max=max(Max,num[i]);
        }
        //初始化;
        memset(dp,0x3f,sizeof(dp));
        for(int i=num[1];i<=Max;i++){
            dp[1][i]=i*(hi+sly);
        }
        for(int i=2;i<=n;i++){
            for(int j=num[i];j<=Max;j++){
                int Min=0x3f3f3f3f;
                for(int k=num[i-1];k<=Max;k++){
                    if(j>=k){   //这个月人数大于上个月
                        Min=min(dp[i-1][k]+(j-k)*hi+j*sly,Min);
                    }
                    if(j<k){     //这个月人数小于上个月
                        Min=min(dp[i-1][k]+(k-j)*fr+j*sly,Min);
                    }
                }
                dp[i][j]=Min;
            }
        }
        int anc=1010101010;
        for(int i=num[n];i<=Max;i++){
            anc=min(anc,dp[n][i]);
        }
        cout<<anc<<endl;
    }
    return 0;
}