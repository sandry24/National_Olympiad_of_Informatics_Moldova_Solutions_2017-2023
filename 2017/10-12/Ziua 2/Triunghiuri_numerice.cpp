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
    int n;
    cin >> n;
    vector<vi> a(n, vi(n, -1));
    vector<vector<pi>> dp(n, vector<pi>(n, {-1e9, 1e9}));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++)
            cin >> a[i][j];
    }
    dp[0][0] = {a[0][0], a[0][0]};
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = -1; k <= 1; k++){
                int ind = j + k;
                if(ind < 0 || ind >= i)
                    continue;
                dp[i][j].f = max(dp[i][j].f, dp[i-1][ind].f + a[i][j]);
                dp[i][j].s = min(dp[i][j].s, dp[i-1][ind].s + a[i][j]);
            }
        }
    }
    int maxe = -1e9, mine = 1e9;
    for(int j = 0; j < n; j++){
        maxe = max(maxe, dp[n-1][j].f);
        mine = min(mine, dp[n-1][j].s);
    }
    cout << mine << ' ' << maxe << '\n';
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