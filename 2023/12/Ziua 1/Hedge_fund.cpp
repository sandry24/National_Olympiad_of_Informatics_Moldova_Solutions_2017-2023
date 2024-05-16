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
    ll n, m, s;
    cin >> n >> m >> s;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    ll mine = a[0], best_long = 0;
    for(int i = 0; i < n; i++){
        best_long = max(best_long, a[i] - mine);
        mine = min(mine, a[i]);
    }
    ll max_ind = 0, best_short = 0;
    for(int i = 0; i < n; i++){
        best_short = max(best_short, a[max_ind] - a[i] - s*(i-max_ind));
        if(a[i] >= a[max_ind] - s*(i-max_ind))
            max_ind = i;
    }
    cout << max(best_long, best_short) * m << '\n';
}  
 
int main(){
    // freopen("monede.in", "r", stdin);
    // freopen("monede.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}