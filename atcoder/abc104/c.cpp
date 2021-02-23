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

typedef pair<ll, ll> P;

int main() {
    ll d;
    cin >> d;

    ll g;
    cin >> g;

    vector<ll> p(d), c(d);
    rep2(i, d) cin >> p[i] >> c[i];

    ll ans = 1e9;
    rep2(i, 1 << d) {
        ll s = 0, num = 0, rest_max = -1;
        rep2(j, d) {
            if (i >> j & 1) {
                s += 100 * (j + 1) * p[j] + c[j];
                num += p[j];
            } else {
                rest_max = j;
            }
        }
        if (s < g) {
            int s1 = 100 * (rest_max + 1);
            int need = (g - s + s1 - 1) / s1;
            if (need >= p[rest_max]) continue;
            num += need;
        }
        ans = min(ans, num);
    }
    print(ans);
    return 0;
}