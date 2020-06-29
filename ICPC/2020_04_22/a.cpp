#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

char Map[20][20];

int main()
{
    int n,t=0;
    while(cin>>n&&n){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cin>>Map[i][j];
            }
        }
        printf("Input matrix #%d:\n",++t);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                printf("%c ",Map[i][j]);
            }
            printf("\n");
        }
        int T;
        cin>>T;
        while(T--){
            int Q;
            cin>>Q;
            printf("Symmetric diagonals %d:\n",Q);
            if(Q==1){
                int x=1,y=1;
                while(x<=n||y<=n){
                    cout<<Map[x][y]<<" ";
                    x++,y++;
                }
                cout<<endl;
            }
            else{
                int x=1,y=Q;
                while(x<=n||y<=n){
                    cout<<Map[x][y]<<" ";
                    x++,y++;
                }
                cout<<endl;
                x=Q,y=1;
                while(x<=n||y<=n){
                    cout<<Map[x][y]<<" ";
                    x++,y++;
                }
                cout<<endl;
            }
        }
        puts("");
    }
    return 0;
}