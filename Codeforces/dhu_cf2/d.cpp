#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
const int N=500000;
int f[N];
int main()
{
    ios::sync_with_stdio(false);
    int q,x;int ans=0;
    cin>>q>>x;
    while(q--){
        int y;
        cin>>y;
        f[y%x]++;
        while(f[ans%x]!=0){
            f[ans%x]--;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}