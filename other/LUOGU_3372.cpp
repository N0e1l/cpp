#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

#define RG register int
#define LL long long

template<typename elemType>
inline void Read(elemType &T){
    elemType X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    T=(w?-X:X);
}

struct SegTreeNode{LL Value,Lazytag;};
SegTreeNode SegTree[400010];
int Data[100010];
int N,M;

inline void Push_Down(int Root,int L,int R){
    if(!SegTree[Root].Lazytag) return;
    int Add=SegTree[Root].Lazytag;
    SegTree[Root].Lazytag=0;
    int mid=(L+R)>>1;
    SegTree[Root<<1].Value+=(LL)(mid-L+1)*Add;
    SegTree[Root<<1|1].Value+=(LL)(R-mid)*Add;
    SegTree[Root<<1].Lazytag+=Add;
    SegTree[Root<<1|1].Lazytag+=Add;
    return;
}

void Build_SegTree(int Root,int L,int R){
    SegTree[Root].Lazytag=0;
    if(L==R){SegTree[Root].Value=Data[L];return;}
    int mid=(L+R)>>1;
    Build_SegTree(Root<<1,L,mid);
    Build_SegTree(Root<<1|1,mid+1,R);
    SegTree[Root].Value=SegTree[Root<<1].Value+SegTree[Root<<1|1].Value;
    return;
}

void Update(int Root,int L,int R,int QL,int QR,LL Add){
    if(R<QL||QR<L) return;
    if(QL<=L && R<=QR){
        SegTree[Root].Value+=(LL)(R-L+1)*Add;
        SegTree[Root].Lazytag+=Add;
        return;
    }
    int mid=(L+R)>>1;
    Push_Down(Root,L,R);
    Update(Root<<1,L,mid,QL,QR,Add);
    Update(Root<<1|1,mid+1,R,QL,QR,Add);
    SegTree[Root].Value=SegTree[Root<<1].Value+SegTree[Root<<1|1].Value;
    return;
}

LL Query(int Root,int L,int R,int QL,int QR){
    if(R<QL||QR<L) return 0;
    if(QL<=L && R<=QR) return SegTree[Root].Value;
    int mid=(L+R)>>1;
    Push_Down(Root,L,R);
    return Query(Root<<1,L,mid,QL,QR)+Query(Root<<1|1,mid+1,R,QL,QR);
}

int main(){
    Read(N);Read(M);
    for(RG i=1;i<=N;++i)
        Read(Data[i]);
    Build_SegTree(1,1,N);
    while(M--){
        int opt,L,R;LL Num;
        Read(opt);Read(L);Read(R);
        if(opt==1){Read(Num);Update(1,1,N,L,R,Num);}
        else printf("%lld\n",Query(1,1,N,L,R));
    }
    return 0;
}