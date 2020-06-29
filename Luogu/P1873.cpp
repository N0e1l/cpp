#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

LL len[1000010];
LL n,m;

LL f(LL x){
    LL sumlen=0;
    for(int i=1;i<=n;i++){
        if(len[i]<=x)continue;
        sumlen+=len[i]-x;
    }
    return sumlen;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>len[i];
    LL L=0,R=1000000000,mid;
    while(L<=R){
        mid=(L+R)/2;
        if(f(mid)<m)R=mid-1;
        else L=mid+1;
    }
    cout<<L-1;
    return 0;
}