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
        int n,k;
        cin>>n>>k;
        if(n<k){cout<<"NO\n";continue;}
        if(n%2){
            if(k%2){
                cout<<"YES\n";
                for(int i=1;i<=k-1;i++)cout<<"1 ";
                cout<<n+1-k;
            }
            else cout<<"NO";
        }
        else{
            if(k%2){
                if(2*k<=n){
                    cout<<"YES\n";
                    for(int i=1;i<=k-1;i++)cout<<"2 ";
                    cout<<n-2*k+2;
                }
                else cout<<"NO";
            }
            else{
                cout<<"YES\n";
                for(int i=1;i<=k-1;i++)cout<<"1 ";
                cout<<n-k+1;
            }
        }
        cout<<endl;
    }
    return 0;
}