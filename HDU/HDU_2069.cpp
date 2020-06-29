#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int type[5]={1,5,10,25,50};
const int Max=1000,num=120;
int dp[Max][num];
int anc[Max];
void soive(){
    dp[0][0]=1;
    for(int i=0;i<=4;i++){
        for(int j=1;j<=100;j++){
            for(int k=type[i];k<Max;k++){
                dp[k][j]+=dp[k-type[i]][j-1];
            }
        }
    }
    for(int i=0;i<Max;i++){
        for(int j=0;j<=100;j++){
            anc[i]+=dp[i][j];
        }
    }
}
int main()
{
    int s;
    soive();
    while(cin>>s){cout<<anc[s]<<endl;}
    return 0;
}