#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
typedef long long lint;

int T, n, m, lef, v[maxn], sum[maxn], cnt[maxn], id[maxn];
lint f[maxn][maxn];
char s[maxn];

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s", &n, s+1);

		m=lef=0;
		memset(sum, 0, sizeof sum);
		memset(cnt, 0, sizeof cnt);

		for(int i=1; i<=n; i++)
		{
			scanf("%d", &v[i]);
			if(s[i]=='(')
			{
				lef++;
				sum[lef]=sum[lef-1]+v[i];
			}
			else
			{
				m++;
				cnt[m]=lef, id[m]=i;
			}
		}

		memset(f, 0x8f, sizeof f);
		lint def=f[0][0];
		f[0][0]=0;
		for(int i=1; i<=m; i++)
		{
			int cur=id[i];
			for(int j=i; j<=cur; j++)
			{
				int pre=id[i-1];
				lint tmp=def;
				for(int k=i-1; k<=pre && k<j; k++)	tmp=max(tmp, f[i-1][k]);
				f[i][j]=tmp+(lint)v[cur]*(sum[cnt[i]]-sum[cnt[i]-(cur-j)]);
				//printf("tmp=%I64d i=%d j=%d f=%I64d\n", tmp, i, j, f[i][j]);
			}
		}

		lint ans=0;
		for(int j=m; j<=id[m]; j++)	ans=max(ans, f[m][j]);
		cout<<ans<<endl;
	}
	//system("pause");
	return 0;
}
