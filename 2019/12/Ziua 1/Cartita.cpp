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

vector<vi> adj(1e6+3);
vi pos(1e6+3), level(1e6+3);

void dfs(int x, int p, int height, int coord){
    pos[x] = coord;
    level[x] = height;
    for(auto i : adj[x]){
        if(i < 0)
            dfs(-i, x, height+1, coord-1);
        else
            dfs(i, x, height+1, coord+1);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<bool> is_root(n+1, 1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        is_root[b] = 0;
        if(c == 'S')
            b *= -1;
        adj[a].pb(b);
    }
    for(int i = 1; i <= n; i++){
        if(is_root[i])
            dfs(i, -1, 0, 0);
    }
    int mine = 1e9, maxe;
    for(int i = 1; i <= n; i++){
        if(level[i] == k){
            if(mine == 1e9){
                mine = i;
                maxe = i;
            }
            if(pos[i] < pos[mine])
                mine = i;
            if(pos[i] > pos[maxe])
                maxe = i;
        }
    }
    cout << mine << ' ' << maxe << '\n';
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