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
const int maxn=200000+10;

int T, n, m, cnt, pos[maxn], pl[maxn], pr[maxn];
char s[maxn];
struct node
{
	int ls, rs;
	node(int _ls=0, int _rs=0)
	{
		ls=_ls, rs=_rs;
	}
}tr[maxn<<2];

void Push_up(int k)
{
	int sum=min(tr[kl].ls, tr[kr].rs);
	tr[k].ls=tr[kl].ls+tr[kr].ls-sum;
	tr[k].rs=tr[kl].rs+tr[kr].rs-sum;
	return ;
}

void Build(int k=1, int l=1, int r=n)
{
	if(l==r)
	{
		tr[k].ls=(s[l]=='('), tr[k].rs=(s[l]==')');
		return ;
	}
	Build(kl, l, mid);
	Build(kr, mid+1, r);
	Push_up(k);
	return ;
}

void Change(int x, int k=1, int l=1, int r=n)
{
	if(l==r)
	{
		swap(tr[k].ls, tr[k].rs);
		return ;
	}
	if(x<=mid)	Change(x, kl, l, mid);
	else Change(x, kr, mid+1, r);
	Push_up(k);
	return ;
}

void Query(int ll, int rr, int k=1, int l=1, int r=n)
{
	if(rr< l || r< ll)	return ;
	if(ll<=l && r<=rr)
	{
		pos[++cnt]=k, pl[cnt]=l, pr[cnt]=r;
		return ;
	}
	Query(ll, rr, kl, l, mid);
	Query(ll, rr, kr, mid+1, r);
	Push_up(k);
	return ;
}

node Update(node l, node r)
{
	int sum=min(l.ls, r.rs);
	return node(l.ls+r.ls-sum, l.rs+r.rs-sum);
}

int Find(int tot, int d, int k=1, int l=1, int r=n)
{
	if(l==r)	return l;
	if(d==0)
	{
		if(tot<=tr[kl].rs)	return Find(tot, d, kl, l, mid);
		return Find(tot-tr[kl].rs+tr[kl].ls, d, kr, mid+1, r);
	}
	else if(tot<=tr[kr].ls)	return Find(tot, d, kr, mid+1, r);
	return Find(tot-tr[kr].ls+tr[kr].rs, d, kl, l, mid);
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%s", &n, &m, s+1);
		Build();
		
		for(int i=1, d, x, l, r, k, ans; i<=m; i++)
		{
			scanf("%d", &d);
			if(d==1)
			{
				scanf("%d", &x);
				Change(x);
			}
			else
			{
				scanf("%d%d%d", &l, &r, &k);
				
				cnt=ans=0;
				Query(l, r);
				node cur;
				for(int j=1; j<=cnt; j++) cur=Update(cur, tr[pos[j]]);

				if(cur.ls+cur.rs<k)	ans=-1;
				else if(k<=cur.rs)
				{
					node tp1, tp2;
					for(int j=1; j<=cnt; j++)
					{
						tp2=Update(tp1, tr[pos[j]]);
						if(k<=tp2.rs)
						{
							ans=Find(k-tp1.rs+tp1.ls, 0, pos[j], pl[j], pr[j]);
							break;
						}
						tp1=tp2;
					}
				}
				else
				{
					k=cur.ls+cur.rs-k+1;
					node tp1, tp2;
					for(int j=cnt; j>=1; j--)
					{
						tp2=Update(tr[pos[j]], tp1);
						if(k<=tp2.ls)
						{
							ans=Find(k-tp1.ls+tp1.rs, 1, pos[j], pl[j], pr[j]);
							break;
						}
						tp1=tp2;
					}
				}
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
