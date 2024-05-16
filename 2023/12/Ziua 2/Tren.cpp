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
    ll n, m, k, l, e, r, t;
    cin >> n >> m >> k >> l >> e >> r >> t;
    map<ll, ll> dist;
    vi stops(m);
    for(int i = 0; i < m; i++){
        cin >> stops[i];
        dist[stops[i]] = e*(stops[i]-1);
    }
    vector<pair<ll, ll>> ranges(m-1);
    for(int i = 0; i < m-1; i++)
        ranges[i] = {stops[i], stops[i+1]};
    ll ans = 0;
    for(int i = 0; i < m-1; i++){ //count those we can reach at the moment
        ll lf = ranges[i].f, rh = ranges[i].s;
        if(dist[lf] > t)
            break;
        ans += min((t - dist[lf]) / l + 1, rh-lf);
    }
    if(dist[n] <= t)
        ans++;
    for(int tms = 0; tms < k-m; tms++){ //each iteration pick the best interval to put a stop
        ll best_cnt = 0, best_ind, best_node, best_dist;
        for(int i = 0; i < m-1; i++){
            ll lf = ranges[i].f, rh = ranges[i].s;
            if(dist[lf] > t) //cant make anything better
                continue;
            ll limit = (t - dist[lf]) / l;
            if((t - dist[lf]) % l)
                limit++;
            ll cur_node = limit+lf; //suppose we put a stop here
            ll cur_dist = r*(cur_node-lf) + dist[lf];
            if(cur_node <= lf || cur_node >= rh || cur_dist > t) //cant make anything better
                continue;
            ll cnt = min((t - cur_dist) / l + 1, rh-cur_node); //how many stops will it add to ans
            if(cnt > best_cnt){
                best_cnt = cnt;
                best_ind = i;
                best_node = cur_node;
                best_dist = cur_dist;
            }
        }
        if(best_cnt == 0)
            break;
        ans += best_cnt; //add newly reached stops
        ranges[best_ind].f = best_node; //shorten the interval
        dist[best_node] = best_dist; //for future iterations
    }
    cout << ans-1 << '\n'; //without 1
}   
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("infasuratoare.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}