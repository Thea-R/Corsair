#include<bits/stdc++.h>
#define MX 40
#define ll long long
using namespace std;
struct Node{int x,m;};
vector<Node>face[MX],cha[MX];
map<pair<ll,int>,ll> dp[2];
map<pair<ll,int>,ll>::iterator j;
int vis[MX];
int to[MX];
int tn,n;
void inint(){
	tn=0;
	memset(to,-1,sizeof(to));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		face[i].clear();
		cha[i].clear();
	}
}
int main(){
	int T,i,f,c,m,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		inint();
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&f,&c,&m);
			if(to[c]==-1) to[c]=tn++;
			face[f].push_back(Node{c,m});
			cha[c].push_back(Node{f,m});
		}
		int flag=0;
		ll s1=0,s2=0;
		for(i=1;i<=n;i++)
			if(cha[i].size()==1){
				if(vis[cha[i][0].x]==1){
					printf("0\n");
					flag=1;
					break;
				}
				s1|=1LL<<to[i];
				s2^=cha[i][0].m;
				vis[cha[i][0].x]=1;
			}
		if(flag) continue;
		int now=1,pre=0;
		dp[1].clear();
		dp[1][make_pair(s1,s2)]=1;
		for(i=1;i<=n;i++){  //dp
			if(vis[i]||face[i].size()==0) continue;
			swap(now,pre);
			dp[now]=dp[pre];
			for(j=dp[pre].begin();j!=dp[pre].end();j++){ //pre
				pair<ll,int> p=j->first;
				ll w=j->second;
				for(k=0;k<face[i].size();k++){    //now
					pair<ll,int> q=p;
					q.first|=1LL<<(to[face[i][k].x]);
					q.second^=face[i][k].m;
					dp[now][q]+=w;
				}
			}
		}
		printf("%lld\n",dp[now][make_pair((1LL<<tn)-1,0)]);
	}
	return 0;
}
