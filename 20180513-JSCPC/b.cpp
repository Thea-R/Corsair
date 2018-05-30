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
typedef long long lint;

lint n, a;

int main()
{	
	while(cin>>n>>a)
	{
		lint l=1, r=n;

		while(l<=r)
		{
			lint mid=(l+r)>>1;
			//cout<<mid<<' '<<a+mid-1<<"ci "<<n-mid+1<<"pian"<<endl;
			if(n-mid+1>=a+mid-1)	l=mid+1;
			else r=mid-1;
		}
		cout<<a+(l-1)-1<<endl;//ci
	}	
	return 0;
}
