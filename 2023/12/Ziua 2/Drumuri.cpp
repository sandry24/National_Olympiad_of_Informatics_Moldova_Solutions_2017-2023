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

int n, m, k;
vector<vi> adj(3e5+4);
vector<bool> used(6);
vi color(3e5+4);
int cnt = 0;

void dfs(int x){
    used[color[x]] = 1;
    cnt++;
    for(auto i : adj[x])
        if(!used[color[i]])
            dfs(i);
    used[color[x]] = 0;
}

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> color[i];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 1; i <= n; i++)
        dfs(i);
    cout << cnt - n << '\n';
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