#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

const int maxn=5*10e5+100;
const long long inf=2147483647;

struct node{
    int id;
    LL dis;
    bool operator<(const node&a)const{return dis>a.dis;}
}pre,nex;

struct edge{
    LL to,val,next;
}G[maxn];
int cnt=1,head[10010];

void add(int u,int v,int w){
    G[cnt].to=v;
    G[cnt].val=w;
    G[cnt].next=head[u];
    head[u]=cnt++;
}

LL dis[10010];
bool vir[10010];
priority_queue<node>q;


int n,m,s;
void dij(int st){
    dis[st]=0;
    pre.id=st;pre.dis=0;
    q.push(pre);
    while(q.size()){
        int now=q.top().id;q.pop();
        if(vir[now])continue;
        vir[now]=1;
        for(int i=head[now];i;i=G[i].next){
            int go=G[i].to;
            if(dis[go]>dis[now]+G[i].val){
                dis[go]=G[i].val+dis[now];
                nex.id=go;nex.dis=dis[go];
                q.push(nex);
            }
        }
    }
}

int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        LL x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    for(int i=1;i<=n;i++){
        dis[i]=1e10;
    }
    dij(s);
    for(int i=1;i<=n;i++)cout<<dis[i]<<" "; 
    return 0;
}