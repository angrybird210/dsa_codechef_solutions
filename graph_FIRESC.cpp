#include<bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
const int mod = 1e9 + 7;
void dfs(vector<bool>&vis,vector<vector<int>>&g,int v,int &cnt)
{
  cnt++;
  vis[v] = true;
  for(auto u : g[v])
  {
    if(!vis[u])
    dfs(vis,g,u,cnt);
  }
  return;
}
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>>g(n);
  rep(i,0,m)
  {
    int a,b;
    cin>>a>>b;
    --a;--b;
    g[a].pb(b);
    g[b].pb(a);

  }
  int c = 0;
  vector<int>val;
  vector<bool>vis(n);
  rep(i,0,n)
  {
    if(vis[i]==false)
    {
      int cnt = 0;
      dfs(vis,g,i,cnt);
      val.pb(cnt);
    }

  }
  cout<<val.size()<<" ";
  ll ans = 1;
  rep(i,0,val.size())
  ans = (ans*val[i])%mod;
  cout<<ans<<"\n";
  
  
}
int main()
{
    fastIO;
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}