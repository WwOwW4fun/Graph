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

#define for0 for(int i = 0 ; i < n ; i++)
#define for1  for(int i = 0; i < m ; i++)
int pos[100000];
int main()
{
    int n;
    while(cin >> n && n)
    {
         vector< vector<int> > adj(n, vector<int>());
         int x ,y;
         for0
         {
             pos[i] = 0;
         }
         while(cin >> x >> y)
         {
             if(x == 0 && y == 0) break;
             else
             {
                 adj[x - 1].push_back(y - 1);
                 adj[y - 1].push_back(x - 1);
             }

         }
             pos[0] = 1;
             int a = 0, b = 0;
             for(int i = 0 ;i < n ; i++)
             {

                     for(int v : adj[i])
                     {
                         if(pos[v] == 0 && pos[i] != 0)
                         {
                             pos[v] = 3 - pos[i];
                         }
                         if(pos[i] == 0 && pos[v] != 0)
                         {
                             pos[i] = 3 - pos[v];
                         }
                          if(pos[v] == pos[i] && pos[i] != 0)
                         {
                             a = 1;
                             break;
                         }
                     }
                     if(a == 1)
                     {
                         b = 1;
                         break;
                     }


             }
             cout << (b == 0 ? "YES" : "NO") << endl;

    }
}