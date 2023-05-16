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
int n, m;
bool visited[10000][10000];
int dx[] = {-1 , 0 ,0 ,1,-1,1,-1,1};
int dy[] = {0, -1, 1, 0,-1,1,1,-1};
char a[10000][10000];
bool valid(int x , int y)
{
     if(x<0||x>=n||y<0||y>=m) return true;
     if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]=='.') return true;
     return false;
}
bool check(int x, int y)
{
        for(int i=0;i<8;i++)
        if(!valid(x+dx[i],y+dy[i]))  return false;
        return true;
}
int main()
{
    fastio;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0) break;
        else
        {

            ll cnt = 0;
            for0(i,0,n)
            {
                for0(j,0,m)
                {
                    cin >> a[i][j];

                }

            }
           for0(i,0,n)
           {
               for0(j,0,m)
               {
                   if(a[i][j] == '*')
                   {
                       if(check(i,j)) cnt++;
                   }
               }
           }
            cout << cnt << endl;

        }
    }
}