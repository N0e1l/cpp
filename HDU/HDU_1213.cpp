//! 并查集模板题！
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
int n,m,fa[1010];  //!fa[x]=y:元素 x的祖先为y(用y代表属于这一个集合的元素)
//* 一下三个函数为并查集的基本操作
inline void init(){   //! 初始化开始没有任何元素有联系用属于集合i的元素只有自己i
    for(RG i=1;i<=n;i++)fa[i]=i;
}

int Find(int x){//!查找x属于哪个集合
    if(fa[x]==x)return x;//!找到根节点了
    return fa[x]=Find(fa[x]);//!向上递归,并且压缩路径,将路径上所有节点直接与根相连,
                            //!与记忆化搜索有相似点，减少重复查询 防止单链的情况
}
void Union(int x,int y){//!合并x和y所在集合
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