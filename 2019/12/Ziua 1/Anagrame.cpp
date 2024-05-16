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

bool check(vi &a, vi &b){
    for(int i = 0; i < 26; i++)
        if(a[i] != b[i])
            return false;
    return true;
}

void solve(){
    string s, t;
    cin >> s >> t;
    vi cnt1(26), cnt2(26);
    for(int i = 0; i < t.size(); i++)
        cnt1[t[i]-'a']++;
    for(int i = 0; i < s.size(); i++){
        cnt2[s[i]-'a']++;
        if(i - (int)t.size() >= 0)
            cnt2[s[i-t.size()]-'a']--;
        if(check(cnt1, cnt2)){
            cout << i-t.size()+1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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