#include <queue>
#include <string.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#define ll long long

#define inf 0x3f3f3f3f
const int maxn = 107;
using namespace std;
int r,c,k;
int beginx,beginy,endx,endy,ans;
int d[4][2]= { {-1,0},{1,0},{0,1},{0,-1}};
char mymap[maxn][maxn];  //存图
char vis[maxn][maxn][10];  //标记数组， k 最大为10。
struct Node
{
    int x,y,step;
};
bool check(Node next)
{
    if(next.x<0||next.x>=r) return false;   //判断是否越界
    if(next.y<0||next.y>=c) return false;   //判断是否越界
    if(mymap[next.x][next.y]== '#' && next.step%k) return false; 
    //如果人走到该点时 碰到了障碍且步数不是k的倍数就返回假
    if(vis[next.x][next.y][next.step%k]) return false;    
     //如果走过就返回假。但 k的整数倍是可以重复走的。
    return true;
}
void bfs()
{
    ans=0;
    memset(vis,0,sizeof(vis));   //永远记得要先把所有标记归零。
    queue<Node>q;
    q.push( {beginx,beginy,0} );
    vis[beginx][beginy][0]=true;
    while(!q.empty())
    {
        Node t = q.front() ;
        q.pop();
        if(t.x== endx &&t.y== endy )
        {
            ans=t.step;
            return;
        }
        for(int i=0;i<4;i++)
        {
            Node temp = {t.x+d[i][0],t.y+d[i][1],t.step+1 };
            if(check(temp))
            {
                vis[temp.x][temp.y][temp.step%k]=true;
                q.push(temp);
            }
        }
    }
}

int main()
{
   int T;
   scanf("%d",&T);
   while(T--)
   {
       scanf("%d%d%d",&r,&c,&k);
       for(int i=0;i<r;i++)
       {
           getchar();
           for(int j=0;j<c;j++)
           {
               mymap[i][j]=getchar();
               if(mymap[i][j]== 'Y') beginx=i,beginy=j; 
                //记录终点和起点的坐标
               else if(mymap[i][j]== 'G' ) endx=i,endy=j;
           }
       }
       bfs();
       if(ans!=0) printf("%d\n",ans);
       else printf("Please give me another chance!\n");

   }
    return 0;
}
