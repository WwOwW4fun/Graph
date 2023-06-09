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

int n , m;

vector <int> topo;
bool visited[10000];
vector<int> adj[10000];
void dfs(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
topo.push_back(u);
}
int main()
{
    fastio;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0 ) break;
        else
        {
            memset(visited,false,sizeof(visited));
            for(int i = 0 ; i < m ; i++)
            {
                int x,y; cin >> x >> y;
                adj[x].push_back(y);
            }
            for(int i = 1; i <= n; i++)
            {
                if(!visited[i])
                {
                    dfs(i);
                }
            }
           for(int i = topo.size() -1 ; i >= 0; i--)
           {
               cout << topo[i] << " ";
           }
           cout <<endl;
           topo.clear();
           for(int i = 1; i <= n ; i++)
           {
               adj[i].clear();
           }
        }
    }
}
