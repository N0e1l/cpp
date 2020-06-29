#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
map<string,LL>Map1;//名字相同
map<char,LL>Map2;//记录首字母相同
int main()
{
    int n;
    cin>>n;
    string name;
    for(int i=0;i<n;i++){
        cin>>name;
        Map1[name]++;
        Map2[name[0]]++;
    }
    map<string,LL>::iterator it1;
    map<char,LL>::iterator it2;
    ULL anc=0LL;
    for(it2=Map2.begin();it2!=Map2.end();it2++){
        LL T=it2->second;
        //cout<<T<<" \n";
        if(T>=2){
            anc+=(T*(T-1));
        }
    }
    //puts(" !!");
    for(it1=Map1.begin();it1!=Map1.end();it1++){
        LL S=it1->second;
        //cout<<S<<" \n";
        if(S>=2){
            anc-=(S*(S-1));
        }
    }
    cout<<anc;
    return 0;
}