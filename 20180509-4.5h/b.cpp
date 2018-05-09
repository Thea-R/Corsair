#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=400000+10;

int T, n, a[maxn], s[maxn], d[maxn];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);

        int init=0;
        for(int i=1; i<=n; i++) scanf("%d", &d[i]);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &s[i]);
            init=max(init, d[i]-s[i]);
        }

        int ans=0;
        memset(a, 0, sizeof a);
        for(int i=1, tp; i<=n; i++)
        {
            tp=s[i]-d[i]+init, ++a[tp];
            ans=max(ans, a[tp]);
        }

        printf("%d\n", ans);
    }
    //system("pause");
    return 0;
}
