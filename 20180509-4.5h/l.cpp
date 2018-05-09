#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=100+10;
typedef long long lint;

int T, n, m;
char s[maxn];
set<string> st;
map<string, int> mmp;
struct node
{
	lint val;
	string s;
	void init(lint vv, string t)
	{
		val=vv, s=t;
		//cout<<"val "<<val<<endl;
	}
	bool operator <(const node&t)const
	{
		return val==t.val ? s<t.s : val>t.val;
	}
}p[maxn];

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		st.clear();
		mmp.clear();
		scanf("%d%d", &n, &m);
		for(int i=1, d; i<=n; i++)
		{
			scanf("%s%d", s, &d);
			string t=s;
			if(st.find(t)==st.end())
			{
				st.insert(t);
				mmp[t]=d;
			}
			else mmp[t]=max(mmp[t], d);
		}

		n=0;
		for(map<string, int>::iterator it=mmp.begin(); it!=mmp.end(); it++)	p[++n].init((lint)it->second, it->first);
		sort(p+1, p+1+n);

		lint ans=0;
		string out="";
		for(int i=1; i<=m; i++)
		{
			ans+=p[i].val*(m-i+1);
			//cout<<p[i].val<<' '<<m-i+1<<' '<<ans<<endl;
			out+=" ";
			out+=p[i].s;
		}
		cout<<ans<<out<<endl;
	}
	//system("pause");
	return 0;
}
