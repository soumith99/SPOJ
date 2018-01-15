#include<iostream>
using namespace std;

int main(){
  bool f[10000];
  bool ff[10000];
  int n,m,f1,i,j,count;
  for(j=0;j<10000;j++){
    f[j]=false;ff[j]=false;
  }
  cin>>n;
  for(i=0;i<n;i++){
    count=0;
    cin>>f1;
    f[f1]=true;
    cin>>m;
    while(m--){
      cin>>f1;
      ff[f1]=true;
    }
    for(j=0;j<10000;j++){
      if(ff[j] && !f[j]) count++;
    }
  }
  cout<<count<<endl;
}
