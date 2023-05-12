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
int dx[] = {-1 , 0 ,0 ,1,-1,1,-1,1};
int dy[] = {0, -1, 1, 0,-1,1,1,-1};
int n, maxx;
string a[10000];

int dfs(int i, int j){
    if (i < 0 || i == n || j < 0 || j == a[0].size() || a[i][j] == '0') return 0;
    a[i][j] = '0';
    int cnt = 1;
    cnt+= dfs(i-1,j);
    cnt += dfs(i,j-1);
    cnt += dfs(i,j+1);
    cnt += dfs(i+1,j);
    cnt += dfs(i-1,j-1);
    cnt += dfs(i+1,j+1);
    cnt += dfs(i-1,j+1);
    cnt += dfs(i+1,j-1);
    return cnt;
}

int main(){
    int tc;cin >> tc;
    cin.ignore();
    cin.ignore();
    while(tc--){
        string s;
        n = 0, maxx = INT_MIN;
        while (getline(cin,s) && s != ""){
            a[n] = s, n++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a[0].size(); j++)
            {
        
                maxx = max(maxx,dfs(i,j));
            }
        }
        cout << maxx << endl;
        if (tc != 0) cout << endl;
    }

}