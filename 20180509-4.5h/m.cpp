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

int luna[maxn];

int main(int argc, char const *argv[])
{
    FASTIO;
    int t;
    cin>>t;
    while(t--)
    {
        int n,b;
        cin>>n>>b;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            if((tmp+b)%7==0)    flag=true;
        }
        if(flag)    cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    //SYS;
    return 0;
}
