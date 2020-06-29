#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long


int a[200010];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int r,l;
        cin>>r>>l;
        a[r]++;a[l+1]--;
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=i*a[i];
    }
    cout<<ans;
    return 0;
}