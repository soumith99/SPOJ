#include<stdio.h>
#include<math.h>

long long int gcd(long long int a ,long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int main(){
  long long int t,a,b,i,k,x,y;
  scanf("%lld",&t);
  for(i=0;i<t;i++){
    scanf("%lld %lld",&a,&b);
    k=gcd(a,b);
    y=a/k;
    x=b/k;
    printf("%lld %lld\n",x,y);
  }
}
