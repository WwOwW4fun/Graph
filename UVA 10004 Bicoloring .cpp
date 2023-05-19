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
int main()
{
    int n, m;
    while(cin >> n)
    {
        if(n == 0) break;
        else{
            cin >> m;
            for0(i,0,n)
            {
                pos[i] = 0;
            }
            int a[m], b[m];
            vector< vector<int> > adj(n, vector<int>());
            for0(i,0,m)
            {
                cin >> a[i] >> b[i];
                adj[a[i]].push_back(b[i]);
                adj[b[i]].push_back(a[i]);
            }
            int x = 0;
            pos[0] = 1;
            for0(i,0,m)
            {
                if(pos[a[i]] == 0 && pos[b[i]] != 0)
                {
                    pos[a[i]] = 3 - pos[b[i]];
                }
                else if(pos[b[i]] == 0 && pos[a[i]] != 0)
                {
                    pos[b[i]] = 3 - pos[a[i]];
                }
                else if(pos[a[i]] == pos[b[i]] && pos[a[i]] != 0)
                {
                    x = 1;
                    break;
                }
            }
            cout << (x == 0 ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
        }
    }
}
