#include<bits/stdc++.h>
using namespace std;
int cnt;
int n,m;
char Map[25][25];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool check(int x,int y){
    if(Map[x][y]=='.'&&x>=1&&y>=1&&x<=n&&y<=m)return 1;
    return 0;
}
void dfs(int x,int y){
    cnt++,Map[x][y]='#';
    for(int i=0;i<=4;i++){
        if(check(x+dx[i],y+dy[i])){
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main(){
    while(cin>>m>>n&&m&&n){
        cnt=0;
        int x,y;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>Map[i][j];
                if(Map[i][j]=='@'){
                    x=i;
                    y=j;
                }
            }
        }
        dfs(x,y);
        cout<<cnt<<endl;
    }
    return 0;
}

