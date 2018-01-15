#include<stdio.h>

int main(){

  long int n,p,k;
  scanf("%ld",&n);
  scanf("%ld",&p);
  k=p;
  for(int i=1;i<n;i++){
    scanf("%ld",&p);
    k=p^k;
  }
  printf("%ld\n",k);
}
