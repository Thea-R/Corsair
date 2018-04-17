#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1000000+10;

int T, n, m1, m2, w[maxn], in[maxn];
int cur, fir[maxn], nxt[maxn<<1], ver[maxn<<1];
bool flag, vis[maxn];
struct node
{
	int u, v;
	bool operator <(const node&t)const
	{
		return u==t.u ? v<t.v : u<t.u;
	}
	bool operator ==(const node&t)const
	{
		return u==t.u && v==t.v;
	}
}e[maxn];

void Add(int u, int v)
{
	ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur;
	return ;
}

void Dfs(int u, int f)
{
	vis[u]=true, w[u]=w[f];
	for(int i=fir[u], v; i; i=nxt[i])
	{
		if(!vis[v=ver[i]])	Dfs(v, u);
		else if(v!=f)	flag=true;
	}
	return ;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &m1, &m2);
		for(int i=1; i<=n; i++)	w[i]=i;

		cur=0;
		memset(fir, 0, sizeof fir);
		for(int i=1, u, v; i<=m1; i++)
		{
			scanf("%d%d", &u, &v);
			Add(u, v), Add(v, u);
		}

		flag=false;
		memset(vis, 0, sizeof vis);
		for(int i=1; i<=n; i++) if(!vis[i]) Dfs(i, i);

		cur=0;
		memset(in, 0, sizeof in);
		memset(fir, 0, sizeof fir);
		for(int i=1, u, v; i<=m2; i++)
		{
			scanf("%d%d", &u, &v);
			e[i].u=w[u], e[i].v=w[v];
		}
		sort(e+1, e+1+m2);
		m2=unique(e+1, e+1+m2)-(e+1);

		for(int i=1; i<=m2; i++)
		{
			if(e[i].u==e[i].v)	flag=true;
			else
			{
				in[e[i].v]++;
				Add(e[i].u, e[i].v);
			}
		}

		queue<int> q;
		memset(vis, 0, sizeof vis);

		int tot=n;
		for(int i=1; i<=n; i++) if(!in[i])	q.push(i);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			--tot;

			for(int i=fir[u], v; i; i=nxt[i])
			{
				--in[v=ver[i]];
				if(!in[v]) q.push(v);
			}
		}
		if(tot)	flag=true;

		flag ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}
