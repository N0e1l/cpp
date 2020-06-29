#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
int Mod,n,m;
struct SegNode{LL value,MuLA,AddLa;};
SegNode Seg[400040];
int date[100010];

inline void Push_Down(int Root,int L,int R){
    if(!Seg[Root].AddLa&&Seg[Root].MuLA==1) return;
    LL add=Seg[Root].AddLa,mul=Seg[Root].MuLA;
    int mid=(R+L)>>1;
    Seg[Root].MuLA=1;
    Seg[Root].AddLa=0;
    Seg[Root<<1].value=(Seg[Root<<1].value*mul%Mod+add*(LL)(mid-L+1)%Mod)%Mod;
    Seg[Root<<1|1].value=((Seg[Root<<1|1].value*mul)%Mod+add*(LL)(R-mid)%Mod)%Mod;
    Seg[Root<<1].MuLA=mul*Seg[Root<<1].MuLA%Mod;
    Seg[Root<<1|1].MuLA=mul*Seg[Root<<1|1].MuLA%Mod;
    Seg[Root<<1].AddLa=(Seg[Root<<1].AddLa*mul+add)%Mod;
    Seg[Root<<1|1].AddLa=(Seg[Root<<1|1].AddLa*mul%+add)%Mod;
    return ;
}
// inline void Push_Down(int Root,int L,int R){
//     int mid=(L+R)>>1;
//     LL Mul=Seg[Root].MuLA,Add=Seg[Root].AddLa;
//     Seg[Root].MuLA=1;
//     Seg[Root].AddLa=0;
//     Seg[Root<<1].value=(Seg[Root<<1].value*Mul%Mod+Add*(LL)(mid-L+1)%Mod)%Mod;
//     Seg[Root<<1|1].value=(Seg[Root<<1|1].value*Mul%Mod+Add*(LL)(R-mid)%Mod)%Mod;
//     Seg[Root<<1].MuLA=Seg[Root<<1].MuLA*Mul%Mod;
//     Seg[Root<<1|1].MuLA=Seg[Root<<1|1].MuLA*Mul%Mod;
//     Seg[Root<<1].AddLa=(Seg[Root<<1].AddLa*Mul+Add)%Mod;
//     Seg[Root<<1|1].AddLa=(Seg[Root<<1|1].AddLa*Mul+Add)%Mod;
//     return;
// }

void Build_Tree(int Root,int L,int R){
    Seg[Root].MuLA=1;
    Seg[Root].AddLa=0;
    if(L==R){Seg[Root].value=date[L];return;}
    int mid=(L+R)>>1;
    Build_Tree(Root<<1,L,mid);
    Build_Tree(Root<<1|1,mid+1,R);
    Seg[Root].value=(Seg[Root<<1].value+Seg[Root<<1|1].value)%Mod;
}

void Add(int Root,int L,int R,int ql,int qr,LL num){
    if(L>qr||R<ql)return;
    if(ql<=L&&R<=qr){
        Seg[Root].value=(Seg[Root].value+(LL)(R-L+1)*num)%Mod;
        Seg[Root].AddLa=(Seg[Root].AddLa+num)%Mod;
        return;
    }
    Push_Down(Root,L,R);
    int mid=(R+L)>>1;
    Add(Root<<1,L,mid,ql,qr,num);
    Add(Root<<1|1,mid+1,R,ql,qr,num);
    Seg[Root].value=(Seg[Root<<1].value+Seg[Root<<1|1].value)%Mod;
    return;
}

// void Mul(int Root,int L,int R,int ql,int qr,LL num){
//     if(L>qr||R<ql)return;
//     if(ql<=L&&R<=qr){
//         Seg[Root].value==Seg[Root].value*num%Mod;
//         Seg[Root].MuLA=Seg[Root].MuLA*num%Mod;
//         Seg[Root].AddLa=Seg[Root].AddLa*num%Mod;
//         return;
//     }
//     Push_Down(Root,L,R);
//     int mid=(R+L)>>1;
//     Mul(Root<<1,L,mid,ql,qr,num);
//     Mul(Root<<1|1,mid+1,R,ql,qr,num);
//     Seg[Root].value=(Seg[Root<<1|1].value+Seg[Root<<1|1].value)%Mod;
// }

void Mul(int Root,int L,int R,int QL,int QR,LL num){
    if(R<QL||QR<L) return;
    if(QL<=L && R<=QR){
        Seg[Root].value=Seg[Root].value*num%Mod;
        Seg[Root].MuLA=Seg[Root].MuLA*num%Mod;
        Seg[Root].AddLa=Seg[Root].AddLa*num%Mod;
        return;
    }
    int mid=(L+R)>>1;
    Push_Down(Root,L,R);
    Mul(Root<<1,L,mid,QL,QR,num);
    Mul(Root<<1|1,mid+1,R,QL,QR,num);
    Seg[Root].value=(Seg[Root<<1].value+Seg[Root<<1|1].value)%Mod;
    return;
}
LL ask(int Root,int L,int R,int ql,int qr){
    if(L>qr||R<ql) return 0;
    if(ql<=L&&R<=qr) return Seg[Root].value;
    Push_Down(Root,L,R);
    int mid=(L+R)>>1;
    return ( ask(Root<<1,L,mid,ql,qr)+ask(Root<<1|1,mid+1,R,ql,qr) )%Mod;
}
void pr();
int main()
{
    cin>>n>>m>>Mod;
    for(int i=1;i<=n;i++) cin>>date[i];
    int L,R,op,num;
    Build_Tree(1,1,n);
    while(m--){
        cin>>op>>L>>R;
        if(op==3) {cout<<ask(1,1,n,L,R)<<endl;}
        else if(op==2){cin>>num;Add(1,1,n,L,R,num);}
        else if(op==1){cin>>num;Mul(1,1,n,L,R,num);}
    }
}
void pr(){
    puts("!!!PR!!");
    for(int i=1;i<=n;i++) cout<<Seg[i].value<<endl;
    cout<<endl;
}