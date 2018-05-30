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
const int maxn=2e5+10;
typedef long long lint;

int n, luna[maxn];

int main()
{	
	while(cin>>n)
	{
		n++;
		for(int i=1;i<=n;i++)	scanf("%d", &luna[i]);
		/*
		int le=1,ri=n;
		while(le<=ri)
		{
			int mid=(le+ri)>>1;
			if(check(mid))	le=mid+1;
			else ri=mid-1;
		}
		cout<<le-1<<endl;
		*/
		
		lint sum=0, ans=0;
		for(lint i=n; i>=1; i--)
		{
			sum=sum+(lint)luna[i];
			if(sum>=i-1)	ans=max(ans, i-1);
		}
		printf("%d\n", ans);
	}	
	return 0;
}
