#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int Next[1000009];
char s[1000009];
int len;
void getNext()
{
    int i=0,j=-1;
    Next[0]=-1;
     while(i<len)
     {
         if(j==-1||s[i]==s[j])Next[++i]=++j;
         else j=Next[j];
     }
}
int main()
{
    int  n,i,k;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        len=strlen(s);
        getNext();
            i=len;
        while (i)
        {
            if(Next[i]*3<=len)break;
            else i=Next[i];
        }
 
        if(i==0||len<3)
        {
            printf("0\n");
            continue ;
        }
        i=Next[i];
       int  ans=-1;
        for(k=1;k<len;k++)
        {
            if(k>=Next[k]*2&&k<=len-Next[k]&&Next[k]>ans)ans=Next[k];
            if(ans==i)break;
        }
        printf("%d\n",ans);
 
 
    }
    return 0;
}