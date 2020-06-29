#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long


int main()
{
    int t;
    cin>>t;
    while(t--){
        LL k,n;
        cin>>k>>n;
        LL a=(n/(k-1)*k);
        LL b=n%(k-1);
        if(b==0)a--;
        else a+=b;
        cout<<a<<endl;
    }
    return 0;
}