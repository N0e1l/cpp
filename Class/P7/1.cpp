#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<queue>
 
using namespace std;
 
int s,e,n;
int ss[205],vis[205];
 
struct node
{
    int x,step;
};
int check(int x) 
{
    if(x<=0||x > n)
        return 1;
    return 0;
}
int BFS()
{
    queue<node> Q;
    node a,next;
    int i;
    a.x = s;
    a.step = 0;
    vis[a.x] = 1;
    Q.push(a);
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        if(a.x == e)
            return a.step;
        for(i = -1; i <= 1; i+=2)
        {
            next = a;
            next.x += i * ss[next.x];
            if(check(next.x)||vis[next.x]) 
            {
                continue;
            }
            vis[next.x] = 1;
            next.step++;
            Q.push(next);
        }
    }
    return -1;
}
int main()
{
    int i;
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d%d",&s,&e);
        memset(vis,0,sizeof(vis));
        for(i = 1; i <= n; i++)
        {
            scanf("%d",&ss[i]);
        }
        printf("%d\n",BFS());
    }
    return 0;
}