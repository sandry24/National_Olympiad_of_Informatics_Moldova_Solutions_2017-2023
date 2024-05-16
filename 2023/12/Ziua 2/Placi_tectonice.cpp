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

vector<ll> BIT(2e5+5);

void add(int x, int delta){
    for(; x <= 2e5; x += x & -x)
        BIT[x] += delta;
}

ll sum(int x){
    ll ans = 0;
    for(; x > 0; x -= x & -x)
        ans += BIT[x];
    return ans;
}

void solve(){
    ll n, q, s, t, ans = 0;
    cin >> n >> q >> s >> t;
    vi a(n+1);
    for(int i = 0; i <= n; i++){
        cin >> a[i];
        if(i)
            ans += (a[i-1] - a[i]) * (a[i] > a[i-1] ? s : t);
    }
    for(int i = 0; i < q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        ll cur = a[l] + sum(l), othr = a[l-1] + sum(l-1), nxt = cur + x; //how much left changed
        ans += (othr - nxt) * (nxt > othr ? s : t) 
                    - (othr - cur) * (cur > othr ? s : t);
        if(r != n) {
            cur = a[r] + sum(r), othr = a[r+1] + sum(r+1), nxt = cur + x; //how much right changed
            ans += (nxt - othr) * (othr > nxt ? s : t) 
                        - (cur - othr) * (othr > cur ? s : t);
        }
        cout << ans << '\n';
        add(l, x);
        add(r+1, -x);
    }
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