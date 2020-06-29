#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define RG register int
#define ULL unsigned long long
int ma(int year){
    int cnt=0;
    for(int i=2001;i<=year;++i){
        if(i%400==0||(i%4==0&&i%100!=0)){
            ++cnt;
        }
    }
    int Gap=(year-2000+cnt)%7;
    return 14-Gap;
}
int fa(int year){
    int cnt=0;
    for(int i=2001;i<=year;++i){
        if(i%400==0||(i%4==0&&i%100!=0)){
            ++cnt;
        }
    }
    int Gap=(year-2000+cnt)%7;
    int a=18;
    while(Gap--){
        a--;
        if(a==14)a=21;
    }
    return a;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int year,mouth,day;
        cin>>year>>mouth>>day;
        int fad=fa(year);
        int mad=ma(year);
        if(mouth<=4||(mouth==5&&day<mad)){
            printf("Mother's Day: May %dth, %d\n",mad,year);
        }
        else if(mouth<=5||mouth==6&&day<fad){
            if(fad==21){
                printf("Father's Day: June 21st, %d\n",year);
            }
            else printf("Father's Day: June %dth, %d\n",fad,year);
        }
        else printf("Mother's Day: May %dth, %d\n",ma(year+1),year+1);
    }
    return 0;
}