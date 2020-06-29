#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long


int main()
{
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int a=0,b=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')a++;
            else b++;
        }
        if(a==0||b==0){
            cout<<s<<endl;
        }
        else{
            if(s[0]=='1'){
                for(int i=0;i<s.length();i++){
                    cout<<"10";
                }
                cout<<endl;
            }
            else{
                for(int i=0;i<s.length();i++){
                    cout<<"01";
                }
                cout<<endl;
            }
        }

    }
    return 0;
}