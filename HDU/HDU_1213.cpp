//! ���鼯ģ���⣡
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
int n,m,fa[1010];  //!fa[x]=y:Ԫ�� x������Ϊy(��y����������һ�����ϵ�Ԫ��)
//* һ����������Ϊ���鼯�Ļ�������
inline void init(){   //! ��ʼ����ʼû���κ�Ԫ������ϵ�����ڼ���i��Ԫ��ֻ���Լ�i
    for(RG i=1;i<=n;i++)fa[i]=i;
}

int Find(int x){//!����x�����ĸ�����
    if(fa[x]==x)return x;//!�ҵ����ڵ���
    return fa[x]=Find(fa[x]);//!���ϵݹ�,����ѹ��·��,��·�������нڵ�ֱ���������,
                            //!����仯���������Ƶ㣬�����ظ���ѯ ��ֹ���������
}
void Union(int x,int y){//!�ϲ�x��y���ڼ���
    int a=Find(x);       
    int b=Find(y);
    fa[a]=fa[b];
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        init();
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            Union(a,b);
        }
        int anc=0;
        for(int i=1;i<=n;i++){
            if(fa[i]==i)anc++;
        }
        cout<<anc<<endl;
    } 
    return 0;
}