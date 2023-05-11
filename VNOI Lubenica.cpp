/* 
Author : Nguyen Xuan An 
Gmail : xuanan437@gmail.com
*/   
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define for0(i ,l ,r) for(int i = (l); i < (r); ++i)
#define for1(i, l, r) for(int i = (l); i >= (r); --i)
#define for2(v) for(auto it : v)
#define reset(a) memset(a,0,sizeof(a))
#define mem(a) memset(a,-1,sizeof(a))
#define membo(a) memset(a,false,sizeof(a))

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pii pair<int,int>
#define fi first
#define se second
#define prq priority_queue
#define pb push_back

#define output ios::sync_with_stdio(0);cin.tie(0);
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define PI 3.1415926535897932385
#define INF 10000000

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
const ll maxsize = 200000;
ll dp[maxsize][30];
ll h[maxsize];
vector<pair<int,int>> adj[maxsize];
ll minimum[maxsize][30], maximum[maxsize][30];
ll n;
void dfs(ll u)
{
    for(auto it : adj[u])
    {
        ll v = it.first, w = it.second;
        if(v == dp[u][0]) continue;
        dp[v][0] = u;
        maximum[v][0] = minimum[v][0] = w;
        h[v] = h[u] + 1;
        for(int j = 1; j < 28 ; j++)
        {
            dp[v][j] = dp[dp[v][j-1]][j-1];
            maximum[v][j] = max(maximum[v][j-1], maximum[dp[v][j-1]][j-1]);
            minimum[v][j] = min(minimum[v][j-1], minimum[dp[v][j-1]][j-1]);
        }
        dfs(v);
    }
}
ll Max, Min;
void solve(ll u, ll v)
{
    Min = INT_MAX;
    Max = INT_MIN;
    if(h[u] != h[v])
    {
        if(h[u] < h[v]) swap(u,v);
        ll k = h[u] - h[v];
        for(int j = 27 ; j >= 0 ; j--)
        {
            if(k >= (1 << j))
            {
                Min = min(Min,minimum[u][j]);
                Max = max(Max,maximum[u][j]);
                k -= (1 << j); u = dp[u][j];
            }

        }
    }
    if( u != v)
    {
        for(int j = 27; j >= 0; j--)
        {
            if(dp[u][j] != dp[v][j])
            {
                
                Min = min(Min,min(minimum[u][j], minimum[v][j]));
                Max = max(Max,max(maximum[u][j], maximum[v][j]));
                u = dp[u][j], v = dp[v][j];
            }
        }
         Min = min(Min,min(minimum[u][0], minimum[v][0]));
         Max = max(Max,max(maximum[u][0], maximum[v][0]));

    }
    cout << Min << " " << Max << endl;
}
int main()
{
    output;
    cin >> n;
    n -= 1;
    while(n --)
    {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1);
    ll q; cin >> q;
    while(q --)
    {
        ll u, v; cin >> u >> v;
        solve(u ,v);

    }

}