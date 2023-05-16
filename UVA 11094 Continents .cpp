/* 
Author : Nguyen Xuan An 
Gmail : xuanan437@gmail.com
*/   
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define for0(i ,l ,r) for(int i = (l); i < (r); ++i)
#define for0(i, l, r) for(int i = (l); i >= (r); --i)
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
bool visited[1000][1000];
char a[1000][1000];
int dx[] = {-1 , 0 ,0 ,1};
int dy[] = {0, -1, 1, 0};
int n ,m;
char c,b;
int dem ;
void dfs(int i, int j) {
    if(j < 0)   j = m-1;
    if(j >= m)  j = 0;
    if(i < 0 || i >= n)
        return ;
    if(visited[i][j] != 0 || a[i][j] != b)
        return ;
    visited[i][j] = true;
    dem++;
    for(int k = 0; k < 4 ; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];
        dfs(ni,nj);
    }
}
int main()
{
    while(cin >> n >> m)
    {
        membo(visited);
        for0(i,0,n)
        {
            for0(j,0,m)
            {
                cin >> a[i][j];
            }
        }
        int x, y; cin >> x >> y;
        char d = a[x][y];
        b = d;
        dfs(x,y);
        int maxx = 0;
        for0(i,0,n)
        {
            for0(j,0,m)
            {
                    if(a[i][j] == b && !visited[i][j])
                    {
                        dem = 0;
                        dfs(i,j);
                        maxx = max(maxx,dem);
                    }

            }
        }

        cout << maxx << endl;
    }
}