#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100000+10;

int T, n, m, id[maxn];
char s[2];

int main()
{
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &n, &m);

		int w=0;
		for(int i=1, d; i<=n; i++)
		{
			scanf("%s", s);
			if(s[0]=='C')
			{
				scanf("%d", &d);
				id[i]=d;
			}
			else if(s[0]=='B')
			{
				scanf("%d", &d);
				id[i]=m+d;
			}
			else if(s[0]=='D')
			{
				scanf("%d", &d);
				id[i]=m+m+d;
			}
			else w=i;
		}
		id[n+1]=m+m+m+1;

		if(w==0)
		{
			if(n>=2 && id[1]>id[2])
			{
				printf("1\n");
				continue;
			}
			printf("%d\n", m*3-(n-1));//没有白板
			continue;
		}
		else
		{
			if(w==1)	printf("%d\n", id[2]-1);//第一个就是白板
			else
			{
				int ans=0;

				//第一个会不会是财神
				if(w==2)//第二个是白板
				{
					if(n==2)	ans=1;
					if(n>2 && id[1]<id[3])	ans=1;
				}
				else
				{
					if(id[1]>id[2])
					{
						if(id[w-1]<=id[1] && id[1]<=id[w+1])	printf("1\n");
						else printf("0\n");
						continue;
					}
					if(id[w-1]<=id[1] && id[1]<=id[w+1])	ans=1;
				}

				ans+=id[w+1]-id[w-1]-1;
				printf("%d\n", ans);
			}
		}
	}
	//system("pause");
	return 0;
}
