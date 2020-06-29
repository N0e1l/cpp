#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

struct Edge{
    int w,to,next;
}G[10010];
int head[10010],cnt=1;
bool vir[10010];

void add_edge(int u,int v,int w){
    G[cnt].to=v;        //存节点
    G[cnt].w=w;         //存边权
    G[cnt].next=head[u];//存邻边
    head[u]=cnt++;          //存节点u上一次读的边的编号
}
void forG(int u){
    for(int i=head[u];i;i=G[i].next){
        int v=G[i].to;
    }
}

void dfs(int u){
    vir[u]=true;
    //一系列操作;
    //......
    for(int i=head[u];i;i=G[i].next){
        int v=G[i].to;
        if(vir[v])continue;
        //一系列操作//
        //... ...;
        dfs(v);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v,-1);//有向边加一次：无向边反向再加一次就行；
    }
    dfs(1);
    return 0;
}

void nothing(){
    ;
}