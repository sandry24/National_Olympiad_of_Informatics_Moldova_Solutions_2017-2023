#include <bits/stdc++.h>
using namespace std;
 
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define pb push_back
#define mp make_pair
#define f first
#define s second

void solve(){
    vi coins = {1, 5, 10, 25, 50};
    int n, g;
    cin >> n >> g;
    pi dp[g+5][n+5];
    for(int i = 0; i <= g; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = {1e9, 0};
    dp[0][0] = {0, 1};
    for(int i = 0; i <= g; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < 5; k++){
                int v = coins[k], w = k+1;
                if(i - w < 0)
                    continue;
                dp[i][j].f = min(dp[i-w][j-1].f + v, dp[i][j].f); 
                if(dp[i-w][j-1].f != 1e9){
                    dp[i][j].s += dp[i-w][j-1].s;
                    if(i-w == w)
                        dp[i][j].s += dp[i-w][j-1].s;
                }
            }
        }
    }
    cout << dp[g][n].f << ' ' << dp[g][n].s/2 << '\n';
}   
 
int main(){
    //freopen("infasuratoare.in", "r", stdin);
    //freopen("infasuratoare.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}