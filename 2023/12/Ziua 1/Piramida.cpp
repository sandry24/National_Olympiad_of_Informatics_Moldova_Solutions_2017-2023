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

char g[5000][5000];
int nr[5000][5000];

int calc(int n, int m){
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m-1; j++){
            if(g[i][j] == '1' && g[i-1][j-1] == '1' && g[i-1][j] == '1' && g[i-1][j+1] == '1')
                nr[i][j] = min({nr[i-1][j-1], nr[i-1][j], nr[i-1][j+1]}) + 1;
            ans += nr[i][j];
        }
    }
    return ans;
}

void rotate_clear(int n, int m){
    char g2[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            nr[i][j] = 0;
            g2[i][j] = g[n-1-j][i];
        }
    }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = g2[i][j];
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    ll ans = 0;
    int sz1 = n, sz2 = m;
    for(int i = 0; i < 4; i++){
        ans += calc(sz1, sz2);
        rotate_clear(sz1, sz2);
        swap(sz1, sz2);
    }
    cout << ans << '\n';
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