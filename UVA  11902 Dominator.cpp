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

int n;
bool visited[1000];
int  a[1000][1000];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int pos[10000];
vector <int> adj[10000];
int res[1000][1000];
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
}
int main()
{
    int tc; cin >> tc;
    int k = 0;
    while(tc --)
    {
        int n; cin >> n;
        for0(i,0,n)
        {
            for0(j,0,n)
            {
                cin >> a[i][j];
                res[i][j] = 0;
                if(a[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        membo(visited);
        dfs(0);
        for(int i = 0 ; i < n ; i++)
        {
            if(visited[i] == 1)
            {
                pos[i] = 1;
            }
            else pos[i] = 0;
        }
        membo(visited);
        for(int i = 0; i < n ; i++)
        {
            if(pos[i] == 1)
            {
                membo(visited);
                visited[i] = true;
                dfs(0);
                for(int j = 0; j < n ; j++)
                {
                    if(pos[j] == 1)
                    {
                        if(!visited[j]) res[i][j] = 1;
                    }
                }
            }
        }
       for(int i = 1; i < n ; i++)
        {
            if(pos[i] == 1)
            {
                res[0][i] = 1;
            }
            else if(pos[i] == 0) res[0][i] = 0;
        }
        cout << "Case " << ++k << ":\n";
       for0(i,0,n)
       {
           cout << "+";
            for(int j = 0; j < 2*n -1 ; j ++)
            {
                cout << "-";
            }
            cout << "+" << endl;
           for0(j,0,n)
           {
               if(j == 0) cout << "|";
               if(res[i][j] == 1 || (pos[i] == 1 && i == j)) cout << "Y|";
               else cout << "N|";
            }
           cout << endl;
       }
            cout << "+";
            for(int j = 0; j < 2*n -1 ; j ++)
            {
                cout << "-";
            }
            cout << "+" << endl;
            for0(i,0,n) adj[i].clear();
    }
}