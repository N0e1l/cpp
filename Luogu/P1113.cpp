#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
vector<pair<int,int>>Map[10010];
int val[10010];
int anc=0;
int vir[10010];
void dfs(int x){
    for(auto now:Map[x]){
        if(vir[now.first])continue;
        anc+=now.second;
        vir[now.first]=1;
        dfs(now.first);
    }
}
int main()
{
    int T;
    cin>>T;
    int a,b,c;
    cin>>a>>b>>c;
    val[a]=b;
    for(int i=2;i<=T;i++){
        cin>>a>>b;
        val[a]=b;
        int cost=10001000;
        int num=-1;
        while(cin>>c&&c){
            if(val[c]<cost){
                cost=val[c];
                num=c;
            }
            Map[num].push_back({a,val[num]});
        }
    }
    dfs(1);
    for(int i=1;i<=T;i++){
        if(Map[i].size()==0){
            anc+=val[T];
        }
    }
    cout<<anc;
    return 0;
}