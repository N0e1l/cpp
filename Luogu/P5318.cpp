#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long 
vector<int>Map[100010];
int vir[100010];
void dfs(int x){
    vir[x]=1;
    printf("%d ",x);
    for(int i=0;i<Map[x].size();i++){
        if(vir[Map[x][i]])continue;
        dfs(Map[x][i]);
    }
}
queue<int>q;
void bfs(int x){
    q.push(x);
    vir[x]=1;
    while(!q.empty()){
        int now=q.front();q.pop();
        printf("%d ",now);
        for(int i=0;i<Map[now].size();i++){
            if(vir[Map[now][i]])continue;
            vir[Map[now][i]]=1;
            q.push(Map[now][i]);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        Map[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        sort(Map[i].begin(),Map[i].end());
    }
    dfs(1);
    cout<<endl;
    memset(vir,0,sizeof(vir));
    bfs(1);
    return 0;
}