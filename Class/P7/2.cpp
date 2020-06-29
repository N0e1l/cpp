#include<iostream>
#include<queue>
#include<algorithm>
#include <cstring>
using namespace std;
struct node
{
    int x;
    int steps;
}t,pre,now;
queue<node>q;
int is[1000501]={0};
int bfs(int x,int y)
{
    while(!q.empty()){
    q.pop();}
    pre.x=x;
    pre.steps=0;
    q.push(pre);
    is[x]=1;
    while(!q.empty()){

        now=q.front();
        q.pop();
        for(int i=1;i<=3;i++){

            if(i==1){
                t.x=now.x+1;
            }
            else if(i==2){
                t.x=now.x*2;
            }
            else if(i==3){
                t.x=now.x-1;
            }
            if (t.x >= 0 && t.x <= 100000 && is[t.x] == 0){
                
                if(t.x==y){
                    return now.steps+1;
                }
                else{
                    is[t.x]=1;
                    t.steps=now.steps+1;
                    q.push(t);
                }
            }
        }
    }
}
int main()
{
    int x,y;
    while(cin>>x>>y){
        memset(is,0,sizeof(is));
        int anc;
        anc= x>=y? (x-y):bfs(x,y);
        cout<<anc<<endl;
    }
    return 0;

}