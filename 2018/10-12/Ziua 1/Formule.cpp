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

bool is_op(char c){
    if(c == '+' || c == '=' || c == '/' || c == '-' || c == '*')
        return true;
    return false;
}

bool valid(string s){
    bool last = 0; // 0 - sign, 1 - number
    int n = s.size(), cnt = 0; // used for paranthesis
    for(int i = 0; i < n; i++){
        //cerr << s[i] << ' ';
        if(is_op(s[i])){
            if(!last)
                return 0;
            last = 0;
        } else if(s[i] == '('){
            if(i != 0 && s[i-1] == ')')
                return 0;
            cnt++;
        } else if(s[i] == ')'){
            cnt--;
            if(cnt < 0)
                return 0;
        } else if(s[i] >= '0' && s[i] <= '9'){
            if(i != 0 && s[i-1] == ')')
                return 0;
            last = 1;
        } else return 0;
    }
    if(cnt != 0 || !last)
        return 0;
    return 1;
}

void solve(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(valid(s))
            cout << "DA\n";
        else
            cout << "NU\n";
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