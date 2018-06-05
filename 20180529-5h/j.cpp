#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int main(){
    int n,x,i;
    LL a1,a2,a3,b1,b2,b3,P1,P2,P3;
    while(scanf("%d",&n)!=EOF){
        a1=a2=a3=b1=b2=b3=0;
        for(i=1;i<=n;i++){
            cin>>x;
            if(i%3==1) a1+=x;
            if(i%3==2) a2+=x;
            if(i%3==0) a3+=x;
        }
        for(i=1;i<=n;i++){
            cin>>x;
            if(i%3==1) b1+=x;
            if(i%3==2) b2+=x;
            if(i%3==0) b3+=x;
        }
        P1=a1*b2+a2*b1+a3*b3;
        P2=a1*b3+a2*b2+a3*b1;
        P3=a1*b1+a2*b3+a3*b2;
        cout<<P1<<' '<<P2<<' '<<P3<<endl;
    }   
    return 0;
}
