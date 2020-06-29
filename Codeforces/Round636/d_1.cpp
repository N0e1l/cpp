#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	 
	    long long int a[n],sum[2*k+2]={0},x,m;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    sum[0]=n;
	    for(int i=0;i<n/2;i++){
	       x=a[i]+a[n-1-i];
	       sum[x]+=-1;
	       sum[x+1]+=1;
	       x=min(a[i],a[n-1-i])+1;
	       sum[x]+=-1;
	       x=max(a[i],a[n-1-i])+k;
	       sum[x+1]+=1;
	    }m=sum[0];
	    for(int i=1;i<=2*k+1;i++){
	        sum[i]+=sum[i-1];
	        m=min(m,sum[i]);
	    }
	  cout<<m<<endl;
	}
	return 0;
}