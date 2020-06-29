#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
int INF=0x3f3f3f3f;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,t,f,Max=0,Min=-INF;
        LL anc=0;
        cin>>n>>t;
        n--;
        if(t>=0){f=1;Max=t;}
        else{f=-1;Min=t;}
        while(n--){
            cin>>t;
            if(f==1){
                if(t>=0){
                    Max=max(Max,t);
                }
                else{
                    anc+=Max;Max=0;f=-1;
                    Min=t;
                }
            }
            if(f==-1){
                if(t<=0){
                    Min=max(Min,t);
                }
                else{
                    anc+=Min;Min=-INF;f=1;
                    Max=t;
                }
            }
        }
        if(f==-1)anc+=Min;
        else anc+=Max;
        cout<<anc<<endl;
    }
    return 0;
}