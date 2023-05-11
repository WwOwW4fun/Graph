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
bool visited[10000][10000];
int dx[] = {-1,-1,0,0,1,1};
int dy[] = {-1,0,-1,1,0,1};
char a[10000][10000];
int n;
void dfs(int i, int j)
{
    visited[i][j] = true;
    for(int k = 0; k < 6 ;k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni >= 1 and ni <= n and nj >= 1 and nj <= n and a[ni][nj] == 'w' and !visited[ni][nj])
        {
            dfs(ni,nj);
        }
    }
}
int main()
{
    int k = 1;
    while(cin >> n && n!= 0)
    {
        memset(visited,false,sizeof(visited));
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n ;j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i =0 ;i < n ; i++)
        {
            if(a[i][0] == 'w' and !visited[i][0])
            {
                dfs(i,0);
            }
        }
        int x = 0;
        for(int i = 0; i < n ; i++)
        {
            if(visited[i][n-1])
            {
                x = 1;
                break;
            }
        }
        cout << k << " ";
        k++;
        cout << (x == 0 ? "B" : "W") << endl;
    }
}
