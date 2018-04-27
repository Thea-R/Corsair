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
const int maxm=2e4+10;

int n,m;
int a[maxm],b[maxm],c[maxm];
int s[maxn][maxn],f[maxn][maxn];
int vis[maxn];

void dfs(int x)
{
    vis[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(s[x][i])
        {
            if(!vis[i]) dfs(i);
            for(int j=1;j<=n;j++)
                if(f[i][j])
                    f[x][j]=f[j][x]=1;            
        }
    }
}

bool check(int x)
{
    CLR(s,0);
    CLR(f,0);
    CLR(vis,0);
    
    for(int i=1;i<=n;i++)   s[i][i]=1;              //计算自反闭包
    for(int i=1;i<=x;i++)
    {
        if(c[i]==1) s[a[i]][b[i]]=1;
        else if(c[i]==2)    s[a[i]][b[i]]=s[b[i]][a[i]]=1;
        else if(c[i]==4)    f[a[i]][b[i]]=f[b[i]][a[i]]=1;  //对称闭包
    }
    //计算传递闭包
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                s[i][j]|=s[i][k]&&s[k][j];
    //计算一个s到f的特殊的传递闭包
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);

    for(int i=1;i<=x;i++)
    {
        if(c[i]==3)
            if(f[a[i]][a[i]]&&f[b[i]][b[i]]||s[a[i]][b[i]]&&s[b[i]][a[i]])
                return false;
        if(c[i]==5)
            if(f[a[i]][b[i]]||f[a[i]][a[i]]||f[b[i]][b[i]])
                return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    FASTIO;
    while(cin>>n>>m)
    {
        for(int i=1;i<=m;i++)   cin>>c[i]>>a[i]>>b[i];
        int le=0,ri=m;
        while(le<ri)
        {
            int mid=(le+ri+1)>>1;
            if(check(mid))  le=mid;
            else ri=mid-1;
        }
        cout<<le<<endl;
    }
    //SYS;
    return 0;
}