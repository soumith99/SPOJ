#include<iostream>
#include<cstdlib>
using namespace std;

int bs(int arr[],int len,int c);
bool f(int arr[],int len,int mid,int c);
void swap(int *num1,int *num2);
void quick_sort(int arr[],int i, int j);
int partition(int arr[],int start,int end);

int main(){
  int t,n,c;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n>>c;
    int arr[n];
    for(int j=0;j<n;j++){
      cin>>arr[j];
    }
    quick_sort(arr,0,n-1);
    cout<<bs(arr,n,c)<<endl;
  }

}
int bs(int arr[],int len,int c)
{
  int start=0,end=arr[len-1],max=-1,mid;

  while(start<end){
    mid=(start+end)/2;
    if(f(arr,len,mid,c)){
      if(mid>max) max=mid;
      start=mid+1;
    }
    else{
      end=mid;
    }
  }
  return max;
}
bool f(int arr[],int len,int mid,int c){
  int cows=1,pos=arr[0];
  for(int i=1;i<len;i++){
    if(arr[i]-pos>=mid){
      pos=arr[i]; cows++;
    }
  }
  if(cows==c) return true;
  return false;
}
void swap(int *num1,int *num2){
  int temp=*num2;
  *num2=*num1;
  *num1=temp;
}
void quick_sort(int arr[],int i, int j){
  if(i<j){
    int k=partition(arr,i,j);
    quick_sort(arr,i,k-1);
    quick_sort(arr,k+1,j);
  }
}
int partition(int arr[],int start,int end){
  int r=start+rand()%(end-start+1),i=start-1,p=arr[r];
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
