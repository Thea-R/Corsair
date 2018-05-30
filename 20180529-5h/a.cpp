#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=2000+10;

int n, m, a[maxn], b[maxn], c[maxn*maxn];

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
		for(int j=1; j<=m; j++)	scanf("%d", &b[j]);

		int tot=0;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++) if(b[j]>=a[i])
				c[++tot]=b[j]-a[i];

		int mx=-1, ans=0;
		sort(c+1, c+1+tot);
		for(int i=1; i<=tot; i++)
		{
			int j=i+1;
			while(j<=tot && c[j]==c[i])	++j;
			if(j-i>mx)	mx=j-i, ans=c[i];
			i=j-1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
