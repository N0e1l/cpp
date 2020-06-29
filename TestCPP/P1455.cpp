#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int w[10010];//价值
int c[10010];//价格
int fa[10010];
int n,m,mo;
int dp[10010];
void init(){
    for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}

void merge(int x,int y){
    x=find(x),y=find(y);
    fa[x]=y;
}

bool pd(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return true;
    else return false;
}



int main()
{
    cin>>n>>m>>mo;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>w[i];
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        merge(a,b);
    }

    for(int i=1;i<=n;i++){
        if(fa[i]!=i){
            c[find(i)]+=c[i];
            w[find(i)]+=w[i];
            c[i]=0;w[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=mo;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    cout<<endl;
    cout<<dp[mo];
    return 0;
}