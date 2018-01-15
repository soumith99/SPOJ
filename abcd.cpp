#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while(1)
    {
        long long int n,k;
        scanf("%lld%lld",&n,&k);
        if(k==-1) break;
        if(k<3){
            printf("0\n");
            continue;
        }
        long long int k1,n1;
        n1=n*(n-1)/2;
        if(k%2==0) k1=(k/2)*((k-2)/2);
        else k1=((k-1)/2)*((k-1)/2);
        long long int temp=__gcd(n1,k1);
        n1=n1/temp;
        k1=k1/temp;
        if(k1>=n1){
            printf("1\n");
        }
        else printf("%lld/%lld\n",k1,n1);
    }
    return 0;

}
