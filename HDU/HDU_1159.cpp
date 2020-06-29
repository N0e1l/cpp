//! LCSģ����:
/*//!  ��str1[i]==str2[j]ʱ�൱����x(i-1)y(j-1)������������к�������ϵ�ǰԪ
  //!  ��,�ʴ𰸸���Ϊdp[i-1][j-1]+1,��str1[i]!=str2[j]�ǣ��𰸼̳�dp[i-1][j]��
  //!  dp[i][j-1]�Ľϴ���:
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
string str1,str2;
int dp[1005][1005];
int LCS(){
    memset(dp,0,sizeof(dp));
    int len1=str1.size(),len2=str2.size();
    for(int i=1;i<=len1;++i){
        for(int j=1;j<=len2;++j){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[len1][len2];
}
int DP[1005];
int LCS_roll(){
    int len1=str1.size(),len2=str2.size();
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=len1;++i){
        for(int j=len2;j>=1;--j){
            if(str1[i-1]==str2[j-1]){
                DP[j]=DP[j-1]+1;
            }
            else DP[j]=max(DP[j],DP[j-1]);
        }
    }
    return DP[len2];
}
int main()
{
    while(cin>>str1>>str2){
        cout<<LCS()<<"  "<<LCS_roll()<<endl;
    }
    return 0;
}