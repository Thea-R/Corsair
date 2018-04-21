#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
const double INF=1e18;
#define pb(a) push_back(a)

int T, n, from[maxn];
double ans, mst, dis[maxn][maxn], _min[maxn];
vector<int> e[maxn];
bool vis[maxn];
struct node
{
	double x, y, p;
	double dis(node t)
	{
		return sqrt((x-t.x)*(x-t.x)+(y-t.y)*(y-t.y));
	}
	void sc()
	{
		scanf("%lf%lf%lf", &x, &y, &p);
		return ;
	}
}p[maxn];

void MST()
{
	mst=0;
	for(int i=1; i<=n; i++)	_min[i]=INF;
	for(int i=1; i<=n; i++)	e[i].clear();
	memset(from, 0, sizeof from);
	memset(vis, 0, sizeof vis);

	int u=1, v, cnt=1;
	double cur=INF;

	while(cnt++<n)
	{
		vis[u]=true;
		for(int i=1; i<=n; i++) if(!vis[i])
		{
			if(_min[i]>dis[u][i])
			{
				_min[i]=dis[u][i];
				from[i]=u;
			}
			if(_min[i]<cur)	cur=_min[i], v=i;
		}
		e[v].pb(from[v]);
		e[from[v]].pb(v);
		u=v, mst+=cur, cur=INF;
	}
	return ;
}

void Dfs(int fa, int u, double mx)
{
	vis[u]=true;
	for(int i=0, len=e[u].size(), v; i<len; i++) if(!vis[v=e[u][i]])
	{
		if(fa==u)	ans=max(ans, (p[fa].p+p[v].p)/(mst-dis[u][v]));
		else ans=max(ans, (p[fa].p+p[v].p)/(mst-mx));
		Dfs(fa, v, max(mx, dis[u][v]));
	}
	return ;
}

void Work()
{
	ans=0;
	for(int i=1; i<=n; i++)
	{
		memset(vis, 0, sizeof vis);
		Dfs(i, i, 0);
	}
	return ;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; i++)	p[i].sc();

		memset(dis, 0, sizeof dis);
		for(int i=1; i<=n; i++)
			for(int j=1; j<i; j++)
				dis[i][j]=dis[j][i]=p[i].dis(p[j]);
		
		MST();
		Work();
		printf("%.2f\n", ans);
	}
}
