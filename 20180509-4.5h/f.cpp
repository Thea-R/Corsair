#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=500000+10, mod=1000000000;
typedef long long lint;

int T, n, m, sum[maxn][35];
lint a[maxn];

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i=1; i<=n; i++)	scanf("%lld", &a[i]);

		sort(a+1, a+1+n);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=32; j++)
				sum[i][j]=(sum[i-1][j]+a[i]/j)%mod;

		lint ans=0, p;
		for(int i=1; i<=m; i++)
		{
			scanf("%lld", &p);
			lint z=0, tmp=1ll, j=1ll;
			while(true)
			{
				int l=upper_bound(a+1, a+1+n, tmp)-a;
				if(l>n)	break;

				int r=upper_bound(a+1, a+1+n, tmp*p)-a;
				if(l!=r)	z=(z+sum[r-1][j]-sum[l-1][j]+mod)%mod;
				j++, tmp*=p;
			}

			ans=(ans+z*i%mod)%mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
