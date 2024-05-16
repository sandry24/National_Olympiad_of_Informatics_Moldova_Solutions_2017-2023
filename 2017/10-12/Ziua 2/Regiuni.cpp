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

vector<vi> adj(1005);
vector<vi> adj_inv(1005);
vector<bool> visited(1005);
vi topological;

void dfs(int x){
    visited[x] = 1;
    for(auto i : adj[x])
        if(!visited[i])
            dfs(i);
    topological.pb(x);
}

void dfs2(int x){
    visited[x] = 1;
    for(auto i : adj_inv[x])
        if(!visited[i])
            dfs2(i);
}

void solve(){
    int n;
    cin >> n;
    while(true){
        int a, b;
        cin >> a >> b;
        if(a == 0)
            break;
        adj[a].pb(b);
        adj_inv[b].pb(a);
    }
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            dfs(i);
    reverse(topological.begin(), topological.end());
    visited = vector<bool>(1005);
    int num = 0;
    for(auto i : topological){
        if(!visited[i]){
            dfs2(i);
            num++;
        }
    }
    cout << num << '\n';
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