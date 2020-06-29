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
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        int sum=a+b+c+n;
        int ave=sum/3;
        if(sum%3==0&&ave>=a&&ave>=b&&ave>=c)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}