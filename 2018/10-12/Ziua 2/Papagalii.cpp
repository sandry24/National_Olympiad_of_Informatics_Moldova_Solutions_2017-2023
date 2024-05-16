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

vector<vector<string>> dp(50, vector<string>(500, "0"));
vector<string> prefix(500);

string add(string a, string b){
    string ans = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(b.size() < a.size())
        swap(a, b);
    int carry = 0;
    for(int i = 0; i < a.size(); i++){
        int dig1 = a[i] - '0';
        int dig2 = b[i] - '0';
        int sum = dig1 + dig2 + carry;
        carry = 0;
        while(sum >= 10){
            sum -= 10;
            carry++;
        }
        ans += char(sum + '0');
    }
    for(int i = a.size(); i < b.size(); i++){
        int dig = b[i] - '0';
        int sum = dig + carry;
        carry = 0;
        while(sum >= 10){
            sum -= 10;
            carry++;
        }
        ans += char(sum + '0');
    }
    if(carry != 0)
        ans += char(carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(){
    int s, n;
    cin >> s >> n;
    int total = s;
    dp[0][0] = "1";
    prefix[0] = "1";
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= total; j++)
            dp[i][j] = add(dp[i][j], prefix[min(j-1, total-s)]);
        prefix[0] = "0";
        for(int j = 1; j <= total; j++)
            prefix[j] = add(prefix[j-1], dp[i][j]); 
        total += s;
    }
    cout << prefix[total-s] << '\n';
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