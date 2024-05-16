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

ll mod = 1e9+7;

ll count(string s, bool low){
    ll dp[101][10][2] = {}; //dp[i][j][k], cate numere panta de i cifre, cu j ultima si tight = k
    int n = s.size();
    dp[0][0][1] = 1;
    for(int i = 1; i <= n; i++){
        int dig = s[i-1] - '0';
        for(int j = 0; j <= dig; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j][j == dig] += dp[i-1][k][1];
                dp[i][j][j == dig] %= mod;
            }
        }
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j][0] += dp[i-1][k][0];
                dp[i][j][0] %= mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= 9; i++){
        ans += dp[n][i][0];
        if(i != s.back() - '0' || !low)
            ans += dp[n][i][1];
        ans %= mod;
    }
    return ans;
}

void solve(){
    string a, b;
    cin >> a >> b;
    cout << (count(b, 0) - count(a, 1) + mod) % mod << '\n';
}  
 
int main(){
    // freopen("monede.in", "r", stdin);
    // freopen("monede.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}