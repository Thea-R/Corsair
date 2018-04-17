#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define DE(x) cout<<"debug: "<<(x)<<endl
#define FASTIO ios::sync_with_stdio(false)
#define SYS system("pause");
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const double eps=1e-6;
const double pi=acos(-1.0);
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const int maxn=2e2+10;
const int maxm=1e5+10;

int luna[maxn];
bool dp[maxn][maxn];

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		memset(dp,0,sizeof dp);
		cin>>n>>m;
		for(int i=0;i<m;i++)	cin>>luna[i];
		dp[1][0]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<i;j++)
			{
				for(int k=0;k<m;k++)
				{
					if(dp[i-1][j])	dp[i][(j+luna[k])%i]=1;
				}
			}
		}
		int sum=0;
		vector<int> v;
		for(int i=0;i<n;i++)	if(dp[n][i])	v.push_back(i+1);
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++)
		{
			if(i==0)cout<<v[i];
			else cout<<" "<<v[i];
		}
		cout<<endl;
	}
	//SYS;
	return 0;
}
