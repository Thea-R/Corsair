#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define DE(x) cout<<"debug: "<<(x)<<endl
#define CLR(x,y) memset(x,y,sizeof(x))
#define FASTIO ios::sync_with_stdio(false)
#define SYS system("pause")
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const double eps=1e-6;
const double pi=acos(-1.0);
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e2+10;
const int maxm=1e5+10;

const int N=60;
struct node{int to,w;};
vector<node>g[N];
int n,m,K,msk;
int st[N],vis[N][1<<11];
int dis[N][1<<11],dp[1<<11];
queue<int>que;

void spfa(int state)
{
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		vis[u][state]=0;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i].to;
			int w=g[u][i].w;
			if(dis[v][state|st[v]]>dis[u][state]+w)
			{
				dis[v][state|st[v]]=dis[u][state]+w;
				if(((state|st[v])==state)&&!vis[v][state])
				{
					vis[v][state]=true;
					que.push(v);
				}
			}
		}
	}
}

void steinerTree()
{
	for(int s=0;s<=msk;s++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int p=(s-1)&s;p;p=(p-1)&s)
			{
				dis[i][s]=min(dis[i][s],dis[i][p|st[i]]+dis[i][(s-p)|st[i]]);
			}
			if(dis[i][s]<INF&&!vis[i][s])
			{
				que.push(i);
				vis[i][s]=true;
			}
		}
		spfa(s);
	}
}

bool check(int state)
{
	int res=0;
	int i=0;
	while(state)
	{
		res+=(state&1)*(i<K?1:-1);
		i++;
		state>>=1;
	}
	return (res==0?true:false);
}

void init()
{
	msk=(1<<(2*K))-1;
	for(int i=0;i<N;i++)	g[i].clear();
	CLR(vis,0);
	CLR(st,0);
	CLR(dis,INF);
	CLR(dp,INF);
	for(int i=1;i<=K;i++)
	{
		st[i]=1<<(i-1);
		dis[i][st[i]]=0;
		st[n-i+1]=1<<(K+i-1);
		dis[n-i+1][st[n-i+1]]=0;
	}
}

int main(int argc, char const *argv[])
{
	FASTIO;
	int t;cin>>t;
	while(t--)
	{
		cin>>n>>m>>K;
		init();
		for(int i=0;i<m;i++)
		{
			int u,v,w;
			node a,b;
			cin>>u>>v>>w;
			a.to=v,a.w=w;
			b.to=u,b.w=w;
			g[u].emplace_back(a);
			g[v].emplace_back(b);
		}

		steinerTree();

		for(int s=0;s<=msk;s++)	
			for(int i=1;i<=n;i++)
				dp[s]=min(dp[s],dis[i][s]);
		for(int s=0;s<=msk;s++)
			if(check(s))
				for(int p=(s-1)&s;p;p=(p-1)&s)
					if(check(p))
						dp[s]=min(dp[s],dp[p]+dp[s-p]);
		if(dp[msk]>=INF)	cout<<"No solution"<<endl;
		else cout<<dp[msk]<<endl;
	}
	//SYS;
	return 0;
}