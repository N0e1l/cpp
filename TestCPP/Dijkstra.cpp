#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
priority_queue<pair<LL,int >,vector<pair<LL,int> >,greater<pair<LL,int> > >q;
//pair<���룬�ߵı��>

//��ʽǰ���Ǵ�ͼ.
//���μ�¼��ĳһ���ڵ�Ϊ�������бߡ�
struct edge{
    int v,w,next; //v:��һ���˵㣬wȨ�أ�next:u���ӵ���һ����
}G[200010];  //�ߵ�����

int head[100010];//head[u] u ���ӵ���һ���ߵı�š�
int cnt=1; //��������
void add(int u,int v,int w){
    G[cnt].w=w;
    G[cnt].v=v;
    G[cnt].next=head[u];//�����¼����һ������ı��Ǳ���ʱ������һ����
    head[u]=cnt++;
}
LL dis[100010];
bool vir[100010];


int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){ //����
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
    }
    for(int i=1;i<=n;i++){
        dis[i]= 1e10;
    }
    dis[s]=0;
    //�Ͻ�˹��������
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