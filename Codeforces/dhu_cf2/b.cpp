#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
struct Point{
    int x,y;
};
Point P[1010];
int cmp(Point p1,Point p2){
    if(p1.x!=p2.x) return p1.x<p2.x;
    else return p1.y<p2.y;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=0;i<n;i++){
            cin>>P[i].x>>P[i].y;
        }
        sort(P,P+n,cmp);
        int flag=0;
        int cpx=P[0].x,cpy=P[0].y;
        for(int i=1;i<n;i++){
            if(cpx<P[i].x&&cpy>P[i].y){flag=1;break;}
            else {cpx=P[i].x;cpy=P[i].y;}
        }
        if(flag)cout<<"NO\n";
        else{
            cout<<"YES\n";
            int x=0,y=0;
            for(int i=0;i<n;i++){
                //R:
                if(x!=P[i].x){
                    while(1){
                        ++x;
                        cout<<"R";
                        if(x==P[i].x)break;
                    }
                }
                //U:
                if(y!=P[i].y){
                    while(1){
                        ++y;
                        cout<<"U";
                        if(y==P[i].y)break;
                    }
                }
            }
            cout<<endl;
        }
    }
    return 0;
}