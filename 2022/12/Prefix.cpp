#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int maxn = 21, maxv = 2e6 + 2;
bitset <maxv> sieve;
int a [maxn], n;
int used [maxn], p[maxn];

void back (int step, int s) {
    if (step == n) {
        for (int i = 0; i < n; i++) cout << p[i] << " ";
        exit(0);
    }
    for (int i = 0; i < n; i++){
        if (!used[i] && !sieve[s + a[i]]) {
            used[i] = 1;
            p[step] = a[i] + s;
            back(step + 1, s + a[i]);
            used[i] = 0;
        }
    }
}

int main() {    
    sieve[1] = 1;
    for (int i = 2; i < maxv; i++){
        if (sieve[i]) continue;
        for (int j = i * 2; j < maxv; j+=i) {
            sieve[j] = 1;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    back(0, 0);
    return 0;
}