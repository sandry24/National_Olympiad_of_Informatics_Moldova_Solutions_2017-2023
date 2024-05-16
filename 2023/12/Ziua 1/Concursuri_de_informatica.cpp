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
    int n, m;
    cin >> n >> m;
    vi a(n), diffs(n-1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i)
            diffs[i-1] = a[i] - a[i-1] - 1;
    }
    int tot = a[n-1] - a[0] + 1;
    sort(diffs.begin(), diffs.end(), greater<int>());
    for(int i = 0; i < m-1; i++)
        tot -= diffs[i];
    cout << tot << '\n';
}  
 
int main(){
    // freopen("monede.in", "r", stdin);
    // freopen("monede.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}