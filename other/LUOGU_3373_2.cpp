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

struct SegTreeNode{LL Value,MulTag,AddTag;};
SegTreeNode SegTree[400040];
LL Data[100010];
int N,M;
LL MOD;

// inline void Push_Down(int Root,int L,int R){
//     int mid=(L+R)>>1;
//     LL Mul=SegTree[Root].MulTag,Add=SegTree[Root].AddTag;
//     SegTree[Root].MulTag=1; 
//     SegTree[Root].AddTag=0;
//     SegTree[Root<<1].Value=(SegTree[Root<<1].Value*Mul%MOD+Add*(LL)(mid-L+1)%MOD)%MOD;
//     SegTree[Root<<1|1].Value=(SegTree[Root<<1|1].Value*Mul%MOD+Add*(LL)(R-mid)%MOD)%MOD;
//     SegTree[Root<<1].MulTag=SegTree[Root<<1].MulTag*Mul%MOD;
//     SegTree[Root<<1|1].MulTag=SegTree[Root<<1|1].MulTag*Mul%MOD;
//     SegTree[Root<<1].AddTag=(SegTree[Root<<1].AddTag*Mul+Add)%MOD;
//     SegTree[Root<<1|1].AddTag=(SegTree[Root<<1|1].AddTag*Mul+Add)%MOD;
//     return;
// }
inline void Push_Down(int Root,int L,int R){
    if(!SegTree[Root].AddTag&&SegTree[Root].MulTag==1) return;
    LL add=SegTree[Root].AddTag,mul=SegTree[Root].MulTag;
    int mid=(R+L)>>1;
    SegTree[Root].MulTag=1;
    SegTree[Root].AddTag=0;
    SegTree[Root<<1].Value=(SegTree[Root<<1].Value*mul%MOD+add*(LL)(mid-L+1)%MOD)%MOD;
    SegTree[Root<<1|1].Value=((SegTree[Root<<1|1].Value*mul)%MOD+add*(LL)(R-mid)%MOD)%MOD;
    SegTree[Root<<1].MulTag=mul*SegTree[Root<<1].MulTag%MOD;
    SegTree[Root<<1|1].MulTag=mul*SegTree[Root<<1|1].MulTag%MOD;
    SegTree[Root<<1].AddTag=(SegTree[Root<<1].AddTag*mul+add)%MOD;
    SegTree[Root<<1|1].AddTag=(SegTree[Root<<1|1].AddTag*mul%+add)%MOD;
    return ;
}


void Build_SegTree(int Root,int L,int R){
    SegTree[Root].MulTag=1;
    SegTree[Root].AddTag=0;
    if(L==R){SegTree[Root].Value=Data[L];return;}
    int mid=(L+R)>>1;
    Build_SegTree(Root<<1,L,mid);
    Build_SegTree(Root<<1|1,mid+1,R);
    SegTree[Root].Value=(SegTree[Root<<1].Value+SegTree[Root<<1|1].Value)%MOD;
    return;
}

// void Update_Add(int Root,int L,int R,int QL,int QR,LL Add){
//     if(R<QL||QR<L) return;
//     if(QL<=L && R<=QR){
//         SegTree[Root].Value=(SegTree[Root].Value+(LL)(R-L+1)*Add)%MOD;
//         SegTree[Root].AddTag=(SegTree[Root].AddTag+Add)%MOD;
//         return;
//     }
//     int mid=(L+R)>>1;
//     Push_Down(Root,L,R);
//     Update_Add(Root<<1,L,mid,QL,QR,Add);
//     Update_Add(Root<<1|1,mid+1,R,QL,QR,Add);
//     SegTree[Root].Value=(SegTree[Root<<1].Value+SegTree[Root<<1|1].Value)%MOD;
//     return;
// }
void Update_Add(int Root,int L,int R,int ql,int qr,LL num){
    if(L>qr||R<ql)return;
    if(ql<=L&&R<=qr){
        SegTree[Root].Value=(SegTree[Root].Value+(LL)(R-L+1)*num)%MOD;
        SegTree[Root].AddTag=(SegTree[Root].AddTag+num)%MOD;
        return;
    }
    Push_Down(Root,L,R);
    int mid=(R+L)>>1;
    Update_Add(Root<<1,L,mid,ql,qr,num);
    Update_Add(Root<<1|1,mid+1,R,ql,qr,num);
    SegTree[Root].Value=(SegTree[Root<<1].Value+SegTree[Root<<1|1].Value)%MOD;
    return;
}

// void Update_Mul(int Root,int L,int R,int ql,int qr,LL num){
//     if(L>qr||R<ql)return;
//     if(ql<=L&&R<=qr){
//         SegTree[Root].Value==SegTree[Root].Value*num%MOD;
//         SegTree[Root].MulTag=SegTree[Root].MulTag*num%MOD;
//         SegTree[Root].AddTag=SegTree[Root].AddTag*num%MOD;
//         return;
//     }
//     Push_Down(Root,L,R);
//     int mid=(R+L)>>1;
//     Update_Mul(Root<<1,L,mid,ql,qr,num);
//     Update_Mul(Root<<1|1,mid+1,R,qr,ql,num);
//     SegTree[Root].Value=(SegTree[Root<<1|1].Value+SegTree[Root<<1|1].Value)%MOD;
// }

void Update_Mul(int Root,int L,int R,int QL,int QR,LL Mul){
    if(R<QL||QR<L) return;
    if(QL<=L && R<=QR){
        SegTree[Root].Value=SegTree[Root].Value*Mul%MOD;
        SegTree[Root].MulTag=SegTree[Root].MulTag*Mul%MOD;
        SegTree[Root].AddTag=SegTree[Root].AddTag*Mul%MOD;
        return;
    }
    int mid=(L+R)>>1;
    Push_Down(Root,L,R);
    Update_Mul(Root<<1,L,mid,QL,QR,Mul);
    Update_Mul(Root<<1|1,mid+1,R,QL,QR,Mul);
    SegTree[Root].Value=(SegTree[Root<<1].Value+SegTree[Root<<1|1].Value)%MOD;
    return;
}

// LL Query(int Root,int L,int R,int QL,int QR){
//     if(R<QL||QR<L) return 0;
//     if(QL<=L && R<=QR) return SegTree[Root].Value;
//     int mid=(L+R)>>1;
//     Push_Down(Root,L,R);
//     return (Query(Root<<1,L,mid,QL,QR)+Query(Root<<1|1,mid+1,R,QL,QR))%MOD;
// }

LL Query(int Root,int L,int R,int ql,int qr){
    if(L>qr||R<ql) return 0;
    if(ql<=L&&R<=qr) return SegTree[Root].Value;
    Push_Down(Root,L,R);
    int mid=(L+R)>>1;
    return ( Query(Root<<1,L,mid,ql,qr)+Query(Root<<1|1,mid+1,R,ql,qr) )%MOD;
}
void pr(){
    puts("!!!");
    for(int i=1;i<=N;i++) cout<<SegTree[i].Value<<endl;
    cout<<endl;
}
int main(){
    Read(N);Read(M);Read(MOD);
    for(RG i=1;i<=N;++i)
        Read(Data[i]);
    Build_SegTree(1,1,N);
    while(M--){
        int opt,L,R;LL Num;
        Read(opt);Read(L);Read(R);
        if(opt==1){Read(Num);Update_Mul(1,1,N,L,R,Num);}
        else if(opt==2){Read(Num);Update_Add(1,1,N,L,R,Num);}
        else {printf("%lld\n",Query(1,1,N,L,R));}
    }
}

