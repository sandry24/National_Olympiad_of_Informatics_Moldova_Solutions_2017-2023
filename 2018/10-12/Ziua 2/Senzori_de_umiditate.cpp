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

struct Sensor {
    int x, y;
};

struct Acces {
    int x, y, r;
};

vector<vector<int>> cont(1005); //every sensor access i can reach
vector<vector<int>> adj(1005); //every access point that access i can reach
vector<bool> visited(1005), can_be_reached(1005);
vector<Acces> acces;
vector<Sensor> sensor;

void dfs(int x){
    visited[x] = 1;
    for(auto i : adj[x])
        if(!visited[i])
            dfs(i);
    for(auto i : cont[x])
        can_be_reached[i] = 1;
}

void solve(){
    int n_s, n_a, n_br;
    Acces start;
    cin >> start.x >> start.y >> start.r;
    cin >> n_a;
    n_a++;
    acces = vector<Acces>(n_a);
    acces[0] = start;
    for(int i = 1; i < n_a; i++)
        cin >> acces[i].x >> acces[i].y >> acces[i].r;
    cin >> n_s;
    sensor = vector<Sensor>(n_s);
    for(int i = 0; i < n_s; i++)
        cin >> sensor[i].x >> sensor[i].y;
    cin >> n_br;
    vector<int> broken(n_br);
    for(int i = 0; i < n_br; i++){
        cin >> broken[i];
        visited[broken[i]] = 1;
    }

    for(int i = 0; i < n_a; i++){
        for(int j = 0; j < n_s; j++){
            double diffx = abs(acces[i].x - sensor[j].x);
            double diffy = abs(acces[i].y - sensor[j].y);
            double dist = sqrtl(diffx*diffx + diffy*diffy);
            if(dist <= (double)acces[i].r) //sensor j is in range of access i
                cont[i].push_back(j);
        }
        for(int j = i+1; j < n_a; j++){
            double diffx = abs(acces[i].x - acces[j].x);
            double diffy = abs(acces[i].y - acces[j].y);
            double dist = sqrtl(diffx*diffx + diffy*diffy);
            if(dist <= double(acces[i].r + acces[j].r)){ //access j is in range of access i
                adj[i].push_back(j);
                adj[j].push_back(i);           
            }
        }
    }
    
    dfs(0);
    int ans = 0;
    for(int i = 0; i < n_s; i++)
        if(!can_be_reached[i])
            ans++;
    cout << ans << '\n';
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