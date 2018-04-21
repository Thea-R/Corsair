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

int n, m, tot, dl[maxn], dr[maxn];
int cur, fir[maxn], nxt[maxn<<1], ver[maxn<<1];
struct node
{
	int tot, sum, f;
}tr[maxn<<2];

void Add(int u, int v)
{
	ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur;
	return ;
}

void Dfs(int u)
{
	dl[u]=dr[u]=++tot;
	for(int i=fir[u], v; i; i=nxt[i]) Dfs(ver[i]);
	dr[u]=tot;
	return ;
}

void Push_down(int k)
{
	tr[k].f=0;
	tr[kl].sum=tr[kl].tot-tr[kl].sum, tr[kl].f^=1;
	tr[kr].sum=tr[kr].tot-tr[kr].sum, tr[kr].f^=1;
	return ;
}

void Push_up(int k)
{
	tr[k].sum=tr[kl].sum+tr[kr].sum;
	return ;
}

void Build(int k=1, int l=1, int r=n)
{
	tr[k].sum=tr[k].f=0, tr[k].tot=r-l+1;
	if(l==r)	return ;
	Build(kl, l, mid);
	Build(kr, mid+1, r);
	Push_up(k);
	return ;
}

void Update(int ll, int rr, int k=1, int l=1, int r=n)
{
	if(rr< l || r <ll)	return ;
	if(ll<=l && r<=rr)
	{
		tr[k].sum=tr[k].tot-tr[k].sum, tr[k].f^=1;
		return ;
	}
	if(tr[k].f)	Push_down(k);
	Update(ll, rr, kl, l, mid);
	Update(ll, rr, kr, mid+1, r);
	Push_up(k);
	return ;
}

int Query(int ll, int rr, int k=1, int l=1, int r=n)
{
	if(rr< l || r <ll)	return 0;
	if(ll<=l && r<=rr)	return tr[k].sum;
	if(tr[k].f)	Push_down(k);
	int tp1=Query(ll, rr, kl, l, mid), tp2=Query(ll, rr, kr, mid+1, r);
	Push_up(k);
	return tp1+tp2;
}

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		cur=0;
		memset(fir, 0, sizeof fir);

		for(int i=2, a; i<=n; i++)
		{
			scanf("%d", &a);
			Add(a, i);
		}

		tot=0;
		Dfs(1);
		Build();

		for(int i=1, x; i<=m; i++)
		{
			char s[2];
			scanf("%s%d", s, &x);
			if(s[0]=='u')	Update(dl[x], dr[x]);
			else printf("%d\n", Query(dl[x], dr[x]));
		}
	}
	return 0;
}
