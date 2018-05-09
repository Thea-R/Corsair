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
	int T,n,f,i;
	string str;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		f=n%4;
		cin>>str;
		if(f==1||f==2){
			printf("-1\n");
		}
		else if(f==0){
			for(i=0;i<n;i++){
				if(i%4==0||i%4==3){
					if(str[i]=='1') cout<<3;
					else cout<<1;
				}
				else{
					if(str[i]=='1') cout<<4;
					else cout<<2;
				}
			}
			cout<<endl;
		}
		else{
			if(str[0]=='1') cout<<3;
			else cout<<1;
			for(i=1;i<n-2;i++){
				if((i-1)%4==0||(i-1)%4==3){
					if(str[i]=='1') cout<<3;
					else cout<<1;
				}
				else{
					if(str[i]=='1') cout<<4;
					else cout<<2;
				}
			}
			if(str[n-2]=='1') cout<<3;
			else cout<<1;
			if(str[n-1]=='1') cout<<4<<endl;
			else cout<<2<<endl;
		}
		//cout<<str<<"......"<<endl;
	}
	//SYS;
	return 0;
}
