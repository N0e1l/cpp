#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
const int maxn=5*10e5+100;
const long long inf=2147483647;

priority_queue<pair<int,LL>,vector<pair<int,LL> >,greater<pair<int,LL> > >q;

struct edge{
    int v,w,next;
}G[maxn];
int cnt=1;
int head[100010];

void add(int u,int v,int w){
    G[cnt].v=v;
    G[cnt].w=w;
    G[cnt].next=head[u];
    head[u]=cnt++;
}

LL dis[100010];
bool vis[100010];

int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    for(int i=1;i<=n;i++){
        dis[i]=1e10;
    }
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=head[u];i;i=G[i].next){
            int v=G[i].v;
            if(dis[v]>dis[u]+G[i].w){
                dis[v]=dis[u]+G[i].w;
                q.push(make_pair(dis[v],v));
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    return 0;
}