#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long


int data[30010];

int main()
{
    int w,n;
    cin>>w>>n;
    for(int i=1;i<=n;i++)cin>>data[i];
    sort(data+1,data+n+1);
    int i=1,j=n,ans=0,cnt=0;
    while(i!=j){
        if(cnt==n)break;
        if(data[j]+data[i]<=w){ans+=1,cnt+=2,i++,j--;}
        else {ans+=1;cnt+=1,j--;}
    }
    if(cnt!=n)ans++;
    cout<<ans;
    return 0;
}