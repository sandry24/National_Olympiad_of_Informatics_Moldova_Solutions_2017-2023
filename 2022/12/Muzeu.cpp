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

int n, m, maxe = 0;
char grid[1000][1000];
bool visited[1000][1000];
int dist[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_possible(pi temp){
    if(temp.f < 0 || temp.s < 0 || temp.f >= n || temp.s >= m)
        return false;
    if(visited[temp.f][temp.s] || grid[temp.f][temp.s] == 'b')
        return false;
    return true;
}

void bfs(vector<pi> &coords){
    queue<pi> q;
    for(auto temp : coords){
        q.push(temp);
        dist[temp.f][temp.s] = 0;
        visited[temp.f][temp.s] = 1;
    }
    while(!q.empty()){
        pi temp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            pi next = {temp.f + dx[i], temp.s + dy[i]};
            if(is_possible(next)){
                dist[next.f][next.s] = dist[temp.f][temp.s] + 1;
                visited[next.f][next.s] = 1;
                q.push(next);
                maxe = max(maxe, dist[next.f][next.s]);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    vector<pi> coords;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'p')
                coords.pb({i, j});
        }
    }
    bfs(coords);
    cout << maxe << '\n';
}  
 
int main(){
    // freopen("monede.in", "r", stdin);
    // freopen("monede.out", "w", stdout);
    // ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}