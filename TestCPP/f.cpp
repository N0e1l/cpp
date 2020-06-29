#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
struct Point
{
    int x,y;
    Point(int x,int y){
        this->x=x;this->y=y;
    }
}Tm[20],Em[20];
int A,B,C;
int f(Point P){
    return A*P.x+B*P.y+C;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>Tm[i].x>>Tm[i].y;
    }
    for(int i=1;i<=n;i++){
        cin>>Em[i].x>>Em[i].y;
    }
    A=Tm[n].y-Tm[1].y;
    B=Tm[1].x-Tm[n].x;
    C=Tm[1].x*Tm[n].y-Tm[n].x*Tm[1].y;
    int TT=1;
    for(int i=2;i<n;i++){
        if(f(Tm[i])==0)TT++;
    }
    int EE=0;
    for(int i=1;i<=n;i++){
        if(f(Em[i])==0)EE++;
    }
    if(EE)
    return 0;
}