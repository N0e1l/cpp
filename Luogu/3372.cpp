//*Ä£°åÌâSegTree;
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

struct SegTreeNode{LL value,La;};
int date[100010];
SegTreeNode Seg[400010];

inline void Push_Down(int root,int L,int R){
    if(!Seg[root].La) return;
    int Add=Seg[root].La;
    Seg[root].La=0;
    int mid=(R+L)>>1;
    Seg[root<<1].La+=Add;
    Seg[root<<1|1].La+=Add;
    Seg[root<<1].value+=LL(mid-L+1)*Add;
    Seg[root<<1|1].value+=LL(R-mid)*Add;
    return;
}

void Build_SegTree(int root,int L,int R){
    Seg[root].La=0;
    if(R==L){ Seg[root].value=date[L];return;}
    int mid=(R+L)>>1;
    Build_SegTree(root<<1,L,mid);
    Build_SegTree(root<<1|1,mid+1,R);
    Seg[root].value=Seg[root<<1].value+Seg[root<<1|1].value;
    return;
}

void Update(int root,int L,int R,int ql,int qr,LL Add){
    if(L>qr||R<ql)return;
    if(ql<=L&&R<=qr){
        Seg[root].value+=(LL)(R-L+1)*Add;
        Seg[root].La+=Add;
        return;
    }
    Push_Down(root,L,R);
    int mid=(L+R)>>1;
    Update(root<<1,L,mid,ql,qr,Add);
    Update(root<<1|1,mid+1,R,ql,qr,Add);
    Seg[root].value=Seg[root<<1].value+Seg[root<<1|1].value;
    return;
}

LL Quiry(int root,int L,int R,int ql,int qr){
    if(L>qr||R<ql)return 0;
    if(ql<=L&&R<=qr){return Seg[root].value;}
    Push_Down(root,L,R);
    int mid=(R+L)>>1;
    return Quiry(root<<1,L,mid,ql,qr)+Quiry(root<<1|1,mid+1,R,ql,qr);
}

void dfs(int root){
    if(root>=10)return;
    printf("%lld\n",Seg[root].value);
    dfs(root<<1);
    dfs(root<<1|1);
}
int main(){
    int m,n,R,L,op;
    cin>>n>>m;
    for(int i=1;i<=n;++i)scanf("%d",&date[i]);
    Build_SegTree(1,1,n);
    while(m--){
        cin>>op>>L>>R;
        if(op==1){
            LL num;
            cin>>num;
            Update(1,1,n,L,R,num);
        }
        else printf("%lld\n",Quiry(1,1,n,L,R)); 
    }
}