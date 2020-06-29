#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long


int main()
{
    LL n;
    cin>>n;
    LL sum=0;
    for(int i=1;i<=n;++i){
        LL t;
        cin>>t;
        sum+=t;
        sum-=(LL)(i-1);
    }
    cout<<sum;
    return 0;
}