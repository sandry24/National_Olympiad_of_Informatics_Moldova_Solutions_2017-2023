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

int m[10001][2]; //left, right margins
int dp[10001][2]; //cost to finish on left, right

void solve(){
    int n, maxe = 0;
    cin >> n;
    vector<pi> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].f >> a[i].s;
        swap(a[i].f, a[i].s); //go from up to down
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(m[a[i].f][0] == 0)
            m[a[i].f][0] = a[i].s;
        m[a[i].f][1] = a[i].s;
    }
    m[0][0] = m[0][1] = 1;
    dp[0][0] = dp[0][1] = -1;
    int last = 0;
    for(int i = 1; i <= 10000; i++){
        if(m[i][0] == 0)
            continue;
        int left = m[i][0], right = m[i][1];
        int prev_left = m[last][0], prev_right = m[last][1];
        int sum = i - last + right - left;
        dp[i][0] = min(dp[last][1] + abs(prev_right - right), dp[last][0] + abs(prev_left - right)) + sum;
        dp[i][1] = min(dp[last][0] + abs(prev_left - left), dp[last][1] + abs(prev_right - left)) + sum;
        last = i;
    }
    cout << min(dp[last][0], dp[last][1]) << '\n';
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