#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long


struct node{
    int w,id;
}p[1010];
LL sum[1010];
bool cmp(node a,node b){
    return a.w<b.w;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].w;
        p[i].id=i;
    }
    sort(p+1,p+n+1,cmp);
    sum[1]=p[1].w;
    LL ans=sum[1];
    for(int i=2;i<=n-1;i++){
        sum[i]=sum[i-1]+p[i].w;
        ans+=sum[i];
    }
    for(int i=1;i<=n;i++){
        cout<<p[i].id<<" ";
    }
    printf("\n%.2f",double(ans)/double(n));
    return 0;
}