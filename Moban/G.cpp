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
    G[cnt].to=v;        //��ڵ�
    G[cnt].w=w;         //���Ȩ
    G[cnt].next=head[u];//���ڱ�
    head[u]=cnt++;          //��ڵ�u��һ�ζ��ıߵı��
}
void forG(int u){
    for(int i=head[u];i;i=G[i].next){
        int v=G[i].to;
    }
}

void dfs(int u){
    vir[u]=true;
    //һϵ�в���;
    //......
    for(int i=head[u];i;i=G[i].next){
        int v=G[i].to;
        if(vir[v])continue;
        //һϵ�в���//
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
        add_edge(u,v,-1);//����߼�һ�Σ�����߷����ټ�һ�ξ��У�
    }
    dfs(1);
    return 0;
}

void nothing(){
    ;
}