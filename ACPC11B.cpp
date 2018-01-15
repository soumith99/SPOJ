#include<cstdio>
#include<cstdlib>

void swap(int *num1,int *num2);
void quick_sort(int arr[],int i, int j);
int partition(int arr[],int start,int end);
int min_diff(int a[],int b[],int n1,int n2);

int main(){
  int t,n1,n2,i,j;
  scanf("%d",&t);
  for(i=0;i<t;i++){
    scanf("%d",&n1);
    int a[n1];
    for(j=0;j<n1;j++) scanf("%d",&a[j]);
    scanf("%d",&n2);
    int b[n2];
    for(j=0;j<n2;j++) scanf("%d",&b[j]);
    printf("%d\n",min_diff(a,b,n1,n2));
  }

}
int min_diff(int a[],int b[],int n1,int n2){
  int a1=0,b1=0,min=abs(a[0]-b[0]);
  quick_sort(a,0,n1-1);
  quick_sort(b,0,n2-1);
  while(a1<n1 && b1<n2){
    if(a[a1]>=b[b1]){
      if(min>a[a1]-b[b1]) min=a[a1]-b[b1];
      b1++;
    }
    else if(b[b1]>a[a1]){
      if(min>b[b1]-a[a1]) min=b[b1]-a[a1];
      a1++;
    }
  }
  while(a1<n1){
    if(min>abs(b[b1-1]-a[a1])) min=abs(b[b1-1]-a[a1]);
    a1++;
  }
  while(b1<n2){
    if(min>abs(a[a1-1]-b[b1])) min=abs(a[a1-1]-b[b1]);
    b1++;
  }
  return min;
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
