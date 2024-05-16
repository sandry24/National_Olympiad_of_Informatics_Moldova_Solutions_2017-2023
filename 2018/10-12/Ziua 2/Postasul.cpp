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

int n;
char a[50][50];
bool visited[50][50];
int h[50][50];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_possible(pi temp, int high, int low){
    if(temp.f < 0 || temp.s < 0 || temp.f >= n | temp.s >= n)
        return false;
    if(visited[temp.f][temp.s] || h[temp.f][temp.s] < low || h[temp.f][temp.s] > high)
        return false;
    return true;
}

void dfs(pi current, int high, int low){
    visited[current.f][current.s] = 1;
    for(int i = 0; i < 8; i++){
        pi temp = {current.f + dx[i], current.s + dy[i]};
        if(is_possible(temp, high, low)){
            dfs(temp, high, low);
        }
    }
}

void clear(int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = 0;
}

void solve(){
    cin >> n;
    pi start;
    vector<pi> houses;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 'P')
                start = {i, j};
            if(a[i][j] == 'K')
                houses.pb({i, j});
        }
    }
    vi heights; //to make log2(2500) not log2(1e6)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> h[i][j];
            heights.pb(h[i][j]);
        }
    }
    int min_high = h[start.f][start.s];
    for(auto i : houses)
        min_high = max(min_high, h[i.f][i.s]);
    sort(heights.begin(), heights.end());
    heights.erase(unique(heights.begin(), heights.end()), heights.end());
    int start_ind = lower_bound(heights.begin(), heights.end(), min_high) - heights.begin();
    int ans = 1e9;
    for(int i = start_ind; i < heights.size(); i++){
        int high = heights[i];
        int current = -1;
        for(int k = i; k > 0; k /= 2){
            bool flag = 1;
            while(flag){
                if(current + k > i)
                    break;
                int low = heights[current + k];
                if(low > high || low > h[start.f][start.s])
                    break;
                clear(n);
                dfs(start, high, low);
                for(pi house : houses)
                    if(!visited[house.f][house.s])
                        flag = 0;
                if(flag)
                    current += k;
            }
        }
        if(current != -1)
            ans = min(ans, high - heights[current]);
    }
    cout << ans << '\n';
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