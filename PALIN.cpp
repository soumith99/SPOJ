#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void conv_palin(string s);

int main(){
  string s;
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>s;
    conv_palin(s);
  }
}
void conv_palin(string s){
  int len=s.length(),i,j;
  i=-1;j=len;
  while(++i<=--j){
    if(s[i]!=s[j]) break;
  }
  //palindrome
  if(j<i){
    if(len%2==1){
      if(s[len/2]<'9') {
        s[len/2]++;
        cout<<s<<endl;
      }
      else{
        s[len/2]='0';
        i=(len/2)-1;
        j=(len/2)+1;
        while(i>=0){
          if(s[i]<'9'){
            s[i]++;s[j]++;break;
          }
          else{
            s[i]=s[j]='0';
          }
          i--;j++;
        }
        if(i<0){
          cout<<"1";
          i = len;
          while(--i > 0) cout<<"0";
          cout<<"1"<<endl;
        }
        else cout<<s<<endl;
      }
    }
    else{
      i=(len/2)-1;
      j=len/2;
      while(i>=0){
        if(s[i]<'9'){
          s[i]++;s[j]++;break;
        }
        else{
          s[i]=s[j]='0';
        }
        i--;j++;
      }
      if(i<0){
        cout<<"1";
        i = len;
        while(--i > 0)cout<<"0";
        cout<<"1"<<endl;
      }
      else cout<<s<<endl;
    }
  }
  else{
    //non palindrome
    if(len%2==1){
      i=(len/2)-1;
      j=(len/2)+1;
    }
    else{
      i=(len/2)-1;
      j=len/2;
    }
    int cse;
    while(i>=0){
      if(s[i]-s[j]>0){
        cse=1;break;
      }
      else if(s[i]-s[j]<0){
        cse=2;break;
      }
      i--;j++;
    }
    if(len%2==1){
      i=(len/2)-1;
      j=(len/2)+1;
    }
    else{
      i=(len/2)-1;
      j=len/2;
    }

    if(cse==1){
      while(i>=0){
        s[j]=s[i];
        i--;j++;
      }
    }
    else if(cse==2 && len%2==1 && s[len/2]<'9'){
      s[len/2]++;
      i=len/2-1;
      j=len/2+1;
      while(i>=0){
        s[j]=s[i];
        i--;j++;
      }
    }
    else{

      if(len%2==1) {
        s[len/2]='0';
      }
      while(i>=0){
        if(s[i]<'9'){
          s[i]++;
          s[j]=s[i];
          break;
        }
        else{
          s[i]=s[j]='0';
        }
        i--;j++;
      }
      while(i>=0){
        s[j]=s[i];
        i--;j++;
      }
    }
  cout<<s<<endl;
  }
}
