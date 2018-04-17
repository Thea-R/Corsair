#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=300000+10;

int T, n, m, d[maxn], fa[maxn], cnt[maxn];
int cur, fir[maxn], nxt[maxn<<1], ver[maxn<<1];
bool f1, f2;

void Add(int u, int v)
{
	ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur;
	ver[++cur]=u, nxt[cur]=fir[v], fir[v]=cur;
	return ;
}

void Dfs(int u, int p)
{
	d[u]=p;

	for(int i=fir[u], v; i; i=nxt[i])
	{
		if(d[v=ver[i]]==-1)
		{
			fa[v]=u;
			Dfs(v, p^1);
		}
		else if(v!=fa[u])
		{
			if(d[u]==d[v])
			{
				f1=true;

				int w=u;
				while(w && w!=v)
				{
					if(cnt[w])	f2=true;
					++cnt[w];
					w=fa[w];
				}
			}
			else f2=true;
		}
	}
	return ;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		cur=0;
		f1=f2=false;
		memset(d, -1, sizeof d);
		memset(fa, 0, sizeof fa);
		memset(cnt, 0, sizeof cnt);
		memset(fir, 0, sizeof fir);

		scanf("%d%d", &n, &m);
		for(int i=1, u, v; i<=m; i++)
		{
			scanf("%d%d", &u, &v);
			Add(u, v);
		}

		for(int i=1; i<=n; i++) if(d[i]==-1)	Dfs(i, 0);


		f1 ? printf("YES\n") : printf("NO\n");
		f2 ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}
