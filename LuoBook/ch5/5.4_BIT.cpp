#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
/*lowbit(x) ȡһ�����������λ��1���ߵ�0��ɵ�����
 *�� lowbit(1)=1
 *  lowbit(2)=lowbit((10)2)=(10)2=2;
 */
inline int lowbit(int x){return x&(-x);}

int C[500100];   //c[x]ά�� sum[x,x-lowbit(x)+1]
int n;
void add(int Pos,int k){//! ��pos����+k
    while(Pos<=n){
        C[Pos]+=k;//pos�ĸ��׽ڵ�λpos+lowbit(pos)
        Pos+=lowbit(Pos);
    }
}

int sum(int x){     //��ǰ׺��
    int anc=0; 
    while(x!=0){
        anc+=C[x];
        x-=lowbit(x);
    }
    return anc;
}

int main()
{
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        add(i,t);
    }
    while(m--){
        int op,x,k;
        cin>>op>>x>>k;
        if(op==1)add(x,k);
        else cout<<sum(k)-sum(x-1)<<endl;;
    }
    return 0;
}