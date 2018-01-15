#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int n,i;
  bool inve;
  while(1){
    inve=true;
    scanf("%d",&n);
    if(n==0) break;
    int arr[n];
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    int inv[n];
    for(i=0;i<n;i++) inv[arr[i]-1]=i+1;
    for(i=0;i<n;i++){
      if(arr[i]!=inv[i]) inve=false;
    }
    if(inve) printf("ambiguous\n");
    else printf("not ambiguous\n");
  }
}
