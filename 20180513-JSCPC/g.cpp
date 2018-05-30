#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=10000+10;

int n, m, c1, c2, k1[maxn], k2[maxn];
char s[maxn], t[maxn];

bool ok()
{
	if(c1!=c2)	return false;
	
	int a1[maxn]={0}, b1[maxn]={0}, a2[maxn]={0}, b2[maxn]={0};
	for(int i=1, cnt=1; i<=n; i++)
	{
		a1[cnt]+=(s[i]=='a');
		b1[cnt]+=(s[i]=='b');
		if(k1[cnt]==i)	++cnt;
	}
	for(int i=1, cnt=1; i<=m; i++)
	{
		a2[cnt]+=(t[i]=='a');
		b2[cnt]+=(t[i]=='b');
		if(k2[cnt]==i)	++cnt;
	}
	//cout<<c1<<endl;
	//for(int i=1; i<=c1+1; i++) printf("a1=%d b1=%d a2=%d b2=%d\n", a1[i], b1[i], a2[i], b2[i]);
	for(int i=1; i<=c1+1; i++)
	{
		if(a1[i]%2!=a2[i]%2)	return false;
		if(b1[i]%2!=b2[i]%2)	return false;
	}
	return true;
}

int main()
{	
	while(scanf("%s%s", s+1, t+1)!=EOF)
	{
		n=strlen(s+1), m=strlen(t+1);
		
		c1=c2=0;
		memset(k1, 0, sizeof k1);
		memset(k2, 0, sizeof k2);
		for(int i=1; i<=n; i++)	if(s[i]=='c')	k1[++c1]=i;
		for(int i=1; i<=m; i++) if(t[i]=='c')	k2[++c2]=i;
		
		ok() ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
