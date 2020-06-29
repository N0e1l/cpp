#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

struct node
{
    int id;
    int s;
}p[110];

bool cmp(node a,node b){
    return a.s>b.s;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].id;
        int r,w,b;
        cin>>r>>w>>b;
        p[i].s=r+2*w+3*b;
    }
    sort(p+1,p+n+1,cmp);
    cout<<p[1].id<<" "<<p[1].s;
    return 0;
}