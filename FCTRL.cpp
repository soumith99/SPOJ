#include<iostream>
#include<cstdlib>
using namespace std;

/*long int zeros(long int k){

  long int zero=0,t=0,f=0,n;
  for(int i=1;i<=k;i++){
    n=i;
    while(n%2==0 && n>=2){
      t++;n/=2;
    }
    while(n%5==0 &&n>=5){
      f++;n/=5;
    }
  }
  if(f<t)return f;
  return t;
}*/

long int zeros(long int  n)
{
    long int count = 0;
    for (long int i=5; n/i>=1; i *= 5)
          count += n/i;

    return count;
}
int main(){
  long int t,n,j,zero;
  //cin>>t;
  t=100000;
  for(int i=0;i<t;i++){
    //cin>>n;
    n=rand();
    zero=zeros(n);
    cout<<zero<<endl;
  }
}
