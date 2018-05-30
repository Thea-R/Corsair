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
#define LL long long
using namespace std;

LL f(int x,int y,int t){
	return ((y/t)-(x-1)/t);
}
int main()
{	
	LL x,y,xk1,xk2,yk1,yk2,ans,x2,y2;
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
		x=b-a+1;
		y=d-c+1;
		x2=f(a,b,2);
		y2=f(c,d,2);
		xk1=f(a,b,2018);
		xk2=f(a+1009,b+1009,2018);
		yk1=f(c,d,2018);
		yk2=f(c+1009,d+1009,2018);
	//	cout<<x<<' '<<x2<<' '<<xk1<<' '<<xk2<<endl;
	//	cout<<y<<' '<<y2<<' '<<yk1<<' '<<yk2<<endl;
		ans=yk1*x+xk1*y+yk2*x2+xk2*y2-xk1*yk1-xk2*yk1-yk2*xk1;
		printf("%lld\n",ans);		
	}
	return 0;
}
