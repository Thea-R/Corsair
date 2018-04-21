#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define mp(a, b) make_pair(a, b)
using namespace std;
const int maxn=100000+10;

int T, n, a[maxn], f[maxn], g[maxn];
vector<pair<int, int> > p;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);

		p.clear();
		int i=1, j=2;
		while(j<=n)
		{
			while(j<=n && a[j-1]<=a[j])	j++;
			p.push_back(mp(a[i], a[j-1]));
			i=j++;
		}

		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);

		int m=p.size(), mn=p[0].first;
		for(int i=0; i<m; i++)
		{
			mn=min(mn, p[i].first);
			if(i==0)	f[i]=p[i].second-mn;
			else f[i]=max(f[i-1], p[i].second-mn);
		}

		int mx=p[m-1].second;
		for(int i=m-1; i>=0; i--)
		{
			mx=max(mx, p[i].second);
			if(i==m-1)	g[i]=mx-p[i].first;
			else g[i]=max(g[i+1], mx-p[i].first);
		}

		int ans=0;
		for(int i=0; i<m; i++)
		{
			if(i==m-1)	ans=max(ans, f[i]);
			else ans=max(ans, f[i]+g[i+1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
