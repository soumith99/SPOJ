#include<stdio.h>
#include<cstdlib>
using namespace std;

long int bs(long int arr[],long int len,long int h);
bool f(long int arr[],long int len,long int mid,long int h);
void swap(long int *num1,long int *num2);
void quick_sort(long int arr[],long int i, long int j);
long int partition(long int arr[],long int start,long int end);

int main(){
  long int n,m;
    scanf("%ld %ld",&n,&m);

    long int arr[n];
    for(int j=0;j<n;j++){
      scanf("%ld",&arr[j]);
    }
    quick_sort(arr,0,n-1);
    printf("%ld\n",bs(arr,n,m));

}
long int bs(long int arr[],long int len,long int h)
{
  long int start=0,end=arr[len-1],max=-1,mid;

  while(start<end){
    mid=(start+end)/2;
    if(f(arr,len,mid,h)){
      if(mid>max) max=mid;
      start=mid+1;
    }
    else{
      end=mid;
    }
  }
  return max;
}
bool f(long int arr[],long int len,long int mid,long int h){
  long int meters=0;
  for(long int i=1;i<len;i++){
    if(arr[i]-mid>=0){
      meters+=arr[i]-mid;
    }
  }
  if(meters>=h) return true;
  return false;
}
void swap(long int *num1,long int *num2){
  long int temp=*num2;
  *num2=*num1;
  *num1=temp;
}
void quick_sort(long int arr[],long int i, long int j){
  if(i<j){
    long int k=partition(arr,i,j);
    quick_sort(arr,i,k-1);
    quick_sort(arr,k+1,j);
  }
}
long int partition(long int arr[],long int start,long int end){
  long int r=start+rand()%(end-start+1),i=start-1,p=arr[r];
  swap(&arr[r],&arr[end]);
  for(long int m=start;m<end;m++){
    if(arr[m]<p){
      i+=1;
      swap(&arr[i],&arr[m]);
    }
  }
  swap(&arr[i+1],&arr[end]);
  return i+1;
}
