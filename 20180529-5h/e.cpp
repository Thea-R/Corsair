#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=10000+10;
typedef long long lint;

int m, N, n;
int cur, fir[maxn], nxt[maxn*100], ver[maxn*100], cst[maxn*100], pre[maxn*100];
bool vis[maxn], in[maxn];
map<string, int> mmp;
lint a[maxn], b[maxn], f[maxn];

void Add(int u, int v, int c, int p)
{
	in[v]=true;
	ver[++cur]=v, nxt[cur]=fir[u], fir[u]=cur, cst[cur]=c, pre[cur]=p;
	return ;
}

void Spfa()
{
	queue<int> q;
	for(int i=1; i<=n; i++)
	{
		if(!in[i])
		{
			q.push(i);
			vis[i]=true;
			a[i]=b[i]=0;
		}
		else
		{
			vis[i]=false;
			a[i]=b[i]=(lint)1e12;
		}
	}

	while(!q.empty())
	{
		int u=q.front();

		for(int i=fir[u], v; i; i=nxt[i]) if(a[v=ver[i]]>=a[u]+cst[i])
		{
			if(a[v]>a[u]+cst[i])
			{
				a[v]=a[u]+cst[i];
				b[v]=b[u]+pre[i];
			}
			else if(b[v]<b[u]+pre[i])	b[v]=b[u]+pre[i];
			if(!vis[v])
			{
				q.push(v);
				vis[v]=true;
			}
		}

		q.pop();
		vis[u]=false;
	}
	return ;
}

int main()
{
	while(scanf("%d%d", &m, &N)!=EOF)
	{
		n=0;
		mmp.clear();
		memset(in, 0, sizeof in);

		cur=0;
		memset(fir, 0, sizeof fir);
		char s1[20+10], s2[20+10], s3[20+10];
		for(int i=1, c, p; i<=N; i++)
		{
			scanf("%s%s%s%d%d", s1, s2, s3, &c, &p);
			string t1=s1, t2=s2;

			if(!mmp[t1])	mmp[t1]=++n;
			if(!mmp[t2])	mmp[t2]=++n;

			int u=mmp[t2], v=mmp[t1];
			Add(u, v, c, p);
		}

		Spfa();

		memset(f, 0, sizeof f);
		for(int i=1; i<=n; i++)
			for(int j=m; j>=a[i]; j--)
				f[j]=max(f[j], f[j-a[i]]+b[i]);

		lint cost=0, ans=0;
		for(int i=0; i<=m; i++)	if(f[i]>ans)	ans=f[i], cost=i;
		
		printf("%lld\n%lld\n", ans, cost);
	}
	return 0;
}
