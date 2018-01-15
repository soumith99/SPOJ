#include<stdio.h>
#include<cstdlib>
using namespace std;

void swap(int *num1,int *num2);
void quick_sort(int arr[],int i, int j);
int partition(int arr[],int start,int end);
unsigned long int count(int arr[],int len);

int main(){
  int t,n,i,j,k;
  unsigned long int rank,count;
  int arr[50000];
  scanf("%d;",&t);
  for(i=0;i<t;i++){
    rank=0;count=0;
    for(int ll=0;ll<50000;ll++) arr[ll]=0;
    scanf("%d",&n);
    for(j=0;j<n;j++){
      scanf("%d",&k);
      arr[k-1]++;
    }
    for(j=0;j<50000;j++){
      rank+=arr[j];
      count+=rank*arr[j];
    }
    printf("%lu\n",count);
  }
}
/*
unsigned long int count(int arr[],int len){
  int i,repeat=0,k;
  long unsigned int count=0;
  for(i=0;i<len;i++){

    if(repeat==0){
      k=arr[i];
      repeat++;
    }
    else if(repeat!=0){
      if(arr[i]==k){
        repeat++;
      }
      else{
        count+=repeat*(i);
        //cout<<"hii "<<count<<" repeat nd i"<<repeat<<" "<<i<<endl;
        repeat=0; i-=1;
      //  cout<<"hii1 "<<count<<" repeat nd i"<<repeat<<" "<<i<<endl;
      }
    }
  }
  count+=repeat*len;
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
}*/
