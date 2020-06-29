#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int n,A,B;
int to[300];
bool vir[300];
struct node{
    int pos,step;
}now,nxt,pre;
queue<node>q;
int dfs(){
    pre.pos=A;
    pre.step=0;
    q.push(pre);
    vir[A]=1;
    while(!q.empty()){
        if(now.step>n)return -1;
        now=q.front();q.pop();
        if(now.pos==B)return now.step; 
        for(int i=1;i<=2;i++){
            if(i==1){
                nxt.pos=now.pos+to[now.pos];
            }
            if(i==2){
                nxt.pos=now.pos-to[now.pos];
            }
            if(!vir[nxt.pos]&&nxt.pos>=0&&nxt.pos<=n){
                nxt.step=now.step+1;
                q.push(nxt);
            }
        }

    }
    return -1;
}
int main()
{
    cin>>n>>A>>B;
    for(int i=1;i<=n;i++)cin>>to[i];
    cout<<dfs();
    return 0;
}