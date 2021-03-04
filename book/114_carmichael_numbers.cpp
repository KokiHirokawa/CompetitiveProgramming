#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(n) for (ll i = 0; i < n; ++i)
#define rep2(i, n) for (ll i = 0; i < n; ++i)
#define rep3(i, a, b) for (ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define erep(n) for (ll i = 0; i <= n; ++i)
#define erep2(i, n) for (ll i = 0; i <= n; ++i)
#define erep3(i, a, b) for (ll i = a; i <= b; ++i)
#define erep4(i, a, b, c) for (ll i = a; i <= b; i += c)
#define rrep(i, a, b) for (ll i = a; i > b; --i)
#define rrep2(i, a, b, c) for (ll i = a; i > b; i -= c)
#define errep(i, a, b) for (ll i = a; i >= b; --i)
#define errep2(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define print(a) cout << a << endl;
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define cin(x) cin >> x;
const ll MOD = 1000000007;
const double PI = 3.14159265358979323846264338327950;
inline int newline() { putchar('\n'); return 0; }

ll mod_pow(ll x, ll n, ll mod) {
    ll m = x % n;
    if (m == 0) return 0;

    ll res = 1;
    n >>= 1;

    while (n > 0) {
        m = m * m % mod;
        if (n & 1) res = res * m % mod;
        n >>= 1;
    }

    return res;
}

int main() {
    ll n;
    cin >> n;

    rep3(i, 2, n) {
        ll a = i % n;
        if (mod_pow(i, n, n) == a) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}