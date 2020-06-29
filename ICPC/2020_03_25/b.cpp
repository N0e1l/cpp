#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

int check[30];
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        check[s[i]-'a']++;
    }
    int odd=0,even=0;
    for(int i=0;i<26;i++){
        if(check[i]==0)continue;
        if(check[i]%2==0)even++;
        else odd++;
    }
    int anc=2;
    if(odd==0)anc=0;
    if(even==0)anc=1;
    cout<<anc;
    return 0;
}