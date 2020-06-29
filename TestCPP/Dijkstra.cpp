#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
priority_queue<pair<LL,int >,vector<pair<LL,int> >,greater<pair<LL,int> > >q;
//pair<距离，边的编号>

//链式前向星存图.
//依次记录以某一个节点为起点的所有边。
struct edge{
    int v,w,next; //v:另一个端点，w权重，next:u连接的下一个边
}G[200010];  //边的条数

int head[100010];//head[u] u 连接的上一条边的编号。
int cnt=1; //计数器。
void add(int u,int v,int w){
    G[cnt].w=w;
    G[cnt].v=v;
    G[cnt].next=head[u];//反向记录，第一条读入的边是遍历时候的最后一条边
    head[u]=cnt++;
}
LL dis[100010];
bool vir[100010];


int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){ //读边
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    for(int i=1;i<=n;i++){
        dis[i]= 1e10;
    }
    dis[s]=0;
    //迪杰斯特拉核心
    q.push(make_pair(0,s));
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vir[u])continue;
        vir[u]=1;
        for(int i=head[u];i;i=G[i].next){
            int v=G[i].v;
            if(dis[v]>dis[u]+G[i].w){
                dis[v]=dis[u]+G[i].w;
                q.push( make_pair(dis[v],v) );
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    return 0;
}