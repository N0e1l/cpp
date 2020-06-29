#include<iostream>
#include<cstring>
#include<cstdio>
#include <algorithm>
using namespace std;

#define LL long long
#define RG register int

int n,m,Fa[50050];

void init(){
    for(RG i=1;i<=n;i++) Fa[i]=i;
}

int FindFa(int x){
    if(Fa[x]==x)return x;
    return Fa[x]=FindFa(Fa[x]);
}

void uni(int x,int y){
    int a=FindFa(x);
    int b=FindFa(y);
    Fa[a]=b;
}

int main(){
    int cnt=1;
    while (cin>>n>>m&&n&&m){
        init();
        for(int i=1;i<=m;i++){
            int a,b;
            scanf("%d%d",&a, &b);
            uni(a,b);
        }
        int anc=0;
        for(RG i=1;i<=n;i++){
            if(Fa[i]==i) anc++;
        }
        printf("Case %d: %d\n",cnt++,anc);
    }
    return 0;
}