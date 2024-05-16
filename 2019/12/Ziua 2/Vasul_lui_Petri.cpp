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

string subtract(string a, string b){ // assume a > b
    string ans = "";
    reverse(a.begin(), a.end()); 
    reverse(b.begin(), b.end());
    int carry = 0;
    for(int i = 0; i < b.size(); i++){
        int dig1 = a[i] - '0';
        int dig2 = b[i] - '0';
        int sum = dig1 - dig2 + carry;
        carry = 0;
        while(sum < 0){
            sum += 10;
            carry--;
        }
        ans += char(sum + '0');
    }
    for(int i = b.size(); i < a.size(); i++){
        int dig = a[i] - '0';
        int sum = dig + carry;
        carry = 0;
        while(sum < 0){
            sum += 10;
            carry--;
        }
        ans += char(sum + '0');
    }
    while(ans.size() > 1 && ans.back() == '0')
        ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(){
    int p, t, n;
    cin >> p >> t >> n;
    vector<pair<string, string>> dp(n+5, {"0", "0"}); //first - adult, second - teen
    dp[0].s = to_string(p);
    for(int i = 1; i <= n; i++){
        dp[i].s = dp[i-1].f; //prev adults made one child each
        dp[i].f = add(dp[i-1].f, dp[i-1].s); //prev adults + teens that grew up
        if(i-t >= 0)
            dp[i].f = subtract(dp[i].f, dp[i-t].s); //remove born at time i-t
    }
    cout << add(dp[n].f, dp[n].s) << '\n';
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