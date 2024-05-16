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
    string s;
    cin >> s;
    if(s[0] == '0'){ //not sure daca exista asa test case
        cout << 1 << '\n';
        return;
    }
    int n = s.size(), ans = 0;
    for(int i = 1; i < n/2; i++){
        if(s[i] == '0')
            continue;
        ans++;
    }
    if(n % 2 == 0){
        string left = string(s.begin(), s.begin()+n/2);
        string right = string(s.begin()+n/2, s.end());
        if(left <= right)
            ans++;
    } else
        ans++;
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