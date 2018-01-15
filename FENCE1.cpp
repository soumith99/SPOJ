#include<cstdio>

int main(){

  double n,pi=3.14159;
  scanf("%lf",&n);
  while(n!=0){  
    printf("%.2lf\n",((n*n/pi)/2));
    scanf("%lf",&n);
  }
}
