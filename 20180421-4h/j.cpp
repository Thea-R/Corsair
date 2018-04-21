#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long lint;

lint gcd(lint x,lint y){
	if(y==0) return x;
	return	gcd(y, x%y);
}
map<lint, int> vis;
vector<lint> o;

int main(){
	int T, i;
	lint a, b;
	
	scanf("%d",&T);
	while(T--){
		cin>>a>>b;
		if(a==0)
		{
			printf("0\n");
			continue;
		}
		if((a<0)!=(b<0))	printf("-");
		a=abs(a), b=abs(b);
		lint p=gcd(a,b);
		a/=p, b/=p;

		if(a%b==0) printf("%lld\n",a/b);
		else
		{
			vis.clear();
			o.clear();
			int k=1, flag=0;
			
			printf("%lld.",a/b);
			a%=b;
			vis[a]=-1;
			while(1){
				a*=10;
				o.push_back(a/b);
				a%=b;
				if(vis[a]){
					k=(vis[a]==-1 ? 0 : vis[a]);
					flag=1;
					break;
				}
				vis[a]=o.size();
				if(a==0) break;
			}
			if(flag){
				for(i=0;i<k;i++) printf("%lld",o[i]);
				printf("(");
				for(i=k;i<o.size();i++) printf("%lld",o[i]);
				printf(")\n");
			}
			else{
				for(i=0;i<o.size();i++) printf("%lld",o[i]);
				printf("\n");
			}
		}
	}	
	return 0;
}
