#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
const int N = 1005;
const int M = 15;
char s[N][N],ch[2][5]={"girl","cat"};
bool v[N][N];
int ans[2],n,m;
bool check(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m;
}
void dfs(int x,int y,int k,int t)
{
    if(!check(x,y)||s[x][y]!=ch[t][k])
        return;
    v[x][y]=true;
    if(t&&k==2||!t&&k==3)
    {
        ans[t]++;
        return;
    }
    dfs(x+1,y,k+1,t);
    dfs(x,y+1,k+1,t);
    dfs(x-1,y,k+1,t);
    dfs(x,y-1,k+1,t);
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        ans[0]=ans[1]=0;
        memset(v,false,sizeof(v));
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(!v[i][j])
                {
                    if(s[i][j]=='g')
                        dfs(i,j,0,0);
                    else if(s[i][j]=='c')
                        dfs(i,j,0,1);
                }
        printf("%d %d\n",ans[0],ans[1]);
    }
    return 0;
}