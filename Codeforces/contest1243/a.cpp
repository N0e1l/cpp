#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long


int main()
{
    int T;
    cin>>T;
    while(T--){
        LL x,y,a,b;
        cin>>x>>y;
        cin>>a>>b;
        if(x>y)swap(x,y);
        if(b>2*a) cout<<x*(2*a)+(y-x)*a<<endl;
        else cout<<x*b+(y-x)*a<<endl;
        
    }
    return 0;
}