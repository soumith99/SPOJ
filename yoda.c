#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
char *arr[30001];
char *sol[30001];
int  mearge(int i,int k,int j,int len);
int inp(int i,int j,int len);
void swap(char *a,char *b);
bool compare(int i,int j,int len);

int main(){
    int t,len,i,j,k;
  for(j=0;j<30001;j++) arr[j]=malloc(21*sizeof(char));
  for(j=0;j<30001;j++) sol[j]=malloc(21*sizeof(char));

  scanf("%d",&t);
  for(k=0;k<t;k++){
    scanf("%d",&len);

    for(j=0;j<len;j++) scanf("%s",arr[j]);
    for(j=0;j<len;j++) scanf("%s",sol[j]);

    printf("%d\n",inp(0,len-1,len));
  }
}
int inp(int i,int j,int len){
  if(j<=i+1){
    if(compare(i,j,len)){
      swap(arr[i],arr[j]);
      return 1;
    }
    return 0;
  }
  else{
    int k=(i+j)/2;
    return inp(i,k,len)+inp(k+1,j,len)+mearge(i,k,j,len);
  }
}
int  mearge(int i,int k,int j,int len){

    char *arr1[j-i+1];
    for(int l=0;l<(j-i+1);l++) arr1[l]=malloc(21*sizeof(char));
    int left=i,right=k+1,a=0,count=0;

    while(left<=k && right<=j){
      if(compare(left,right,len)) {
        strcpy(arr1[a++],arr[right++]);
        count+=(k-left+1);
      }
      else strcpy(arr1[a++],arr[left++]);
    }
    while(left<=k) strcpy(arr1[a++],arr[left++]);
    while(right<=j) strcpy(arr1[a++],arr[right++]);
    a=0;
    for(;i<=j;i++){
      strcpy(arr[i],arr1[a++]);
    }

    return count;
  }
void swap(char *a,char *b){
      char *temp=malloc(21*sizeof(char));
      strcpy(temp,a);
      strcpy(a,b);
      strcpy(b,temp);
      free(temp);
    }
bool compare(int i,int j,int len){
    int k,m;
    for(k=0;k<len;k++){
      if(strcmp(arr[i],sol[k])==0) break;
    }
    for(m=0;m<len;m++){
      if(strcmp(arr[j],sol[m])==0) break;
    }
    if(k>m) return true;
    else return false;
}
