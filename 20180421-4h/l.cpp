#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=5000+10;

int T, n, a[maxn];

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; i++)	scanf("%d", &a[i]);

		int ans=0, i=1, j=2;
		while(j<=n)
		{
			while(j<=n && a[j-1]<=a[j])	++j;
			ans+=a[j-1]-a[i];
			i=j++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
