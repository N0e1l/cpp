#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
int dp[505][505];
int x[505],y[505],t[505],r[505];

int main()
{
    int n,s1,s2;
    cin>>n>>s1>>s2;
    for(int i=1;i<=n;i++)cin>>x[i]>>t[i]>>y[i]>>r[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=1001;j++){
            dp[i][j]=dp[i-1][j];
            if(j>)
        }
    }
    return 0;
}