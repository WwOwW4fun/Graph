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
char a[1000][10000];
bool visited[10000][10000];
int n, m;
int cnt;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
char x;
pair<int, int> pi[10000];
void dfs(int i, int j)
{
    if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] != x || visited[i][j]) return ;
    visited[i][j] = true;
    cnt++;
    for(int k = 0; k < 4 ; k++)
    {
        int ni = i + dx[k];
        int nj = j + dy[k];
        dfs(ni,nj);
    }
}
int main()
{
    fastio;
    int tc = 1;
    while(cin >> n >> m)
    {
        if(n == 0 and m == 0) break;

        else
        {

            membo(visited);
            for0(i,0,n)
            {
                for0(j,0,m)
                {
                    cin >> a[i][j];
                }
            }
            int k = 0;
            for0(i,0,n)
            {
                for0(j,0,m)
                {
                    if(a[i][j] >= 'A' && a[i][j] <= 'Z' && !visited[i][j])
                    {
                        cnt = 0;
                        x = a[i][j];
                        dfs(i,j);
                        pi[k].second= - int(a[i][j]);
                        pi[k].first = cnt;
                        k++;
                    }
                }
            }
            sort(pi,pi+k);
            cout << "Problem " << tc << ":\n";
            tc ++;
            for(int i = k - 1; i >= 0 ; i -- )
            {
                cout << char(-pi[i].second) << " " << pi[i].first << endl;
            }

        }
    }
}