//P118 7.1.1
//!问题介绍:有n种硬币,数量无限，对于给定的金额用最少的硬币凑出，求出最少硬币数及其组合
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

const int Max=305;
int type[5]={1,5,10,25,50};
int dp[Max];
//! 关键点,记录硬币组合，利用dp问题的性质：建立数组dp_path记录路径
//!dp_path[i]=m; 凑出i元钱的最优方案的最后一枚硬币的数额.输出方案细节见函数pr(t);
int dp_path[Max];

void solve(){
    for(int i=1;i<=Max;i++){
        dp[i]=0x3f3f3f3f;
    }
    dp[0]=0;
    for(int i=0;i<=4;i++){   //基础转移
        for(int j=type[i];j<=Max;j++){
            if(dp[j]>dp[j-type[i]]+1){
                dp_path[j]=type[i];
                dp[j]=dp[j-type[i]]+1;
            }
        }
    }
}
void pr(int t){
    cout<<dp[t]<<endl;
    //! 输出方案:
    while(t){  //t不为0时继续输出方案
        cout<<dp_path[t]<<" ";//当前拥有t元,最优方案的最后一枚硬币为dp_path[t];
        t-=dp_path[t];//当前金额更新
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    solve();
    while(n--){
        int ask;
        cin>>ask;
        pr(ask);
    }
    return 0;
}