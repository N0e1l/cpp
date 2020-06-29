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
        string s;
        cin>>s;
        string a="",b="";
        bool f=0;
        for(int i=0;i<n;i++){
            if(f){
                a+="0";
                b+=s[i];
            }
            else{
                if(s[i]=='1'){
                    a+="1";
                    b+='0';
                    f=1;
                }
                if(s[i]=='2'){
                    a+='1';
                    b+='1';
                }
                if(s[i]=='0'){
                    a+="0";b+="0";
                }
            }
        }
        cout<<a<<endl;cout<<b<<endl;
    }
    return 0;
}