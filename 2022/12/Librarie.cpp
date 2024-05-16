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
    int sz = (1 << n);
    vi a(2*sz), dp(2*sz); //dp[i] max_diff between score1 - score2 on that interval
    for(int i = sz; i < 2*sz; i++){
        cin >> a[i];
        dp[i] = a[i];
    }
    for(int i = sz-1; i > 0; i--)
        a[i] = a[2*i] + a[2*i+1];
    for(int i = sz-1; i > 0; i--)
        dp[i] = max(a[i*2] - dp[i*2+1], a[i*2+1] - dp[i*2]);
    cout << (a[1] + dp[1]) / 2 << ' ' << (a[1] - dp[1]) / 2 << '\n';
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