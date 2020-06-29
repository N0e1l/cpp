#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
const int N=3*10e5;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;++i){
        int b,c;
        cin>>b>>c;
        a[b]++,a[c]++;
    }
    int ans=0;
    for(int i=1;i<=N;++i){
        if(a[i]>=3)ans+=(a[i]-2);
    }
    cout<<ans;
    return 0;
}