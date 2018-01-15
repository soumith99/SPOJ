#include<stdio.h>
#include<math.h>

long int factors(long int m,long int n);
long int gcd(long int a ,long int b);

int main(){
  long int t,m,n;
  scanf("%ld",&t);
  for(int i=0;i<t;i++){
    scanf("%ld %ld",&m,&n);
    printf("%ld\n",factors(m,n));
  }
}
long int factors(long int a,long int b){
  long int n = gcd(a, b),result = 0;
  for (int i=1; i<=sqrt(n); i++){
    if (n%i==0){
      if (n/i == i)
        result += 1;
      else
        result += 2;
      }
  }
  return result;
}
long int gcd(long int a ,long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
