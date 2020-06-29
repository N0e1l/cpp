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
        int n,k;
        cin>>n>>k;
        int sum=0,cnt;
        k-=1;
        for(int i=0;;i++){
            if(sum+i+1>k){
                cnt=i+1;
                break;
            }
            sum+=i+1;
        }
        k-=sum;
        for(int i=0;i<n;i++){
            if(i==n-1-cnt||i==n-k-1)cout<<"b";
            else cout<<'a';
        }
        cout<<endl;
    }
    return 0;
}