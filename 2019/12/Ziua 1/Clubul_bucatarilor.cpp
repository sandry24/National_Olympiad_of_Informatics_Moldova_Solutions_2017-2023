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
    int n, k, r;
    cin >> n >> k >> r;
    vi a(r);
    for(int i = 0; i < r; i++)
        cin >> a[i];
    int p;
    cin >> p;
    for(int i = r-1; i >= 0; i--){
        if(p == n)
            p = a[i];
        else
            p++;
    }
    cout << p << '\n';
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