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

int mod = 1e9+7;
vi sum_l(101);
vector<vi> dp(101, vi(10));

bool valid(string s){
    for(int i = 1; i < s.size(); i++)
        if(s[i] < s[i-1])
            return false;
    return true;
}

int count(string s){
    if(s == "0")
        return 1;
    if(s.size() == 1)
        return s[0]-'0'+1;
    int n = s.size();
    ll sum = sum_l[n-1]; //add all numbers smaller than n digits
    s = '1' + s; //to make loop easier
    for(int i = 1; i <= n; i++){ //find all numbers with i-th digit smaller than current
        int current = s[i]-'0';
        int prev = s[i-1]-'0';
        if(current < prev) //cant continue
            break;
        for(int j = prev; j < current; j++){ 
            sum += dp[n-i+1][j];
            sum %= mod;
        }
        //at the end of each loop we lock i-th digit in place
    }
    if(valid(s)){
        sum++;
        sum %= mod;
    }
    return sum;
}

void solve(){
    dp[1] = vi(10, 1); //cate numere panta de i cifre cu prima cifra j exista
    for(int i = 2; i <= 100; i++){
        for(int j = 0; j < 10; j++){
            for(int k = j; k < 10; k++){
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= mod;
            }
        }
    }
    sum_l[0] = 1; //sum_l[i] - cate numere panta de i cifre sau mai putin exista
    for(int i = 1; i <= 100; i++){
        for(int j = 0; j < 10; j++){
            sum_l[i] += dp[i][j];
            sum_l[i] %= mod;
        }
    }
    string a, b;
    cin >> a >> b;
    cout << (((count(b) - count(a) + valid(a)) % mod) + mod) % mod << '\n';
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