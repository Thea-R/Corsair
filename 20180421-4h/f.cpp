#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define DE(x) cout<<"debug: "<<(x)<<endl
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
const int maxn=1e5+10;
const int maxm=1e7+10;

struct node
{
	char ch;
	int m;
	int pre;
};
int luna[11];
bool hashp[11];
int num[11];
node q[maxm];
bool vis[maxn];

void print(int x)
{
	if(x==0)return ;
	print(q[x].pre);
	cout<<q[x].ch;
	return;
}

int main(int argc, char const *argv[])
{
	FASTIO;
	int t;cin>>t;
	while(t--)
	{
		int n,m;
		memset(hashp,false,sizeof hashp);
		memset(vis,false,sizeof vis);
		cin>>n>>m;
		for(int i=0;i<m;i++)	
		{
			cin>>luna[i];
			hashp[luna[i]]=true;
		}
		int k=0;
		for(int i=0;i<10;i++)
		{
			if(!hashp[i])	num[k++]=i;
		}

		int l=1,r=1,ans=-1;
		for(int i=0;i<k;i++)
		{
			if(num[i])
			{
				q[r].pre=0;
				q[r].ch=num[i]+'0';
				vis[q[r].m=num[i]%n]=true;
				if(q[r].m==0)
				{
					ans=r;
					break;
				}
				r++;	
			}
			
		}
		if(m==10)
		{
			cout<<-1<<endl;
			continue;
		}
		while(l<r&&ans==-1)
		{
			for(int i=0;i<k;i++)
			{
				q[r].m=(q[l].m*10+num[i])%n;
				if(!vis[q[r].m])
				{
					q[r].pre=l;
					q[r].ch=num[i]+'0';
					vis[q[r].m]=true;
					if(q[r].m==0)
					{
						ans=r;
						break;
					}
					r++;	
				}				
			}
			l++;
		}
		if(ans==-1)cout<<-1<<endl;
		else print(ans),cout<<endl;
	}
	//SYS;
	return 0;
}
