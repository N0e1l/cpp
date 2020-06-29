#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
int Fa[5010];
void init(int x){
    for(int i=1;i<=x;++i)Fa[i]=i;
}

int find(int x){
    if(Fa[x]==x)return x;
    else return Fa[x]=find(Fa[x]);
}

void Uni(int x,int y){
    int a=find(x);
    int b=find(y);
    Fa[a]=b;
}

bool pd(int x,int y){
    return find(x)==find(y);
}
int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    init(n);
    while(m--){
        int a,b;
        cin>>a>>b;
        Uni(a,b);
    }
    while(p--){
        int a,b;
        cin>>a>>b;
        if(pd(a,b))cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}