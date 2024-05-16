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

int ga(string a, string b){
    int sum = 0;
    vi cnt1(26), cnt2(26);
    for(auto i : a)
        cnt1[i-'a']++;
    for(auto i : b)
        cnt2[i-'a']++;
    for(int i = 0; i < 26; i++)
        sum += min(cnt1[i], cnt2[i]);
    return sum;
}

void solve(){
    int t, n, m, g;
    cin >> t >> n >> m >> g;
    string s;
    cin >> s;
    vector<vector<string>> a(n, vector<string>(m));
    vector<vi> prefix(n+1, vi(m+1));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j]; 
    if(t == 1){
        int maxe = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                maxe = max(maxe, ga(s, a[i][j]));
        if(maxe <= g){
            cout << "MONEA NU ARE RUDE\n";
            return;
        }
        cout << maxe << '\n';
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(ga(s, a[i][j]) == maxe)
                    cout << i+1 << ' ' << j+1 << ' ' << a[i][j] << '\n';
    } else {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                prefix[i+1][j+1] = (ga(s, a[i][j]) > g);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        int maxe = 0, x, y;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 1; k <= min(n, m); k++){
                    if(i - k < 0 || j - k < 0)
                        break;
                    int sum = prefix[i][j] - prefix[i-k][j] - prefix[i][j-k] + prefix[i-k][j-k];
                    if(sum == k*k && k > maxe){
                        maxe = k;
                        x = i-k+1;
                        y = j-k+1;
                    }
                }
            }
        }
        if(maxe == 0){
            cout << "MONEA NU ARE RUDE\n";
            return;
        }
        cout << x << ' ' << y << ' ' << maxe << '\n';
    }
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