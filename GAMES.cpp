#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

int gcd(int a,int b){
	if(a<b) return gcd(b,a);
	if(b==0) return a;

	return gcd(b,a%b);
}
int main(){
  int t,i,j;
  string s;
  scanf("%d",&t);
  for(i=0;i<t;i++){
    cin>>s;
    int count=0;
    for(j=0;j<s.size();j++) if(s[j]=='.') break;
    if(s[j]=='.'){
      j++;
      for(;j<s.size();j++) count++;
      int num=0,r=1;
      for(j=s.size()-1;j>=0;j--){
        if(s[j]!='.'){
          num+=(s[j]-'0')*r;
          r*=10;
        }
      }
      j=1;
      while(count--)j=j*10;
      r=gcd(num,j);
      printf("%d\n",j/r);

    }
    else printf("1\n");
  }

}
