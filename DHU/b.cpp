#include <iostream>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}
ll inv(ll a, ll p)
{
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}
int main(){
	int T;
	ll y,p;
	cin>>T;
	while(T--){
		cin>>y>>p;
		cout<<inv(y,p)<<endl;
	}
	return 0;
}