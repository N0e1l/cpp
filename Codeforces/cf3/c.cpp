#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

map<char,int>mp;string s;
int main()
{
    int t;
    cin>>t;
    while(t--){
        mp.clear();
        int n,k;
        cin>>n>>k; 
        cin>>s;
        for(int i=0;i<n;i++)mp[s[i]]++;
        sort(s.begin(),s.end());
        map<char,int>::iterator it;
        int cnt=0;
        for(it=mp.begin();it!=mp.end();it++){
            int num=it->second;
            if(num%k==0)for(int i=1;i<=num/k;i++){cout<<it->first;cnt+=num;}
            else{
                if(num<k)cout<<s[cnt+k-1];
                else{
                    for(int i=k-1;i<s.size();i++)cout<<s[i];
                }
            }
        }
        cout<<endl;
    }
    return 0;
}