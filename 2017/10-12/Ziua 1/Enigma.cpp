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
    string a, b;
    cin >> a >> b;
    vi cnt(26);
    int ans = 0;
    for(int i = 0; i < b.size(); i++){
        if(i < a.size())
            cnt[a[i]-'a']++;
        if(i > b.size() - a.size())
            cnt[a[a.size() + i - b.size()]-'a']--;
        ans += cnt[b[i]-'a'];
    }
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