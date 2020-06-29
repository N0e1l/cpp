#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
int Have[101],Use[101];

int main()
{
    string s1,s2;
    int num;
    cin>>s1>>num>>s2;
    char Pre;
    bool f=1;//! f=1代表前面不是字母;
    for(int i=1;i<s1.size();++i){
        if(isdigit(s1[i])){
            int tmp=0;
            while(isdigit(s1[i])){
                tmp=tmp*10+s1[i]-'0';
                ++i;
            }
            Have[Pre-'a']+=tmp;
            i--;
        }
    }
    return 0;
}