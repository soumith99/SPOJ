#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

vector <int> seq(vector <int> a,int c,int s);
bool check(vector <int> a,int s);
int main(){
  int t,s,c,i,j,k;
  cin>>t;
  for(i=0;i<t;i++){
    vector <int> a;
    cin>>s>>c;
    for(j=0;j<s;j++){
      cin>>k;
      a.push_back(k);
    }
    vector <int> b=seq(a,c,s);
    for(int ll=1;ll<=c;ll++){
      cout<<b[s+ll-1]<<" ";
    }
    cout<<endl;
  }
}
vector <int> seq(vector <int> a,int c,int s){
  vector <int> arr[s+1];
  vector <int> :: iterator i;
  int arr_len=1,seq_len=s,k;
  for(i = a.begin(); i!= a.end();++i) arr[0].push_back(*i);
  while(1){
    if(check(arr[arr_len-1],seq_len)==true) break;
    else{
      for(i = arr[arr_len-1].begin(); i!= arr[arr_len-1].end()-1;i++){
        arr[arr_len].push_back((*(i+1))-(*i));
        //cout<<*(arr[arr_len].end()-1)<<endl;
      }
      arr_len++;
      seq_len--;
    }
  }
  arr_len--;
  k=*(arr[arr_len].begin());
  for(int j=0;j<c;j++){
     arr[arr_len].push_back(k);
     for(int l=arr_len;l>0;l--){
       arr[l-1].push_back(*(arr[l].end()-1)+ *(arr[l-1].end()-1));
     }
   }
   return arr[0];
}
bool check(vector <int> a ,int s){
  if(s==1){
    return true;
  }
  else{
    vector <int> :: iterator i; int k=a[0];
    for (i = a.begin(); i != a.end(); ++i){
      if(*i!=k) return false;
    }
    return true;
  }
}



/*
vector <int> seq(vector <int> a,int c,int s){
  if(check(a,s)){
    int k=a[0];
    for(int j=0;j<c;j++) a.push_back(k);
    return a;
  }
  else{
    vector <int> :: iterator i;
    vector <int> a1;
    for(i = a.begin(); i!= a.end(); i++){
      a1.push_back((*(i+1))-(*i));
    }
    return seq(a,c,s-1);
  }
}*/
