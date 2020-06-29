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
        int n;
        cin>>n;
        for(int k=2;pow(2,k)-1<=n;k++){
            int s=pow(2,k)-1;
            if(n%s==0){
                cout<<n/s<<endl;
                break;
            }
        }
    }
    return 0;
}