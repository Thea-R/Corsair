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
const int maxm=1e3+10;

int l[maxm],r[maxm],ans[maxm],luna[maxm];

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}

int main(int argc, char const *argv[])
{
	FASTIO;
	int t;
	cin>>t;
	while(t--)
	{
		bool flag=true;
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;i++)	ans[i]=1;
		for(int i=1;i<=q;i++)
		{
			cin>>l[i]>>r[i];
			cin>>luna[i];
			for(int j=l[i];j<=r[i];j++)	ans[j]=lcm(ans[j],luna[i]);
		}
		for(int i=1;i<=q;i++)
		{
			int tmp=ans[l[i]];
			for(int j=l[i]+1;j<=r[i];j++)
			{
				tmp=gcd(tmp,ans[j]);
			}
			if(tmp!=luna[i])	
			{
				cout<<"Stupid BrotherK!"<<endl;
				flag=false;
				break;
			}
		}	
		if(flag)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==1)cout<<ans[i];
				else cout<<" "<<ans[i];
			}			
			cout<<endl;
		}
	}
	//SYS;
	return 0;
}
