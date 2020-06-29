#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
const int N= 5050;
struct edge{
    int from,to,w;
};
edge G[200005];
int Fa[N];

bool cmp(edge a,edge b){
    return a.w<b.w;
}
void init(int n){
    for(int i=1;i<=n;++i) Fa[i]=i;
}

int Find(int x){
    if(Fa[x]==x)return x;
    else return Fa[x]=Find(Fa[x]);
}

int Merge(int x,int y){
    x=Find(x),y=Find(y);
    Fa[x]=y;
}
bool Same(int x,int y){
    return Find(x)==Find(y);
}
int n,m;
int Kruskal(){
    int cnt=0;
    sort(G+1,G+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(Same(G[i].to,G[i].from))continue;
        cnt+=G[i].w;
        Merge(G[i].from,G[i].to);
    }
    return cnt;
}
int main()
{
    cin>>n>>m;
    init(n);
    for(int i=1;i<=m;i++){
        cin>>G[i].from>>G[i].to>>G[i].w;
    }
    cout<<Kruskal();
    return 0;
}
