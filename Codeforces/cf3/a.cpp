#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

LL f[33];
void init(){
    f[1]=2;
    for(int i=2;i<=30;i++){
        f[i]=2*f[i-1];
    }
}
int main(){
    int t;
    cin>>t;
    init();
    while(t--){
        int n;
        cin>>n;
        int a=0;
        for(int i=1;i<=n/2-1;i++){
            a+=f[i];
        }
        a+=f[n];
        int b=0;
        for(int i=1;i<=n;i++){
            b+=f[i];
        }
        cout<<abs(b-2*a)<<endl;
    }
}