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
        int a[3]={-1,-1,-1};
        for(int i=2;i*i<=n;i++){
            if(n%i==0){a[0]=i;n/=i;break;}
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0&&a[0]!=i){a[1]=i;n/=a[1];break;}
        }
        if(a[0]==-1||a[1]==-1||a[0]==n||a[1]==n){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            a[2]=n;
            sort(a,a+3);
            cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        }
    }
    return 0;
}