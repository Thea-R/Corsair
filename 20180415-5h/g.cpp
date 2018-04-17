#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=32+10;

int T, n, ans, cnt, a[maxn], g[maxn];
bool vis[maxn];
struct node
{
	int fac, cha, mag;
	bool operator <(const node&t)const
	{
		return cha<t.cha;
	}
}p[maxn];

void Dfs(int i, int k, int mag)//前i个角色，已经选了前k个character，异或和为mag
{
	if(k==cnt && mag==0)	++ans;
	for(int j=i+1; j<=n && p[j].cha<=k+1; j++) if(g[p[j].cha]==1 || !vis[p[j].fac])
	{
		if(g[p[j].cha]>1)	vis[p[j].fac]=true;
		Dfs(j, p[j].cha, (mag^p[j].mag));
		if(g[p[j].cha]>1)	vis[p[j].fac]=false;
	}
	return ;
}

bool ok()
{
	for(int i=1; i<=n; i++)	g[p[i].cha]++;
	for(int i=1; i<=n; i++) if(g[p[i].cha]==1)
	{
		if(vis[p[i].fac])	return false;
		vis[p[i].fac]=true;
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);

		for(int i=1; i<=n; i++)
		{
			scanf("%d%d%d", &p[i].fac, &p[i].cha, &p[i].mag);
			a[i]=p[i].cha;
		}
		sort(a+1, a+1+n);
		cnt=unique(a+1, a+1+n)-(a+1);
		for(int i=1; i<=n; i++)	p[i].cha=lower_bound(a+1, a+1+cnt, p[i].cha)-a;
		sort(p+1, p+1+n);

		ans=0;
		memset(g, 0, sizeof g);
		memset(vis, 0, sizeof vis);
		if(ok())	Dfs(0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
