#include<iostream>
#include<string>
using namespace std;


int main(){
  int t,n,count=0;
  string s;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n;
    count=0;
    for(int j=0;j<n;j++){
      cin>>s;
      if(s=="lxh") count++;
    }
    if(count%2==0) cout<<"hhb"<<endl;
    else cout<<"lxh"<<endl;
  }

}
