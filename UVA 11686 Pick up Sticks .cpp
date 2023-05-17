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

bool visited[1000000];
vector<int> topo;
vector<int> adj[1000000];
int pos[1000000];
int mar ;
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
bool check(int u)
{
    pos[u] = 1;

    for(int v : adj[u])
    {
        if(pos[v] == 0)
        {
            if(check (v))
            {
                return true;
            }
        }
        else if (pos[v] == 1)
        {
            return true;
        }
    }
    pos[u] = 2;
    return false;
}
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0)break;
        else
        {
            for(int i = 1; i <= n ; i++)
            {
                pos[i] = 0;
            }
            membo(visited);
            for0(j,0,m)
            {
                int x, y;
                cin >> x >> y;
                adj[x].push_back(y);
            }
            int c = 0;
            for(int i = 1 ;i <= n; i++)
            {
                if(check(i)) c = 1;
                break;
            }
            if(c == 1) cout << "IMPOSSIBLE" << endl;
            else
            {
                for0(i,1,n + 1)
                {
                    if(!visited[i])
                    {
                        dfs(i);
                    }
                }
                    for(int i = topo.size() - 1; i >= 0; i--)
                    {
                        cout << topo[i] <<endl;
                    }
            }
            topo.clear();
            for0(i,1, n + 1) adj[i].clear();


        }
    }
}
