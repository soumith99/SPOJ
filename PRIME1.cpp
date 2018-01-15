#include<iostream>
#include<cstdlib>
using namespace std;

struct number{
  long int n;
  bool marked;
};

void mark_primes(struct number *arr[],int bias,int start,int len);
bool is_prime(long int n,int k);
bool miller_rabin(long int n,long int d);
long int power(long int x,long int y,long int p);

int main(){
  int t,i;
  long int n,m,j,p;
  cin>>t;
  for(i=0;i<t;i++){
    cin>>n>>m;
    struct number *arr[m-n+1];
    for(j=0;j<m-n+1;j++){
      arr[j]=(struct number*)std::malloc(sizeof(struct number));
      arr[j]->n=j+n;
      arr[j]->marked=false;
    }
    for(j=0;j<m-n+1;j++){
      if(!arr[j]->marked){
        if(is_prime(arr[j]->n,100)){
          p=arr[j]->n;
          mark_primes(arr,n,p,m-n+1);
        }
        else{
          arr[j]->marked=true;
        }
      }

    }
    for(j=0;j<m-n+1;j++) if(!arr[j]->marked) cout<<arr[j]->n<<endl;

  }
}

void mark_primes(struct number *arr[],int bias,int start,int len){
  struct number *cur;
  long int p=start,p1=start;
  while(1){
    p+=p1;
    if(p-bias<len){
      arr[p-bias]->marked=true;
    }
    else{
      p1++;
      if(p1-bias>=len) {break;break;}
      while(p1-bias<len){
        if(p1-bias==len){ break;break;}
        if(!arr[p1-bias]->marked){
          p=p1;
          break;
        }
        p1++;
      }
    }
  }
}
bool is_prime(long int n,int k){
  if(n==3 || n==2) return true;
  else if(n%2==0||n==1) return false;
  else{
    int d=n-1;
    while(d%2!=1) d=d/2;
    if(d==0) cout<<"heyfuck\n";
    for(int i=0;i<k;i++) if(!miller_rabin(n,d)) return false;
    return true;
  }
}
bool miller_rabin(long int n, long int d){
  long int a = 2 + rand() % (n - 4);
  long int x = power(a, d, n);

  if(x==1||x==n-1) return true;

  while (d != n-1){
    x = (x * x) % n;
    d *= 2;
    if (x == 1)return false;
    if (x == n-1)return true;
  }
  return false;
}
long int power(long int x,long int y,long int p){
  long int sol=1;
  x=x%p;

  while(y>0){
    if(y%2==1) sol=(sol*x)%p;

    x=(x*x)%p;
    y=y/2;
  }
  return sol;
}
