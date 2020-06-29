#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

struct People
{
    int Date;
    int ID;
    double temp;
}st[105];
bool cmp(People p1,People p2){
    if(p1.Date!=p2.Date){
        return p1.Date>p2.Date;
    }
    else if(p1.temp!=p2.temp){
        return p1.temp>p2.temp;
    }
    else{
        return p1.ID<p2.ID;
    }
}


int main()
{
    int n;
    cin>>n;
    int cnt=0;
    while(n--){
        int d,i;
        double t;
        cin>>d>>i>>t;
        if(t>=38.0){
            st[cnt].Date=d;
            st[cnt].ID=i;
            st[cnt].temp=t;
            ++cnt;
        }
    }
    sort(st,st+cnt,cmp);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;++i){
        printf("%d %d %.1f\n",st[i].Date,st[i].ID,st[i].temp);
    }
    return 0;
}