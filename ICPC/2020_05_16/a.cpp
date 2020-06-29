#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long

string s;

bool huiwen(int L,int R){
    while(L<=R){
        if(s[L]!=s[R])return false;
        L++,R--;
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    cin>>s;
    int len=1;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[s.length()-1]){
            if(huiwen(i,s.length()-1)){
                len=s.length()-i;
                break;
            }
        }
    }
    cout<<s.length()-len;
    return 0;
}