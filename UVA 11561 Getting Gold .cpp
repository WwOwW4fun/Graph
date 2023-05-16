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
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int cnt;
void dfs(int i, int j)
{
    if(a[i][j] == '#' || visited[i][j]) return ;
    if(a[i][j] == 'G') cnt++;
    visited[i][j] = true;
    for(int k = 0; k < 4 ; k++)
    {
        if(a[i + dx[k]][j + dy[k]] == 'T') return;
    }
    for(int k = 0 ; k < 4 ; k++)
    {
        dfs(i + dx[k], j + dy[k]);
    }

}
int main()
{
    int m ,n;
    while(cin >> m >> n)
    {

            membo(visited);
            int x, y;
            for0(i,0,n)
            {
                for0(j,0,m)
                {
                    cin >> a[i][j];
                    if(a[i][j] == 'P')
                    {
                        x = i;
                        y = j;
                    }
                }
            }
            cnt = 0;
            dfs(x ,y);
            cout << cnt << endl;


    }
}