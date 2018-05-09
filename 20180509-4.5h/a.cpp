#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define DE(x) cout<<"debug: "<<(x)<<endl
#define CLR(x,y) memset(x,y,sizeof(x))
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
const int maxn=1e2+10;
const int maxm=1e5+10;

int main(int argc, char const *argv[])
{
	int T,n,f1,f2,f,x,lst,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		f1=1;f2=0;f=0;
		scanf("%d",&lst);
		for(i=1;i<n;i++){
			scanf("%d",&x);
			if(f1&&x<=lst){
				f1=0;
				f2=1;
			}
			if(i==1&&f1==0) f=1;
			if(f2&&x>=lst) f=1;
			lst=x;
		}
		if(f||f2==0) printf("No\n");
		else printf("Yes\n");
	}	
	return 0;
}
