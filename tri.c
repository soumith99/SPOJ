#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void swap(long long int *num1,long long int *num2);
void quick_sort(int i, int j);
int partition(int start,int end);
int triangle(int start,int end);

long long int arr[2000];

int main(){
  int t,len,i,r;
  scanf("%d",&len);
  r=(len*(len-1)*(len-2))/6;
  while(len!=0){
    for(i=0;i<len;i++) scanf("%lld",&arr[i]);
    quick_sort(0,len-1);
    printf("%d\n",r-triangle(0,len-1));
    scanf("%d",&len);
    r=(len*(len-1)*(len-2))/6;
  }
}
int triangle(int start,int end){
  int i,j,k,count=0,n=end-start+1;
  for(i=0;i<n-2;i++){
    k=i+2;
    for(j=i+1;j<n;j++){
      while(k<n && arr[i]+arr[j]>=arr[k]) k++;
      if(k>=n) k--;
      if(j<k){
          if(arr[i]+arr[j]>=arr[k]) count+=(k-j);
          else count+=k-j-1;
        }

    }
  }
  return count;
}
void swap(long long int *num1,long long int *num2){
  long long int temp=*num2;
  *num2=*num1;
  *num1=temp;
}
void quick_sort(int i, int j){
  if(i<j){
    int k=partition(i,j);
    quick_sort(i,k-1);
    quick_sort(k+1,j);
  }
}
int partition(int start,int end){
  int r=start+rand()%(end-start+1),i=start-1;
  long long int p=arr[r];
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
