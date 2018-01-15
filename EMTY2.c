#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool check(char *str,int len);

int main(){
  int t,i;
  char *str=malloc(120000*sizeof(char));
  scanf("%d",&t);
  for(i=0;i<t;i++){
    scanf("%s",str);
    if(check(str,strlen(str)))printf("Case %d: yes\n",i+1);
    else printf("Case %d: no\n",i+1);
  }
}
bool check(char *str,int len){
  if(str[0]=='0' || str[len-1]=='1') return false;
  int i,ones=0,useless=0,tempo=0;
  for(i=0;i<len;i++){
    if(str[i]=='1'){
      ones++;
      tempo+=2;
    }
    else{
      if(tempo!=0) tempo--;
      else useless++;
    }
  }
  int useful=len-ones-useless;
  if(2*useful>=ones && tempo==0) return true;
  else return false;
}
