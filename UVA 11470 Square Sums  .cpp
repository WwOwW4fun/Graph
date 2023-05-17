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
int main()
{
    int n;
    int k = 1;
    while(cin >> n && n)
    {
        int a[n][n] , sum[n/2 +2];
        for(int i = 0; i < n/2 +2 ; i++)
        {
            sum[i] = 0;
        }
        for0(i,0,n)
        {
            for0(j,0,n)
            {

                cin >> a[i][j];
            }
        }
        if(n % 2 != 0)
        {
            for(int k = 0 ; k <= n/2  ; k++)
            {
                for(int i = n/2 - k ; i <= n/2 + k ;i++)
                {
                    for(int j = n/2 - k; j <= n/2 + k ; j++)
                    {
                        sum[k] += a[i][j];
                    }
                }
             for(int l = 0 ; l < k ; l++)
                {
                    sum[k] -= sum[l];
                }
            }

            cout << "Case " << k << ":";
            k++;
            for(int i = n/2 ;i >= 0 ; i--)
            {
                cout << " " << sum[i];
            }
            cout << endl;
        }
        else if(n % 2 == 0)
        {
            for(int k = 0 ; k < n/2  ; k++)
            {
                for(int i = n/2 - k - 1 ; i <= n/2 + k  ;i++)
                {
                    for(int j = n/2 - k - 1; j <= n/2 + k ; j++)
                    {
                        sum[k] += a[i][j];
                    }
                }
             for(int l = 0 ; l < k ; l++)
                {
                    sum[k] -= sum[l];
                }
            }
            cout << "Case " << k << ":";
            k++;
            for(int i = n/2 -1 ;i >= 0 ; i--)
            {
                cout << " " <<  sum[i];
            }
            cout << endl;

        }

    }
}
