#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
const long double def=1e-15;

struct Node{
	long double v1, v2;
	int c;
	bool operator <(const Node&t)const
	{
		long double tmp1=v1*t.v2, tmp2=v2*t.v1;
		return fabs(tmp1-tmp2)<=def ? c<t.c : tmp1<=tmp2;
	}
}p[1005];

int main(){	
	int n;
	//cout<<(1+1)/(2e9+2e9+2e9)<<endl;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			long double a, b, c;
			cin>>a>>b>>c;
			p[i].v1=(a+b), p[i].v2=(a+b+c), p[i].c=i;
		}
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++) printf("%d%c",p[i].c, " \n"[i==n]);
	}
	return 0;
}
