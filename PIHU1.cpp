#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;


long long int bs(long long int arr[],long long int start,long long int end,long long int n,long long int k);
void swap(long long int *num1,long long int *num2);
void quick_sort(long long int arr[],long long int i,long long int j);
int partition(long long int arr[],long long int start,long long int end);

int main(){
  long long int t,n,p,i,j,k,found;
  scanf("%lld",&t);
  for(i=0;i<t;i++){
    found=0;
    scanf("%lld",&n);
    long long int arr[n];
    for(j=0;j<n;j++){
      scanf("%lld",&arr[j]);
    }
    scanf("%lld",&p);
    quick_sort(arr,0,n-1);
    for(j=0;j<n;j++){
      if(bs(arr,0,n-1,j,p)==0){
        found=1;
        break;
      }
    }
    if(found==0) printf("NO\n");
  }
}
long long int bs(long long int arr[],long long int start,long long int end,long long int n,long long int k){
  //long long int k=arr[n];
    k-=arr[n];
    while(start<end){
      //cout<<start<<" "<<end<<endl;
      if(arr[start]+arr[end]==k){
        if(start!=n && end!=n){
          printf("YES\n");
          return 0;
        }
        start++;
      }
      else if(arr[start]+arr[end]<k) start++;
      else end--;
  }
  return 1;
}
void swap(long long int *num1,long long int *num2){
  long long int temp=*num2;
  *num2=*num1;
  *num1=temp;
}
void quick_sort(long long int arr[],long long int i,long long int j){
  if(i<j){
    long long int k=partition(arr,i,j);
    quick_sort(arr,i,k-1);
    quick_sort(arr,k+1,j);
  }
}
int partition(long long int arr[],long long int start,long long int end){
  long long int r=start+rand()%(end-start+1),i=start-1,p=arr[r];
  swap(&arr[r],&arr[end]);
  for(int m=start;m<end;m++){
    if(arr[m]<p){
      i+=1;
      swap(&arr[i],&arr[m]);
    }
  }
  swap(&arr[i+1],&arr[end]);
  return i+1;
}
