#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define kl (k<<1)
#define kr ((k<<1)+1)
#define mid ((l+r)>>1)
using namespace std;
const int maxn=100000+10;

int T, n, m, a[maxn];
int cur, fir[maxn], nxt[maxn<<1], ver[maxn<<1];
int tot, siz[maxn], son[maxn], dep[maxn], fa[maxn], id[maxn], lst[maxn], val[maxn], top[maxn];
struct node
{
	int sum, ans, d;
}tr[maxn<<2];

void Add(int u, int v)
{
	ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur;
	ver[++cur]=u, nxt[cur]=fir[v], fir[v]=cur;
	return ;
}

void Dfs1(int u)
{
	siz[u]=1, dep[u]=dep[fa[u]]+1;
	for(int i=fir[u], v, tmp; i; i=nxt[i]) if((v=ver[i])!=fa[u])
	{
		fa[v]=u, Dfs1(v);
		siz[u]+=siz[v];
		if(!son[u] || siz[v]>tmp)	son[u]=v, tmp=siz[v];
	}
	return ;
}

void Dfs2(int u, int tp)
{
	id[u]=lst[u]=++tot, val[tot]=u, top[u]=tp;
	if(!son[u])	return ;
	Dfs2(son[u], tp);
	for(int i=fir[u], v; i; i=nxt[i]) if((v=ver[i])!=fa[u] && v!=son[u])	Dfs2(v, v);
	lst[u]=tot;
	return ;
}

void Push_down(int k)
{
	tr[kl].d=1, tr[kl].ans=tr[kl].sum;
	tr[kr].d=1, tr[kr].ans=tr[kr].sum;
	tr[k].d=0;
	return ;
}

void Push_up(int k)
{
	tr[k].sum=tr[kl].sum+tr[kr].sum;
	tr[k].ans=tr[kl].ans+tr[kr].ans;
	return ;
}

void Build(int k=1, int l=1, int r=tot)
{
	tr[k].d=tr[k].ans=0;
	if(l==r)
	{
		tr[k].sum=a[val[l]];
		return ;
	}
	Build(kl, l, mid);
	Build(kr, mid+1, r);
	Push_up(k);
	return ;
}

void Update(int ll, int rr, int d, int k=1, int l=1, int r=tot)
{
	if(rr <l || r< ll)	return ;
	if(ll<=l && r<=rr)
	{
		tr[k].d=d, tr[k].ans=d ? tr[k].sum : 0;
		return ;
	}
	if(tr[k].d)	Push_down(k);
	Update(ll, rr, d, kl, l, mid);
	Update(ll, rr, d, kr, mid+1, r);
	Push_up(k);
	return ;
}

void Find(int u, int v, int d)
{
	int fu=top[u], fv=top[v];
	while(fu!=fv)
	{
		if(dep[fu]<dep[fv])	swap(u, v), swap(fu, fv);
		Update(id[fu], id[u], d);
		u=fa[fu], fu=top[u];
	}
	if(dep[u]>dep[v])	swap(u, v);
	Update(id[u], id[v], d);
	return ;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);

		cur=0;
		memset(fir, 0, sizeof fir);
		for(int i=1, u, v; i<n; i++)
		{
			scanf("%d%d", &u, &v);
			Add(u, v);
		}

		tot=0;
		memset(son, 0, sizeof son);
		Dfs1(1);
		Dfs2(1, 1);
		Build();

		scanf("%d", &m);
		for(int i=1, d, x, u, v; i<=m; i++)
		{
			scanf("%d", &d);
			if(d==1)
			{
				scanf("%d%d", &u, &v);
				Find(u, v, 1);
			}
			else if(d==2)
			{
				scanf("%d", &x);
				Update(id[x], id[x], 0);
			}
			else
			{
				scanf("%d", &x);
				Update(id[x], lst[x], 1);
			}
			printf("%d\n", tr[1].ans);
		}
	}
	return 0;
}
