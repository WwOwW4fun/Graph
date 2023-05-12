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
int a[10000];
bool  visited[10000][10000];
bool check;
int n, k;
int m;
void dfs(int cnt, int u)
{

    if(cnt == n )
    {
        if(u % k == 0)
        {
            check = true;

        }
        return ;
    }
    if(visited[cnt][u]) return ;
    visited[cnt][u] =  true;
    dfs(cnt + 1,(u + a[cnt] + k) % k );
    dfs(cnt + 1,(u - a[cnt] + k) % k);

}
int main()
{
    int tc; cin >> tc;
    while(tc --)
    {
        cin >> n >> k;
        membo(visited);
        check = false;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a[i];
        }
        dfs(0,0);
        cout << (check ? "Divisible" : "Not divisible") << endl;

    }
}