#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
vector<int>Map[100010];
int vir[100010];
void dfs(int x,int y){
    vir[x]=y;
    for(int i=0;i<Map[x].size();i++){
        if(vir[Map[x][i]]==0){
            dfs(Map[x][i],y);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        Map[b].push_back(a);
    }
    for(int i=n;i>=1;i--){;
        if(vir[i]==0){
            dfs(i,i);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",vir[i]);
    }
    return 0;
}