#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int t,n,m,d,i,j,cur,count;
  scanf("%d",&t);
  for(i=0;i<t;i++){
    count=0;
    scanf("%d %d %d",&n,&m,&d);
    for(j=0;j<n;j++){
      scanf("%d",&cur);
      while(cur-d>0){
        cur-=d;
        count++;
      }
      //count--;
    }
    if(count>=m) printf("YES\n");
    else printf("NO\n");
  }
}
