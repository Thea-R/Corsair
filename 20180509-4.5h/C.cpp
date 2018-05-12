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

const int MAXN1 = 60;  
const int MAXN2 = 60;  
ll C[MAXN1][MAXN2];  
  
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

void init()  
{  
    for(int i= 0;i<=MAXN1;i++)  
        C[i][0] = 1;  
    for(int i=1; i<=MAXN1;i++)  
    {  
        for(int j=1; j<=min(i, MAXN2 - 1);j++)  
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;  
    }  
}  

int main(int argc, char const *argv[])
{
    init();
    int t;
    cin>>t;
    while(t--)
    {
        map<int,int>mp;
        for(int i=1;i<=12;i++)  mp[i]=4;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string s;cin>>s;
            if(s[0]=='A')   mp[1]--;
            else if(s[0]=='J')  mp[11]--;
            else if(s[0]=='Q')  mp[12]--;
            else if(s=="10")    mp[10]--;
            else mp[s[0]-'0']--;
        }

        int m=48-n;
        if(mp[1]==0)
        {
            cout<<1;
            for(int i=2;i<=12;i++)
                if(mp[i]==0)    cout<<" "<<1;
                else cout<<" "<<0;
            cout<<endl;
        }
        else
        {
            cout<<1;
            for(int i=2;i<=12;i++)
            {
                if(mp[i]==0)    cout<<" "<<1;
                else
                {
                    ll q=C[m][mp[1]]*C[m-mp[1]][mp[i]];
                    ll p=0;
                    for(int j=mp[1]+mp[i];j<=m;j++) p+=C[j-1][mp[1]-1]*C[j-mp[1]][mp[i]];
                    ll g=gcd(p,q);
                    p/=g;q/=g;
                    if(p==0)    cout<<" "<<0;
                    else if(p==q)   cout<<" "<<1;
                    else cout<<" "<<p<<"/"<<q;
                }
            }
            cout<<endl;
        }
    }
    //SYS;
    return 0;
}