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

int n, s;
pi st, en;
char a[805][805];
bool visited[805][805];
int dist[805][805];
int dist2[805][805];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_possible(pi temp, int type, int time){
    if(temp.f <= 0 || temp.s <= 0 || temp.f > n || temp.s > n)
        return false;
    else if(visited[temp.f][temp.s] || a[temp.f][temp.s] == 'T' || a[temp.f][temp.s] == 'H')
        return false;
    if(type && dist[temp.f][temp.s] <= time) //bees get there before bear
        return false;
    if(!type && a[temp.f][temp.s] == 'D') //bees cant go through home
        return false;
    return true;
}

void bfs(vector<pi> b, int type, int time){ //type = 0 if bees
    queue<pi> q;
    for(auto start : b){
        q.push(start);
        visited[start.f][start.s] = 1;
        if(!type)
            dist[start.f][start.s] = 0;
        else 
            dist2[start.f][start.s] = time;
    }
    while(!q.empty()){
        pi current = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            pi temp = {current.f + dx[i], current.s + dy[i]};
            if(is_possible(temp, type, dist2[current.f][current.s] + 1)){
                q.push(temp);
                visited[temp.f][temp.s] = 1;
                if(!type)
                    dist[temp.f][temp.s] = dist[current.f][current.s] + 1;
                else 
                    dist2[temp.f][temp.s] = dist2[current.f][current.s] + 1;
            }
        }
    }
}

void clear(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist2[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void solve(){
    cin >> n >> s;
    vector<pi> bees;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 'H')
                bees.pb({i, j});
            if(a[i][j] == 'M')
                st = {i, j};
            if(a[i][j] == 'D')
                en = {i, j};
        }
    }
    bfs(bees, 0, 0);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dist[i][j] = s * dist[i][j]; //1 step for bees = s for bear
    if(!visited[st.f][st.s]){ //bees cant reach bear
        cout << -1 << '\n';
        return;
    }
    dist[en.f][en.s] = 1e9; //bees cant go inside home
    //binary search for how much time to eat honey
    int current = -1;
    for(int i = 1e9; i > 0; i /= 2){
        while(true){
            if(dist[st.f][st.s] <= current+i) //cant start
                break;
            clear();
            bfs({st}, 1, current+i);
            if(visited[en.f][en.s])
                current += i;
            else
                break;
        }
    }
    if(current == -1){ //bear cant reach home
        cout << -1 << '\n';
        return;
    }
    cout << current / s << '\n';
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