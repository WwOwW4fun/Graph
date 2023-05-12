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

bool visited[100000];
int n;
vector< int> adj[40000];
void dfs(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            dfs(v);
        }
    }
}
int main()
{
    int m;
    while(cin >> n >> m &&(m || n))
    {
        membo(visited);
        for0(j,0,m - 1)
        {
            int x;cin >> x;
            int a[x];
            for(int i = 0; i < x ;i ++)
            {
                cin >> a[i];
            }
            for(int i = 0 ; i < x ; i++)
            {
                for(int k = 0; k < x ;k ++)
                {
                    if(a[i] != a[k])
                    {
                        adj[a[i]].push_back(a[k]);
                    }
                }
            }
        }
        dfs(0);
        int cnt = 0;
        for0(i,0,n)
        {
            if(visited[i])
            {
                cnt ++;
            }
        }
        cout << cnt << endl;
        for0(i,0,n)
        {
            adj[i].clear();
        }
    }
}