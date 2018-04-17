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
const int maxn=1e2+10;
const int maxm=1e6+10;

int a[maxn],b[maxn];

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		bool flag=true;
		int n,m;
		int ans=0;
		cin>>n>>m;
		for(int i=0;i<m;i++)	cin>>a[i];
		for(int i=0;i<m;i++)	cin>>b[i];

		sort(a,a+m);
		sort(b,b+m);
		for(int i=0;i<m;i++)
		{
			if(a[i]>b[i])
			{
				cout<<"Stupid BrotherK!"<<endl;
				flag=false;
				break;
			}
		}
		if(!flag)continue;

		if(a[0]>1)ans=max(ans,a[0]-1);
		if(b[m-1]<n)ans=max(ans,n-b[m-1]);
		for(int i=1;i<m;i++)
		{
			if(a[i]>b[i-1])ans=max(ans,a[i]-b[i-1]-1);
		}
		printf("%.6f\n",ans*1.0);
		//cout<<ans<<endl;
	}	
	//SYS;
	return 0;
}
