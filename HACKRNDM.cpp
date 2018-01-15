#include<iostream>
#include<cstdlib>
using namespace std;

void swap(int *num1,int *num2);
void quick_sort(int arr[],int i, int j);
int partition(int arr[],int start,int end);
int find_pairs(int arr[],int n,int k);
bool bs(int arr[],int start,int end,int n);
int main(){
  int n,k;
  cin>>n>>k;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  quick_sort(arr,0,n-1);
  int pairs= find_pairs(arr,n,k);
  cout<<pairs<<endl;

}
int find_pairs(int arr[],int n,int k){
  int a,count=0;
  for(int i=0;i<n;i++){
    a=arr[i];
    if(bs(arr,0,n-1,a+k)) count++;
  }
  return count;
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
bool bs(int arr[],int start,int end,int n){
  if(start>=end){
    if(arr[end]!=n) return false;
    else return true;
  }
  else if(arr[(start+end)/2]==n) return true;
  else if(arr[(start+end)/2]>n) return bs(arr,start,((start+end)/2)-1,n);
  else if(arr[(start+end)/2]<n) return bs(arr,((start+end)/2)+1,end,n);
}
