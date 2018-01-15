#include<iostream>
#include<cstdlib>
#include<math.h>
using namespace std;


bool is_prime(int n,int k);
bool miller_rabin(int n, int d);
int power(int x,int y, int p);
long int f(int x);

int main(){
  int n;
  cin>>n;
  cout<<f(n)<<endl;
}
long int f(int x){

  if(x==1) return 0;
  else if(x==2) return 2;
  else if(is_prime(x,100)) return 0;
  else{
    int k=floor(sqrt(x)),k1;
    if(k<sqrt(x))k1=k+1;
    else k1=k;
    while(x%k!=0) k--;
    while(x%k1!=0) k1++;
    return f(k)+f(k1);
  }
}
bool is_prime(int n,int k){
  if(n==3 || n==2) return true;
  else if(n%2==0||n==1) return false;
  else{
    int d=n-1;
    while(d%2!=1) d=d/2;
    for(int i=0;i<k;i++) if(!miller_rabin(n,d)) return false;
    return true;
  }
}
bool miller_rabin(int n, int d){
  int a = 2 + rand() % (n - 4);
  int x = power(a, d, n);

  if(x==1||x==n-1) return true;

  while (d != n-1){
    x = (x * x) % n;
    d *= 2;
    if (x == 1)return false;
    if (x == n-1)return true;
  }
  return false;
}
int power(int x,int y, int p){
  int sol=1;
  x=x%p;

  while(y>0){
    if(y%2==1) sol=(sol*x)%p;

    x=(x*x)%p;
    y=y/2;
  }
  return sol;
}
