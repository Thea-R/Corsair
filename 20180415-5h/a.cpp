#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=10000000+10;

int T, n;
unsigned int l[maxn], r[maxn], a, b, c, d;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		cin>>n>>l[1]>>r[1]>>a>>b>>c>>d;
		for(int i=2; i<=n; i++)
		{
			l[i]=(l[i-1]*a+b);
			r[i]=(r[i-1]*c+d);
		}
		for(int i=1; i<=n; i++)	if(l[i]>r[i]) swap(l[i], r[i]);

		unsigned int mn=r[1], mx=l[1];
		for(int i=1; i<=n; i++)
		{
			mn=min(mn, r[i]);
			mx=max(mx, l[i]);
		}

		if(mn>=mx || n<3)	printf("NO\n");
		else
		{
			bool ok=false;
			for(int i=2; i<=n && !ok; i++) if(mn<l[i] && r[i]<mx)	ok=true;

			if(ok)	printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
