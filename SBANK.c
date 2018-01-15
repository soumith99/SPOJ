#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool compare_row(int (*arr)[6],int c1,int c2);
void row_swap(int (*arr)[6],int r1,int r2);
void swap(int *num1,int *num2);
void quick_sort(int (*arr)[6],int i, int j);
int partition(int (*arr)[6],int start,int end);
void print_acc(int (*arr)[6],int len);
bool is_equal(int (*arr)[6],int r1,int r2);


int main(){
  int t,len=10,i,j,k;
  int arr[100000][6];
  scanf("%d",&t);
  for(k=0;k<t;k++){
    scanf("\n%d",&len);
    for(i=0;i<len;i++){
      for(j=0;j<6;j++){
        scanf("%d",&arr[i][j]);
      }
    }
    quick_sort(arr,0,len-1);
    print_acc(arr,len);

  }
}

bool compare_row(int (*arr)[6],int r1,int r2){
  int i;
  for(i=0;i<6;i++){
    if(arr[r1][i]>arr[r2][i]){
      return true;
      break;
    }
    else if(arr[r1][i]!=arr[r2][i]) break;
  }
  return false;
}
void row_swap(int (*arr)[6],int r1,int r2){
  int i;
  for(i=0;i<6;i++){
    swap(&arr[r1][i],&arr[r2][i]);
  }
}
void swap(int *num1,int *num2){
  int temp=*num2;
  *num2=*num1;
  *num1=temp;
}

void quick_sort(int (*arr)[6],int i, int j){
  if(i<j){
    int k=partition(arr,i,j);
    quick_sort(arr,i,k-1);
    quick_sort(arr,k+1,j);
  }
}
int partition(int (*arr)[6],int start,int end){
  int r=start+rand()%(end-start+1),i=start-1;
  row_swap(arr,r,end);
  for(int m=start;m<end;m++){
    if(compare_row(arr,end,m)){
      i+=1;
    row_swap(arr,i,m);
    }
  }
  row_swap(arr,i+1,end);
  return i+1;
}
void print_acc(int (*arr)[6],int len){
  printf("\n\n");
  int i,c,j;
  for(i=0;i<len;i++){
    j=i+1;
    while(is_equal(arr,i,j)) j++;
    printf("%02d %08d %04d %04d %04d %04d %d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4],arr[i][5],j-i);
    i=j-1;
  }
}
bool is_equal(int (*arr)[6],int r1,int r2){
  int i,j;
  for(i=0;i<6;i++){
    if(arr[r1][i]!=arr[r2][i]){
      return false;
      break;
    }
  }
  return true;
}
