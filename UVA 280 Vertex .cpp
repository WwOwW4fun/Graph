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

bool visited[10000];
int n;
int main()
{
    while(cin >> n && n)
    {
        int x;
        vector< vector<int> > adj(n+1, vector<int>());
        while(cin >> x && x != 0)
        {
            int y;
            while(cin >> y && y != 0)
            {
                adj[x].push_back(y);
            }
        }
        int t; cin >> t;
        int a[t];
        for(int i = 0 ; i < t ;i++)
        {
           int s; cin >> s;
           membo(visited);
           queue<int> qu;
           int cnt =n;
           qu.push(s);
           while(!qu.empty())
           {
               int u = qu.front();
               qu.pop();
               for(int v : adj[u])
               {
                   if(!visited[v])
                   {
                       visited[v] = true;
                       qu.push(v);
                       cnt --;
                   }
               }
           }
           cout << cnt;
           for(int j = 1 ; j <= n ; j++)
           {
               if(!visited[j])
               {
                   cout << " " << j;
               }
           }
           cout << endl;

        }


    }
    return 0;
}