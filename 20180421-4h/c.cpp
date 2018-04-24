#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<math.h>
#define MX 1555
#define INF 10000005
#define LL long long
using namespace std;
LL dp[MX][MX];
int main(){
	LL T1,n,x,y,z,t,i,j,k,t1;
	scanf("%lld",&T1);
	while(T1--){
		cin>>n>>x>>y>>z>>t;
		LL ans=x*n*t;
		for(i=1;i<=n;i++){
			dp[i][0]=dp[i-1][0]+(i-1)*y*t;
			for(j=1;j<=i;j++){
				LL p1=dp[i-1][j-1]+(t+(j-1)*z)*y*(i-j);
				LL p2=dp[i-1][j]+(t+j*z)*y*(i-j-1);
				dp[i][j]=max(p1,p2);
				ans=max(ans,dp[i][j]+(n-i)*x*(t+j*z)+(n-i)*(t+j*z)*(i-j)*y); 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
