#include<stdio.h>
using namespace std;

long int maxi(int arr[],int n,long int m);

int main(){
  int n; long int m;
  scanf("%d %ld",&n,&m);
  int arr[n];
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  printf("%ld\n",maxi(arr,n,m));
}
long int maxi(int arr[],int n,long int m){
  int i=0,j=0;
  long int sum=0,max=0;
  while(j<n){
    sum+=arr[j];
    while(sum>m){
      sum-=arr[i];
      i++;
    }
    if(sum>max) max=sum;
    j++;
  }
  return max;
}
