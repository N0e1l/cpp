#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

const int maxn=5*10e5+100;
const long long inf=2147483647;

struct edge{int u,v,w;}G[maxn];

LL dis[10010];

int main()
{
    LL n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        cin>>G[i].u>>G[i].v>>G[i].w;
    }
    for(int i=1;i<=n;i++){
        dis[i]=inf;
    }
    dis[s]=0;
    bool flag=1;
    while(flag){
        flag=0;
        for(int i=1;i<=m;i++){
            int x=G[i].u,y=G[i].v;
            if(dis[y]>dis[x]+G[i].w){
                dis[y]=dis[x]+G[i].w;
                flag=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}