#include<iostream>
using namespace std;


int main(){
  long int n,t,i;
  cin>>t;
  int arr[]={1,4,6,5,2,0};
  for(i=0;i<t;i++){
    cin>>n;
    cout<<arr[(n-1)%6]<<endl;
  }
}
