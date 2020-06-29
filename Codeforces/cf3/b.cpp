#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

set<int>s;

int main()
{
    int t;
    cin>>t;
    while(t--){
        s.clear();
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int num;
            cin>>num;
            s.insert(num);
        }
        if(s.size()>k)cout<<"-1\n";
        else{
            cout<<k*n<<endl;
            for(int i=1;i<=n;i++){
                set<int>::iterator it=s.begin();
                for(;it!=s.end();it++)cout<<*it<<" ";
                if(s.size()<k)for(int i=1;i<=k-s.size();i++)cout<<"1 ";
            }
            cout<<endl;
        }
    }
    return 0;
}