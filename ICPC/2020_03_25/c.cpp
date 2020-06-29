#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

struct Point
{
    int x,y;
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
};
int dis(Point P1,Point P2){
    return (P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y);
}
int R,len;
//返回-1代表相切 返回4代表在内部也就是相交,返回0代表（1：相离开，2:圆在矩形内部或者相切）
int pd1(Point cir,Point sqr){ 
    Point p1=sqr,p2(sqr.x-len,sqr.y),p3(sqr.x-len,sqr.y-len),p4(sqr.x,sqr.y-len);
    int anc=0;
    int T=0;
    if(dis(p1,cir)<R*R) anc++;
    if(dis(p2,cir)<R*R) anc++;
    if(dis(p3,cir)<R*R) anc++;
    if(dis(p4,cir)<R*R) anc++;
    if(dis(p1,cir)==R*R) T++;
    if(dis(p2,cir)==R*R) T++;
    if(dis(p3,cir)==R*R) T++;
    if(dis(p4,cir)==R*R) T++;
    if(T&&T+anc==4)return -1;
    return anc;
}
bool pd2(Point cir,Point sqr){
    Point p1(cir.x+R,cir.y),p2(cir.x-R,cir.y),p3(cir.x,cir.y+R),p4(cir.x,cir.y-R);
    if(p1.x==sqr.x||p1.x==sqr.x+len) return 1;
    if(p2.x==sqr.x||p2.x==sqr.x+len) return 1;
    if(p3.y==sqr.y||p3.y==sqr.y+len) return 1;
    if(p4.y==sqr.y||p1.y==sqr.y+len) return 1;
    return 0;
}
int main()
{
    int Rx,Ry;
    cin>>Rx>>Ry>>R;
    Point cir(Rx,Ry);
    cin>>Rx>>Ry>>len;
    Point sqr(Rx,Ry);
    int anc=0;
    if(pd1(cir,sqr)==-1)anc=1;//切
    else if(pd1(cir,sqr)!=0)anc=2;//交
    else if(pd1(cir,sqr)==0){
        if(pd2(cir,sqr)==1){
            if(cir.x>sqr.x&&cir.x<sqr.x+len&&cir.y>sqr.y&&cir.y<sqr.y+len){
                anc=2;//交
            }
            else anc=0;//离
        }
    }
    cout<<anc;
    return 0;
}